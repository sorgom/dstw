#include <baselib/BaseLib.h>

#include <cstring>
using std::memcpy;

void swapBytes(const PTR pA, const PTR pB, const PTR pS, const UINT32 size)
{
    memcpy(pS, pB, size);
    memcpy(pB, pA, size);
    memcpy(pA, pS, size);
}