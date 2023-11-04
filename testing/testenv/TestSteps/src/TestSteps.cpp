
#include <TestSteps/TestSteps.h>
#include <CppUTest/Utest.h>
#include <cstdio>
#include <cstring>

using std::printf;
using std::memset;

bool TestSteps::mDone = false;
unsigned char TestSteps::mLevel = 0;
unsigned char TestSteps::mShow = 0;

const char* const TestSteps::c__step = "STEP(";
const char* const TestSteps::c__precondition = "PRE";
const char* const TestSteps::c__printFile = "file: %s\n";
const char* const TestSteps::c__printFunc = "func: %s\n";
const char* const TestSteps::c__printLine = "line: %d\n";
const char* const TestSteps::c__ErrTestSteps = "TestSteps error";
const char* const TestSteps::c__ErrStep = "TestSteps: STEP(n) n must be greater 0.";
const char* const TestSteps::c__ErrSubSteps = "TestSteps: SUBSTEPS error. Did you forget ENDSTEPS?";
const char* const TestSteps::c__ErrEndSteps = "TestSteps: ENDSTEPS error. Did you forget SUBSTEPS?";

TestSteps::Trace TestSteps::mTrace[cNmuLevels] = {0};

void TestSteps::clear()
{
    mShow = 0;
    enterLevel(0, 0, 0, 0);
}

void TestSteps::show(const unsigned char trcLevel)
{
    mShow = trcLevel;
    if (isShowing())
    {
        printf(")\n");
    }
}

void TestSteps::clearLevel(const unsigned char level)
{
    for (unsigned char l = level; l < cNmuLevels; ++l)
    {
        memset(&mTrace[l], 0, sizeof(Trace));
    }
    if (level == 0)
    {
        mDone = false;
    }
}

void TestSteps::enterLevel(
    const unsigned char level,
    const char* const file,
    const unsigned short line,
    const char* const func
)
{
    chk(level < cNmuLevels, c__ErrSubSteps);
    clearLevel(level);
    Trace& trc = mTrace[level];
    trc.file = file;
    trc.line = line;
    trc.func = func;
    trc.step = cStepPre;
    mLevel = level;
}

void TestSteps::step(
    const unsigned short step,
    const char* const file,
    const unsigned short line,
    const char* const func
)
{
    chk(step > 0, c__ErrStep);
    Trace& trc = mTrace[mLevel];
    trc.step = step;
    trc.file = file;
    trc.line = line;
    trc.func = func;
    if (mLevel < cMaxLevel)
    {
        mTrace[mLevel + 1].step = 0;
    }
    mDone = true;
    if (mShow > mLevel)
    {
        out();
    }
}

void TestSteps::setLine(const unsigned short line)
{
    mTrace[mLevel].line = line;
}

void TestSteps::subSteps(
    const char* const file,
    const unsigned short line,
    const char* const func
)
{
    enterLevel(mLevel + 1, file, line, func);
}

void TestSteps::endSteps()
{
    chk(mLevel > 0, c__ErrEndSteps);
    clearLevel(mLevel);
    --mLevel;
}

bool TestSteps::subStepsDone()
{
    return mTrace[1].step > 0;
}

void TestSteps::out()
{
    printf(c__step);
    for (unsigned char l = 0; l < cNmuLevels; ++l)
    {
        const Trace& trc = mTrace[l];
        if (trc.step > 0)
        {
            if (l > 0)
            {
                printf(".");
            }
            stepOut(trc.step);
        }
    }
    printf(")\n");
}

void TestSteps::trace(const bool insertLine)
{
    if (insertLine)
    {
        printf("\n");
    }

    for (unsigned char l = 0; l < cNmuLevels; ++l)
    {
        const Trace& trc = mTrace[l];
        if (trc.step > 0)
        {
            if (l > 0)
            {
                printf("\n");
            }
            printf(c__step);
            stepOut(trc.step);
            printf(")\n");
            if (trc.file not_eq 0)
            {
                printf(c__printFile, trc.file);
            }
            if (trc.func not_eq 0)
            {
                printf(c__printFunc, trc.func);
            }
            printf(c__printLine, trc.line);
        }
    }
}

void TestSteps::fail()
{
    if (mDone)
    {
        if (subStepsDone())
        {
            out();
            trace(true);
        }
        else
        {
            trace();
        }
    }
    clear();
}

void TestSteps::chk(const bool ok, const char* const msg)
{
    if (not ok)
    {
        clear();
        FAIL(msg);
    }
}

void TestSteps::stepOut(const unsigned short step)
{
    if (step == cStepPre)
    {
        printf(c__precondition);
    }
    else
    {
        printf("%d", step);
    }
}
