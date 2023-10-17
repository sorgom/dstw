//  ============================================================
//  type & position mapping based on ElementName
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef NAMETYPEPOSMAP_H
#define NAMETYPEPOSMAP_H

#include <baselib/StaticArrays.h>
#include <ifs/DataTypes.h>
#include <baselib/Mem.h>

struct NameTypePos
{
    ElementName name;
    INT32 type;
    UINT32 pos;
};

const NameTypePos& getNameTypePos(
    const ElementName& name, 
    INT32 type = 0, 
    UINT32 pos = 0);

template<UINT32 CAP>
class NameTypePosMap : public SearchableStaticArray<NameTypePos, CAP>
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
    inline INT32 addNtp(const ElementName& eName, INT32 type, UINT32 pos)
    {
        return this->add(getNameTypePos(eName, type, pos));
    }
    inline INT32 searchName(const ElementName& eName)
    {
        return this->search(getNameTypePos(eName));
    }
};


#endif // H_