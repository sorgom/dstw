#include <TestSteps/TestStepsPlugin.h>
#include <TestSteps/TestSteps.h>
#include <CppUTestExt/MockSupport.h>
#include <CppUTest/TestRegistry.h>

void TestStepsPlugin::setup()
{
    TestRegistry::getCurrentRegistry()->installPlugin(&TestStepsPlugin::instance());
}

const char* const TestStepsPlugin::cName = "TSP";

void TestStepsPlugin::preTestAction(UtestShell& s, TestResult& r)
{
    MockSupportPlugin::preTestAction(s, r);
    TestSteps::clear();
}

void TestStepsPlugin::postTestAction(UtestShell& test, TestResult& result)
{
    if (test.hasFailed())
    {
        TestSteps::fail();
        if (mPostAction not_eq 0)
        {
            (*mPostAction)();
        }
    }
    mock().clear();
    mock().removeAllComparatorsAndCopiers();
}

TestStepsPlugin& TestStepsPlugin::instance()
{
    static TestStepsPlugin instance;
    return instance;
}
