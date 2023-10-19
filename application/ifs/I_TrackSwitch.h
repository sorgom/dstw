//  ============================================================
//  interface TrackSwitch
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_TRACKSWITCH_H
#define I_TRACKSWITCH_H

#include <baselib/BaseTypes.h>

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

class I_TrackSwitch
{
public:
//  commands from GUI

    virtual void WU() = 0;

//  infos from field element

    virtual void fromFld(INT32 state) = 0;
};

#endif // _H