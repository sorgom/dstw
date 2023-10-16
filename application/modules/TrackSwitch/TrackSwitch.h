#pragma once
#ifndef TRACKSWITCH_H
#define TRACKSWITCH_H

//  ============================================================
//  class TrackSwitch implements I_TrackSwitch
//  ============================================================
//  created by Manfred Sorgo

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
    void fromFld(INT32 rcv);

private:
    const UINT32 mId;
    INT32 mState;

    void chgState(INT32 state);
    void toFld(INT32 state) const;

    //  Standard 8.1.1
    TrackSwitch(const TrackSwitch& o);
    TrackSwitch& operator=(const TrackSwitch& o);
};


#endif // _H
