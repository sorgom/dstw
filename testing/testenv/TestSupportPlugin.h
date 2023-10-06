//! @file
//! @brief      definition of the test support plugin
//!
//! @description
//!             this plugin is used to
//!             - install project individual CppUTest style comparators
//!             - evaluate the TestStepper in case of a failed test
//!
//! @author     unknown
//!
//! @reviewer   SRM, Martin Schneider, martin.sm.schneider@siemens.com
//!
//! @copyright (c) Siemens Mobility AG 2020 all rights reserved confidential
//!
//! Change History
//! @date 2019-06-20 SOM: adaption for bcm300
//! @date 2020-07-29 SRM: review performed
//! @date 2020-08-17 SRM: review ok

#ifndef TESTLIB_TESTSUPPORTPLUGIN_H
#define TESTLIB_TESTSUPPORTPLUGIN_H

//! @(#)4b4d9f83e9e5ce165af89f9dc2806df3 2021-08-23 13:05:48 TestSupportPlugin.h >

#include <CppUTestExt/MockSupport.h>
#include <CppUTestExt/MockSupportPlugin.h>
#include <CppUTest/TestPlugin.h>

#include <baselib/BaseTypes.h>

namespace test
{
    //! the test support plugin
    class TestSupportPlugin: public MockSupportPlugin
    {
    public:
        //! type of function pointer for post action
        typedef void (*PostActionFunc)();

        //! TestSupportPlugin::instance()
        static TestSupportPlugin& instance();

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

    protected:
        //! name of plugin
        //! "TSP"
        static const CONST_C_STRING cName;

        //! post test action function pointer
        PostActionFunc mPostAction;

        //! default constructor
        inline TestSupportPlugin() :
            MockSupportPlugin(0),
            // MockSupportPlugin(cName),
            mPostAction(0)
        {}
    };
} // namespace

#endif // _H
