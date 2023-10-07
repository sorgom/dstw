
#pragma once
#ifndef M_TRACKSWITCHTOFIELD_H
#define M_TRACKSWITCHTOFIELD_H

#include <ifs/I_TrackSwitch.h>
#include <testenv/M_Base.h>

namespace test
{
    class M_TrackSwitchToField :
        public I_TrackSwitchToField,
        private M_Base
    {
    public:
        inline M_TrackSwitchToField():
            M_Base("TrackSwitchToField")
        {}

        // interface methods

        inline void cmd(E_CmdTswToFld cmd)
        {
            mkCall("cmd").withParameter("cmd", cmd);
        }

        //  expected calls

        inline void expectCmd(E_CmdTswToFld cmd)
        {
            mkExpect("cmd").withParameter("cmd", cmd);
        }
    };
}

#endif // _H