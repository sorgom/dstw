#pragma once
#ifndef M_HUB_H
#define M_HUB_H

#include "M_Base.h"
#include <ifs/I_Hub.h>

namespace test
{
    template <class T>
    class M_Hub : 
        public T,
        protected M_Base
    {
public:
        inline void toFld(size_t id, UINT8 param1, UINT8 param2 = PARAM_UNDEF) const
        {
            call("toFld").PARAM(id).PARAM(param1).PARAM(param2);
        }
        inline void expectToFld(size_t id, UINT8 param1, UINT8 param2 = PARAM_UNDEF) const
        {
            expect("toFld").PARAM(id).PARAM(param1).PARAM(param2);
        }

        inline void toGui(size_t id, UINT8 param1, UINT8 param2 = PARAM_UNDEF) const
        {
            call("toGui").PARAM(id).PARAM(param1).PARAM(param2);
        }
        inline void expectToGui(size_t id, UINT8 param1, UINT8 param2 = PARAM_UNDEF) const
        {
            expect("toGui").PARAM(id).PARAM(param1).PARAM(param2);
        }

        inline void fromDsp(size_t pos, const ComTeleFld& tele) const
        {
            call("fromDsp").PARAM(pos).TPARAM(ComTeleFld, tele);
        }
        inline void expectFromDsp(size_t pos, const ComTeleFld& tele) const
        {
            expect("fromDsp").PARAM(pos).TPARAM(ComTeleFld, tele);
        }

        inline void fromDsp(size_t pos, const ComTeleGui& tele) const
        {
            call("fromDsp").PARAM(pos).TPARAM(ComTeleGui, tele);
        }
        inline void expectFromDsp(size_t pos, const ComTeleGui& tele) const
        {
            expect("fromDsp").PARAM(pos).TPARAM(ComTeleGui, tele);
        }
protected:
    M_Hub(const CONST_C_STRING name) :
        M_Base(name)
    {}
        NODEF(M_Hub)
        NOCOPY(M_Hub)
    };

    class M_LCR_Hub : public M_Hub<I_LCR_Hub>
    {
    public:
        inline M_LCR_Hub():
            M_Hub(c__LCR_Hub)
        {}
        INSTANCE_DEC(M_LCR_Hub)
    };

    class M_SIG_Hub : public M_Hub<I_SIG_Hub>
    {
    public:
        inline M_SIG_Hub():
            M_Hub(c__SIG_Hub)
        {}
        INSTANCE_DEC(M_SIG_Hub)
    };
    
} // namespace

#endif // _H