
#pragma once
#ifndef M_SIGNALPORT_H
#define M_SIGNALPORT_H

#include <ifs/I_SignalPort.h>
#include <testenv/M_Base.h>

namespace test
{
    class M_SignalPort :
        public I_SignalPort,
        private M_Base
    {
    public:
        inline M_SignalPort():
            M_Base("SignalPort")
        {}

        // interface methods

        inline void toFld(E_SigToFld cmd) const
        {
            call("toFld").withParameter("cmd", cmd);
        }

        inline void toGui(E_SigToGui cmd) const
        {
            call("toGui").withParameter("cmd", cmd);
        }

        //  expected calls

        inline void expectToFld(E_SigToFld cmd) const
        {
            expect("toFld").withParameter("cmd", cmd);
        }

        inline void expectToGui(E_SigToGui cmd) const
        {
            expect("toGui").withParameter("cmd", cmd);
        }
    };
}

#endif // _H