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
        
        inline void fromFld(INT32 state)
        {
            call("fromFld").PARAM(state);
        }
        inline void expectFromFld(INT32 state)
        {
            expect("fromFld").PARAM(state);
        }
        inline void expectNumFromFld(UINT32 num = 0)
        {
            expect(num, "fromFld").IGNORE();
        }

        inline void fromGui(INT32 cmd)
        {
            call("fromGui").PARAM(cmd);
        }
        inline void expectFromGui(INT32 cmd)
        {
            expect("fromGui").PARAM(cmd);
        }
        inline void expectNumFromGui(UINT32 num = 0)
        {
            expect(num, "fromGui").IGNORE();
        }
    };
}
#endif // H_