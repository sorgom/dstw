//  ============================================================
//  class SIG_X implements I_SIG
//  - SIG_H  main signal
//  - SIG_N  support signal with speed indicator
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef SIG_X_H
#define SIG_X_H

#include <ifs/I_SIG.h>
#include <baselib/coding.h>

class SIG : public I_SIG
{
public:
    inline SIG(UINT32 id):
        mId(id),
        mStateGui(SIG_STATE_UNDEF),
        mSpeed(0)
    {}

protected:
    const UINT32 mId;
    INT32 mStateGui;
    INT32 mSpeed;

    void toGui() const;
    void toFld(INT32 state, INT32 speed) const;

    NOCOPY(SIG)
    SIG();
};

class SIG_H : public SIG
{
public:
    inline SIG_H(UINT32 id): SIG(id) {}

    void fromFld(INT32 state, INT32 speed);
    void fromGui(INT32 state, INT32 speed);

    inline INT32 type() const
    {
        return SIG_TYPE_H;
    }
private:
    NOCOPY(SIG_H)
    SIG_H();
};

class SIG_N : public SIG
{
public:
    inline SIG_N(UINT32 id): SIG(id) {}

    void fromFld(INT32 state, INT32 speed);
    void fromGui(INT32 state, INT32 speed);

    inline INT32 type() const
    {
        return SIG_TYPE_N;
    }

    NOCOPY(SIG_N)
    SIG_N();
};

class SIG_H_N : public SIG
{
public:
    inline SIG_H_N(UINT32 id): SIG(id) {}

    void fromFld(INT32 state, INT32 speed);
    void fromGui(INT32 state, INT32 speed);

    inline INT32 type() const
    {
        return SIG_TYPE_H_N;
    }

    NOCOPY(SIG_H_N)
    SIG_H_N();
};
#endif // _H
