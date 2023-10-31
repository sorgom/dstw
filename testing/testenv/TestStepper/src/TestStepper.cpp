
#include <TestStepper/TestStepper.h>
#include <CppUTest/Utest.h>
#include <cstdio>
#include <cstring>

using std::printf;
using std::memset;

bool TestStepper::mDone = false;
unsigned char TestStepper::mLevel = 0;
unsigned char TestStepper::mShow = 0;

const char* const TestStepper::c__step = "STEP(";
const char* const TestStepper::c__precondition = "PRE";
const char* const TestStepper::c__printFile = "file: %s\n";
const char* const TestStepper::c__printFunc = "func: %s\n";
const char* const TestStepper::c__printLine = "line: %d\n";
const char* const TestStepper::c__ErrTestStepper = "TestStepper error";
const char* const TestStepper::c__ErrStep = "TestStepper: STEP(n) n must be greater 0.";
const char* const TestStepper::c__ErrSubSteps = "TestStepper: SUBSTEPS error. Did you forget ENDSTEPS?";
const char* const TestStepper::c__ErrEndSteps = "TestStepper: ENDSTEPS error. Did you forget SUBSTEPS?";

TestStepper::Trace TestStepper::mTrace[cNmuLevels] = {0};

void TestStepper::clear()
{
    mShow = 0;
    enterLevel(0, 0, 0, 0);
}

void TestStepper::show(const unsigned char trcLevel)
{
    mShow = trcLevel;
    if (isShowing())
    {
        printf(")\n");
    }
}

void TestStepper::clearLevel(const unsigned char level)
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

void TestStepper::enterLevel(
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

void TestStepper::step(
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

void TestStepper::setLine(const unsigned short line)
{
    mTrace[mLevel].line = line;
}

void TestStepper::subSteps(
    const char* const file,
    const unsigned short line,
    const char* const func
)
{
    enterLevel(mLevel + 1, file, line, func);
}

void TestStepper::endSteps()
{
    chk(mLevel > 0, c__ErrEndSteps);
    clearLevel(mLevel);
    --mLevel;
}

bool TestStepper::subStepsDone()
{
    return mTrace[1].step > 0;
}

void TestStepper::out()
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

void TestStepper::trace(const bool insertLine)
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

void TestStepper::fail()
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

void TestStepper::chk(const bool ok, const char* const msg)
{
    if (not ok)
    {
        clear();
        FAIL(msg);
    }
}

void TestStepper::stepOut(const unsigned short step)
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
