//  ============================================================
//  defintion of position result
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef POSRES_H
#define POSRES_H

#include <BAS/coding.h>

struct PosRes
{
    const size_t pos;
    const bool valid;
    inline PosRes(size_t pos, bool valid):
        pos(pos),
        valid(valid)
    {}
    NODEF(PosRes)
};

#endif // H_