//  ============================================================
//  name, type, position
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef NTPARRAY_H
#define NTPARRAY_H

#include <BAS/coding.h>
#include <BAS/Mem.h>
#include <BAS/StaticArray.h>
#include <ifs/ComTypes.h>

//  name, type, position
struct Ntp
{
    const ComName name;
    const INT32 type;
    const size_t pos;
    inline Ntp(
        const ComName& name,
        INT32 type = 0,
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
    public StaticArray<Ntp, CAP>
{
public:
    inline NtpArray() = default;

    inline auto add(const ComName& name, INT32 type, size_t pos)
    {
        return StaticArray<Ntp, CAP>::add(name, type, pos);
    }
    NOCOPY(NtpArray)
};

//  ============================================================
//  - index of name, type, position by name
//  ============================================================
template <size_t CAP>
class NtpIndex : 
    public StaticIndex<Ntp, CAP>
{
private:
    using BaseT = StaticIndex<Ntp, CAP>;
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
    inline bool isGreater(const Ntp& a, const Ntp& b) const
    {
        return Mem::cmp(a.name, b.name) > 0;
    }
};

#endif // H_