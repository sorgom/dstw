//  ============================================================
//  interface TSW
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_TSW_H
#define I_TSW_H

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

enum E_TswGuiCmd
{
    TSW_GUI_GMD_WU,
    TSW_GUI_GMD_LEFT,
    TSW_GUI_GMD_RIGHT
};

class I_TSW
{
public:
//  commands from GUI

    virtual void fromGui(INT32 cmd) = 0;

//  infos from field element

    virtual void fromFld(INT32 state) = 0;
};

#endif // _H