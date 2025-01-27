//  ============================================================
//  common mock for all Provider interfaces
//  - I_TSW_Provider
//  - I_SIG_Provider
//  - I_LCR_Provider
//  ============================================================
//  created by Manfred Sorgo

#ifndef M_PROVIDER_H
#define M_PROVIDER_H

#include <ifs/I_Provider.h>
#include "M_Base.h"
#include "M_Elem.h"

namespace test
{
    class M_Provider :
        public I_Provider,
        private M_Base
    {
    public:

        inline size_t size() const
        {
            return static_cast<size_t>(call("size").RETURN_DEF_INT(0));
        }
        inline void expectSize(int ret = 0) const
        {
            expect("size").AND_RETURN(ret);
        }

        inline void clear()
        {
            call("clear");
        }
        inline void expectClear() const
        {
            expect("clear");
        }

        inline void load(const ProjItem* data, UINT32 num)
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

    class M_TSW_Provider : public M_Provider
    {
    public:
        INSTANCE_DEC(M_TSW_Provider)

        inline I_Elem& at(size_t pos)
        {
            return M_TSW::instance();
        }
    private:
        M_TSW_Provider(): M_Provider("TSW_Provider") {}
    };

    class M_SIG_Provider : public M_Provider
    {
    public:
        INSTANCE_DEC(M_SIG_Provider)

        inline I_Elem& at(size_t pos)
        {
            return M_SIG::instance();
        }
    private:
        M_SIG_Provider(): M_Provider("SIG_Provider") {}
    };

    class M_LCR_Provider : public M_Provider
    {
    public:
        INSTANCE_DEC(M_LCR_Provider)

        inline I_Elem& at(size_t pos)
        {
            return M_LCR::instance();
        }
    private:
        M_LCR_Provider(): M_Provider("LCR_Provider") {}
    };
}
#endif // _H
