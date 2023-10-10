#pragma once
#ifndef TRACKSWITCH_H
#define TRACKSWITCH_H

#include <ifs/I_TrackSwitch.h>
#include <ddi/ddiMacros.h>

class TrackSwitch : public I_TrackSwitch
{
public:
    inline TrackSwitch():
        mState(TSW_TO_GUI_UNDEF)
    {}

    E_Result WU();
    
    void fromFld(E_TswTromFld rcv);

private:
    E_TswToGui mState;

    void chgState(E_TswToGui state);
    DDI_MEMB_C(mPort, TrackSwitchPort)

    // Standard 8.1.1
    TrackSwitch(const TrackSwitch& o);
    TrackSwitch& operator=(const TrackSwitch& o);
};


#endif // _H
