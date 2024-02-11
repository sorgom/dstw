#include <BAS/SwapBytes.h>

#include <cstring>

void SwapBytes::swapBytes(BYTE* const pA, BYTE* const pB, BYTE* const pS, const size_t size)
{
    std::memcpy(pS, pB, size);
    std::memcpy(pB, pA, size);
    std::memcpy(pA, pS, size);
}