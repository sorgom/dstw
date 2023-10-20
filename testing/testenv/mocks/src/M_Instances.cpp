#include <mocks/M_Instances.h>

#define MOCK_DEF(NAME) \
    INSTANCE_DEF(M_ ## NAME)

#define MOCK_ACT(NAME) \
    mock_ ## NAME();

namespace test
{
    //# MOCK_DEF
    MOCK_DEF(FldCom)
    MOCK_DEF(SignalPort)
    MOCK_DEF(TrackSwitch)
    MOCK_DEF(TrackSwitchHub)
    MOCK_DEF(TrackSwitchProvider)
    //# END

    void mockAll()
    {
        //# MOCK_ACT
        MOCK_ACT(FldCom)
        MOCK_ACT(SignalPort)
        MOCK_ACT(TrackSwitch)
        MOCK_ACT(TrackSwitchHub)
        MOCK_ACT(TrackSwitchProvider)
        //# END
    }
}