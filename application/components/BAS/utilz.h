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

//  get subset of ComData params
template <size_t N>
const data_tn<N>& getn(const ComData& data)
{
    static_assert(N <= ComDataSize);
    return *reinterpret_cast<const data_tn<N>*>(&data);
}

#endif // _H
