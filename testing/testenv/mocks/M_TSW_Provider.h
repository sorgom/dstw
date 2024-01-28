//  ============================================================
//  mock for interface TSW_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_TSW_PROVIDER_H
#define M_TSW_PROVIDER_H

#include <ifs/I_TSW_Provider.h>
#include "M_Base.h"
#include "M_TSW.h"

namespace test
{
    MOCK_CLASS(TSW_Provider)
    {
    public:
        MOCK_CON(TSW_Provider)

        inline bool has(size_t pos) const
        {
            return call("has").PARAM(pos).RETURN_DEF_BOOL(true);
        }
        inline void expectHas(size_t pos, bool ret = true) const
        {
            expect("has").PARAM(pos).AND_RETURN_BOOL(ret);
        }

        inline I_TSW& at(size_t pos)
        {
            return M_TSW::instance();
        }

        inline void load(const ProjTSW* data, UINT32 num)
        {
            call("load").PPARAM(data).PARAM(num);
        }
        inline void expectLoad(const ProjTSW* data, UINT32 num) const
        {
            expect("load").PPARAM(data).PARAM(num);
        }
   };
}
#endif // H_