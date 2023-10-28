//  ============================================================
//  interface TSW_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_TSW_HUB_H
#define I_TSW_HUB_H

#include "DataTypes.h"

class I_TSW_Hub
{
public:
    virtual void toFld(UINT32 id, INT32 cmd) const = 0;
    virtual void toGui(UINT32 id, INT32 state) const = 0;

    virtual void fromDsp(UINT32 pos, const FldState& tele) const = 0;
    virtual void fromDsp(UINT32 pos, const GuiCmd&   tele) const = 0;
};

#endif // _H