//  ============================================================
//  class LCR_Provider implements I_Provider of level crossings
//  ============================================================
//  created by Manfred Sorgo

#ifndef LCR_PROVIDER_H
#define LCR_PROVIDER_H

#include <BAS/coding.h>
#include <BAS/BAS_Provider.h>

class LCR_Provider : public BAS_Provider<COMP_LCR>
{
public:
    INSTANCE_DEC(LCR_Provider)
    NOCOPY(LCR_Provider)
protected:
    bool add(size_t id, const ProjItem& item) final;
private:
    inline LCR_Provider() = default;
};
#endif // _H
