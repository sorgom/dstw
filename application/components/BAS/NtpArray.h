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

#include <codebase/packBegin.h>

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

#include <codebase/packEnd.h>

//  ============================================================
//  - storage of name, type, position
//  ============================================================
template <size_t CAP>
using NtpArray = ConstArray<Ntp, CAP>;

//  ============================================================
//  - index of name, type, position by name
//  ============================================================

template <size_t CAP>
using NtpIndexT = ConstArrayIndex<ComName, Ntp, CAP>;

template <size_t CAP>
class NtpIndex : public NtpIndexT<CAP>
{
public:
    inline NtpIndex(const NtpArray<CAP>& a):
        NtpIndexT<CAP>(a)
    {}

    NOCOPY(NtpIndex)
    NODEF(NtpIndex)

protected:
    inline const ComName& getKey(const Ntp& ntp) const final
    {
        return ntp.name;
    }

    inline bool isGreater(const ComName& a, const ComName& b) const override
    {
        return Mem::cmp(a.chars, b.chars) > 0;
    }
};

#endif // H_