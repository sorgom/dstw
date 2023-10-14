//  ============================================================
//  utilities complex ostream operators
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef OSTREAMHELPERS_H
#define OSTREAMHELPERS_H

#include <baselib/BaseTypes.h>
#include <ostream>
#include <iomanip>

#ifndef OUT_FILL_C
#define OUT_FILL_C '.'
#endif

#ifndef OUT_FILL_W
#define OUT_FILL_W 16
#endif

#ifndef OUT_NOPR_C
#define OUT_NOPR_C '*'
#endif


#define OSTREAM_DEF(NAME) \
    std::ostream& operator << (std::ostream& os, const NAME& d)

#define OSTREAM_DEC(NAME) OSTREAM_DEF(NAME);

#define DOUT(NAME) \
    std::setw(OUT_FILL_W) << std::setfill(OUT_FILL_C) << std::left << #NAME << ':' << ' ' << d.NAME << endl 

#define DFIX(NAME) \
    std::setw(OUT_FILL_W) << std::setfill(OUT_FILL_C) << std::left << #NAME << ':' << ' ' << fixC(d.NAME) << endl 

struct FixChar
{
    const CONST_C_STRING str;
    const size_t size;
    inline FixChar(const CONST_C_STRING str, const size_t size):
        str(str),
        size(size)
    {}
    inline FixChar(const FixChar& o):
        str(o.str),
        size(o.size)
    {}

private:
    FixChar();
    FixChar& operator =(const FixChar&);
};

template <size_t N>
inline FixChar fixC(const CHAR (&str)[N])
{
    return FixChar(str, N);
}

OSTREAM_DEC(FixChar)


#endif // H_