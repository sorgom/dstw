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

        inline void toFld(size_t id, UINT8 state) const
        {
            call("toFld").PARAM(id).PARAM(state);
        }
        inline void expectToFld(size_t id, UINT8 state) const
        {
            expect("toFld").PARAM(id).PARAM(state);
        }

        inline void toGui(size_t id, UINT8 state, UINT8 ubk = LCR_UBK_STATE_UNDEF) const
        {
            call("toGui").PARAM(id).PARAM(state).PARAM(ubk);
        }
        inline void expectToGui(size_t id, UINT8 state, UINT8 ubk = LCR_UBK_STATE_UNDEF) const
        {
            expect("toGui").PARAM(id).PARAM(state).PARAM(ubk);
        }

        inline void fromDsp(size_t pos, const ComTeleFld& tele) const
        {
            call("fromDsp").PARAM(pos).TPARAM(ComTeleFld, tele);
        }
        inline void expectFromDsp(size_t pos, const ComTeleFld& tele) const
        {
            expect("fromDsp").PARAM(pos).TPARAM(ComTeleFld, tele);
        }

        inline void fromDsp(size_t pos, const ComTeleGui& tele) const
        {
            call("fromDsp").PARAM(pos).TPARAM(ComTeleGui, tele);
        }
        inline void expectFromDsp(size_t pos, const ComTeleGui& tele) const
        {
            expect("fromDsp").PARAM(pos).TPARAM(ComTeleGui, tele);
        }
    };
}

#endif // _H