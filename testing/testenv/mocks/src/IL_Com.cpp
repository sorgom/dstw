#include <mocks/ILPlugs.h>

namespace IL
{
    I_Com& getCom() { return ILPLugs::instance().mCom.ref(); }
} // namespace