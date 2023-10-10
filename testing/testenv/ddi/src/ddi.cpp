#include <ddi/ddi.h>
#include "DDIPlug.h"

#include <mocks/M_Instances.h>
#include <baselib/InstanceMacros.h>


#define DDI_MEMB(NAME) \
    DDIPlug<I_ ## NAME> m ## NAME;

// default: application instance
#define DDI_CON(NAME) \
    m ## NAME(NAME::instance()),

//  default: mock only
#define DDI_CON_MOCK(NAME) \
    m ## NAME(test::m_ ## NAME()),

#define DDI_RESET(NAME) \
    m ## NAME.reset();

//  I_NAME& getNAME() { return DDI::instance().mNAME(); }
//  void setNAME(I_NAME& ref) { DDI::instance().mNAME = ref; } 
#define DDI_DEF(NAME) \
    I_ ## NAME& get ## NAME() { return DDI::instance().m ## NAME(); } \
    void set ## NAME(I_ ## NAME& ref) { DDI::instance().m ## NAME = ref; } 

namespace ddi
{
    class DDI
    {
    public:
        DDI();    
        INSTANCE_DEC(DDI)

        void reset();

        //# DDI_MEMB
        DDI_MEMB(SignalPort)
        DDI_MEMB(TrackSwitchPort)
        //# END
        int mTerm;
    };
    
    INSTANCE_DEF(DDI)
    
    DDI::DDI():
        //# DDI_CON
        DDI_CON(SignalPort)
        DDI_CON(TrackSwitchPort)
        //# END
        //# DDI_CON_MOCK
        DDI_CON_MOCK(SignalPort)
        DDI_CON_MOCK(TrackSwitchPort)
        //# END
        mTerm(0)
    {}

    void DDI::reset()
    {
        //# DDI_RESET
        DDI_RESET(SignalPort)
        DDI_RESET(TrackSwitchPort)
        //# END
    }

    //# DDI_DEF
    DDI_DEF(SignalPort)
    DDI_DEF(TrackSwitchPort)
    //# END

    void reset()
    {
        DDI::instance().reset();
    }
}
