#include <ddi/ddi.h>
#include "DDIPlug.h"

#include <baselib/InstanceMacros.h>


#define DDI_MEMB(NAME) \
    DDIPlug<I_ ## NAME> m ## NAME;

#define DDI_CON(NAME) \
    m ## NAME(NAME::instance()),

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
        DDI_MEMB(TrackSwitchPort)
        //# END
        int mTerm;
    };
    
    INSTANCE_DEF(DDI)
    
    DDI::DDI():
    //# DDI_CON
        DDI_CON(TrackSwitchPort)
    //# END
        mTerm(0)
    {}

    void DDI::reset()
    {
    //# DDI_RESET
        DDI_RESET(TrackSwitchPort)
    //# END
    }

    //# DDI_DEF
    DDI_DEF(TrackSwitchPort)
    //# END

    void reset()
    {
        DDI::instance().reset();
    }
}
