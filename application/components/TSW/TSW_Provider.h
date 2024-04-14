//  ============================================================
//  class TSW_Provider implements I_TSW_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TSW_PROVIDER_H
#define TSW_PROVIDER_H

#include <BAS/coding.h>
#include <BAS/Containers.h>
#include <ifs/I_Provider.h>
#include <TSW/TSW.h>

class TSW_Provider : public I_TSW_Provider
{
public:
    inline TSW_Provider() = default;

    inline bool has(size_t pos) const
    {
        return mElems.size() > pos;
    }

    inline I_TSW& at(size_t pos)
    {
        return mElems.at(pos);
    }

    inline void reset()
    {
        mElems.clear();
    }

    void load(const ProjTSW* data, UINT32 num);

    IL_INSTANCE_DEC(TSW_Provider)

    NOCOPY(TSW_Provider)

private:
    PolyVec<I_TSW> mElems;
};
#endif // H_