#pragma once
#ifndef TRACKSWITCH_H
#define TRACKSWITCH_H

#include <ifs/I_TrackSwitch.h>

class TrackSwitch : public I_TrackSwitch
{
public:
    inline TrackSwitch(
        I_TrackSwitchToField& rTrackSwitchToField,
        I_TrackSwitchToGui& rTrackSwitchToGui    
    ):
        mTrackSwitchToField(rTrackSwitchToField),
        mTrackSwitchToGui(rTrackSwitchToGui),
        mState(TSW_TO_GUI_UNDEF)
    {}

    E_Result WU();
    
    void rcv(E_RcvTswTromFld rcv);

private:
    I_TrackSwitchToField& mTrackSwitchToField;
    I_TrackSwitchToGui&   mTrackSwitchToGui;
    E_CmdTswToGui mState;

    void chngState(E_CmdTswToGui state);

    // Standard 8.1.1
    TrackSwitch();
    TrackSwitch(const TrackSwitch& o);
    TrackSwitch& operator=(const TrackSwitch& o);
};


#endif // _H
