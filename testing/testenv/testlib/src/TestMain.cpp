
#include <TestSteps/TestStepsPlugin.h>
#include <comparators/installComparators.h>
#include <CppUTest/CommandLineTestRunner.h>

#include <codebase/BaseTypes.h>

int main(const INT32 argc, const CONST_C_STRING* const argv)
{
    MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();

    TestStepsPlugin::setup();
    test::installComparators(TestStepsPlugin::instance());
#ifdef RUN_ON_DEMAND
    return argc > 1 ? CommandLineTestRunner::RunAllTests(argc - 1, &argv[1]) : 0;
#else
    return CommandLineTestRunner::RunAllTests(argc, argv);
#endif
}
