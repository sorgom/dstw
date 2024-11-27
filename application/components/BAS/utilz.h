//  ============================================================
//  misc utilities
//  ============================================================
//  created by Manfred Sorgo
#ifndef UTILZ_H
#define UTILZ_H

#include <codebase/BaseTypes.h>

//  get byte subset of a const object
template <class T, size_t N, size_t P=0>
inline const ByteArray<N>& getn(const T& obj)
{
    static_assert(P + N <= sizeof(T));
    return *(reinterpret_cast<const ByteArray<N>*>(&obj) + P);
}

//  get byte subset of ComData
template <size_t N, size_t P=0>
inline const ByteArray<N>& getn(const ComData& obj)
{
    return getn<ComData, N, P>(obj);
}

#endif // _H
