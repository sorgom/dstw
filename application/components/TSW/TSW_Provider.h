//  ============================================================
//  class TSW_Provider implements I_TSW_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TSW_PROVIDER_H
#define TSW_PROVIDER_H

#include <BAS/coding.h>
#include <BAS/BAS_Provider.h>
#include <TSW/TSW.h>

class TSW_Provider : public BAS_Provider
{
public:
    inline TSW_Provider() = default;

    IL_INSTANCE_DEC(TSW_Provider)

    NOCOPY(TSW_Provider)
protected:
    bool add(size_t id, const ProjItem& item) final
    {
        mElems.add<TSW>(id);
        return true;
    }
    inline E_Comp comp() const final { return COMP_TSW; }; 
};

#endif // H_