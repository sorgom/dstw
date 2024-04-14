//  ============================================================
//  mock for interface I_SIG_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_SIG_HUB_H
#define M_SIG_HUB_H

#include <ifs/I_Hub.h>
#include "M_Base.h"

namespace test
{
    MOCK_CLASS(SIG_Hub)
    {
    public:
        MOCK_CON(SIG_Hub)

        inline void toFld(size_t id, UINT8 param1, UINT8 param2 = PARAM_UNDEF) const
        {
            call("toFld").PARAM(id).PARAM(param1).PARAM(param2);
        }
        inline void expectToFld(size_t id, UINT8 param1, UINT8 param2 = PARAM_UNDEF) const
        {
            expect("toFld").PARAM(id).PARAM(param1).PARAM(param2);
        }

        inline void toGui(size_t id, UINT8 param1, UINT8 param2 = PARAM_UNDEF) const
        {
            call("toGui").PARAM(id).PARAM(param1).PARAM(param2);
        }
        inline void expectToGui(size_t id, UINT8 param1, UINT8 param2 = PARAM_UNDEF) const
        {
            expect("toGui").PARAM(id).PARAM(param1).PARAM(param2);
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