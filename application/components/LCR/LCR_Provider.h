//  ============================================================
//  class LCR_Provider implements I_LCR_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef LCR_PROVIDER_H
#define LCR_PROVIDER_H

#include <BAS/coding.h>
#include <BAS/Containers.h>
#include <ifs/I_LCR_Provider.h>
#include <LCR/LCR_X.h>

class LCR_Provider : public I_LCR_Provider
{
public:
    inline LCR_Provider() = default;

    inline bool has(size_t pos) const
    {
        return mLCRs.size() > pos;
    }

    inline I_LCR& at(size_t pos)
    {
        return mLCRs.at(pos);
    }

    inline void reset()
    {
        mLCRs.clear();
    }

    void load(const ProjLCR* data, UINT32 num);

    IL_INSTANCE_DEC(LCR_Provider)

    NOCOPY(LCR_Provider)

private:
    PolyVec<I_LCR> mLCRs;
};


#endif // H_