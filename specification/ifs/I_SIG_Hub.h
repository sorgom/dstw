//  ============================================================
//  interface SIG_Hub
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef I_SIG_HUB_H
#define I_SIG_HUB_H

#include "DataTypes.h"

class I_SIG_Hub
{
public:
    virtual void toFld(UINT32 id, INT32 state, INT32 speed) const = 0;
    virtual void toGui(UINT32 id, INT32 state, INT32 speed) const = 0;

    virtual void fromFld(const FldState& tele, UINT32 pos) = 0;
    virtual void fromGui(const GuiCmd&   tele, UINT32 pos) = 0;
};

#endif // H_