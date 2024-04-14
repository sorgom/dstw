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
    MOCK_CLASS(Dispatcher)
    {
    public:
        MOCK_CON(Dispatcher)

        inline void reset()
        {
            call("reset");
        }
        inline void expectReset() const
        {
            expect("reset");
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

        inline void dispatch(const ComTeleFld& tele) const
        {
            call("dispatch").TPARAM(ComTeleFld, tele);
        }
        inline void expectDispatch(const ComTeleFld& tele) const
        {
            expect("dispatch").TPARAM(ComTeleFld, tele);
        }

        inline void dispatch(const ComTeleGui& tele) const
        {
            call("dispatch").TPARAM(ComTeleGui, tele);
        }
        inline void expectDispatch(const ComTeleGui& tele) const
        {
            expect("dispatch").TPARAM(ComTeleGui, tele);
        }


        inline void dispatch(size_t id, ComTeleFld&& tele) const
        {
            call("dispatch").PARAM(id).TPARAM(ComTeleFld, tele);
        }
        inline void expectDispatch(size_t id, ComTeleFld&& tele) const
        {
            expect("dispatch").PARAM(id).TPARAM(ComTeleFld, tele);
        }

        inline void dispatch(size_t id, ComTeleGui&& tele) const
        {
            call("dispatch").PARAM(id).TPARAM(ComTeleGui, tele);
        }
        inline void expectDispatch(size_t id, ComTeleGui&& tele) const
        {
            expect("dispatch").PARAM(id).TPARAM(ComTeleGui, tele);
        }
    };
} 

#endif // H_