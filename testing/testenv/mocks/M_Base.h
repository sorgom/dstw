//  ============================================================
//  base class for mocks
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_BASE_H
#define M_BASE_H

#include <testlib/CppUTest.h>

#include <BAS/BaseTypes.h>
#include <BAS/coding.h>
#include <testlib/TestLiterals.h>

#include <sstream>

//  standard mock class begin
#define MOCK_CLASS(NAME) \
    class M_ ## NAME : \
        public I_ ## NAME, \
        private M_Base

//  standard constructor with test literals
#define MOCK_CON(NAME) \
    inline M_ ## NAME(): \
        M_Base(c__ ## NAME) \
    {} \
    static M_ ## NAME& instance();

namespace test
{
    class M_Base
    {
    protected:
        M_Base(const CONST_C_STRING name):
            mName(name)
        {}

        const CONST_C_STRING mName;
        static std::ostringstream mStream;

        inline virtual std::ostringstream& begin() const
        {
            prep() << mName;
            return mStream;
        }

        inline MockActualCall& call(const CONST_C_STRING meth) const
        {
            begin() << "::" << meth;
            return mkCall();
        }

        inline MockExpectedCall& expect(const CONST_C_STRING meth) const
        {
            begin() << "::" << meth;
            return mkExpect();
        }

        inline MockExpectedCall& expect(const UINT16 numCalls, const CONST_C_STRING meth) const
        {
            begin()  << "::" << meth;
            return mkExpect(numCalls);
        }

    private:
        inline static std::ostringstream& prep()
        {
            mStream.str("");
            mStream << "I_";
            return mStream;
        }
        inline static MockActualCall& mkCall()
        {
            return mock().actualCall(mStream.str().c_str());
        }
        inline static MockExpectedCall& mkExpect()
        {
            return mock().expectOneCall(mStream.str().c_str());
        }

        inline static MockExpectedCall& mkExpect(const UINT16 numCalls)
        {
            return mock().expectNCalls(numCalls, mStream.str().c_str());
        }

        NOCOPY(M_Base)
    };
} // namespace
#endif // _H
