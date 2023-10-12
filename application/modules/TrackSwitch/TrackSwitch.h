#pragma once
#ifndef TRACKSWITCH_H
#define TRACKSWITCH_H

#include <ifs/I_TrackSwitch.h>
#include <ddi/ddiMacros.h>

class TrackSwitch : public I_TrackSwitch
{
public:
    inline TrackSwitch(UINT32 id = 0):
        mId(id),
        mState(TSW_TO_GUI_UNDEF)
    {}

    E_Result WU();
    
    void fromFld(E_TswTromFld rcv);

private:
    const UINT32 mId;
    E_TswToGui mState;
    DDI_MEMB_C(mPort, TrackSwitchPort)

    void chgState(E_TswToGui state);
    void toFld(E_TswToFld state) const;

    // Standard 8.1.1
    TrackSwitch(const TrackSwitch& o);
    TrackSwitch& operator=(const TrackSwitch& o);
};


#endif // _H
