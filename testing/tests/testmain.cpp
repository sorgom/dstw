
#define CPPUTEST_MEM_LEAK_DETECTION_DISABLED


// #include <TestLib/CppUTest.h>
#include <CppUTest/TestHarness.h> // i.a. includes MemoryLeakDetectorNewMacros.h
#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTestExt/MockSupport.h>
#include <CppUTest/TestRegistry.h>

int main(int argc, const char* argv[])
{
    const char* argvDef[] = {"exe", "-v"};

    MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
    CommandLineTestRunner::RunAllTests(2, argvDef);

    return 0;
}