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

        inline bool send(const CmdFld& tele) const
        {
            return call("send").TPARAM(CmdFld, tele).RETURN_DEF_BOOL(true);
        }
        inline void expectSend(const CmdFld& tele, bool ret = true) const
        {
            expect("send").TPARAM(CmdFld, tele).AND_RETURN_BOOL(ret);
        }

        inline bool send(const StateGui& tele) const
        {
            return call("send").TPARAM(StateGui, tele).RETURN_DEF_BOOL(true);
        }
        inline void expectSend(const StateGui& tele, bool ret = true) const
        {
            expect("send").TPARAM(StateGui, tele).AND_RETURN_BOOL(ret);
        }
        
        inline void expectSend(bool ret = true) const
        {
            expect("send").IGNORE().AND_RETURN_BOOL(ret);
        }

        inline void expectNumSend(bool ret = true, UINT32 num = 1) const
        {
            expect(num, "send").IGNORE().AND_RETURN_BOOL(ret);
        }
    };
} // namespace

#endif // H_