//  ============================================================
//  classes SIG_(X) implement I_SIG
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef SIG_X_H
#define SIG_X_H

#include <ifs/I_SIG.h>
#include <baselib/coding.h>

class SIG_X : public I_SIG
{
public:
    inline SIG_X(UINT32 id):
        mId(id),
        mStateToFld(SIG_STATE_UNDEF),
        mSpeedToFld(0),
        mStateToGui(SIG_STATE_UNDEF),
        mSpeedToGui(0)
    {}

protected:
    const UINT32 mId;
    INT32 mStateToFld;
    INT32 mSpeedToFld;
    INT32 mStateToGui;
    INT32 mSpeedToGui;

    void procFromFld(INT32 state, INT32 speed);
    void procFromGui(INT32 state, INT32 speed);

    NOCOPY(SIG_X)
    SIG_X();
};

//  ============================================================
//  SIG_H  main signal without speed indicator
//  handles:
//  - H0
//  - H1
//  ============================================================
class SIG_H : public SIG_X
{
public:
    inline SIG_H(UINT32 id): SIG_X(id) {}

    void fromFld(INT32 state, INT32 speed);
    void fromGui(INT32 state, INT32 speed);

    inline INT32 type() const { return SIG_TYPE_H; }

private:
    NOCOPY(SIG_H)
    SIG_H();
};

//  ============================================================
//  SIG_N  support signal with speed indicator
//  handles:
//  - N0
//  - N1
//  - speed
//  ============================================================
class SIG_N : public SIG_X
{
public:
    inline SIG_N(UINT32 id): SIG_X(id) {}

    void fromFld(INT32 state, INT32 speed);
    void fromGui(INT32 state, INT32 speed);

    inline INT32 type() const { return SIG_TYPE_N; }

    NOCOPY(SIG_N)
    SIG_N();
};

//  ============================================================
//  SIG_H_N  main signal and support signal with speed indicator
//  handles:
//  - H0N0
//  - H0N1
//  - H1N0
//  - H1N1
//  - speed
//  ============================================================
class SIG_H_N : public SIG_X
{
public:
    inline SIG_H_N(UINT32 id): SIG_X(id) {}

    void fromFld(INT32 state, INT32 speed);
    void fromGui(INT32 state, INT32 speed);

    inline INT32 type() const { return SIG_TYPE_H_N; }

    NOCOPY(SIG_H_N)
    SIG_H_N();
};
#endif // _H
