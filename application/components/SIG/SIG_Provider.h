//  ============================================================
//  class SIG_Provider implements I_SIG_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef SIG_PROVIDER_H
#define SIG_PROVIDER_H

#include <BAS/coding.h>
#include <BAS/Containers.h>
#include <ifs/I_SIG_Provider.h>
#include <SIG/SIG_X.h>

class SIG_Provider : public I_SIG_Provider
{
public:
    inline SIG_Provider() = default;

    inline bool has(size_t pos) const
    {
        return mElems.size() > pos;
    }

    inline I_SIG& at(size_t pos)
    {
        return mElems.at(pos);
    }

    inline void reset()
    {
        mElems.clear();
    }

    void load(const ProjSIG* data, UINT32 num);

    IL_INSTANCE_DEC(SIG_Provider)
    NOCOPY(SIG_Provider)
private:
    PolyVec<I_SIG> mElems;

};


#endif // H_