//  ============================================================
//  mock for interface I_CuiCom
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_GUICOM_H
#define M_GUICOM_H

#include <ifs/I_GuiCom.h>
#include "M_Base.h"

namespace test
{
    MOCK_CLASS(GuiCom)
    {
    public:
        MOCK_CON(GuiCom)

        inline void send(const StateGui& tele) const
        {
            call("send").TPARAM(StateGui, tele);
        }
        inline void expectSend(const StateGui& tele) const
        {
            expect("send").TPARAM(StateGui, tele);
        }
    };
} // namespace

#endif // H_