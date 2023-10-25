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

        inline void toFld(UINT32 id, INT32 state, INT32 speed) const
        {
            call("toFld").PARAM(id).PARAM(state).PARAM(speed);
        }
        inline void expectToFld(UINT32 id, INT32 state, INT32 speed = 0) const
        {
            expect("toFld").PARAM(id).PARAM(state).PARAM(speed);
        }

        inline void toGui(UINT32 id, INT32 state, INT32 speed) const
        {
            call("toGui").PARAM(id).PARAM(state).PARAM(speed);
        }
        inline void expectToGui(UINT32 id, INT32 state, INT32 speed = 0) const
        {
            expect("toGui").PARAM(id).PARAM(state).PARAM(speed);
        }

        inline void fromFld(const FldState& tele, UINT32 pos)
        {
            call("fromFld").TPARAM(FldState, tele).PARAM(pos);
        }
        inline void expectFromFld(const FldState& tele, UINT32 pos) const
        {
            expect("fromFld").TPARAM(FldState, tele).PARAM(pos);
        }
        inline void expectFromFld(UINT32 pos) const
        {
            expect("fromFld").IGNORE().PARAM(pos);
        }

        inline void fromGui(const GuiCmd& tele, UINT32 pos)
        {
            call("fromGui").TPARAM(GuiCmd, tele).PARAM(pos);
        }
        inline void expectFromGui(const GuiCmd& tele, UINT32 pos) const
        {
            expect("fromGui").TPARAM(GuiCmd, tele).PARAM(pos);
        }
        inline void expectFromGui(UINT32 pos) const
        {
            expect("fromGui").IGNORE().PARAM(pos);
        }

    };
}

#endif // _H