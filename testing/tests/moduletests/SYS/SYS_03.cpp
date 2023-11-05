//  ============================================================
//  test of modules Com, Log (coverage)
//  ============================================================
//  created by Manfred Sorgo
#include <testlib/TestGroupBase.h>
#include <SYS/Com.h>
#include <SYS/Log.h>

namespace test
{
    TEST_GROUP_BASE(SYS_03, TestGroupBase) {};

    //  test type: coverage
    TEST(SYS_03, T01)
    {
        const StateGui s = {0};
        const CmdFld   c = {0};
        Com::instance().send(s);
        Com::instance().send(c);
        Log::instance().log(MOD_LOADER, ERR_MATCH);
    }
}