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

        inline void toFld(size_t id, INT32 state, INT32 speed) const
        {
            call("toFld").PARAM(id).PARAM(state).PARAM(speed);
        }
        inline void expectToFld(size_t id, INT32 state, INT32 speed = 0) const
        {
            expect("toFld").PARAM(id).PARAM(state).PARAM(speed);
        }

        inline void toGui(size_t id, INT32 state, INT32 speed) const
        {
            call("toGui").PARAM(id).PARAM(state).PARAM(speed);
        }
        inline void expectToGui(size_t id, INT32 state, INT32 speed = 0) const
        {
            expect("toGui").PARAM(id).PARAM(state).PARAM(speed);
        }

        inline void fromDsp(size_t pos, const FldState& tele) const
        {
            call("fromDsp").PARAM(pos).TPARAM(FldState, tele);
        }
        inline void expectFromDsp(size_t pos, const FldState& tele) const
        {
            expect("fromDsp").PARAM(pos).TPARAM(FldState, tele);
        }

        inline void fromDsp(size_t pos, const GuiCmd& tele) const
        {
            call("fromDsp").PARAM(pos).TPARAM(GuiCmd, tele);
        }
        inline void expectFromDsp(size_t pos, const GuiCmd& tele) const
        {
            expect("fromDsp").PARAM(pos).TPARAM(GuiCmd, tele);
        }
    };
}

#endif // _H