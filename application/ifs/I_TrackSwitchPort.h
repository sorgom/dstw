//  ============================================================
//  interface TrackSwitchPort
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_TRACKSWITCHPORT_H
#define I_TRACKSWITCHPORT_H

#include <baselib/BaseTypes.h>
#include "E_Result.h"
#include "DataTypes.h"

enum E_TswTromFld
{
    TSW_FROM_FLD_LEFT = 101,
    TSW_FROM_FLD_RIGHT,
    TSW_FROM_FLD_UNDEF,
    TSW_FROM_FLD_DEFECT
};

enum E_TswToFld
{
    TSW_TO_FLD_LEFT = 201,
    TSW_TO_FLD_RIGHT
};

enum E_TswToGui
{
    TSW_TO_GUI_LEFT = 301,
    TSW_TO_GUI_RIGHT,
    TSW_TO_GUI_WAIT_LEFT,
    TSW_TO_GUI_WAIT_RIGHT,
    TSW_TO_GUI_UNDEF,
    TSW_TO_GUI_DEFECT
};

class I_TrackSwitchPort
{
public:
    virtual void toFld(UINT32 id, INT32 cmd) const = 0;
    virtual void toGui(UINT32 id, INT32 cmd) const = 0;

    virtual void fromFld(const FldTelegram& tele) const = 0;
    virtual void fromGui(const GuiTelegram& tele) const = 0;

    virtual bool load(UINT32 num, const TrackSwitchProj* data) = 0;
};

#endif // _H