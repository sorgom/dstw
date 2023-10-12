#include <TrackSwitch/TrackSwitchPort.h>
#include <baselib/InstanceMacros.h>
#include <baselib/Mem.h>
#include <ddi/ddi.h>

RastaTelegram TrackSwitchPort::mTele = {0};

INSTANCE_DEF(TrackSwitchPort)

void TrackSwitchPort::toFld(const UINT32 id, const E_TswToFld cmd) const
{
    Mem::zero(mTele);
    mTele.type = RASTA_TSW;
    mTele.id = id;
    mTele.state1 = cmd;
    ddi::getRastaPort().send(mTele);
}