#include <comparators/installComparators.h>
#include <comparators/BaseComparator.h>
#include <comparators/ostreams.h>
#include <testlib/TestLiterals.h>

#include <ifs/DataTypes.h>

#define ADD_COMP(NAME) \
    static BaseComperator<NAME> cmp_ ## NAME; \
    plugin.installComparator(c__ ## NAME, cmp_ ## NAME);

namespace test
{
    void installComparators(MockSupportPlugin& plugin)
    {
        //# ADD_COMP
        ADD_COMP(RastaTelegram)
        //# END
    }
}
