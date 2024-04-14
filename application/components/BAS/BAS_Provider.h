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

template <typename I_ELEM, typename PROJ, typename I_PROV>
class BAS_Provider : public I_PROV
{
public:
    inline BAS_Provider() = default;

    inline bool has(size_t pos) const
    {
        return mElems.size() > pos;
    }

    inline I_ELEM& at(size_t pos)
    {
        return mElems.at(pos);
    }

    inline void reset()
    {
        mElems.clear();
    }

protected:
    PolyVec<I_ELEM> mElems;
};


#endif // H_