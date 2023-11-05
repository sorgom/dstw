//  ============================================================
//  Dispatcher implements I_Dispatcher
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <BAS/coding.h>
#include <BAS/NtpArray.h>
#include <ifs/I_Dispatcher.h>
#include <setup/capacities.h>

class Dispatcher : public I_Dispatcher
{
public:
    inline Dispatcher():
        mIndx(mData)
    {}

    void reset();
    void index();

    INT32 assign(const ElementName& name, E_Subsys subs, UINT32 pos);
    
    void dispatch(const FldState& tele) const;
    void dispatch(const GuiCmd&   tele) const;

    void dispatch(UINT32 id, const CmdFld&   tele) const;
    void dispatch(UINT32 id, const StateGui& tele) const;

    IL_INSTANCE_DEC(Dispatcher)

private:
    NtpArray<CAPACITY_DSP> mData;
    NtpIndex<CAPACITY_DSP> mIndx;

    NOCOPY(Dispatcher)
};

#endif // H_