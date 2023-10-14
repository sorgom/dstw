//  ============================================================
//  mock for interface I_SignalPort
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_SIGNALPORT_H
#define M_SIGNALPORT_H

#include <ifs/I_SignalPort.h>
#include "M_Base.h"

namespace test
{
    MOCK_CLASS(SignalPort)
    {
    public:
        MOCK_CON(SignalPort)

        // interface methods

        inline void toFld(E_SigToFld cmd) const
        {
            call("toFld").PARAM(cmd);
        }

        inline void toGui(E_SigToGui cmd) const
        {
            call("toGui").PARAM(cmd);
        }

        //  expected calls

        inline void expectToFld(E_SigToFld cmd) const
        {
            expect("toFld").PARAM(cmd);
        }

        inline void expectToGui(E_SigToGui cmd) const
        {
            expect("toGui").PARAM(cmd);
        }
    };
}

#endif // _H