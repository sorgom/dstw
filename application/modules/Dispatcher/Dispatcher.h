//  ============================================================
//  Dispatcher implements I_Dispatcher
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <ifs/I_Dispatcher.h>
#include <setup/capacities.h>
#include <Dispatcher/NtpArray.h>
#include <baselib/InstanceMacros.h>

class Dispatcher : public I_Dispatcher
{
public:
    inline Dispatcher():
        mIndx(mData)
    {}

    void reset();
    void index();

    INT32 assign(const ElementName& name, E_Subsys subs, UINT32 pos);
    bool label(ElementName& name, UINT32 id) const;
    
    bool dispatch(const FldState& tele) const;
    bool dispatch(const GuiCmd&   tele) const;

    DDI_INSTANCE_DEC(Dispatcher)

private:
    NtpArray<CAPACITY_ELEMENTS> mData;
    NtpIndex<CAPACITY_ELEMENTS> mIndx;
};

#endif // H_