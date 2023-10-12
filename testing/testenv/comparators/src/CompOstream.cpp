#include <comparators/CompOstream.h>

namespace test
{
    INSTANCE_DEF(CompOstream)

    std::ostream& CompOstream::begin()
    {
        mStream.str("");
        return mStream << std::endl;
    }

}