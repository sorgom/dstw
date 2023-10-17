//  ============================================================
//  telegram mapping based on ElementName type
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef TELEMAPPER_H
#define TELEMAPPER_H

#include <baselib/StaticArrays.h>
#include <ifs/DataTypes.h>
#include <baselib/Mem.h>

struct NameNum
{
    ElementName name;
    UINT32 num;
};

const NameNum& getNameNum(const ElementName& name, UINT32 num = 0);


template<UINT32 CAP>
class TeleMap : public StaticArrayMappable<NameNum, CAP>
{
public:
    inline bool isGreater(UINT32 posA, UINT32 posB) const
    {
        return Mem::cmp(this->at(posA).name, this->at(posB).name) > 0;
    }
    inline bool isEqual(UINT32 posA, UINT32 posB) const
    {
        return Mem::cmp(this->at(posA).name, this->at(posB).name) == 0;
    }
    inline INT32 find(const ElementName& eName)
    {
        const INT32 p = this->search(getNameNum(eName));
        return (p < 0 ? p : this->at(p).num);
    }
    inline bool addName(const ElementName& eName)
    {
        return this->add(getNameNum(eName, this->size()));
    }
};

template<UINT32 CAP>
class TeleMapper
{
public:

    //  add element
    //  return position
    inline bool add(const ElementName& name)
    {
        return mMap.add(getNameNum(name, mMap.size()));
    }

    //  add element
    //  return position
    inline INT32 search(const ElementName& name)
    {
        return mMap.search(getNameNum(name));
    }

    inline void reset()
    {
        mMap.reset();
    }

    inline void sort()
    {
        mMap.sort();
    }
private:
    TeleMap<CAP> mMap;
};

#endif // H_