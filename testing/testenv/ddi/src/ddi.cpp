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
        DDI_MEMB(Dispatcher)
        DDI_MEMB(FldCom)
        DDI_MEMB(Loader)
        DDI_MEMB(SIG_Hub)
        DDI_MEMB(TSW)
        DDI_MEMB(TSW_Hub)
        DDI_MEMB(TSW_Provider)
        //# END
        int mTerm;
    };
    
    INSTANCE_DEF(DDI)
    
    DDI::DDI():
        //# DDI_CON : APP
        DDI_CON(Dispatcher)
        DDI_CON(Loader)
        DDI_CON(TSW_Hub)
        DDI_CON(TSW_Provider)
        //# END
        //# DDI_CON_MOCK : MOCK
        DDI_CON_MOCK(FldCom)
        DDI_CON_MOCK(SIG_Hub)
        DDI_CON_MOCK(TSW)
        //# END
        mTerm(0)
    {}

    void DDI::reset()
    {
        //# DDI_RESET
        DDI_RESET(Dispatcher)
        DDI_RESET(FldCom)
        DDI_RESET(Loader)
        DDI_RESET(SIG_Hub)
        DDI_RESET(TSW)
        DDI_RESET(TSW_Hub)
        DDI_RESET(TSW_Provider)
        //# END
    }

    //# DDI_DEF
    DDI_DEF(Dispatcher)
    DDI_DEF(FldCom)
    DDI_DEF(Loader)
    DDI_DEF(SIG_Hub)
    DDI_DEF(TSW)
    DDI_DEF(TSW_Hub)
    DDI_DEF(TSW_Provider)
    //# END

    void reset()
    {
        DDI::instance().reset();
    }
}
