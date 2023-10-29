#include <mocks/M_Base.h>
#include <mocks/M_Instances.h>

#define MOCK_DEF(NAME) \
    INSTANCE_DEF(M_ ## NAME)

#define MOCK_ACT(NAME) \
    mock_ ## NAME();

namespace test
{
    std::ostringstream M_Base::mStream;

    //# MOCK_DEF
    MOCK_DEF(Com)
    MOCK_DEF(Dispatcher)
    MOCK_DEF(SIG)
    MOCK_DEF(SIG_Hub)
    MOCK_DEF(SIG_Provider)
    MOCK_DEF(TSW)
    MOCK_DEF(TSW_Hub)
    MOCK_DEF(TSW_Provider)
    //# END

    void mockAll()
    {
        //# MOCK_ACT
        MOCK_ACT(Com)
        MOCK_ACT(Dispatcher)
        MOCK_ACT(SIG)
        MOCK_ACT(SIG_Hub)
        MOCK_ACT(SIG_Provider)
        MOCK_ACT(TSW)
        MOCK_ACT(TSW_Hub)
        MOCK_ACT(TSW_Provider)
        //# END
    }
}