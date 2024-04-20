//  ============================================================
//  name, component, position
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef NCPINDEX_H
#define NCPINDEX_H

#include <BAS/coding.h>
#include <BAS/Containers.h>
#include <ifs/DataTypes.h>

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
class NcpIndex : public Index<const ComName&, Ncp>
{
public:
    inline NcpIndex() = default;
    NOCOPY(NcpIndex)

protected:
    inline const ComName& getKey(const Ncp& ntp) const final
    {
        return ntp.name;
    }
};

#endif // H_