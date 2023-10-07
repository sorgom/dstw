#pragma once
#ifndef I_TRACKSWITCH_H
#define I_TRACKSWITCH_H

#include "E_Result.h"

enum E_RcvTswTromFld
{
    TSW_FROM_FLD_LEFT,
    TSW_FROM_FLD_RIGHT,
    TSW_FROM_FLD_UNDEF,
    TSW_FROM_FLD_DEFECT,
};

//! interface TrackSwitch Element
class I_TrackSwitch
{
public:
//  commands from GUI

    virtual E_Result WU() = 0;

//  infos from field element

    virtual void rcv(E_RcvTswTromFld rcv) = 0;
};

enum E_CmdTswToFld
{
    TSW_TO_FLD_LEFT,
    TSW_TO_FLD_RIGHT,
};

class I_TrackSwitchToField
{
public:
    virtual void cmd(E_CmdTswToFld cmd) = 0;
};

enum E_CmdTswToGui
{
    TSW_TO_GUI_LEFT,
    TSW_TO_GUI_RIGHT,
    TSW_TO_GUI_WAIT_LEFT,
    TSW_TO_GUI_WAIT_RIGHT,
    TSW_TO_GUI_UNDEF,
    TSW_TO_GUI_DEFECT,
};

class I_TrackSwitchToGui
{
public:
    virtual void cmd(E_CmdTswToGui cmd) = 0;
};

#endif // _H