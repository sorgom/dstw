#include <comparators/Comparator.h>

namespace test
{
    std::ostringstream ComparatorBase::mStream;
    std::ostream& ComparatorBase::begin()
    {
        mStream.str("");
        return mStream << std::endl;
    }
}