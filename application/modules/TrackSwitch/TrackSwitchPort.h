#pragma once
#ifndef TRACKSWITCHPORT_H
#define TRACKSWITCHPORT_H

#include <ifs/I_TrackSwitchPort.h>
#include <baselib/InstanceMacros.h>

class TrackSwitchPort : public I_TrackSwitchPort
{
public:
    inline void toFld(E_TswToFld cmd) const {}
    inline void toGui(E_TswToGui cmd) const {}

    INSTANCE_DEC(TrackSwitchPort)
};

#endif // _H
