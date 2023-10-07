
#pragma once
#ifndef M_TRACKSWITCHTOGUI_H
#define M_TRACKSWITCHTOGUI_H

#include <ifs/I_TrackSwitch.h>
#include <testenv/M_Base.h>

namespace test
{
    class M_TrackSwitchToGui :
        public I_TrackSwitchToGui,
        private M_Base
    {
    public:
        inline M_TrackSwitchToGui():
            M_Base("TrackSwitchToGui")
        {}

        // interface methods

        inline void cmd(E_CmdTswToGui cmd)
        {
            mkCall("cmd").withParameter("cmd", cmd);
        }

        //  expected calls
        
        inline void expectCmd(E_CmdTswToGui cmd)
        {
            mkExpect("cmd").withParameter("cmd", cmd);
        }
    };
}

#endif // _H