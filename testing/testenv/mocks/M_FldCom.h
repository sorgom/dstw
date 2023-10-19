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
        inline bool send(const CmdFld& tele) const
        {
            return call("send").TPARAM(CmdFld, tele).RETI(true);
        }

        //  expected calls
        inline void expectSend(const CmdFld& tele, bool ret = true) const
        {
            expect("send").TPARAM(CmdFld, tele).ARETV(ret);
        }
        
        inline void expectSend(bool ret = true) const
        {
            expect("send").IGNORE().ARETV(ret);
        }
    };
} // namespace

#endif // H_