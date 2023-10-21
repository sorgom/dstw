//  ============================================================
//  mock for interface I_TSW_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_TSW_HUB_H
#define M_TSW_HUB_H

#include <ifs/I_TSW_Hub.h>
#include "M_Base.h"

namespace test
{
    MOCK_CLASS(TSW_Hub)
    {
    public:
        MOCK_CON(TSW_Hub)

        // interface methods

        inline void toFld(UINT32 id, INT32 cmd) const
        {
            call("toFld").PARAM(id).PARAM(cmd);
        }

        inline void toGui(UINT32 id, INT32 cmd) const
        {
            call("toGui").PARAM(id).PARAM(cmd);
        }

        inline void fromFld(const FldState& tele, UINT32 pos)
        {
            call("fromFld").TPARAM(FldState, tele).PARAM(pos);
        }

        inline void fromGui(const GuiCmd& tele, UINT32 pos)
        {
            call("fromGui").TPARAM(GuiCmd, tele).PARAM(pos);
        }

        inline bool load(UINT32 num, const ProjTSW* data)
        {
            return call("load").PARAM(num).RETI(true);
        }

        //  expected calls

        inline void expectToFld(UINT32 id, INT32 cmd) const
        {
            expect("toFld").PARAM(id).PARAM(cmd);
        }

        inline void expectToGui(UINT32 id, INT32 cmd) const
        {
            expect("toGui").PARAM(id).PARAM(cmd);
        }

        inline void expectFromFld(const FldState& tele, UINT32 pos) const
        {
            expect("fromFld").TPARAM(FldState, tele).PARAM(pos);
        }
        inline void expectFromFld(UINT32 pos) const
        {
            expect("fromFld").IGNORE().PARAM(pos);
        }
        
        inline void expectFromGui(const GuiCmd& tele, UINT32 pos) const
        {
            expect("fromGui").TPARAM(GuiCmd, tele).PARAM(pos);
        }
        inline void expectFromGui(UINT32 pos) const
        {
            expect("fromGui").IGNORE().PARAM(pos);
        }
        
        inline void expectLoad(UINT32 num, bool ret = true) const
        {
            expect("load").PARAM(num).ARETV(ret);
        }
    };
}

#endif // _H