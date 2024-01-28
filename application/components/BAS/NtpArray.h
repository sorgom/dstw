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
#include <ifs/DataTypes.h>

//  name, type, position
struct Ntp
{
    ElementName name;
    INT32 type;
    size_t pos;
    Ntp() = default;
    Ntp(
        const ElementName& name,
        INT32 type = 0,
        size_t pos = 0
    );
    NOCOPY(Ntp)
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

    inline auto add(const ElementName& name, INT32 type, size_t pos)
    {
        return StaticArray<Ntp, CAP>::newC(name, type, pos);
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

    inline auto find(const ElementName& name) const
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