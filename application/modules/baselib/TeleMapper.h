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
};

class GetNameNum
{
protected:
    static const NameNum& getNameNum(const ElementName& name, UINT32 num = 0);
private:
    static NameNum mNameNum;
};

template<UINT32 CAP>
class TeleMapper : private GetNameNum
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