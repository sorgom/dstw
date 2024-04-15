//  ============================================================
//  class SIG_Provider implements I_SIG_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef SIG_PROVIDER_H
#define SIG_PROVIDER_H

#include <BAS/coding.h>
#include <BAS/BAS_Provider.h>

class SIG_Provider : public BAS_Provider
{
public:
    inline SIG_Provider() = default;

    IL_INSTANCE_DEC(SIG_Provider)

    void load(const ProjItem* data, UINT32 num);

    NOCOPY(SIG_Provider)
};


#endif // H_