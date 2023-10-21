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
    MOCK_DEF(TSW)
    MOCK_DEF(TSW_Hub)
    MOCK_DEF(TSW_Provider)
    //# END

    void mockAll()
    {
        //# MOCK_ACT
        MOCK_ACT(FldCom)
        MOCK_ACT(SignalPort)
        MOCK_ACT(TSW)
        MOCK_ACT(TSW_Hub)
        MOCK_ACT(TSW_Provider)
        //# END
    }
}