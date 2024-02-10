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

        inline void toFld(size_t id, UINT8 state, UINT8 speed = 0) const
        {
            call("toFld").PARAM(id).PARAM(state).PARAM(speed);
        }
        inline void expectToFld(size_t id, UINT8 state, UINT8 speed = 0) const
        {
            expect("toFld").PARAM(id).PARAM(state).PARAM(speed);
        }

        inline void toGui(size_t id, UINT8 state, UINT8 speed = 0) const
        {
            call("toGui").PARAM(id).PARAM(state).PARAM(speed);
        }
        inline void expectToGui(size_t id, UINT8 state, UINT8 speed = 0) const
        {
            expect("toGui").PARAM(id).PARAM(state).PARAM(speed);
        }

        inline void fromDsp(size_t pos, const ComFldState& tele) const
        {
            call("fromDsp").PARAM(pos).TPARAM(ComFldState, tele);
        }
        inline void expectFromDsp(size_t pos, const ComFldState& tele) const
        {
            expect("fromDsp").PARAM(pos).TPARAM(ComFldState, tele);
        }

        inline void fromDsp(size_t pos, const ComGuiCmd& tele) const
        {
            call("fromDsp").PARAM(pos).TPARAM(ComGuiCmd, tele);
        }
        inline void expectFromDsp(size_t pos, const ComGuiCmd& tele) const
        {
            expect("fromDsp").PARAM(pos).TPARAM(ComGuiCmd, tele);
        }
    };
}

#endif // _H