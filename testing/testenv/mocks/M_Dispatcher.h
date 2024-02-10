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

        inline const PosRes assign(const ComName& name, E_Subsys subs, size_t pos)
        {
            const INT32 i = call("assign").TPARAM(ComName, name).PARAM(subs).PARAM(pos).RETURN_DEF_INT(0);
            return i < 0 ? PosRes {0, false} : PosRes {static_cast<size_t>(i), true};
        }
        inline void expectAssign(const ComName& name, E_Subsys subs, size_t pos, INT32 ret = 0) const
        {
            expect("assign").TPARAM(ComName, name).PARAM(subs).PARAM(pos).AND_RETURN(ret);
        }

        inline void dispatch(const ComFldState& tele) const
        {
            call("dispatch").TPARAM(ComFldState, tele);
        }
        inline void expectDispatch(const ComFldState& tele) const
        {
            expect("dispatch").TPARAM(ComFldState, tele);
        }

        inline void dispatch(const ComGuiCmd& tele) const
        {
            call("dispatch").TPARAM(ComGuiCmd, tele);
        }
        inline void expectDispatch(const ComGuiCmd& tele) const
        {
            expect("dispatch").TPARAM(ComGuiCmd, tele);
        }


        inline void dispatch(size_t id, ComCmdFld&& tele) const
        {
            call("dispatch").PARAM(id).TPARAM(ComCmdFld, tele);
        }
        inline void expectDispatch(size_t id, ComCmdFld&& tele) const
        {
            expect("dispatch").PARAM(id).TPARAM(ComCmdFld, tele);
        }

        inline void dispatch(size_t id, ComStateGui&& tele) const
        {
            call("dispatch").PARAM(id).TPARAM(ComStateGui, tele);
        }
        inline void expectDispatch(size_t id, ComStateGui&& tele) const
        {
            expect("dispatch").PARAM(id).TPARAM(ComStateGui, tele);
        }
    };
} 

#endif // H_