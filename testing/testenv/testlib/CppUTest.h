//  ============================================================
//  frequently used includes of CppUTest
//  but also
//  - the TestSteps
//  - some useful macros
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef CPPUTEST_H
#define CPPUTEST_H

//  no new malloc in application
#define CPPUTEST_MEM_LEAK_DETECTION_DISABLED

#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

//! standard check 'n' clear
#ifndef CHECK_N_CLEAR
#define CHECK_N_CLEAR() mock().checkExpectations(); mock().clear();
#endif

//! a bit (of) check
#define CHECK_BIT(bit, value) CHECK_TRUE((value & bit) not_eq 0)

//  ============================================================
//  CppUTest parameter macros
//  raw typing:
//      .withParameterOfType("SomeStruct", "param", param)
//  strin constant c__SomeStruct defined:
//      .withParameterOfType(c__SomeStruct, "param", param)
//  use:
//    .TPARAM(SomeStruct, param)
// 
//  raw typing:
//      .withParameter("param", param)
//  use:
//      .PARAM(param)
//  ============================================================
//! must be in namespace test
#define TPARAM(TYPE, NAME) \
    withParameterOfType(c__ ## TYPE, #NAME, &NAME)

#define PARAM(NAME) \
    withParameter(#NAME, NAME)

#define PPARAM(NAME) \
    withPointerParameter(#NAME, (PTR) NAME)

#define RETURN_DEF_INT(VAL) \
    returnIntValueOrDefault(VAL)

#define RETURN_DEF_BOOL(VAL) \
    returnUnsignedIntValueOrDefault(VAL)

#define RETURN_DEF_UNSIGNED(VAL) \
    returnUnsignedIntValueOrDefault(VAL)

#define AND_RETURN(VAL) \
    andReturnValue(VAL)

#define AND_RETURN_BOOL(VAL) \
    andReturnValue(static_cast<unsigned>(VAL))

#define IGNORE() \
    ignoreOtherParameters()

#endif // _H

