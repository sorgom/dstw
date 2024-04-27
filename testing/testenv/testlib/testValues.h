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
    // constexpr UINT16 tcpPortFld  = 8080;
    // constexpr UINT16 tcpPortGui  = 8081;
    // constexpr UINT16 tcpPortCtrl = 8082;
    // constexpr UINT16 tcpTimeout  = 10;

    enum E_TcpVals: UINT16
    {
        tcpPortFld  = 8080,
        tcpPortGui  = 8081,
        tcpPortCtrl = 8082,
        tcpTimeout  = 10
    };

    enum E_TestVals: UINT8
    {
        NO_PARAM = PARAM_UNDEF - 1,
        PARAM_UNKNOWN = PARAM_UNDEF - 2,

    };
} // namespace
