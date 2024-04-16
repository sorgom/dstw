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

#include <ifs/CompEnums.h>
#include <ifs/I_Elem.h>
#include <BAS/coding.h>

class TSW : public I_Elem
{
public:
    inline TSW(size_t id):
        mId(id),
        mState(TSW_STATE_UNDEF)
    {}

    void process(const ComTeleGui& tele);
    void process(const ComTeleFld& tele);

private:
    const size_t mId;
    UINT8 mState;

    void wu();
    void swLeft();
    void swRight();
    void chgState(UINT8 state);
    void toFld(UINT8 state) const;

    NOCOPY(TSW)
    NODEF(TSW)
};


#endif // _H
