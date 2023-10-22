
#pragma once
#ifndef BASELIB_H
#define BASELIB_H

#include <baselib/BaseTypes.h>
#include <baselib/coding.h>

void swapBytes(PTR pA, PTR pB, PTR pS, UINT32 size);

template <class T>
class Ref
{
public:
    inline Ref(const T& obj):
        mPtr(&obj)
    {}
    inline const T& ref() const
    {
        return *mPtr;
    }
private:
    const T* mPtr;

NOCOPY(Ref)
Ref();
};



#endif // H_