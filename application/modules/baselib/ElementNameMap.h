//  ============================================================
//  position mapping based on ElementName type
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef ELEMENTNAMEMAP_H
#define ELEMENTNAMEMAP_H

#include <baselib/StaticArrays.h>
#include <ifs/DataTypes.h>
#include <baselib/Mem.h>

struct NamePos
{
    ElementName name;
    UINT32 pos;
};

const NamePos& getNamePos(const ElementName& name, UINT32 pos = 0);

template<UINT32 CAP>
class ElementNameMap : public StaticArrayMappable<NamePos, CAP>
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
        const INT32 p = this->search(getNamePos(eName));
        return (p < 0 ? p : this->at(p).pos);
    }
    inline bool addName(const ElementName& eName)
    {
        return this->add(getNamePos(eName, this->size()));
    }
};


#endif // H_