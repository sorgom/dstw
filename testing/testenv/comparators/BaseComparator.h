#pragma once
#ifndef BASECOMPERATOR_H
#define BASECOMPERATOR_H

#include <baselib/BaseTypes.h>
#include <baselib/InstanceMacros.h>
#include <sstream>
#include <cstring>

#include <CppUTest/SimpleString.h>
#include <CppUTestExt/MockNamedValue.h>

namespace test
{
    class CompStream
    {
    public:
        std::ostringstream& begin();
        inline const std::ostringstream& get() const
        {
            return mStream;
        }
        
        INSTANCE_DEC(CompStream)

    private:
        std::ostringstream mStream;
    };

    inline std::ostringstream& beginStr()
    {
        return CompStream::instance().begin();
    }
    inline const std::ostringstream& getStr()
    {
        return CompStream::instance().get();
    }

    template <class T>
    class BaseComperator : public MockNamedValueComparator
    {
    public:
        SimpleString valueToString(CPTR ptr)
        {
            beginStr() << *reinterpret_cast<const T*>(ptr);
            return getStr().str().c_str();
        }
        inline bool isEqual(CPTR ptr1, CPTR ptr2)
        {
            return std::memcmp(ptr1, ptr2, sizeof(T)) == 0;
        }
    }; 

}

#endif // H_