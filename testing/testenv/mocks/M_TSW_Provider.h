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

        inline bool has(UINT32 pos) const
        {
            return call("has").PARAM(pos).RETURN_DEF_BOOL(true);
        }
        inline void expectHas(UINT32 pos, bool ret = true) const
        {
            expect("has").PARAM(pos).AND_RETURN_BOOL(ret);
        }

        inline I_TSW& at(UINT32 pos)
        {
            return M_TSW::instance();
        }

        inline bool load(const ProjTSW* data, UINT32 num)
        {
            return call("load").PARAM(num).RETURN_DEF_BOOL(true);
        }
        inline void expectLoad(UINT32 num, bool ret = true) const
        {
            expect("load").PARAM(num).AND_RETURN_BOOL(ret);
        }

    private:
        UINT32 mSize;
    };
}
#endif // H_