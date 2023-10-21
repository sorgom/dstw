//  ============================================================
//  class TSW_Provider implements I_TSW_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TSW_PROVIDER_H
#define TSW_PROVIDER_H

#include <baselib/InstanceMacros.h>
#include <baselib/StackArray.h>
#include <ifs/I_TSW_Provider.h>
#include <setup/capacities.h>
#include <TSW/TSW.h>

class TSW_Provider : public I_TSW_Provider
{
public:
    inline void reset()
    {
        mSwitches.reset();
    }
    inline UINT32 size() const
    {
        return mSwitches.size();
    }
    inline UINT32 capacity() const
    {
        return mSwitches.capacity();
    }
    inline void add(UINT32 id)
    {
        new (mSwitches.addPtr()) TSW(id);
    }
    inline I_TSW& at(UINT32 pos)
    {
        return mSwitches.at(pos);
    }

    DDI_INSTANCE_DEC(TSW_Provider)

private:
    SimpleStackArray<TSW, CAPACITY_TSW> mSwitches;
};
#endif // H_