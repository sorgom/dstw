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

        inline bool send(const StateGui& tele) const
        {
            return call("send").TPARAM(StateGui, tele).RETURN_DEF_BOOL(true);
        }
        inline void expectSend(const StateGui& tele, bool ret = true) const
        {
            expect("send").TPARAM(StateGui, tele).AND_RETURN_BOOL(ret);
        }

        // inline void expectSend(bool ret = true) const
        // {
        //     expect("send").IGNORE().AND_RETURN_BOOL(ret);
        // }

        // inline void expectNumSend(bool ret = true, UINT32 num = 1) const
        // {
        //     expect(num, "send").IGNORE().AND_RETURN_BOOL(ret);
        // }
    };
} // namespace

#endif // H_