//  ============================================================
//  class TSW_Provider implements I_Provider of track switches
//  ============================================================
//  created by Manfred Sorgo

#ifndef TSW_PROVIDER_H
#define TSW_PROVIDER_H

#include <BAS/coding.h>
#include <BAS/BAS_Provider.h>
#include <TSW/TSW.h>

class TSW_Provider : public BAS_Provider<COMP_TSW>
{
public:
    INSTANCE_DEC(TSW_Provider)

    NOCOPY(TSW_Provider)
protected:
    inline bool add(size_t id, const ProjItem& item) final
    {
        mElems.add<TSW>(id);
        return true;
    }
private:
    inline TSW_Provider() = default;
};
#endif // _H
