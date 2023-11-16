//  ============================================================
//  interface LCR (level crossing)
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_LCR_H
#define I_LCR_H

#include <BAS/BaseTypes.h>

enum E_LcrType
{
    LCR_TYPE_LCR = 100,
    LCR_TYPE_LCR_UBK
};

enum E_LcrState
{
    LCR_STATE_UNDEF = 101,
    LCR_STATE_DEFECT,
    LCR_STATE_OPEN,
    LCR_STATE_CLOSED,
    LCR_STATE_WAIT_OPEN,
    LCR_STATE_WAIT_CLOSED
};

enum E_LcrUbkState
{
    LCR_UBK_STATE_UNDEF = 201,
    LCR_UBK_STATE_DEFECT,
    LCR_UBK_STATE_OCCUPIED,
    LCR_UBK_STATE_FREE
};

class I_LCR
{
public:
//  commands from GUI
    virtual void fromGui(INT32 state) = 0;

//  infos from field element
    virtual void fromFld(INT32 state, INT32 ubk) = 0;

//  type info
    virtual INT32 type() const = 0;    
};


#endif // H_