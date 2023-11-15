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

        inline INT32 assign(const ElementName& name, E_Subsys subs, UINT32 pos)
        {
            return call("assign").TPARAM(ElementName, name).PARAM(subs).PARAM(pos).RETURN_DEF_INT(0);
        }
        inline void expectAssign(const ElementName& name, E_Subsys subs, UINT32 pos, INT32 ret = 0) const
        {
            expect("assign").TPARAM(ElementName, name).PARAM(subs).PARAM(pos).AND_RETURN(ret);
        }

        inline void dispatch(const FldState& tele) const
        {
            call("dispatch").TPARAM(FldState, tele);
        }
        inline void expectDispatch(const FldState& tele) const
        {
            expect("dispatch").TPARAM(FldState, tele);
        }

        inline void dispatch(const GuiCmd& tele) const
        {
            call("dispatch").TPARAM(GuiCmd, tele);
        }
        inline void expectDispatch(const GuiCmd& tele) const
        {
            expect("dispatch").TPARAM(GuiCmd, tele);
        }

        inline void dispatch(UINT32 id, const CmdFld& tele) const
        {
            call("dispatch").PARAM(id).TPARAM(CmdFld, tele);
        }
        inline void expectDispatch(UINT32 id, const CmdFld& tele) const
        {
            expect("dispatch").PARAM(id).TPARAM(CmdFld, tele);
        }

        inline void dispatch(UINT32 id, const StateGui& tele) const
        {
            call("dispatch").PARAM(id).TPARAM(StateGui, tele);
        }
        inline void expectDispatch(UINT32 id, const StateGui& tele) const
        {
            expect("dispatch").PARAM(id).TPARAM(StateGui, tele);
        }
    };
} 

#endif // H_