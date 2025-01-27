//  ============================================================
//  base class for mocks
//  ============================================================
//  created by Manfred Sorgo

#ifndef M_BASE_H
#define M_BASE_H

#include <testlib/CppUTest.h>
#include <codebase/BaseTypes.h>
#include <BAS/coding.h>

#include <sstream>

namespace test
{
    class M_Base
    {
    protected:
        M_Base(const CONST_C_STRING name):
            mName(name)
        {}

        inline MockActualCall& call(const CONST_C_STRING meth) const
        {
            begin() << meth;
            return mkCall();
        }

        inline MockExpectedCall& expect(const CONST_C_STRING meth) const
        {
            begin() << meth;
            return mkExpect();
        }
        inline MockExpectedCall& expect(const UINT16 numCalls, const CONST_C_STRING meth) const
        {
            begin() << meth;
            return mkExpect(numCalls);
        }

        NOCOPY(M_Base)
        NODEF(M_Base)

    private:
        inline std::ostringstream& begin() const
        {
            mStream.str("");
            mStream << mName << "::";
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

        const CONST_C_STRING mName;
        static std::ostringstream mStream;
    };
} // namespace
#endif // _H
