#include <comparators/ostreamHelpers.h>

#include <cctype>

std::ostream& operator << (std::ostream& os, const FixArr<CHAR>&& d)
{
    const CHAR* p = &d.ptr[0];
    for (size_t n = 0; n < d.size; ++n, ++p)
    {
        os << (isprint(*p) ? *p : OUT_NOPR_C);
    }
    return os;
}
