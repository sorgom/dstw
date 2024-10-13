//  ============================================================
//  utilities for complex ostream operators
//  ============================================================
//  created by Manfred Sorgo
#pragma once

#include <codebase/BaseTypes.h>
#include <BAS/coding.h>
#include <ostream>
#include <iomanip>

//  width for member names
#ifndef OUT_FILL_W
#define OUT_FILL_W 16
#endif

//  fill character
#ifndef OUT_FILL_C
#define OUT_FILL_C '.'
#endif

//  place holder for non printable characters
#ifndef OUT_NOPR_C
#define OUT_NOPR_C '*'
#endif

//  begin of ostream operator definition
#define OSTREAM_DEF(NAME) \
    std::ostream& operator << (std::ostream& os, const NAME& d)

//  begin of ostream operator declaration
#define OSTREAM_DEC(NAME) OSTREAM_DEF(NAME);

//  output line for standard types
#define DOUT(NAME) \
    std::setw(OUT_FILL_W) << std::setfill(OUT_FILL_C) << std::left << #NAME << ':' << ' ' << d.NAME << std::endl

//  output line for fixed character types
#define DFIX(NAME) \
    std::setw(OUT_FILL_W) << std::setfill(OUT_FILL_C) << std::left << #NAME << ':' << ' ' << fixC(d.NAME) << std::endl

//  helper struct for fixed character types
struct FixChar
{
    const CONST_C_STRING str;
    const size_t size;
    inline FixChar(const CONST_C_STRING str, const size_t size):
        str(str),
        size(size)
    {}
    NOCOPY(FixChar)
    NODEF(FixChar)
};

//  the streamable call
template <size_t N>
inline const FixChar fixC(const CHAR (&str)[N])
{
    return FixChar(str, N);
}

//  stream FixChar as rvalue
std::ostream& operator << (std::ostream& os, const FixChar&& d);

//  make sure UINT8 output is numerical
inline std::ostream& operator << (std::ostream& os, const UINT8 u)
{
    return os << static_cast<UINT16>(u);
}
