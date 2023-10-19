#include <mocks/M_Instances.h>

#define MOCK_DEF(NAME) \
    INSTANCE_DEF(M_ ## NAME)

namespace test
{
    //# MOCK_DEF
    MOCK_DEF(FldCom)
    MOCK_DEF(SignalPort)
    MOCK_DEF(TrackSwitch)
    MOCK_DEF(TrackSwitchFactory)
    MOCK_DEF(TrackSwitchHub)
    //# END
}