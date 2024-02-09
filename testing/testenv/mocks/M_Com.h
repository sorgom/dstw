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

        inline void send(const ComCmdFld& tele) const
        {
            call("send").TPARAM(ComCmdFld, tele);
        }
        inline void expectSend(const ComCmdFld& tele) const
        {
            expect("send").TPARAM(ComCmdFld, tele);
        }

        inline void send(const ComStateGui& tele) const
        {
            call("send").TPARAM(ComStateGui, tele);
        }
        inline void expectSend(const ComStateGui& tele) const
        {
            expect("send").TPARAM(ComStateGui, tele);
        }
    };
} // namespace

#endif // H_