//  ============================================================
//  base CppUTest test group
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include <testlib/CppUTest.h>

#include <ifs/values.h>
#include <codebase/Mem.h>
#include <comparators/ostreams.h>
#include <SYS/IL.h>
#include <mocks/M_Instances.h>
#include <testlib/testNumElements.h>
#include <testlib/GenProjData.h>
#include <testlib/TestLib.h>
#include <TestSteps/TestSteps.h>

namespace test
{
    class TestGroupBase : public Utest
    {
    protected:
        enum E_TestVals: UINT8
        {
            NO_PARAM = PARAM_UNDEF - 1,
            PARAM_UNKNOWN = PARAM_UNDEF - 2,

        };
        inline TestGroupBase()
        {
            mockAll();
        }

        inline void teardown()
        {
            CHECK_N_CLEAR()
        }

    };

} // namespace














