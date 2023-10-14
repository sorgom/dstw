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
    void toFld(UINT32 id, E_TswToFld cmd) const;

//  TODO:
    inline void toGui(UINT32 id, E_TswToGui cmd) const {}

    DDI_INSTANCE_DEC(TrackSwitchPort)
private:
    static RastaTelegram mTele;
};

#endif // _H
