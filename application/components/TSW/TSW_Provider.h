//  ============================================================
//  class TSW_Provider implements I_TSW_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TSW_PROVIDER_H
#define TSW_PROVIDER_H

#include <BAS/coding.h>
#include <BAS/StaticArray.h>
#include <ifs/I_TSW_Provider.h>
#include <setup/capacities.h>
#include <TSW/TSW.h>

class TSW_Provider : public I_TSW_Provider
{
public:
    inline TSW_Provider() {}

    inline bool has(size_t pos) const
    {
        return mTSWs.has(pos);
    }

    inline I_TSW& at(size_t pos)
    {
        return mTSWs.at(pos);
    }

    void load(const ProjTSW* data, UINT32 num);

    IL_INSTANCE_DEC(TSW_Provider)

private:
    StaticArray<I_TSW, CAPACITY_TSW, TSW> mTSWs;

    NOCOPY(TSW_Provider)
};
#endif // H_