//  ============================================================
//  mock for interface I_TrackSwitchPort
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_TRACKSWITCHPORT_H
#define M_TRACKSWITCHPORT_H

#include <ifs/I_TrackSwitchPort.h>
#include "M_Base.h"

namespace test
{
    MOCK_CLASS(TrackSwitchPort)
    {
    public:
        MOCK_CON(TrackSwitchPort)

        // interface methods

        inline void toFld(UINT32 id, INT32 cmd) const
        {
            call("toFld").PARAM(id).PARAM(cmd);
        }

        inline void toGui(UINT32 id, INT32 cmd) const
        {
            call("toGui").PARAM(id).PARAM(cmd);
        }

        inline void fromFld(const FldTelegram& tele) const
        {
            call("fromFld").TPARAM(FldTelegram, tele);
        }

        inline void fromGui(const GuiTelegram& tele) const
        {
            call("fromGui").TPARAM(GuiTelegram, tele);
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

        inline void expectFromFld(const FldTelegram& tele) const
        {
            expect("fromFld").TPARAM(FldTelegram, tele);
        }
        
        inline void expectFromGui(const GuiTelegram& tele) const
        {
            expect("fromGui").TPARAM(GuiTelegram, tele);
        }
    };
}

#endif // _H