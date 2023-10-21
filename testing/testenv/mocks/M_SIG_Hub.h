//  ============================================================
//  mock for interface I_SIG_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_SIG_HUB_H
#define M_SIG_HUB_H

#include <ifs/I_SIG_Hub.h>
#include "M_Base.h"

namespace test
{
    MOCK_CLASS(SIG_Hub)
    {
    public:
        MOCK_CON(SIG_Hub)

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
} // namespace

#endif // _H