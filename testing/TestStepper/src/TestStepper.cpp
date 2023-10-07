
#include <TestStepper/TestStepper.h>
#include <cstdio>
#include <cstring>

using std::printf;
using std::memset;

bool TestStepper::mDone = false;
UINT8 TestStepper::mLevel = 0;
UINT8 TestStepper::mShow = 0;

const CONST_C_STRING TestStepper::c__step = "STEP(";
const CONST_C_STRING TestStepper::c__ErrTestStepper = "TestStepper error";
const CONST_C_STRING TestStepper::c__precondition = "PRE";
const CONST_C_STRING TestStepper::c__printFile = "file: %s\n";
const CONST_C_STRING TestStepper::c__printFunc = "func: %s\n";
const CONST_C_STRING TestStepper::c__printLine = "line: %d\n";

TestStepper::Trace TestStepper::mTrace[cNmuLevels] = {0};

void TestStepper::clear()
{
    mShow = 0;
    enterLevel(0, 0, 0, 0);
}

void TestStepper::show(const UINT8 trcLevel)
{
    mShow = trcLevel;
    if (isShowing())
    {
        printf(")\n");
    }
}

void TestStepper::clearLevel(const UINT8 level)
{
    for (UINT8 l = level; l < cNmuLevels; ++l)
    {
        memset(&mTrace[l], 0, sizeof(Trace));
    }
    if (level == 0)
    {
        mDone = false;
    }
}

void TestStepper::enterLevel(
    const UINT8 level,
    const CONST_C_STRING file,
    const UINT16 line,
    const CONST_C_STRING func
)
{
    chk(level < cNmuLevels);
    clearLevel(level);
    Trace& trc = mTrace[level];
    trc.file = file;
    trc.line = line;
    trc.func = func;
    trc.step = cStepPre;
    mLevel = level;
}

void TestStepper::step(
    const step_t step,
    const CONST_C_STRING file,
    const UINT16 line,
    const CONST_C_STRING func
)
{
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
    chk(step > 0);
    if (mShow > mLevel)
    {
        out();
    }
}

void TestStepper::setLine(const UINT16 line)
{
    mTrace[mLevel].line = line;
}

void TestStepper::beginSteps(
    const CONST_C_STRING file,
    const UINT16 line,
    const CONST_C_STRING func
)
{
    enterLevel(mLevel + 1, file, line, func);
}

void TestStepper::endSteps()
{
    chk(mLevel > 0);
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
    for (UINT8 l = 0; l < cNmuLevels; ++l)
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

    for (UINT8 l = 0; l < cNmuLevels; ++l)
    {
        const Trace& trc = mTrace[l];
        if (trc.step > 0)
        {
            if (l > 0)
            {
                printf("\n");
            }
            if (trc.file not_eq 0)
            {
                printf(c__printFile, trc.file);
            }
            if (trc.func not_eq 0)
            {
                printf(c__printFunc, trc.func);
            }
            printf(c__printLine, trc.line);
            printf(c__step);
            stepOut(trc.step);
            printf(")\n");
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

void TestStepper::chk(const bool ok)
{
    if (not ok)
    {
        clear();
// TODO:            FAIL(c__ErrTestStepper);
    }
}

void TestStepper::stepOut(const step_t step)
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
