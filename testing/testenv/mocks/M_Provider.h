//  ============================================================
//  common mock for all Provider interfaces
//  - I_TSW_Provider
//  - I_SIG_Provider
//  - I_LCR_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_PROVIDER_H
#define M_PROVIDER_H

#include "M_Base.h"
#include <ifs/I_Provider.h>
#include "M_LCR.h"
#include "M_SIG.h"
#include "M_TSW.h"

namespace test
{
    template <typename PROJ, typename IF>
    class M_Provider : 
        public IF,
        protected M_Base
    {
    public:

        inline bool has(size_t pos) const
        {
            return call("has").PARAM(pos).RETURN_DEF_BOOL(true);
        }
        inline void expectHas(size_t pos, bool ret = true) const
        {
            expect("has").PARAM(pos).AND_RETURN_BOOL(ret);
        }

        inline void reset()
        {
            call("reset");
        }
        inline void expectReset() const
        {
            expect("reset");
        }
        
        inline void load(const PROJ* data, UINT32 num)
        {
            call("load").PARAM(num);
        }
        inline void expectLoad(UINT32 num) const
        {
            expect("load").PARAM(num);
        }
        NODEF(M_Provider)
        NOCOPY(M_Provider)
    protected:
        M_Provider(const CONST_C_STRING name) :
            M_Base(name)
        {}
   };

    class M_TSW_Provider : public M_Provider<ProjTSW, I_TSW_Provider>
    {
    public:
        inline M_TSW_Provider():
            M_Provider(c__TSW_Provider)
        {}
        INSTANCE_DEC(M_TSW_Provider)

        inline I_TSW& at(size_t pos)
        {
            return M_TSW::instance();
        }
    };

    class M_SIG_Provider : public M_Provider<ProjSIG, I_SIG_Provider>
    {
    public:
        inline M_SIG_Provider():
            M_Provider(c__SIG_Provider)
        {}
        INSTANCE_DEC(M_SIG_Provider)

        inline I_SIG& at(size_t pos)
        {
            return M_SIG::instance();
        }
    };

    class M_LCR_Provider : public M_Provider<ProjLCR, I_LCR_Provider>
    {
    public:
        inline M_LCR_Provider():
            M_Provider(c__LCR_Provider)
        {}
        INSTANCE_DEC(M_LCR_Provider)

        inline I_LCR& at(size_t pos)
        {
            return M_LCR::instance();
        }
    };
}
#endif // H_