//! @file
//! @brief      implementation according to associated header
//!
//! @author     SOM, Manfred Sorgo, manfred.sorgo.ext@siemens.com
//!
//! @reviewer   SRM, Martin Schneider, martin.sm.schneider@siemens.com
//!
//! @copyright (c) Siemens Mobility AG 2020 all rights reserved confidential
//!
//! Change History
//! @date 2019-06-13 SOM: creation of file
//! @date 2020-06-24 SRM: review ok

//! @(#)9cefdceefba9a6ecdd46216269aa9111 2021-08-23 13:05:53 TestSupportPlugin.cpp >

#include <testenv/CppUTest.h>

//  associated header
#include <testenv/TestSupportPlugin.h>

namespace test
{
    TestSupportPlugin& TestSupportPlugin::instance()
    {
        static TestSupportPlugin instance;
        return instance;
    }

    const CONST_C_STRING TestSupportPlugin::cName = "TSP";

    void TestSupportPlugin::preTestAction(UtestShell& s, TestResult& r)
    {
        MockSupportPlugin::preTestAction(s, r);
        TestStepper::clear();
    }

    void TestSupportPlugin::postTestAction(UtestShell& test, TestResult& result)
    {
        if (test.hasFailed())
        {
            TestStepper::fail();
            if (mPostAction not_eq 0)
            {
                (*mPostAction)();
            }
        }
        mock().clear();
        // TODO: why not supported
        mock().removeAllComparatorsAndCopiers();
    }

} // namespace
