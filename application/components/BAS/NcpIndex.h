//  ============================================================
//  name, component, position
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef NCPINDEX_H
#define NCPINDEX_H

#include <BAS/coding.h>
#include <BAS/Containers.h>
#include <ifs/ComTypes.h>

#include <codebase/packBegin.h>

struct Ncp
{
    const ComName name;
    const UINT8 comp;
    const size_t pos;
    inline Ncp(
        const ComName& name,
        UINT8 comp = 0,
        size_t pos = 0
    ):
        name(name),
        comp(comp),
        pos(pos)
    {}
    NOCOPY(Ncp)
};

#include <codebase/packEnd.h>

//  ============================================================
//  class NcpIndex is the core of Dispatcher
//  see interface I_Dispatcher
//  ============================================================
class NcpIndex : public Index<const ComName*, Ncp>
{
public:
    using BaseT = Index<const ComName*, Ncp>;
    inline NcpIndex() = default;
    NOCOPY(NcpIndex)

public:
    const PosRes find(const ComName& name) const
    {
        return BaseT::find(&name);
    }
protected:
    inline const ComName* getKey(const Ncp& ntp) const final
    {
        return &(ntp.name);
    }
    inline bool greater(const ComName* a, const ComName* b) const final
    {
        return Mem::cmp(a->chars, b->chars) > 0;
    }
};

#endif // H_