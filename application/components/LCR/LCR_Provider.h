//  ============================================================
//  class LCR_Provider implements I_LCR_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef LCR_PROVIDER_H
#define LCR_PROVIDER_H

#include <BAS/coding.h>
#include <BAS/StackArray.h>
#include <ifs/I_LCR_Provider.h>
#include <setup/capacities.h>
#include <LCR/LCR_X.h>

class LCR_Provider : public I_LCR_Provider
{
public:
    inline LCR_Provider() {}

    inline bool has(UINT32 pos) const
    {
        return mLCRs.has(pos);
    }

    inline I_LCR& at(UINT32 pos)
    {
        return mLCRs.at(pos);
    }

    void load(const ProjLCR* data, UINT32 num);

    IL_INSTANCE_DEC(LCR_Provider)

private:
    StackArray<LCR_X, CAPACITY_LCR> mLCRs;

    NOCOPY(LCR_Provider)
};


#endif // H_