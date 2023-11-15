//  ============================================================
//  mock for interface I_LCR_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_LCR_HUB_H
#define M_LCR_HUB_H

#include <ifs/I_LCR_Hub.h>
#include "M_Base.h"

namespace test
{
    MOCK_CLASS(LCR_Hub)
    {
    public:
        MOCK_CON(LCR_Hub)

        inline void toFld(UINT32 id, INT32 state) const
        {
            call("toFld").PARAM(id).PARAM(state);
        }
        inline void expectToFld(UINT32 id, INT32 state) const
        {
            expect("toFld").PARAM(id).PARAM(state);
        }

        inline void toGui(UINT32 id, INT32 state, INT32 ubk) const
        {
            call("toGui").PARAM(id).PARAM(state).PARAM(ubk);
        }
        inline void expectToGui(UINT32 id, INT32 state, INT32 ubk = 0) const
        {
            expect("toGui").PARAM(id).PARAM(state).PARAM(ubk);
        }

        inline void fromDsp(UINT32 pos, const FldState& tele) const
        {
            call("fromDsp").PARAM(pos).TPARAM(FldState, tele);
        }
        inline void expectFromDsp(UINT32 pos, const FldState& tele) const
        {
            expect("fromDsp").PARAM(pos).TPARAM(FldState, tele);
        }

        inline void fromDsp(UINT32 pos, const GuiCmd& tele) const
        {
            call("fromDsp").PARAM(pos).TPARAM(GuiCmd, tele);
        }
        inline void expectFromDsp(UINT32 pos, const GuiCmd& tele) const
        {
            expect("fromDsp").PARAM(pos).TPARAM(GuiCmd, tele);
        }
    };
}

#endif // _H