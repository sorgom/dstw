//  ============================================================
//  class SwapBytes enables static byte swapping
//  (no memory reallocation)
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef SWAPBYTES_H
#define SWAPBYTES_H

#include <BAS/coding.h>

class SwapBytes
{
protected:
    SwapBytes() = default;

    template <size_t N>
    inline static void swapBytes(BYTE(& pA)[N], BYTE(& pB)[N], BYTE(& pS)[N])
    {
        swapBytes(pA, pB, pS, N);
    }

    NOCOPY(SwapBytes)
private:    
    static void swapBytes(BYTE* pA, BYTE* pB, BYTE* pS, size_t size);
};

#endif // H_