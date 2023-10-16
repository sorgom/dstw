//  ============================================================
//  definiton of complex data types
//  - mainly communication telegrams
//  ============================================================
//  created by Manfred Sorgo 

#pragma once
#ifndef DATATYPES_H
#define DATATYPES_H

#include <baselib/BaseTypes.h>
#include <ifs/ProjData.h>


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

struct FldTelegram
{
    INT32 type;
    ElementName name;
    INT32 state1;
    INT32 state2;
    INT32 state3;
    UINT16 md4;
};

struct GuiTelegram
{
    INT32 type;
    ElementName name;
    INT32 state;
    UINT16 md4;
};

#include <baselib/packEnd.h>

#endif // H_