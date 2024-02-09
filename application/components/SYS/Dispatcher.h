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

    const PosRes assign(const ComName& name, E_Subsys subs, size_t pos);
    
    void dispatch(const ComFldState& tele) const;
    void dispatch(const ComGuiCmd&   tele) const;

    void dispatch(size_t id, ComCmdFld&&   tele) const;
    void dispatch(size_t id, ComStateGui&& tele) const;

    IL_INSTANCE_DEC(Dispatcher)

    NOCOPY(Dispatcher)

private:
    NtpArray<CAPACITY_DSP> mData;
    NtpIndex<CAPACITY_DSP> mIndx;


};

#endif // H_