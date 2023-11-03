#include <comparators/installComparators.h>

#include <ifs/DataTypes.h>
#include <comparators/Comparator.h>
#include <comparators/ostreams.h>
#include <testlib/TestLiterals.h>

#define ADD_COMP(NAME) \
    static Comparator<NAME> cmp_ ## NAME; \
    plugin.installComparator(c__ ## NAME, cmp_ ## NAME);

namespace test
{
    void installComparators(MockSupportPlugin& plugin)
    {
        //# ADD_COMP
        ADD_COMP(CmdFld)
        ADD_COMP(ElementName)
        ADD_COMP(FldState)
        ADD_COMP(GuiCmd)
        ADD_COMP(StateGui)
        //# END
    }
}
