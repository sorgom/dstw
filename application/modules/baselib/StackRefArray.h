#pragma once
#ifndef STACKREFARRAY_H
#define STACKREFARRAY_H

#include <baselib/StackArray.h>

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
    //  Standard 8.1.1
    Ref();
    Ref(const Ref& o);
    Ref& operator=(const Ref& o);
};

template <class T, UINT32 CAP>
class StackRefArray : public StackArray<Ref<T>, CAP>
{
public:
    inline StackRefArray(const StackArray<T, CAP>& a):
        mArray(a)
    {}

    inline bool isGreater(const Ref<T>& a, const Ref<T>& b) const
    {
        return mArray.isGreater(a.ref(), b.ref());
    }

    void adapt()
    {
        this->reset();
        for (UINT32 p = 0; p < mArray.size(); ++p)
        {
            new (this->addPtr()) Ref<T>(mArray[p]);
        }
        this->sort();
    }

    inline const T& getRef(UINT32 pos)
    {
        return this->at(pos).ref();
    }

private:
    const StackArray<T, CAP>& mArray;
};

#endif // H_