//  ============================================================
//  class LCR_Provider implements I_LCR_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef LCR_PROVIDER_H
#define LCR_PROVIDER_H

#include <BAS/coding.h>
#include <BAS/BAS_Provider.h>

class LCR_Provider : public BAS_Provider
{
public:
    INSTANCE_DEC(LCR_Provider)
    NOCOPY(LCR_Provider)
protected:
    bool add(size_t id, const ProjItem& item) final;
    inline E_Comp comp() const final { return COMP_LCR; };
private:
    inline LCR_Provider() = default;
};
#endif // _H
