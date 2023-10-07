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


// #include <TestLib/Allocation.h>
// #include <TestLib/Comparator.h>
// #include <TestLib/Call.h>


//! standard check 'n' clear
#ifndef CHECK_N_CLEAR
#define CHECK_N_CLEAR() mock().checkExpectations(); mock().clear();
#endif

//! a bit (of) check
#define CHECK_BIT(bit, value) CHECK_TRUE((value & bit) not_eq 0)

// //! compare of telegrams (or any data pointers) with associated Comparator
// //! @tparam T       telegram / data type
// //! @param expected pointer to expected data
// //! @param actual   pointer to actual   data
// //! @param issue    what it is about
// template <class T>
// inline void compTel(const T* expected, const T* actual, const CONSTSTRPTR issue)
// {
//     test::getComparator<T>().comp(expected, actual, issue);
// }

// //! compare of telegrams with update of TestStepper line
// //! @param expected pointer to expected data
// //! @param actual   pointer to actual   data
// #define L_CHECK_TEL(expected, actual) testlib::TestStepper::setLine(__LINE__); compTel(expected, actual, #actual)

// //! check number of calls with update of TestStepper line
// //! @param id   call id dependent on project
// //! @param cnt  expected count of calls
// #define L_CHECK_CALLS(id, cnt) L_CHECK_EQUAL(cnt, testlib::Call::count(id))

#endif // _H

