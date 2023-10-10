
#pragma once
#ifndef M_BASE_H
#define M_BASE_H

#include <testlib/CppUTest.h>
#include <BaseLib/BaseTypes.h>
#include <sstream>

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
    };
} // namespace
#endif // _H
