//  ============================================================
//  base CppUTest test group
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TESTGROUPBASE_H
#define TESTGROUPBASE_H

#include <testlib/CppUTest.h>

#include <BAS/Mem.h>
#include <comparators/ostreams.h>
#include <SYS/IL.h>
#include <mocks/M_Instances.h>
#include <setup/capacities.h>
#include <testlib/GenProjData.h>
#include <testlib/TestLib.h>
#include <testlib/TestLiterals.h>
#include <TestSteps/TestSteps.h>

namespace test
{
    class TestGroupBase : public Utest
    {
    protected:
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

#define L_CHECK_ELEMENT_NAME(exp, act) L_CHECK_EQUAL(0, Mem::cmp(exp, act))

#endif // _H














