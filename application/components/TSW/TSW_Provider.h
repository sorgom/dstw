//  ============================================================
//  class TSW_Provider implements I_TSW_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TSW_PROVIDER_H
#define TSW_PROVIDER_H

#include <BAS/coding.h>
#include <BAS/BAS_Provider.h>

class TSW_Provider : public BAS_Provider
{
public:
    inline TSW_Provider() = default;

    IL_INSTANCE_DEC(TSW_Provider)

    void load(const ProjItem* data, UINT32 num);

    NOCOPY(TSW_Provider)
};

#endif // H_