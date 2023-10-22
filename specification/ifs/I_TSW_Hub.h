//  ============================================================
//  interface TSW_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_TSW_HUB_H
#define I_TSW_HUB_H

#include <baselib/BaseTypes.h>
#include "DataTypes.h"

class I_TSW_Hub
{
public:
    virtual void toFld(UINT32 id, INT32 cmd) const = 0;
    virtual void toGui(UINT32 id, INT32 state) const = 0;

    virtual void fromFld(const FldState& tele, UINT32 pos) = 0;
    virtual void fromGui(const GuiCmd&   tele, UINT32 pos) = 0;

    virtual bool load(const ProjTSW* data, UINT32 num) = 0;
};

#endif // _H