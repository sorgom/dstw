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
    static void swapBytes(PTR pA, PTR pB, PTR pS, size_t size);
    NOCOPY(SwapBytes)
};

#endif // H_