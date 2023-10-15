#include <baselib/StaticArray.h>

#include <cstring>
using std::memcpy;
using std::memcmp;

void StaticArrayBase::reset()
{
    mSize = 0;
}
PTR StaticArrayBase::getPtr(const UINT32 pos) const
{
    PTR p = 0;
    if (pos < mSize)
    {
        p = mBytes + (mStep * pos);
    }
    else { pass(); }
    return p;
}
PTR StaticArrayBase::addPtr()
{
    PTR p = 0;
    if (mSize < mCap)
    {
        p = mBytes + (mStep * mSize);
        ++mSize;
    }
    else { pass(); }
    return p;
}

bool StaticArrayBase::addBytes(const CPTR ptr, const UINT32 bytes)
{
    bool ok = false;
    if (bytes == mStep)
    {
        const PTR p = addPtr();
        if (p != 0)    
        {
            memcpy(p, ptr, mStep);
            ok = true;
        }
        else { pass(); }
    }
    else { pass(); }
    return ok;
}

UINT32 StaticArrayBase::getSize() const
{
    return mSize;
}

bool StaticArrayBase::okPos(const UINT32 posA, const UINT32 posB) const
{
    bool ok = false;
    if (posA < mSize) 
    {
        if (posB < mSize)
        {
            ok = true;
        }
        else { pass(); }
    }
    else { pass(); }
    return ok;
}

INT32 StaticArrayBase::cmpPos(const UINT32 posA, const UINT32 posB) const
{
    const CPTR pA = mBytes + (mStep * posA);
    const CPTR pB = mBytes + (mStep * posB);
    return memcmp(pA, pB, mStep);
}

void StaticArrayBase::swappBytes(const UINT32 posA, const UINT32 posB) const
{
    if (posA == posB)
    { pass(); }
    else if (okPos(posA, posB))
    {
        const PTR pS = mBytes + (mStep * mCap);
        const PTR pA = mBytes + (mStep * posA);
        const PTR pB = mBytes + (mStep * posB);
        memcpy(pS, pB, mStep);
        memcpy(pB, pA, mStep);
        memcpy(pA, pS, mStep);
    }
    else { pass(); }
}

bool StaticArrayBase::isGreaterBytes(const UINT32 posA, const UINT32 posB) const
{
    bool res = false;
    if (posA == posB)
    { pass(); }
    else if (okPos(posA, posB))
    {
        res = cmpPos(posA, posB) > 0;
    }
    else { pass(); }
    return res;
}

bool StaticArrayBase::isEqualBytes(const UINT32 posA, const UINT32 posB) const
{
    bool res = false;
    if (posA == posB)
    {
        res = true;
    }
    else if (okPos(posA, posB))
    {
        res = cmpPos(posA, posB) == 0;
    }
    else { pass(); }
    return res;
}

void StaticArrayBase::setSearchBytes(const CPTR ptr, const UINT32 bytes)
{
    if (bytes == mStep)
    {
        const PTR pS = mBytes + (mStep * mCap);
        memcpy(pS, ptr, mStep);
    }
    else { pass(); }
}
