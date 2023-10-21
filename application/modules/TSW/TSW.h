#pragma once
#ifndef TSW_H
#define TSW_H

//  ============================================================
//  class TSW implements I_TSW
//  ============================================================
//  created by Manfred Sorgo

#include <ifs/I_TSW.h>

class TSW : public I_TSW
{
public:
    inline TSW(UINT32 id = 0):
        mId(id),
        mState(TSW_TO_GUI_UNDEF)
    {}

    void WU();
    void fromFld(INT32 state);

private:
    const UINT32 mId;
    INT32 mState;

    void chgState(INT32 state);
    void toFld(INT32 state) const;

    //  Standard 8.1.1
    TSW(const TSW& o);
    TSW& operator=(const TSW& o);
};


#endif // _H
