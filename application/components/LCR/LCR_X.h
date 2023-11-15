//  ============================================================
//  classes LCR_(X) implement I_LCR
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef LCR_X_H
#define LCR_X_H

#include <ifs/I_LCR.h>
#include <BAS/coding.h>

class LCR_X : public I_LCR
{
public:
    inline LCR_X(UINT32 id):
        mId(id),
        mStateToGui(LCR_STATE_UNDEF),
        mUbkToGui(LCR_UBK_STATE_UNDEF)
    {}

    void fromGui(INT32 state);

protected:
    const UINT32 mId;
    INT32 mStateToGui;
    INT32 mUbkToGui;

    void open();
    void close();

    void toFld(INT32 state) const;
    void toGui() const;

    virtual INT32 getUbkToGui() const = 0;

    static bool validState(INT32 state);
    static bool validUbk(INT32 ubk);

    NOCOPY(LCR_X)
    LCR_X();
};

//  ============================================================
//  -   LCR without occupation control
//  ============================================================
class LCR : public LCR_X
{
public:
    inline LCR(UINT32 id): LCR_X(id) {}

    void fromFld(INT32 state, INT32 ubk);

    inline INT32 type() const { return LCR_TYPE_LCR; }

protected:
    inline INT32 getUbkToGui() const { return LCR_UBK_STATE_UNDEF; }

private:
    NOCOPY(LCR)
    LCR();
};

//  ============================================================
//  -   LCR with occupation control
//  ============================================================
class LCR_UBK : public LCR_X
{
public:
    inline LCR_UBK(UINT32 id): LCR_X(id) {}

    void fromFld(INT32 state, INT32 ubk);

    inline INT32 type() const { return LCR_TYPE_LCR_UBK; }

protected:    
    inline INT32 getUbkToGui() const { return mUbkToGui; }

private:
    NOCOPY(LCR_UBK)
    LCR_UBK();
};

#endif // _H
