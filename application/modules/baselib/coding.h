//  ============================================================
//  misc coding enhancers
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef CODING_H
#define CODING_H

//  put into empty if / else branches for coverage
inline void pass() {}


#define NOCOPY(CLASS) \
private: \
CLASS(const CLASS& o); \
CLASS& operator = (const CLASS& o);

#endif // H_