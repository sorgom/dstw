//  ============================================================
//  name, type, position
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef NTPARRAY_H
#define NTPARRAY_H

#include <BAS/coding.h>
#include <codebase/Mem.h>
#include <BAS/StaticArray.h>
#include <ifs/ComTypes.h>

//  name, type, position
struct Ntp
{
    const ComName name;
    const UINT8 type;
    const size_t pos;
    inline Ntp(
        const ComName& name,
        UINT8 type = 0,
        size_t pos = 0
    ):
        name(name),
        type(type),
        pos(pos)
    {}
    NOCOPY(Ntp)
    NODEF(Ntp)
};

//  ============================================================
//  - storage of name, type, position
//  ============================================================
template <size_t CAP>
class NtpArray : 
    public ConstArray<Ntp, CAP>
{
public:
    inline NtpArray() = default;

    inline auto add(const ComName& name, UINT8 type, size_t pos)
    {
        return ConstArray<Ntp, CAP>::add(name, type, pos);
    }
    NOCOPY(NtpArray)
};

//  ============================================================
//  - index of name, type, position by name
//  ============================================================
template <size_t CAP>
class NtpIndex : 
    public ConstArrayIndex<Ntp, CAP>
{
private:
    using BaseT = ConstArrayIndex<Ntp, CAP>;
public:
    inline NtpIndex(const NtpArray<CAP>& a):
        BaseT(a)
    {}

    inline auto find(const ComName& name) const
    {
        return BaseT::find(Ntp(name));
    }
    NOCOPY(NtpIndex)
    NODEF(NtpIndex)

protected:
    inline bool isGreater(const Ntp& a, const Ntp& b) const final
    {
        return Mem::cmp(a.name.chars, b.name.chars) > 0;
    }
};

#endif // H_