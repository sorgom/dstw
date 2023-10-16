#include <baselib/ByteArrays.h>
#include <baselib/coding.h>
#include <cstring>

void ByteArray::reset()
{
    mSize = 0;
}

PTR ByteArray::getPtr(const UINT32 pos) const
{
    PTR p = 0;
    if (pos < mSize)
    {
        p = mBytes + (mStep * pos);
    }
    else if (isRef(pos))
    {
        p = mBytes + (mStep * pos);
    }
    else { pass(); }
    return p;
}

PTR ByteArray::addPtr()
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

bool ByteArray::addBytes(const CPTR ptr, const UINT32 bytes)
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

UINT32 ByteArray::getSize() const
{
    return mSize;
}

bool ByteArray::okPos(const UINT32 posA, const UINT32 posB) const
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

void ByteArrayMappable::swappBytes(const UINT32 posA, const UINT32 posB) const
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

UINT32 ByteArrayMappable::getSearchBytePos() const
{
    return mCap;
}

void ByteArrayMappable::setSearchBytes(const CPTR ptr, const UINT32 bytes) const
{
    if (bytes == mStep)
    {
        const PTR pS = mBytes + (mStep * mCap);
        memcpy(pS, ptr, mStep);
    }
    else { pass(); }
}
