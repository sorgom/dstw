#pragma once
#ifndef DATATYPES_H
#define DATATYPES_H

#include <baselib/BaseTypes.h>
//  TODO: static_assert sizes
// #include <cstddef>

#include <baselib/packBegin.h>

struct RastaTelegram
{
    INT32 type;
    UINT32 id;
    INT32 state1;
    INT32 state2;
    INT32 state3;
    UINT16 md4;
};

#include <baselib/packEnd.h>

#endif // H_