//  ============================================================
//  interface LCR (level crossing)
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_LCR_H
#define I_LCR_H

#include <codebase/BaseTypes.h>

enum E_LcrType : UINT8
{
    LCR_TYPE_LCR = 100,
    LCR_TYPE_LCR_UBK
};

enum E_LcrState : UINT8
{
    LCR_STATE_UNDEF = 101,
    LCR_STATE_DEFECT,
    LCR_STATE_OPEN,
    LCR_STATE_CLOSED,
    LCR_STATE_WAIT_OPEN,
    LCR_STATE_WAIT_CLOSED
};

enum E_LcrUbkState : UINT8
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
    virtual void fromGui(UINT8 state) = 0;

//  infos from field element
    virtual void fromFld(UINT8 state, UINT8 ubk) = 0;

//  type info
    virtual UINT8 type() const = 0;    
};


#endif // H_