
#pragma once
#ifndef M_RASTAPORT_H
#define M_RASTAPORT_H

#include <ifs/I_RastaPort.h>
#include "M_Base.h"

namespace test
{
    MOCK_CLASS(RastaPort)
    {
    public:
        MOCK_CON(RastaPort)

        // interface methods

        inline void send(const RastaTelegram& tele)
        {
            call("send").TPARAM(RastaTelegram, tele);
        }

        //  expected calls

        inline void expectSend(const RastaTelegram& tele) const
        {
            expect("send").TPARAM(RastaTelegram, tele);
        }
    };
}

#endif // _H