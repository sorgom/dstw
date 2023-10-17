//  ============================================================
//  mock for interface I_FldCom
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_FLDCOM_H
#define M_FLDCOM_H

#include <ifs/I_FldCom.h>
#include "M_Base.h"

namespace test
{
    MOCK_CLASS(FldCom)
    {
    public:
        MOCK_CON(FldCom)

        // interface methods
        inline bool send(const FldTelegram& tele) const
        {
            return call("send").RETI(true);
        }

        //  expected calls
        inline void expectSend(bool ret = true) const
        {
            expect("send").ARETV(ret);
        }

    };
} // namespace

#endif // H_