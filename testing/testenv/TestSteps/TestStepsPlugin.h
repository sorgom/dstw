//  ============================================================
//  CppUTest plugin to invoke TestSteps
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TESTSTEPPERPLUGIN_H
#define TESTSTEPPERPLUGIN_H

#include <CppUTestExt/MockSupportPlugin.h>

//! the test stepper plugin
class TestStepsPlugin: public MockSupportPlugin
{
public:
    //! type of function pointer for post action
    typedef void (*PostActionFunc)();

    //! - standard preTestAction
    //! - clear TestSteps
    void preTestAction(UtestShell&, TestResult&);

    //! set a function for post processing in case of failure
    //! @param func function to execute in case of failure
    inline void setFailurePostAction(PostActionFunc func)
    {
        mPostAction = func;
    }

    //! post test processing
    //! - evaluate TestSteps in case of a failed test
    //! - call assigned post test function in case of failure
    //! - clear CppUTest mocking
    //! - remove all temporary CppUTest style comparators
    //! Note:
    //! all expectation checks assumed done
    void postTestAction(UtestShell& test, TestResult& result);

    //! register the plugin
    static void setup();

    //! TestStepsPlugin::instance()
    static TestStepsPlugin& instance();

private:

    //! name of plugin
    //! "TSP"
    static const char* const cName;

    //! post test action function pointer
    PostActionFunc mPostAction;

    //! default constructor
    inline TestStepsPlugin() :
        MockSupportPlugin(cName),
        mPostAction(0)
    {}

    TestStepsPlugin(const TestStepsPlugin& o);
    TestStepsPlugin& operator = (const TestStepsPlugin& o);
};

#endif // _H
