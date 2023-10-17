#include <baselib/ByteArrays.h>
#include <baselib/coding.h>
#include <cstring>

#define BPOS(pos) \
    mBytes + mStep * pos

void ByteArray::reset()
{
    mSize = 0;
}

PTR ByteArray::getPtr(const UINT32 pos) const
{
    PTR p = 0;
    if ((pos < mSize) or isRef(pos))
    {
        p = BPOS(pos);
    }
    else { pass(); }
    return p;
}

PTR ByteArray::addPtr()
{
    PTR p = 0;
    if (mSize < mCap)
    {
        p = BPOS(mSize);
        ++mSize;
    }
    else { pass(); }
    return p;
}

INT32 ByteArray::addBytes(const CPTR ptr, const UINT32 bytes)
{
    INT32 pos = -1;
    if (bytes == mStep)
    {
        const PTR p = addPtr();
        if (p != 0)    
        {
            memcpy(p, ptr, mStep);
            pos = mSize - 1;
        }
        else { pass(); }
    }
    else { pass(); }
    return pos;
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

void SearchableByteArray::swappBytes(const UINT32 posA, const UINT32 posB) const
{
    if (posA == posB)
    { pass(); }
    else if (okPos(posA, posB))
    {
        const PTR pS = BPOS(mCap);
        const PTR pA = BPOS(posA);
        const PTR pB = BPOS(posB);
        memcpy(pS, pB, mStep);
        memcpy(pB, pA, mStep);
        memcpy(pA, pS, mStep);
    }
    else { pass(); }
}

UINT32 SearchableByteArray::getSearchBytePos() const
{
    return mCap;
}

void SearchableByteArray::setSearchBytes(const CPTR ptr, const UINT32 bytes) const
{
    if (bytes == mStep)
    {
        const PTR pS = BPOS(mCap);
        memcpy(pS, ptr, mStep);
    }
    else { pass(); }
}
