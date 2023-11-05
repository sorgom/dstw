
#include <TestSteps/TestStepsPlugin.h>
#include <comparators/installComparators.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <BAS/BaseTypes.h>

int main(const INT32 argc, const CONST_C_STRING* const argv)
{
    MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();

    TestStepsPlugin::setup();
    test::installComparators(TestStepsPlugin::instance());
    return CommandLineTestRunner::RunAllTests(argc, argv);
}