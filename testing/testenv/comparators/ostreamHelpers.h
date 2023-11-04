//  ============================================================
//  utilities for complex ostream operators
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef OSTREAMHELPERS_H
#define OSTREAMHELPERS_H

#include <BAS/BaseTypes.h>
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
    std::setw(OUT_FILL_W) << std::setfill(OUT_FILL_C) << std::left << #NAME << ':' << ' ' << d.NAME << endl 

//  output line for fixed character types
#define DFIX(NAME) \
    std::setw(OUT_FILL_W) << std::setfill(OUT_FILL_C) << std::left << #NAME << ':' << ' ' << fixC(d.NAME) << endl 

//  helper struct for fixed character types
struct FixChar
{
    CONST_C_STRING str;
    size_t size;
};

//  helper struct creator 
const FixChar& getFixC(CONST_C_STRING str, size_t size);

//  the streamable call
template <size_t N>
inline FixChar fixC(const CHAR (&str)[N])
{
    return getFixC(str, N);
}

OSTREAM_DEC(FixChar)


#endif // H_