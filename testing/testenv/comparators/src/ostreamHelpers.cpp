#include <comparators/ostreamHelpers.h>

#include <cctype>

OSTREAM_DEF(FixChar)
{
    const CHAR* p = &d.str[0];
    for (size_t n = 0; n < d.size; ++n, ++p)
    {
        os << (isprint(*p) ? *p : OUT_NOPR_C);
    }
    return os;
}

const FixChar& getFixC(const CONST_C_STRING str, const size_t size)
{
    static FixChar fc;
    fc.str  = str;
    fc.size = size;
    return fc;
}