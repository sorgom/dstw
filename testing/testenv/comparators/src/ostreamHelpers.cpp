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
