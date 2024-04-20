#include <mocks/ILPlugs.h>

namespace IL
{
    I_Com& getCom() { return test::ILPLugs::instance().mCom.ref(); }
} // namespace