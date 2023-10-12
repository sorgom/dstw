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

        inline void toFld(UINT32 id, E_TswToFld cmd) const
        {
            call("toFld").PARAM(id).PARAM(cmd);
        }

        inline void toGui(UINT32 id, E_TswToGui cmd) const
        {
            call("toGui").PARAM(id).PARAM(cmd);
        }

        //  expected calls

        inline void expectToFld(UINT32 id, E_TswToFld cmd) const
        {
            expect("toFld").PARAM(id).PARAM(cmd);
        }

        inline void expectToGui(UINT32 id, E_TswToGui cmd) const
        {
            expect("toGui").PARAM(id).PARAM(cmd);
        }
    };
}

#endif // _H