#pragma once
#ifndef I_TRACKSWITCHPORT_H
#define I_TRACKSWITCHPORT_H

#include "E_Result.h"

enum E_TswTromFld
{
    TSW_FROM_FLD_LEFT,
    TSW_FROM_FLD_RIGHT,
    TSW_FROM_FLD_UNDEF,
    TSW_FROM_FLD_DEFECT,
};

enum E_TswToFld
{
    TSW_TO_FLD_LEFT,
    TSW_TO_FLD_RIGHT,
};

enum E_TswToGui
{
    TSW_TO_GUI_LEFT,
    TSW_TO_GUI_RIGHT,
    TSW_TO_GUI_WAIT_LEFT,
    TSW_TO_GUI_WAIT_RIGHT,
    TSW_TO_GUI_UNDEF,
    TSW_TO_GUI_DEFECT,
};

class I_TrackSwitchPort
{
public:
    virtual void toFld(E_TswToFld cmd) const = 0;
    virtual void toGui(E_TswToGui cmd) const = 0;
};

#endif // _H