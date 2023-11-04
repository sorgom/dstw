//  ============================================================
//  capacities of element containers
//  - signals
//  - track switches
//  - segments
//  - level crossings
//
//  pre-defined here
//  definable at compile time
//  e.g.: -DCAPACITY_SIG=500 
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef CAPACITIES_H
#define CAPACITIES_H

#ifndef CAPACITY_TSW
#define CAPACITY_TSW 100
#endif 

#ifndef CAPACITY_SIG
#define CAPACITY_SIG 100
#endif 

#ifndef CAPACITY_SEG
#define CAPACITY_SEG 100
#endif 

#ifndef CAPACITY_LCR
#define CAPACITY_LCR 100
#endif 

#define CAPACITY_DSP (CAPACITY_TSW + CAPACITY_SIG + CAPACITY_SEG + CAPACITY_LCR)

#endif // H_