//  ============================================================
//  class TSW_Provider implements I_TSW_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TSW_PROVIDER_H
#define TSW_PROVIDER_H

#include <BAS/coding.h>
#include <BAS/StackArray.h>
#include <ifs/I_TSW_Provider.h>
#include <setup/capacities.h>
#include <TSW/TSW.h>

class TSW_Provider : public I_TSW_Provider
{
public:
    inline TSW_Provider() {}

    inline bool has(UINT32 pos) const
    {
        return mTSWs.has(pos);
    }

    inline I_TSW& at(UINT32 pos)
    {
        return mTSWs.at(pos);
    }

    void load(const ProjTSW* data, UINT32 num);

    IL_INSTANCE_DEC(TSW_Provider)

private:
    StackArray<TSW, CAPACITY_TSW> mTSWs;

    NOCOPY(TSW_Provider)
};
#endif // H_