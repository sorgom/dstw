
#pragma once
#ifndef BASELIB_H
#define BASELIB_H

#include <baselib/BaseTypes.h>
#include <baselib/coding.h>

void swapBytes(PTR pA, PTR pB, PTR pS, UINT32 size);

template <class T>
class CRef
{
public:
    inline CRef(const T& obj):
        mPtr(&obj)
    {}
    inline const T& ref() const
    {
        return *mPtr;
    }
private:
    const T* mPtr;

    NOCOPY(CRef)
    CRef();
};



#endif // H_