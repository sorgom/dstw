//  ============================================================
//  class TrackSwitchHub implements I_TrackSwitchHub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TRACKSWITCHHUB_H
#define TRACKSWITCHHUB_H

#include <baselib/InstanceMacros.h>
#include <baselib/StackArray.h>
#include <ifs/DataTypes.h>
#include <ifs/I_TrackSwitchHub.h>
#include <setup/capacities.h>
#include <TrackSwitch/TrackSwitch.h>

class TrackSwitchHub : public I_TrackSwitchHub
{
public:
    inline TrackSwitchHub()
    {}

//  TODO:
    inline void toFld(UINT32 id, INT32 cmd) const {}
    inline void toGui(UINT32 id, INT32 cmd) const {}

    inline void fromFld(const FldState& tele, UINT32 pos) {}
    inline void fromGui(const GuiCmd&   tele, UINT32 pos) {}

    bool load(UINT32 num, const TrackSwitchProj* data);

    DDI_INSTANCE_DEC(TrackSwitchHub)
};

#endif // _H
