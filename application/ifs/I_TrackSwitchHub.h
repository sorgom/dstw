//  ============================================================
//  interface TrackSwitchHub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_TRACKSWITCHHUB_H
#define I_TRACKSWITCHHUB_H

#include <baselib/BaseTypes.h>
#include "DataTypes.h"

class I_TrackSwitchHub
{
public:
    virtual void toFld(UINT32 id, INT32 cmd) const = 0;
    virtual void toGui(UINT32 id, INT32 cmd) const = 0;

    virtual void fromFld(const FldState& tele, UINT32 pos) = 0;
    virtual void fromGui(const GuiCmd&   tele, UINT32 pos) = 0;

    virtual bool load(UINT32 num, const ProjTSW* data) = 0;
};

#endif // _H