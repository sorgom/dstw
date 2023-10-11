#pragma once
#ifndef DDIPLUG_H
#define DDIPLUG_H

template <class T>
class DDIPlug
{
public:
    inline DDIPlug(T& ref):
        mDefault(ref),
        mPointer(&ref)
    {}

    inline void operator =(T& ref)
    {
        mPointer = &ref;
    }

    inline void reset()
    {
        mPointer = &mDefault;
    }

    inline T& operator()() const
    {
        return *mPointer;
    }

private:
    T& mDefault;
    T* mPointer;
    DDIPlug();
};
#endif // _H
