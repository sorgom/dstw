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
    class M_Com : public I_Com, private M_Base
    {
    public:
        inline M_Com() : M_Base("Com") {}
        IL_INSTANCE_DEC(M_Com)

        inline void send(const ComTeleFld& tele) const
        {
            call("send").TPARAM(ComTeleFld, tele);
        }
        inline void expectSend(const ComTeleFld& tele) const
        {
            expect("send").TPARAM(ComTeleFld, tele);
        }

        inline void send(const ComTeleGui& tele) const
        {
            call("send").TPARAM(ComTeleGui, tele);
        }
        inline void expectSend(const ComTeleGui& tele) const
        {
            expect("send").TPARAM(ComTeleGui, tele);
        }
    };
} // namespace

#endif // H_