//  ============================================================
//  mock for interface Dispatcher
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef M_DISPATCHER_H
#define M_DISPATCHER_H

#include <ifs/I_Dispatcher.h>
#include "M_Base.h"
#include <baselib/Mem.h>

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
        inline void expectNumAssign(E_Subsys subs, UINT32 num, INT32 offset = 0) const
        {
            for (INT32 pos = 0; pos < num; ++pos)
            {
                expect("assign").PARAM(subs).PARAM(pos).IGNORE().AND_RETURN(pos + offset);
            }
        }
        inline void expectAssign(E_Subsys subs, UINT32 pos, INT32 ret = 0) const
        {
            expect("assign").PARAM(subs).PARAM(pos).IGNORE().AND_RETURN(ret);
        }

        inline bool label(ElementName& name, UINT32 id) const
        {
            Mem::copy(name, mLabel);
            return call("label").PARAM(id).RETURN_DEF_INT(true);
        }
        inline void setLabel(const ElementName& name)
        {
            Mem::copy(mLabel, name);
        }
        inline void expectLabel(UINT32 id, bool ret = true) const
        {
            expect("label").PARAM(id).AND_RETURN_BOOL(ret);
        }

        inline bool dispatch(const FldState& tele) const
        {
            return call("dispatch").TPARAM(FldState, tele).RETURN_DEF_BOOL(true);
        }
        inline void expectDispatch(const FldState& tele, bool ret = true) const
        {
            expect("dispatch").TPARAM(FldState, tele).AND_RETURN_BOOL(ret);
        }

        inline bool dispatch(const GuiCmd& tele) const
        {
            return call("dispatch").TPARAM(GuiCmd, tele).RETURN_DEF_BOOL(true);
        }
        inline void expectDispatch(const GuiCmd& tele, bool ret = true) const
        {
            expect("dispatch").TPARAM(GuiCmd, tele).AND_RETURN_BOOL(ret);
        }

        inline void expectDispatch(bool ret = true, UINT32 num = 1) const
        {
            expect(num, "dispatch").IGNORE().AND_RETURN_BOOL(ret);
        }
    private:
        ElementName mLabel;
    };
} 

#endif // H_