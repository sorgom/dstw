//  ============================================================
//  The test stepper
//  solves a great disadvantage of CppUTest:
//  
//  when CppUTest exits a test due to an unmatched expectation
//  it only provides
//  - the test name
//  - the source line of the test's begin
//  so if you have a test with some amount of lines
//  you will have a hard time to figure out
//  where exactly the mismatch happens
//
//  using TestSteps's STEP() macro
//  will provide you with line of the last STEP() macro placed
//  
//  the STEP() macro also helps
//  to give your tests a more readable structure
//
//  see TestSteps documentation on github for more details
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TESTSTEPS_H
#define TESTSTEPS_H

#include <CppUTest/UtestMacros.h>

//  assign precondition / setup
#define PRECONDITION() TestSteps::precondition(__FILE__, __LINE__, __STEPPER_FUNCTION__);
#define SETUP() PRECONDITION()

//  place a step
#define STEP(n) TestSteps::step(n, __FILE__, __LINE__, __STEPPER_FUNCTION__);

//  begin set of steps including precondition
#define SUBSTEPS() TestSteps::subSteps(__FILE__, __LINE__, __STEPPER_FUNCTION__);

//  leave set of steps
#define ENDSTEPS() TestSteps::endSteps();

//  use loop counter 0 .. for steps
#define LSTEP(n) STEP(n + 1)

//  Utest check macros extensions: show line in case of failure
#define L_CHECK_EQUAL(expected, actual) TestSteps::setLine(__LINE__); CHECK_EQUAL(expected, actual);
#define L_CHECK_TRUE(actual) L_CHECK_EQUAL(true, actual)
#define L_CHECK_FALSE(actual) L_CHECK_EQUAL(false, actual)
//  equal size of two types / structs / classes
#define L_CHECK_EQUAL_SIZE(T1, T2) L_CHECK_EQUAL(sizeof(T1), sizeof(T2))

//  steps / substeps output during test
#define TS_SHOW(level) TestSteps::show(level);
#define TS_SHOW_ALL() TestSteps::showAll();
#define TS_HIDE() TestSteps::hide();

class TestSteps
{
public:
    //  clear test steps
    static void clear();

    //  switch on tracing of test steps
    static void show(unsigned char trcLevel = 1);

    //  switch on tracing of test steps for all levels
    inline static void showAll() { mShow = cNmuLevels; }

    //  switch off tracing of test steps (default)
    inline static void hide() { mShow = 0; }

    //  are we showing any test steps
    inline static bool isShowing() { return mShow > 0; }

    //  begin set of steps
    static void subSteps(
        const char* const file,
        unsigned short line,
        const char* const func
    );

    //  assign precondition with current level / set of steps
    inline static void precondition(
        const char* const file,
        unsigned short line,
        const char* const func
    )
    {
        step(cStepPre, file, line, func);
    }

    //  assign a step with current level / set of steps
    static void step(
        unsigned short step,
        const char* const file,
        unsigned short line,
        const char* const func
    );

    //  set (more precise) line within current test step
    static void setLine(unsigned short line);

    //  end set of steps
    //  required
    static void endSteps();

    //  on test failure
    static void fail();
private:

    struct Trace
    {
        const char* file;
        const char* func;
        unsigned line;
        unsigned step;
    };

    static const unsigned char cNmuLevels = 20;
    static const unsigned char cMaxLevel  = cNmuLevels - 1;
    static const unsigned short cStepPre = ~ 0;

    //  level traces
    static Trace mTrace[cNmuLevels];

    static const char* const c__step;
    static const char* const c__precondition;
    static const char* const c__printFile;
    static const char* const c__printFunc;
    static const char* const c__printLine;
    static const char* const c__ErrTestSteps;
    static const char* const c__ErrStep;
    static const char* const c__ErrSubSteps;
    static const char* const c__ErrEndSteps;

    static bool mDone;
    static unsigned char mLevel;
    static unsigned char mShow;

    static void clearLevel(unsigned char level);

    static void enterLevel(
        unsigned char level,
        const char* const file,
        unsigned short line,
        const char* const func
    );

    //  sub steps done?
    static bool subStepsDone();

    //  output of last step
    static void out();

    //  "stack trace"
    static void trace(bool insertLine = false);

    //  apply internal check
    //  (without CppUTest check counter)
    static void chk(bool ok, const char* msg = c__ErrTestSteps);

    //  step or precondition output
    static void stepOut(unsigned short step);

    //  Standard 8.1.1
    TestSteps();
    TestSteps(const TestSteps& o);
    TestSteps& operator =(const TestSteps& o);
};

//  compiler specifica
#if defined(COMPILER_CADUL)
#define __STEPPER_FUNCTION__ 0
#elif defined(_MSC_VER)
#define __STEPPER_FUNCTION__ __FUNCTION__
#else
#define __STEPPER_FUNCTION__ __func__
#endif


#endif // _H

