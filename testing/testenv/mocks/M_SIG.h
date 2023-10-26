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
        
        inline void fromFld(INT32 state, INT32 speed)
        {
            call("fromFld").PARAM(state).PARAM(speed);
        }
        inline void expectFromFld(INT32 state, INT32 speed = 0)
        {
            expect("fromFld").PARAM(state).PARAM(speed);
        }
        inline void expectNumFromFld(UINT32 num = 0)
        {
            expect(num, "fromFld").IGNORE();
        }

        inline void fromGui(INT32 state, INT32 speed)
        {
            call("fromGui").PARAM(state).PARAM(speed);
        }
        inline void expectFromGui(INT32 state, INT32 speed = 0)
        {
            expect("fromGui").PARAM(state).PARAM(speed);
        }
        inline void expectNumFromGui(UINT32 num = 0)
        {
            expect(num, "fromGui").IGNORE();
        }

        inline INT32 type() const
        {
            return SIG_TYPE_H;
        }  
    };
}
#endif // H_