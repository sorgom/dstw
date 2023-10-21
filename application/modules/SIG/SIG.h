//  ============================================================
//  class SIG implements I_SIG
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef SIG_H
#define SIG_H

#include <ifs/I_SIG.h>

class SIG : public I_SIG
{
public:
    inline SIG(
        I_SIG_Hub& port
    ):
        mHub(port),
        mState(SIG_TO_GUI_UNDEF)
    {}

    E_Result HN0();
    E_Result HN1();
    
    void fromFld(E_SigTromFld rcv);

private:
    I_SIG_Hub& mHub;
    E_SigToGui mState;

    void chgState(E_SigToGui state);

    //  Standard 8.1.1
    SIG();
    SIG(const SIG& o);
    SIG& operator=(const SIG& o);
};


#endif // _H
