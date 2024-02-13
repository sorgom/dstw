//  ============================================================
//  capacities of element containers
//  - track switches
//  - signals
//  - level crossings
//  - segments
//
//  pre-defined here
//  definable at compile time
//  e.g.: -DCAPACITY_SIG=500 
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef CAPACITIES_H
#define CAPACITIES_H

#include <codebase/BaseTypes.h>

#ifndef CAPACITY_TSW
#define CAPACITY_TSW 100
#endif 

#ifndef CAPACITY_SIG
#define CAPACITY_SIG 100
#endif 

#ifndef CAPACITY_LCR
#define CAPACITY_LCR 100
#endif 

#ifndef CAPACITY_SEG
#define CAPACITY_SEG 100
#endif 

constexpr size_t CAPACITY_DSP = CAPACITY_TSW + CAPACITY_SIG + CAPACITY_LCR + CAPACITY_SEG;

#endif // H_