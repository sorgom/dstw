//  ============================================================
//  interface LCR_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_LCR_HUB_H
#define I_LCR_HUB_H

#include "DataTypes.h"

class I_LCR_Hub
{
public:
    virtual void toFld(size_t id, INT32 state) const = 0;
    virtual void toGui(size_t id, INT32 state, INT32 ubk) const = 0;

    virtual void fromDsp(size_t pos, const FldState& tele) const = 0;
    virtual void fromDsp(size_t pos, const GuiCmd&   tele) const = 0;
};

#endif // H_