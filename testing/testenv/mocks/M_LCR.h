//  ============================================================
//  mock for interface LCR
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_LCR_H
#define M_LCR_H

#include <ifs/I_LCR.h>
#include "M_Base.h"

namespace test
{
    MOCK_CLASS(LCR)
    {
    public:
        MOCK_CON(LCR)
        
        inline void fromFld(INT32 state, INT32 ubk)
        {
            call("fromFld").PARAM(state).PARAM(ubk);
        }
        inline void expectFromFld(INT32 state, INT32 ubk)
        {
            expect("fromFld").PARAM(state).PARAM(ubk);
        }

        inline void fromGui(INT32 state)
        {
            call("fromGui").PARAM(state);
        }
        inline void expectFromGui(INT32 state)
        {
            expect("fromGui").PARAM(state);
        }

        inline INT32 type() const
        {
            return LCR_TYPE_LCR;
        }  
    };
}
#endif // H_