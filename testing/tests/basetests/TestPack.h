//  ============================================================
//  packed and unpacked version of same data
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TESTPACK_H
#define TESTPACK_H

#include <baselib/BaseTypes.h>

namespace test
{

    struct Unpacked
    {
        UINT8  m1;
        UINT32 m2;
    };

    #include <baselib/packBegin.h>

    struct Packed
    {
        UINT8  m1;
        UINT32 m2;
    };

    #include <baselib/packEnd.h>

} 
#endif // _H