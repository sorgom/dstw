//  ============================================================
//  mock for interface TrackSwitch
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_TRACKSWITCH_H
#define M_TRACKSWITCH_H

#include <ifs/I_TrackSwitch.h>
#include "M_Base.h"

namespace test
{
    MOCK_CLASS(TrackSwitch)
    {
    public:
        MOCK_CON(TrackSwitch)
        
        // interface methods

        inline void WU()
        {
            call("WU");
        }
        inline void expectWU() const
        {
            expect("WU");
        }

        inline void fromFld(INT32 state)
        {
            call("fromFld").PARAM(state);
        }
        inline void expectFromFld(INT32 state)
        {
            expect("fromFld").PARAM(state);
        }

        inline void expectFromFld()
        {
            expect("fromFld").IGNORE();
        }
        
    };
}
#endif // H_