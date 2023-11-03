#include <BAS/StackArray.h>

#include <cstring>

void SwapBytes::swapBytes(const PTR pA, const PTR pB, const PTR pS, const UINT32 size)
{
    std::memcpy(pS, pB, size);
    std::memcpy(pB, pA, size);
    std::memcpy(pA, pS, size);
}