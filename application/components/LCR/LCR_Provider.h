//  ============================================================
//  class LCR_Provider implements I_LCR_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef LCR_PROVIDER_H
#define LCR_PROVIDER_H

#include <BAS/coding.h>
#include <BAS/BAS_Provider.h>
#include <ifs/I_LCR.h>
#include <ifs/I_LCR_Provider.h>
#include <ifs/SystemEnums.h>

class LCR_Provider : 
    public BAS_Provider<I_LCR, ProjLCR>
{
public:
    inline LCR_Provider() = default;

    ILX_INSTANCE_DEC(LCR_Provider)

    NOCOPY(LCR_Provider)

    void load(const ProjLCR* data, UINT32 num) final;
};


#endif // H_