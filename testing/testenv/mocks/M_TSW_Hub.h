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

        inline void toFld(size_t id, UINT8 cmd) const
        {
            call("toFld").PARAM(id).PARAM(cmd);
        }
        inline void expectToFld(size_t id, UINT8 cmd) const
        {
            expect("toFld").PARAM(id).PARAM(cmd);
        }

        inline void toGui(size_t id, UINT8 state) const
        {
            call("toGui").PARAM(id).PARAM(state);
        }
        inline void expectToGui(size_t id, UINT8 state) const
        {
            expect("toGui").PARAM(id).PARAM(state);
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