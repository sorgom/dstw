//  ============================================================
//  mock for interface SIG
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_SIG_H
#define M_SIG_H

#include <ifs/I_SIG.h>
#include "M_Base.h"

namespace test
{
    MOCK_CLASS(SIG)
    {
    public:
        MOCK_CON(SIG)
        
        inline void fromFld(UINT8 state, UINT8 speed)
        {
            call("fromFld").PARAM(state).PARAM(speed);
        }
        inline void expectFromFld(UINT8 state, UINT8 speed = 0)
        {
            expect("fromFld").PARAM(state).PARAM(speed);
        }

        inline void fromGui(UINT8 state, UINT8 speed)
        {
            call("fromGui").PARAM(state).PARAM(speed);
        }
        inline void expectFromGui(UINT8 state, UINT8 speed = 0)
        {
            expect("fromGui").PARAM(state).PARAM(speed);
        }

        inline UINT8 type() const
        {
            return SIG_TYPE_H;
        }  
    };
}
#endif // H_