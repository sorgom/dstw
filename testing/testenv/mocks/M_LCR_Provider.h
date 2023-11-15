//  ============================================================
//  mock for interface LCR_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_LCR_PROVIDER_H
#define M_LCR_PROVIDER_H

#include <ifs/I_LCR_Provider.h>
#include "M_Base.h"
#include "M_LCR.h"

namespace test
{
    MOCK_CLASS(LCR_Provider)
    {
    public:
        MOCK_CON(LCR_Provider)

        inline bool has(UINT32 pos) const
        {
            return call("has").PARAM(pos).RETURN_DEF_BOOL(true);
        }
        inline void expectHas(UINT32 pos, bool ret = true) const
        {
            expect("has").PARAM(pos).AND_RETURN_BOOL(ret);
        }

        inline I_LCR& at(UINT32 pos)
        {
            return M_LCR::instance();
        }

        inline void load(const ProjLCR* data, UINT32 num)
        {
            call("load").PPARAM(data).PARAM(num);
        }
        inline void expectLoad(const ProjLCR* data, UINT32 num) const
        {
            expect("load").PPARAM(data).PARAM(num);
        }
   };
}
#endif // H_