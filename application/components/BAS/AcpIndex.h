//  ============================================================
//  addr, component, position
//  ============================================================
//  created by Manfred Sorgo

#ifndef ACPINDEX_H
#define ACPINDEX_H

#include <BAS/coding.h>
#include <BAS/Containers.h>
#include <ifs/DataTypes.h>

#include <codebase/packBegin.h>

struct Acp
{
    const ComAddr addr;
    const UINT8 comp;
    const size_t pos;
    inline Acp(
        const ComAddr& addr,
        UINT8 comp = 0,
        size_t pos = 0
    ):
        addr(addr),
        comp(comp),
        pos(pos)
    {}
    NOCOPY(Acp)
};

#include <codebase/packEnd.h>

//  ============================================================
//  class AcpIndex is the core of Dispatcher
//  see interface I_Dispatcher
//  ============================================================
class AcpIndex : public Index<const ComAddr&, Acp>
{
public:
    inline AcpIndex() = default;
    NOCOPY(AcpIndex)

protected:
    inline const ComAddr& getKey(const Acp& acp) const final
    {
        return acp.addr;
    }
};
#endif // _H
