//  ============================================================
//  class BAS_Provider: base class to implement I_Provider
//  - provides almost everything to satisfy
//    an I_Provider derived interface
//  To be defined by derived classes:
//  - add: to add an element to the provider
//  - comp: to return the component identifier
//  ============================================================
//  created by Manfred Sorgo

#ifndef BAS_PROVIDER_H
#define BAS_PROVIDER_H

#include <BAS/Containers.h>
#include <ifs/I_Provider.h>

class X_Provider : public I_Provider
{
public:
    inline size_t size() const final
    {
        return mElems.size();
    }

    inline I_Elem& at(size_t pos) final
    {
        return mElems.at(pos);
    }

    inline void clear() final
    {
        mElems.clear();
    }

    void load(const ProjItem* data, UINT32 num) final;

protected:
    //  individual add method
    virtual bool add(size_t id, const ProjItem& item) = 0;

    //  individual component
    virtual E_Comp comp() const = 0;

    PolyVec<I_Elem> mElems;
};

template <E_Comp COMP>
class BAS_Provider : public X_Provider
{
protected:
    inline E_Comp comp() const final { return COMP; }
};
#endif // _H
