//  ============================================================
//  class BAS_Provider: base class to implement I_Provider
//  - provides everything to satisfy 
//    an I_Provider derived interface
//  - except the load method which is too specific
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef BAS_PROVIDER_H
#define BAS_PROVIDER_H

#include <BAS/Containers.h>
#include <ifs/I_Provider.h>

class BAS_Provider : public I_Provider
{
public:
    inline BAS_Provider() = default;

    inline bool has(size_t pos) const
    {
        return mElems.size() > pos;
    }

    inline I_Elem& at(size_t pos)
    {
        return mElems.at(pos);
    }

    inline void reset()
    {
        mElems.clear();
    }

    void load(const ProjItem* data, UINT32 num);
    
protected:
    virtual bool add(size_t pos, const ProjItem& item) = 0;
    virtual UINT8 getComp() const = 0;

    PolyVec<I_Elem> mElems;
};


#endif // H_