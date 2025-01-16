//  ============================================================
//  utilities for complex ostream operators
//  ============================================================
//  created by Manfred Sorgo
#ifndef OSTREAMHELPERS_H
#define OSTREAMHELPERS_H

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

//  standard output begin of elements
#define OUT_BEGIN(NAME) \
    std::setw(OUT_FILL_W) << std::setfill(OUT_FILL_C) << std::left << #NAME << ':' << ' '

//  output line for standard types
#define DOUT(NAME) \
    OUT_BEGIN(NAME) << d.NAME << '\n'

//  output line for fixed character types
#define DFIX(NAME) \
    OUT_BEGIN(NAME) << fixT(d.NAME) << '\n'

//  output line for UINT8 arrays
#define DU8X(NAME) \
    OUT_BEGIN(NAME) << fixU(d.NAME) << '\n'

//  helper struct for fixed array types
template <typename T>
struct FixArr
{
    const T *const ptr;
    const size_t size;
    inline FixArr(const T* ptr, const size_t size):
        ptr(ptr),
        size(size)
    {}
    NOCOPY(FixArr)
    NODEF(FixArr)
};

//  the streamable call
template <typename T, size_t N>
inline const FixArr<T> fixT(const T (&ptr)[N])
{
    return FixArr<T>(ptr, N);
}

//  stream FixChar as rvalue
std::ostream& operator << (std::ostream& os, const FixArr<CHAR>&& d);

//  make sure UINT8 output is numerical
inline std::ostream& operator << (std::ostream& os, const UINT8 u)
{
    return os << static_cast<UINT16>(u);
}
#endif // _H
