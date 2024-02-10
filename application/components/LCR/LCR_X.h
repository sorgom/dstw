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
    inline LCR_X(size_t id):
        mId(id),
        mStateToGui(LCR_STATE_UNDEF)
    {}
    void fromGui(UINT8 state);

    NOCOPY(LCR_X)
    NODEF(LCR_X)

protected:
    const size_t mId;
    UINT8 mStateToGui;

    void open();
    void close();

    void toFld(UINT8 state) const;

    virtual void toGui() const = 0;

    static bool validState(UINT8 state);
};

//  ============================================================
//  -   LCR without occupation control
//  ============================================================
class LCR : public LCR_X
{
public:
    inline LCR(size_t id): LCR_X(id) {}

    void fromFld(UINT8 state, UINT8 ubk);

    inline UINT8 type() const { return LCR_TYPE_LCR; }

    NOCOPY(LCR)
    NODEF(LCR)

protected:
    void toGui() const;
};

//  ============================================================
//  -   LCR with occupation control
//  ============================================================
class LCR_UBK : public LCR_X
{
public:
    inline LCR_UBK(size_t id): 
        LCR_X(id),
        mUbkToGui(LCR_UBK_STATE_UNDEF)
    {}

    void fromFld(UINT8 state, UINT8 ubk);

    inline UINT8 type() const { return LCR_TYPE_LCR_UBK; }

    NOCOPY(LCR_UBK)
    NODEF(LCR_UBK)

protected:    
    void toGui() const;
private:
    UINT8 mUbkToGui;
    static bool validUbk(UINT8 ubk);
};

#endif // _H
