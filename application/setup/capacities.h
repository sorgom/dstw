//  ============================================================
//  capacities of element containers
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
#ifndef CAPACITIES_H
#define CAPACITIES_H

#include <codebase/BaseTypes.h>

#ifndef TEST_NUM_TSW
#define TEST_NUM_TSW 100
#endif 

#ifndef TEST_NUM_SIG
#define TEST_NUM_SIG 100
#endif 

#ifndef TEST_NUM_LCR
#define TEST_NUM_LCR 100
#endif 

#ifndef TEST_NUM_SEG
#define TEST_NUM_SEG 100
#endif 

constexpr size_t TEST_NUM_DSP = TEST_NUM_TSW + TEST_NUM_SIG + TEST_NUM_LCR + TEST_NUM_SEG;

#endif // H_