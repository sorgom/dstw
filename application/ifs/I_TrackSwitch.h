//  ============================================================
//  interface TrackSwitch
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_TRACKSWITCH_H
#define I_TRACKSWITCH_H

#include "E_Result.h"
#include "I_TrackSwitchPort.h"

class I_TrackSwitch
{
public:
//  commands from GUI

    virtual E_Result WU() = 0;

//  infos from field element

    virtual void fromFld(INT32 rcv) = 0;
};

#endif // _H