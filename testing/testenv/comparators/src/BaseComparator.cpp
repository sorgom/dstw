#include <comparators/BaseComparator.h>

namespace test
{
    INSTANCE_DEF(CompStream)

    std::ostringstream& CompStream::begin()
    {
        mStream.str("");
        return mStream;
    }

}