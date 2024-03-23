//  ============================================================
//  host and network byte order
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef HN_H
#define HN_H

#include <BAS/coding.h>

class HN
{
public:
    static UINT32 toN(const UINT32 val);
    static UINT32 toH(const UINT32 val);
    static UINT16 toN(const UINT16 val);
    static UINT16 toH(const UINT16 val);

    NODEF(HN)
    NOCOPY(HN)
};


#endif // H_