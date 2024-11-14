#include <comparators/installComparators.h>

#include <ifs/DataTypes.h>
#include <comparators/Comparator.h>
#include <comparators/ostreams.h>

#define ADD_COMP(NAME) \
    static Comparator<NAME> cmp_ ## NAME; \
    plugin.installComparator(#NAME, cmp_ ## NAME);

namespace test
{
    void installComparators(MockSupportPlugin& plugin)
    {
        ADD_COMP(ComAddr)
        ADD_COMP(ComData)
        ADD_COMP(ComTele)
    }
}
