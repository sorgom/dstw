//  ============================================================
//  class TrackSwitchPort implements I_TrackSwitchPort
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TRACKSWITCHPORT_H
#define TRACKSWITCHPORT_H

#include <baselib/InstanceMacros.h>
#include <baselib/StackArray.h>
#include <ifs/DataTypes.h>
#include <ifs/I_TrackSwitchPort.h>
#include <setup/capacities.h>
#include <TrackSwitch/TrackSwitch.h>

class TrackSwitchPort : public I_TrackSwitchPort
{
public:
    inline TrackSwitchPort()
    {}

//  TODO:
    inline void toFld(UINT32 id, INT32 cmd) const {}
    inline void toGui(UINT32 id, INT32 cmd) const {}

    inline void fromFld(const FldState& tele, UINT32 pos) {}
    inline void fromGui(const GuiCmd&   tele, UINT32 pos) {}

    bool load(UINT32 num, const TrackSwitchProj* data);

    DDI_INSTANCE_DEC(TrackSwitchPort)
};

#endif // _H
