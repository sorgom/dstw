//! @file
//! @brief      header for CppUTest includes
//!
//! @author     SOM, Manfred Sorgo, manfred.sorgo.ext@siemens.com
//!
//! @reviewer   SRM, Martin Schneider, martin.sm.schneider@siemens.com
//!
//! @copyright (c) Siemens Mobility AG 2020 all rights reserved confidential
//!
//! Change History
//! @date 2016-02-19 SOM: creation of file
//! @date 2020-06-24 SRM: review ok

#ifndef TESTLIB_CPPUTEST_H
#define TESTLIB_CPPUTEST_H

//! @(#)759d979a6b7c1c66b9bbb9baefba42de 2021-09-03 00:12:02 CppUTest.h >

#undef eq
#define CPPUTEST_MEM_LEAK_DETECTION_DISABLED

#define TODO_TEST IGNORE_TEST
#define WRONG_TEST IGNORE_TEST
#define TEST_FAILS IGNORE_TEST
#define TEST_QP TEST

#include <CppUTest/TestHarness.h> // i.a. includes MemoryLeakDetectorNewMacros.h
#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTestExt/MockSupport.h>
#define eq ==

// #include <TestLib/Allocation.h>
#include <testenv/TestStepper.h>
// #include <TestLib/Comparator.h>
// #include <TestLib/Call.h>

//! standard check 'n' clear
#ifndef CHECK_N_CLEAR
#define CHECK_N_CLEAR() mock().checkExpectations(); mock().clear();
#endif

//! a bit (of) check
#define CHECK_BIT(bit, value) CHECK_TRUE((value & bit) not_eq 0)

//! equality check with update of TestStepper line
#define L_CHECK_EQUAL(expected, actual) test::TestStepper::setLine(__LINE__); CHECK_EQUAL(expected, actual)

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

