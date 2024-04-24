//  ============================================================
//  classes LCR_(X) implement I_LCR
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include <ifs/I_Elem.h>
#include <BAS/coding.h>
#include <ifs/values.h>

class LCR_X : public I_Elem
{
public:

    void fromGui(const ComData& data);

    NOCOPY(LCR_X)
    NODEF(LCR_X)

protected:
    inline LCR_X(size_t id):
        mId(id),
        mStateToGui(LCR_STATE_UNDEF)
    {}

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

    void fromFld(const ComData& data);

    inline E_Type type() const { return TYPE_LCR; }

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

    void fromFld(const ComData& data);

    inline E_Type type() const { return TYPE_LCR_UBK; }

    NOCOPY(LCR_UBK)
    NODEF(LCR_UBK)

protected:    
    void toGui() const;
private:
    UINT8 mUbkToGui;
    static bool validUbk(UINT8 ubk);
};
