#include <comparators/ostreamHelpers.h>

#include <cctype>

std::ostream& operator << (std::ostream& os, const FixChar&& d)
{
    const CHAR* p = &d.str[0];
    for (size_t n = 0; n < d.size; ++n, ++p)
    {
        // os << (isprint(*p) ? *p : OUT_NOPR_C);
        os << (UINT16) *p;
    }
    return os;
}
