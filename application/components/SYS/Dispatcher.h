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

    static const size_t invalidPos = -1;

    void reset();
    void index();

    size_t assign(const ElementName& name, E_Subsys subs, size_t pos);
    
    void dispatch(const FldState& tele) const;
    void dispatch(const GuiCmd&   tele) const;

    void dispatch(size_t id, const CmdFld&   tele) const;
    void dispatch(size_t id, const StateGui& tele) const;

    IL_INSTANCE_DEC(Dispatcher)

    NOCOPY(Dispatcher)

private:
    NtpArray<CAPACITY_DSP> mData;
    NtpIndex<CAPACITY_DSP> mIndx;


};

#endif // H_