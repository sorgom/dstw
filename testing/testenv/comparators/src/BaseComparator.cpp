#include <comparators/BaseComparator.h>

namespace test
{
    INSTANCE_DEF(CompStream)

    std::ostream& CompStream::begin()
    {
        mStream.str("");
        return mStream << std::endl;
    }

}