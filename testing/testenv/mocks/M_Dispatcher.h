//  ============================================================
//  mock for interface Dispatcher
//  ============================================================
//  created by Manfred Sorgo
#pragma once

#include <ifs/I_Dispatcher.h>
#include "M_Base.h"

namespace test
{
    class M_Dispatcher : public I_Dispatcher, private M_Base
    {
    public:
        INSTANCE_DEC(M_Dispatcher)
        NOCOPY(M_Dispatcher)

        inline void clear() override
        {
            call("clear");
        }
        inline void expectClear() const
        {
            expect("clear");
        }

        inline void index() override
        {
            call("index");
        }
        inline void expectIndex() const
        {
            expect("index");
        }

        inline const PosRes assign(const ComAddr& name, E_Comp comp, size_t pos) override
        {
            const INT32 i = call("assign").TPARAM(ComAddr, name).PARAM(comp).PARAM(pos).RETURN_DEF_INT(0);
            return i < 0 ? PosRes {false} : PosRes {true, static_cast<size_t>(i)};
        }
        inline void expectAssign(const ComAddr& name, E_Comp comp, size_t pos, INT32 ret = 0) const
        {
            expect("assign").TPARAM(ComAddr, name).PARAM(comp).PARAM(pos).AND_RETURN(ret);
        }

        inline void fromFld(const ComTele& tele) const override
        {
            call("fromFld").TPARAM(ComTele, tele);
        }
        inline void expectFromFld(const ComTele& tele) const
        {
            expect("fromFld").TPARAM(ComTele, tele);
        }

        inline void fromGui(const ComTele& tele) const override
        {
            call("fromGui").TPARAM(ComTele, tele);
        }
        inline void expectFromGui(const ComTele& tele) const
        {
            expect("fromGui").TPARAM(ComTele, tele);
        }

        inline void toFld(size_t id, const ComData& data) const override
        {
            call("toFld").PARAM(id).TPARAM(ComData, data);
        }
        inline void expectToFld(size_t id, const ComData& data) const
        {
            expect("toFld").PARAM(id).TPARAM(ComData, data);
        }

        inline void toGui(size_t id, const ComData& data) const override
        {
            call("toGui").PARAM(id).TPARAM(ComData, data);
        }
        inline void expectToGui(size_t id, const ComData& data) const
        {
            expect("toGui").PARAM(id).TPARAM(ComData, data);
        }

        inline void reGui() const override
        {
            call("reGui");
        }
        inline void expectReGui() const
        {
            expect("reGui");
        }

    private:
        inline M_Dispatcher() : M_Base("Dispatcher") {}
    };
}
