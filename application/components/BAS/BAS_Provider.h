//  ============================================================
//  class BAS_Provider: base class to implement I_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef BAS_PROVIDER_H
#define BAS_PROVIDER_H

#include <BAS/Containers.h>
#include <ifs/I_Provider.h>

template <typename ELEM, typename PROJ, typename IF>
class BAS_Provider : public IF
{
public:
    inline BAS_Provider() = default;

    inline bool has(size_t pos) const
    {
        return mElems.size() > pos;
    }

    inline ELEM& at(size_t pos)
    {
        return mElems.at(pos);
    }

    inline void reset()
    {
        mElems.clear();
    }

protected:
    PolyVec<ELEM> mElems;
};


#endif // H_