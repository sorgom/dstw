#pragma once
#ifndef NTPINDEX_H
#define NTPINDEX_H

#include <BAS/coding.h>
#include <BAS/Containers.h>
#include <ifs/ComTypes.h>

#include <codebase/packBegin.h>

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
};

#include <codebase/packEnd.h>

class NtpIndex : public Index<ComName, Ntp>
{
public:
    inline NtpIndex() = default;
    NOCOPY(NtpIndex)
protected:
    inline const ComName& getKey(const Ntp& ntp) const final
    {
        return ntp.name;
    }
    inline bool greater(const ComName& a, const ComName& b) const final
    {
        return Mem::cmp(a.chars, b.chars) > 0;
    }
};

#endif // H_