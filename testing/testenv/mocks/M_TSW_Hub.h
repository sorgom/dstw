//  ============================================================
//  mock for interface I_TSW_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_TSW_HUB_H
#define M_TSW_HUB_H

#include <ifs/I_TSW_Hub.h>
#include "M_Base.h"

namespace test
{
    MOCK_CLASS(TSW_Hub)
    {
    public:
        MOCK_CON(TSW_Hub)

        inline void toFld(UINT32 id, INT32 cmd) const
        {
            call("toFld").PARAM(id).PARAM(cmd);
        }
        inline void expectToFld(UINT32 id, INT32 cmd) const
        {
            expect("toFld").PARAM(id).PARAM(cmd);
        }

        inline void toGui(UINT32 id, INT32 state) const
        {
            call("toGui").PARAM(id).PARAM(state);
        }
        inline void expectToGui(UINT32 id, INT32 state) const
        {
            expect("toGui").PARAM(id).PARAM(state);
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