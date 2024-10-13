
#include <mocks/M_Instances.h>

#include <mocks/M_Dispatcher.h>
#include <mocks/M_Elem.h>
#include <mocks/M_Log.h>
#include <mocks/M_Provider.h>
#include <mocks/M_Reader.h>
#include <mocks/M_TCP_Con.h>
#include <mocks/M_TCP_Listener.h>
#include <mocks/M_TCP.h>

#include <BAS/coding.h>

namespace test
{

    INSTANCE_DEF(M_Com)
    INSTANCE_DEF(M_Dispatcher)
    INSTANCE_DEF(M_LCR_Provider)
    INSTANCE_DEF(M_LCR)
    INSTANCE_DEF(M_Log)
    INSTANCE_DEF(M_Reader)
    INSTANCE_DEF(M_SIG_Provider)
    INSTANCE_DEF(M_SIG)
    INSTANCE_DEF(M_TCP)
    INSTANCE_DEF(M_TSW_Provider)
    INSTANCE_DEF(M_TSW)
    INSTANCE_DEF(M_TCP_Con_Fld)
    INSTANCE_DEF(M_TCP_Con_Gui)
    INSTANCE_DEF(M_TCP_Con_Ctrl)
    INSTANCE_DEF(M_TCP_Listener_Fld)
    INSTANCE_DEF(M_TCP_Listener_Gui)
    INSTANCE_DEF(M_TCP_Listener_Ctrl)

    std::ostringstream M_Base::mStream;
}
