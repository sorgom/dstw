//  ============================================================
//  misc utilities
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef UTILZ_H
#define UTILZ_H

#include <codebase/BaseTypes.h>

template <size_t N>
using data_tn = UINT8[N];

//  get byte subset of an object
template <class T, size_t N, size_t P=0>
inline const data_tn<N>& getn(const T& obj)
{
    static_assert(P + N <= sizeof(T));
    return *(reinterpret_cast<const data_tn<N>*>(&obj) + P);
}

//  get byte subset of ComData
template <size_t N, size_t P=0>
inline const data_tn<N>& getn(const ComData& obj)
{
    return getn<ComData, N, P>(obj);
}

#endif // _H
