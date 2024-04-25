//  ============================================================
//  number of elements in test data
//  - track switches
//  - signals
//  - level crossings
//  - segments
//
//  pre-defined here
//  definable at compile time
//  e.g.: -DTEST_NUM_SIG=500 
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include <codebase/BaseTypes.h>

#ifndef TEST_NUM_TSW
#define TEST_NUM_TSW 11
#endif 

#ifndef TEST_NUM_SIG
#define TEST_NUM_SIG 10
#endif 

#ifndef TEST_NUM_LCR
#define TEST_NUM_LCR 9
#endif 

#ifndef TEST_NUM_SEG
#define TEST_NUM_SEG 8
#endif 

namespace test
{
    constexpr UINT16 Port_Fld  = 8080;
    constexpr UINT16 Port_Gui  = 8081;
    constexpr UINT16 Port_Ctrl = 8082;
} // namespace
