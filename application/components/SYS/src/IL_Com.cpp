//  ============================================================
//  interface locator of application: module Log
//  - must be compiled into application runtime
//  - must not be compiled into any tests runtime
//  ============================================================
#include <SYS/IL.h>
#include <SYS/Com.h>

namespace IL
{
    I_Com& getCom() { return Com::instance(); }
} // namespace