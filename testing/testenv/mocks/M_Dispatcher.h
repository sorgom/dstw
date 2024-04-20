//  ============================================================
//  mock for interface Dispatcher
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef M_DISPATCHER_H
#define M_DISPATCHER_H

#include <ifs/I_Dispatcher.h>
#include "M_Base.h"

namespace test
{
    class M_Dispatcher : public I_Dispatcher, private M_Base
    {
    public:
        inline M_Dispatcher() : M_Base("Dispatcher") {}
        INSTANCE_DEC(M_Dispatcher)

        inline void clear()
        {
            call("clear");
        }
        inline void expectClear() const
        {
            expect("clear");
        }

        inline void index()
        {
            call("index");
        }
        inline void expectIndex() const
        {
            expect("index");
        }

        inline const PosRes assign(const ComName& name, E_Comp comp, size_t pos)
        {
            const INT32 i = call("assign").TPARAM(ComName, name).PARAM(comp).PARAM(pos).RETURN_DEF_INT(0);
            return i < 0 ? PosRes {0, false} : PosRes {static_cast<size_t>(i), true};
        }
        inline void expectAssign(const ComName& name, E_Comp comp, size_t pos, INT32 ret = 0) const
        {
            expect("assign").TPARAM(ComName, name).PARAM(comp).PARAM(pos).AND_RETURN(ret);
        }

        inline void fromFld(const ComTele& tele) const
        {
            call("fromFld").TPARAM(ComTele, tele);
        }
        inline void expectFromFld(const ComTele& tele) const
        {
            expect("fromFld").TPARAM(ComTele, tele);
        }

        inline void fromGui(const ComTele& tele) const
        {
            call("fromGui").TPARAM(ComTele, tele);
        }
        inline void expectFromGui(const ComTele& tele) const
        {
            expect("fromGui").TPARAM(ComTele, tele);
        }

        inline void toFld(size_t id, const ComData& data) const
        {
            call("toFld").PARAM(id).TPARAM(ComData, data);
        }
        inline void expectToFld(size_t id, const ComData& data) const
        {
            expect("toFld").PARAM(id).TPARAM(ComData, data);
        }

        inline void toGui(size_t id, const ComData& data) const
        {
            call("toGui").PARAM(id).TPARAM(ComData, data);
        }
        inline void expectToGui(size_t id, const ComData& data) const
        {
            expect("toGui").PARAM(id).TPARAM(ComData, data);
        }
    };
} 

#endif // H_