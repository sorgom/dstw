//  ============================================================
//  class LCR_Provider implements I_LCR_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef LCR_PROVIDER_H
#define LCR_PROVIDER_H

#include <BAS/coding.h>
#include <BAS/BAS_Provider.h>
#include <ifs/I_Provider.h>

class LCR_Provider : public BAS_Provider
{
public:
    inline LCR_Provider() = default;

    IL_INSTANCE_DEC(LCR_Provider)

    void load(const ProjItem* data, UINT32 num) final;

    NOCOPY(LCR_Provider)
};


#endif // H_