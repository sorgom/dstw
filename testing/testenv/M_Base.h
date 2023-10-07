
#pragma once
#ifndef M_BASE_H
#define M_BASE_H

#include <testenv/CppUTest.h>
#include <BaseLib/BaseTypes.h>
#include <sstream>

namespace test
{
    //! Basisklasse fuer Mocks
    class M_Base
    {
    protected:
        //! Konstruktor mit Namen der gemockten Klasse
        //! e.g. "BATimer"
        M_Base(const CONST_C_STRING name):
            mName(name)
        {}

        const CONST_C_STRING mName;
        static std::ostringstream mStream;

        inline static std::ostringstream& prep()
        {
            mStream.str("");
            mStream << "I_";
            return mStream;
        }

        //! Standard Aufrufbeginn
        //! kann ueberlagert werden
        inline virtual std::ostringstream& begin() const
        {
            prep() << mName;
            return mStream;
        }

        //! Einen mock() Call kreieren / beginnen
        inline MockActualCall& mkCall(const CONST_C_STRING call) const
        {
            begin() << "::" << call;
            return mkCall();
        }

        inline static MockActualCall& mkCall()
        {
            return mock().actualCall(mStream.str().c_str());
        }

        //! Eine mock() Expectation kreieren / beginnen
        inline MockExpectedCall& mkExpect(const CONST_C_STRING call) const
        {
            begin() << "::" << call;
            return mkExpect();
        }

        //! Eine mock() Expectation kreieren / beginnen
        inline MockExpectedCall& mkExpect(const UINT16 numCalls, const CONST_C_STRING call) const
        {
            begin()  << "::" << call;
            return mkExpect(numCalls);
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
