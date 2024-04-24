
#include <mocks/M_Dispatcher.h>
#include <mocks/M_Elem.h>
#include <mocks/M_Instances.h>
#include <mocks/M_Log.h>
#include <mocks/M_Provider.h>
#include <mocks/M_Tcp.h>

#include <BAS/coding.h>

namespace test
{

    INSTANCE_DEF(M_Com)
    INSTANCE_DEF(M_Dispatcher)
    INSTANCE_DEF(M_LCR_Provider)
    INSTANCE_DEF(M_LCR)
    INSTANCE_DEF(M_Log)
    INSTANCE_DEF(M_SIG_Provider)
    INSTANCE_DEF(M_SIG)
    INSTANCE_DEF(M_Tcp)
    INSTANCE_DEF(M_TSW_Provider)
    INSTANCE_DEF(M_TSW)
    
    std::ostringstream M_Base::mStream;
}
