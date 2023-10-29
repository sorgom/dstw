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

        inline void send(const CmdFld& tele) const
        {
            call("send").TPARAM(CmdFld, tele);
        }
        inline void expectSend(const CmdFld& tele) const
        {
            expect("send").TPARAM(CmdFld, tele);
        }
    };
} // namespace

#endif // H_