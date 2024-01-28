//  ============================================================
//  mock for interface SIG_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_SIG_PROVIDER_H
#define M_SIG_PROVIDER_H

#include <ifs/I_SIG_Provider.h>
#include "M_Base.h"
#include "M_SIG.h"

namespace test
{
    MOCK_CLASS(SIG_Provider)
    {
    public:
        MOCK_CON(SIG_Provider)

        inline bool has(size_t pos) const
        {
            return call("has").PARAM(pos).RETURN_DEF_BOOL(true);
        }
        inline void expectHas(size_t pos, bool ret = true) const
        {
            expect("has").PARAM(pos).AND_RETURN_BOOL(ret);
        }

        inline I_SIG& at(size_t pos)
        {
            return M_SIG::instance();
        }

        inline void load(const ProjSIG* data, UINT32 num)
        {
            call("load").PPARAM(data).PARAM(num);
        }
        inline void expectLoad(const ProjSIG* data, UINT32 num) const
        {
            expect("load").PPARAM(data).PARAM(num);
        }
   };
}
#endif // H_