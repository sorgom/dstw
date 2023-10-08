#pragma once
#ifndef TRACKSWITCH_H
#define TRACKSWITCH_H

#include <ifs/I_TrackSwitch.h>

class TrackSwitch : public I_TrackSwitch
{
public:
    inline TrackSwitch(
        I_TrackSwitchPort& port
    ):
        mPort(port),
        mState(TSW_TO_GUI_UNDEF)
    {}

    E_Result WU();
    
    void fromFld(E_TswTromFld rcv);

private:
    I_TrackSwitchPort& mPort;
    E_TswToGui mState;

    void chgState(E_TswToGui state);

    // Standard 8.1.1
    TrackSwitch();
    TrackSwitch(const TrackSwitch& o);
    TrackSwitch& operator=(const TrackSwitch& o);
};


#endif // _H
