#include <SYS/IL.h>
#include <SYS/Com.h>

namespace IL
{
    I_Com& getCom() { return Com::instance(); }
} // namespace