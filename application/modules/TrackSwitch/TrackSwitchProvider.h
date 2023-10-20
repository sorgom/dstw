//  ============================================================
//  class TrackSwitchProvider implements I_TrackSwitchProvider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TRACKSWITCHPROVIDER_H
#define TRACKSWITCHPROVIDER_H

#include <baselib/InstanceMacros.h>
#include <baselib/StackArray.h>
#include <ifs/I_TrackSwitchProvider.h>
#include <setup/capacities.h>
#include <TrackSwitch/TrackSwitch.h>

class TrackSwitchProvider : public I_TrackSwitchProvider
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
        new (mSwitches.addPtr()) TrackSwitch(id);
    }
    inline I_TrackSwitch& at(UINT32 pos)
    {
        return mSwitches.at(pos);
    }

    DDI_INSTANCE_DEC(TrackSwitchProvider)

private:
    SimpleStackArray<TrackSwitch, CAPACITY_TSW> mSwitches;
};
#endif // H_