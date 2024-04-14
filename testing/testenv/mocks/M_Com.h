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