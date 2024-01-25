//  ============================================================
//  name, type, position
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef NTPARRAY_H
#define NTPARRAY_H

#include <BAS/coding.h>
#include <BAS/Mem.h>
#include <BAS/StackArray.h>
#include <ifs/DataTypes.h>

//  name, type, position
struct Ntp
{
    ElementName name;
    INT32 type;
    UINT32 pos;
};

//  generates Ntp struct from name [, type, position]
class GenNtp
{
protected:
    static const Ntp& genNtp(
        const ElementName& name,
        INT32 type = 0,
        UINT32 pos = 0
    );

    inline GenNtp() {}

    NOCOPY(GenNtp)
};

//  ============================================================
//  - storage of name, type, position
//  ============================================================
template <UINT32 CAP>
class NtpArray : 
    public StackArray<Ntp, CAP>,
    private GenNtp
{
public:
    inline NtpArray() {}

    inline UINT32 addNtp(const ElementName& name, INT32 type, UINT32 pos)
    {
        return this->add(genNtp(name, type, pos));
    }

    NOCOPY(NtpArray)
};

//  ============================================================
//  - index of name, type, position by name
//  ============================================================
template <UINT32 CAP>
class NtpIndex : 
    public StackArrayIndex<Ntp, CAP>,
    private GenNtp
{
public:
    inline NtpIndex(const NtpArray<CAP>& a):
        StackArrayIndex<Ntp, CAP>(a)
    {}

    inline INT32 findNtp(const ElementName& name) const
    {
        return this->findRef(genNtp(name));
    }
protected:
    inline bool isGreater(const Ntp& a, const Ntp& b) const
    {
        return Mem::cmp(a.name, b.name) > 0;
    }

    NOCOPY(NtpIndex)
    NtpIndex();
};

#endif // H_