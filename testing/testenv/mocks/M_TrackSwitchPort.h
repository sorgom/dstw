
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

        inline void toFld(E_TswToFld cmd) const
        {
            call("toFld").PARAM(cmd);
        }

        inline void toGui(E_TswToGui cmd) const
        {
            call("toGui").PARAM(cmd);
        }

        //  expected calls

        inline void expectToFld(E_TswToFld cmd) const
        {
            expect("toFld").PARAM(cmd);
        }

        inline void expectToGui(E_TswToGui cmd) const
        {
            expect("toGui").PARAM(cmd);
        }
    };
}

#endif // _H