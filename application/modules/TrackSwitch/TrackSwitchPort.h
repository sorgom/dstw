//  ============================================================
//  class TrackSwitchPort implements I_TrackSwitchPort
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TRACKSWITCHPORT_H
#define TRACKSWITCHPORT_H

#include <ifs/I_TrackSwitchPort.h>
#include <ifs/DataTypes.h>
#include <baselib/InstanceMacros.h>

class TrackSwitchPort : public I_TrackSwitchPort
{
public:
//  TODO:
    inline void toFld(UINT32 id, INT32 cmd) const {}
    inline void toGui(UINT32 id, INT32 cmd) const {}

    inline void fromFld(const FldTelegram& tele) const {}
    inline void fromGui(const GuiTelegram& tele) const {}

    DDI_INSTANCE_DEC(TrackSwitchPort)
private:
};

#endif // _H
