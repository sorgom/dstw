//  ============================================================
//  misc coding enhancers
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef CODING_H
#define CODING_H

//  enable usage of "and", "or" 
#include <ciso646>

//  put into empty if / else branches for coverage
inline void pass() {}

//  declare copy contructor and copy operator private
#define NOCOPY(CLASS) \
private: \
CLASS(const CLASS& o); \
CLASS& operator = (const CLASS& o);


#endif // H_