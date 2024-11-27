//  ============================================================
//  apply size safe memset, memcpy, memcmp
//  ============================================================
//  created by Manfred Sorgo

#ifndef MEM_H
#define MEM_H

#include <codebase/BaseTypes.h>
#include <cstring>

class Mem
{
public:
    //  memcpy char array
    template <size_t N>
    inline static void cpy(CHAR(& trg)[N], const CHAR(& src)[N])
    {
        std::memcpy(trg, src, N);
    }

    //  mem compare two char arrays
    template <size_t N>
    inline static auto cmp(const CHAR(& c1)[N], const CHAR(& c2)[N])
    {
        return std::memcmp(c1, c2, N);
    }
};
#endif // _H
