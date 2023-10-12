#pragma once
#ifndef BASECOMPERATOR_H
#define BASECOMPERATOR_H

#include <baselib/BaseTypes.h>
#include <baselib/InstanceMacros.h>
#include <sstream>
#include <iostream>
#include <cstring>

#include <CppUTest/SimpleString.h>
#include <CppUTestExt/MockNamedValue.h>

namespace test
{
    class CompStream
    {
    public:
        std::ostream& begin();
        inline const std::ostringstream& get() const
        {
            return mStream;
        }
        
        INSTANCE_DEC(CompStream)

    private:
        std::ostringstream mStream;
    };

    template <class T>
    class BaseComperator : public MockNamedValueComparator
    {
    public:
        SimpleString valueToString(CPTR ptr)
        {
            begin() << std::endl << *reinterpret_cast<const T*>(ptr);
            return get().str().c_str();
        }
        inline bool isEqual(CPTR ptr1, CPTR ptr2)
        {
            return std::memcmp(ptr1, ptr2, sizeof(T)) == 0;
        }
    protected:
        inline static std::ostream& begin()
        {
            return CompStream::instance().begin();
        }
        inline static const std::ostringstream& get()
        {
            return CompStream::instance().get();
        }

    }; 

}

#endif // H_