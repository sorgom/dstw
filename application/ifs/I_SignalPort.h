//  ============================================================
//  interface SignalPort
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_SIGNALPORT_H
#define I_SIGNALPORT_H

#include "E_Result.h"

enum E_SigTromFld
{
    SIG_FROM_FLD_HN0,
    SIG_FROM_FLD_HN1,
    SIG_FROM_FLD_UNDEF,
    SIG_FROM_FLD_DEFECT
};

enum E_SigToFld
{
    SIG_TO_FLD_HN0,
    SIG_TO_FLD_HN1
};

enum E_SigToGui
{
    SIG_TO_GUI_HN0,
    SIG_TO_GUI_HN1,
    SIG_TO_GUI_WAIT_HN0,
    SIG_TO_GUI_WAIT_HN1,
    SIG_TO_GUI_UNDEF,
    SIG_TO_GUI_DEFECT
};

class I_SignalPort
{
public:
    virtual void toFld(E_SigToFld cmd) const = 0;
    virtual void toGui(E_SigToGui cmd) const = 0;
};

#endif // _H