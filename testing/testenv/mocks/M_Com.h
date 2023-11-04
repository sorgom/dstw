//  ============================================================
//  mock for interface I_Com
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_COM_H
#define M_COM_H

#include <ifs/I_Com.h>
#include "M_Base.h"

namespace test
{
    MOCK_CLASS(Com)
    {
    public:
        MOCK_CON(Com)

        inline void send(const CmdFld& tele) const
        {
            call("send").TPARAM(CmdFld, tele);
        }
        inline void expectSend(const CmdFld& tele) const
        {
            expect("send").TPARAM(CmdFld, tele);
        }

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