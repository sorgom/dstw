//  ============================================================
//  mock for interface TSW
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_TSW_H
#define M_TSW_H

#include <ifs/I_TSW.h>
#include "M_Base.h"

namespace test
{
    MOCK_CLASS(TSW)
    {
    public:
        MOCK_CON(TSW)
        
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