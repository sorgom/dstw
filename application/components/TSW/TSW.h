//  ============================================================
//  class TSW implements I_TSW
//  state of implementation:
//  - WU command from GUI
//  - all states from field, forwarding to GUI
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TSW_H
#define TSW_H

#include <ifs/I_TSW.h>
#include <BAS/coding.h>

class TSW : public I_TSW
{
public:
    inline TSW(UINT32 id):
        mId(id),
        mState(TSW_STATE_UNDEF)
    {}

    void fromGui(INT32 cmd);
    void fromFld(INT32 state);

private:
    const UINT32 mId;
    INT32 mState;

    void wu();
    void swLeft();
    void swRight();
    void chgState(INT32 state);
    void toFld(INT32 state) const;

    NOCOPY(TSW)
    TSW();
};


#endif // _H
