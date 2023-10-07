#include <TestStepper/TestStepperPlugin.h>
#include <TestStepper/TestStepper.h>
#include <CppUTestExt/MockSupport.h>
#include <CppUTest/TestRegistry.h>

void TestStepperPlugin::setup()
{
    TestRegistry::getCurrentRegistry()->installPlugin(&TestStepperPlugin::instance());
}

const CONST_C_STRING TestStepperPlugin::cName = "TSP";

void TestStepperPlugin::preTestAction(UtestShell& s, TestResult& r)
{
    MockSupportPlugin::preTestAction(s, r);
    TestStepper::clear();
}

void TestStepperPlugin::postTestAction(UtestShell& test, TestResult& result)
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
    mock().removeAllComparatorsAndCopiers();
}

TestStepperPlugin& TestStepperPlugin::instance()
{
    static TestStepperPlugin instance;
    return instance;
}
