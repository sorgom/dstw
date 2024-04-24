//  ============================================================
//  class SIG_Provider implements I_SIG_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include <BAS/coding.h>
#include <BAS/BAS_Provider.h>

class SIG_Provider : public BAS_Provider
{
public:
    inline SIG_Provider() = default;

    INSTANCE_DEC(SIG_Provider)

    NOCOPY(SIG_Provider)
protected:
    bool add(size_t id, const ProjItem& item) final;
    inline E_Comp comp() const final { return COMP_SIG; }; 
};
