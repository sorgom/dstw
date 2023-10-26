//  ============================================================
//  class SIG_Provider implements I_SIG_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef SIG_PROVIDER_H
#define SIG_PROVIDER_H

#include <baselib/InstanceMacros.h>
#include <baselib/StackArray.h>
#include <ifs/I_SIG_Provider.h>
#include <setup/capacities.h>
#include <SIG/SIG_X.h>

class SIG_Provider : public I_SIG_Provider
{
public:
    inline bool has(UINT32 pos) const
    {
        return mSIGs.has(pos);
    }

    inline I_SIG& at(UINT32 pos)
    {
        return mSIGs.at(pos);
    }

    bool load(const ProjSIG* data, UINT32 num);

    DDI_INSTANCE_DEC(SIG_Provider)

private:
    SimpleStackArray<SIG_X, CAPACITY_SIG> mSIGs;
};


#endif // H_