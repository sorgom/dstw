#pragma once
#ifndef CPPUTEST_H
#define CPPUTEST_H

// #undef eq
#define CPPUTEST_MEM_LEAK_DETECTION_DISABLED

#include <TestStepper/TestStepper.h>

// #include <CppUTest/UtestMacros.h>
#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTestExt/MockSupport.h>
#include <testlib/TestLiterals.h>


// #include <TestLib/Allocation.h>
// #include <TestLib/Comparator.h>
// #include <TestLib/Call.h>


//! standard check 'n' clear
#ifndef CHECK_N_CLEAR
#define CHECK_N_CLEAR() mock().checkExpectations(); mock().clear();
#endif

//! a bit (of) check
#define CHECK_BIT(bit, value) CHECK_TRUE((value & bit) not_eq 0)

//! must be in namespace test
#define TPARAM(TYPE, NAME) withParameterOfType(c__ ## TYPE, #NAME, &NAME);
#define PARAM(NAME) withParameter(#NAME, NAME)

#endif // _H

