#pragma once
#ifndef SIGNAL_H
#define SIGNAL_H

#include <ifs/I_Signal.h>

class Signal : public I_Signal
{
public:
    inline Signal(
        I_SignalPort& port
    ):
        mPort(port),
        mState(SIG_TO_GUI_UNDEF)
    {}

    E_Result HN0();
    E_Result HN1();
    
    void fromFld(E_SigTromFld rcv);

private:
    I_SignalPort& mPort;
    E_SigToGui mState;

    void chgState(E_SigToGui state);

    // Standard 8.1.1
    Signal();
    Signal(const Signal& o);
    Signal& operator=(const Signal& o);
};


#endif // _H
