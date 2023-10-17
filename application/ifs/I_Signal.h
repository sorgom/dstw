//  ============================================================
//  interface Signal
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_SIGNAL_H
#define I_SIGNAL_H

#include "SystemEnums.h"
#include "I_SignalPort.h"

class I_Signal
{
public:
//  commands from GUI

    virtual E_Result HN0() = 0;
    virtual E_Result HN1() = 0;

//  infos from field element

    virtual void fromFld(E_SigTromFld rcv) = 0;
};

#endif // _H