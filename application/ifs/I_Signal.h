#pragma once
#ifndef I_SIGNAL_H
#define I_SIGNAL_H

#include "E_Result.h"
#include "I_SignalPort.h"

//! interface Signal Element
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