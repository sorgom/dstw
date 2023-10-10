#pragma once
#ifndef TESTSTEPPER_H
#define TESTSTEPPER_H

#include <baselib/BaseTypes.h>

#include <CppUTest/UtestMacros.h>

//! test stepper
class TestStepper
{
public:
    typedef UINT16 step_t;

    //! clear test steps
    static void clear();

    //! switch on tracing of test steps
    //! @param trcLevel 1 .. n
    static void show(UINT8 trcLevel = 1);

    //! switch on tracing of test steps for all levels
    inline static void showAll() { mShow = cNmuLevels; }

    //! switch off tracing of test steps (default)
    inline static void hide() { mShow = 0; }

    //! are we showing any test steps
    inline static bool isShowing() { return mShow > 0; }

    //! begin set of steps
    static void beginSteps(
        CONST_C_STRING file,
        UINT16 line,
        CONST_C_STRING func
    );

    //! assign precondition with current level / set of steps
    inline static void precondition(
        CONST_C_STRING file,
        UINT16 line,
        CONST_C_STRING func
    )
    {
        step(cStepPre, file, line, func);
    }

    //! assign a step with current level / set of steps
    static void step(
        step_t step,
        CONST_C_STRING file,
        UINT16 line,
        CONST_C_STRING func
    );

    //! set (more precise) line within current test step
    //! @param line line within source file (usually macro __LINE__)
    static void setLine(UINT16 line);

    //! end set of steps
    //! required
    static void endSteps();

    //! on test failure
    static void fail();
private:

    struct Trace
    {
        CONST_C_STRING file;
        CONST_C_STRING func;
        UINT16 line;
        step_t step;
    };

    static const UINT8 cNmuLevels = 20;
    static const UINT8 cMaxLevel  = cNmuLevels - 1;
    static const step_t cStepPre = ~ 0;

    //! level traces
    static Trace mTrace[cNmuLevels];

    static const CONST_C_STRING c__step;
    static const CONST_C_STRING c__ErrTestStepper;
    static const CONST_C_STRING c__precondition;
    static const CONST_C_STRING c__printFile;
    static const CONST_C_STRING c__printFunc;
    static const CONST_C_STRING c__printLine;

    static bool mDone;
    static UINT8 mLevel;
    static UINT8 mShow;

    static void clearLevel(UINT8 level);

    static void enterLevel(
        UINT8 level,
        CONST_C_STRING file,
        UINT16 line,
        CONST_C_STRING func
    );

    //! sub steps done?
    static bool subStepsDone();

    //! output of last step
    static void out();

    //! "stack trace"
    //! @param insertLine empty line on top
    static void trace(bool insertLine = false);

    //! apply internal check
    //! (without CppUTest check counter)
    static void chk(bool ok);

    //! step or precondition output
    static void stepOut(step_t step);

    //  Standard 8.1.1
    TestStepper();
    TestStepper(const TestStepper& o);
    TestStepper& operator =(const TestStepper& o);
};

//! ============================================================
//! common test step macros
//! ============================================================
#if defined(COMPILER_CADUL)
#define __STEPPER_FUNCTION__ 0
#elif defined(_MSC_VER)
#define __STEPPER_FUNCTION__ __FUNCTION__
#else
#define __STEPPER_FUNCTION__ __func__
#endif

//! assign precondition
#define PRECONDITION() TestStepper::precondition(__FILE__, __LINE__, __STEPPER_FUNCTION__);
#define SETUP() PRECONDITION()

//! assign a step
#define STEP(n) TestStepper::step(n, __FILE__, __LINE__, __STEPPER_FUNCTION__);

//! ============================================================
//! test step macros that need to bee defined
//! in a method other than CppUTest UTest body
//! ============================================================
//! begin set of steps including precondition
#define BEGINSTEPS() TestStepper::beginSteps(__FILE__, __LINE__, __STEPPER_FUNCTION__);

//! leave set of steps
#define ENDSTEPS() TestStepper::endSteps();

//! ============================================================
//! test step macros for
//! - compatibility to recent stuff
//! - less typing
//! ============================================================

//! go into sub step level for current scope
#define SUBSTEPS() BEGINSTEPS()
#define STEPS() BEGINSTEPS()

//! ============================================================
//! Utest macros extensions
//! ============================================================
//! equality check with update of TestStepper line
#define L_CHECK_EQUAL(expected, actual) TestStepper::setLine(__LINE__); CHECK_EQUAL(expected, actual);



#endif // _H

