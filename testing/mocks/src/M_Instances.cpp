#include <mocks/M_Instances.h>

#define MOCK_DEF(NAME) \
    M_ ## NAME& m_ ## NAME() \
    { \
        static M_ ## NAME instance; \
        return instance; \
    }

namespace test
{
    //# MOCK_DEF
    MOCK_DEF(TrackSwitchPort)
    //# END
}