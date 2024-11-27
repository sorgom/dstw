//  ============================================================
//  base CppUTest test group
//  ============================================================
//  created by Manfred Sorgo

#ifndef TESTGROUPBASE_H
#define TESTGROUPBASE_H

#include <testlib/CppUTest.h>

#include <codebase/Mem.h>
#include <comparators/ostreams.h>
#include <ifs/values.h>
#include <mocks/M_Instances.h>
#include <SYS/IL.h>
#include <testlib/GenProjData.h>
#include <testlib/TestLib.h>
#include <testlib/testValues.h>
#include <TestSteps/TestSteps.h>

namespace test
{
    class TestGroupBase : public Utest
    {
    protected:
        inline void teardown()
        {
            CHECK_N_CLEAR()
        }

    };

} // namespace
#endif // _H
