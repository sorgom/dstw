
#pragma once
#ifndef M_TRACKSWITCHPORT_H
#define M_TRACKSWITCHPORT_H

#include <ifs/I_TrackSwitchPort.h>
#include <testenv/M_Base.h>

namespace test
{
    class M_TrackSwitchPort :
        public I_TrackSwitchPort,
        private M_Base
    {
    public:
        inline M_TrackSwitchPort():
            M_Base("TrackSwitchPort")
        {}

        // interface methods

        inline void toFld(E_TswToFld cmd) const
        {
            call("toFld").withParameter("cmd", cmd);
        }

        inline void toGui(E_TswToGui cmd) const
        {
            call("toGui").withParameter("cmd", cmd);
        }

        //  expected calls

        inline void expectToFld(E_TswToFld cmd) const
        {
            expect("toFld").withParameter("cmd", cmd);
        }

        inline void expectToGui(E_TswToGui cmd) const
        {
            expect("toGui").withParameter("cmd", cmd);
        }
    };
}

#endif // _H