//  ============================================================
//  CppUTest plugin to invoke TestStepper
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TESTSTEPPERPLUGIN_H
#define TESTSTEPPERPLUGIN_H

#include <CppUTestExt/MockSupportPlugin.h>
// TODO: #include <CppUTest/TestPlugin.h>

#include <baselib/BaseTypes.h>

//! the test stepper plugin
class TestStepperPlugin: public MockSupportPlugin
{
public:
    //! type of function pointer for post action
    typedef void (*PostActionFunc)();

    //! - standard preTestAction
    //! - clear TestStepper
    void preTestAction(UtestShell&, TestResult&);

    //! set a function for post processing in case of failure
    //! @param func function to execute in case of failure
    inline void setFailurePostAction(PostActionFunc func)
    {
        mPostAction = func;
    }

    //! post test processing
    //! - evaluate TestStepper in case of a failed test
    //! - call assigned post test function in case of failure
    //! - clear CppUTest mocking
    //! - remove all temporary CppUTest style comparators
    //! Note:
    //! all expectation checks assumed done
    void postTestAction(UtestShell& test, TestResult& result);

    //! register the plugin
    static void setup();

    //! TestStepperPlugin::instance()
    static TestStepperPlugin& instance();

private:

    //! name of plugin
    //! "TSP"
    static const CONST_C_STRING cName;

    //! post test action function pointer
    PostActionFunc mPostAction;

    //! default constructor
    inline TestStepperPlugin() :
        MockSupportPlugin(cName),
        mPostAction(0)
    {}
    //  Standard 8.1.1
    TestStepperPlugin(const TestStepperPlugin& o);
    TestStepperPlugin& operator = (const TestStepperPlugin& o);
};

#endif // _H
