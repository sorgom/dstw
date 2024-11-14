
#include <TestSteps/TestStepsPlugin.h>
#include <comparators/installComparators.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <codebase/BaseTypes.h>

int main(const INT32 argc, const CONST_C_STRING* const argv)
{
    MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();

    TestStepsPlugin::setup();
    test::installComparators(TestStepsPlugin::instance());
#ifdef REQUIRE_PARAM
    return argc > 1 ? CommandLineTestRunner::RunAllTests(argc, argv) : 0;
#else
    return CommandLineTestRunner::RunAllTests(argc, argv);
#endif
}
