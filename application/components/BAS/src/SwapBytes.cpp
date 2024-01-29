#include <BAS/SwapBytes.h>

#include <cstring>

void SwapBytes::swapBytes(const PTR pA, const PTR pB, const PTR pS, const size_t size)
{
    std::memcpy(pS, pB, size);
    std::memcpy(pB, pA, size);
    std::memcpy(pA, pS, size);
}