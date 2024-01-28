//  ============================================================
//  classes SIG_(X) implement I_SIG
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef SIG_X_H
#define SIG_X_H

#include <ifs/I_SIG.h>
#include <BAS/coding.h>

class SIG_X : public I_SIG
{
public:
    inline SIG_X(size_t id):
        mId(id),
        mStateToFld(SIG_STATE_UNDEF),
        mStateToGui(SIG_STATE_UNDEF)
    {}

protected:
    const size_t mId;
    INT32 mStateToFld;
    INT32 mStateToGui;

    void procFromFld(INT32 state);
    void procFromGui(INT32 stateFld, INT32 stateGui);

    static void logMismatch();

    NOCOPY(SIG_X)
    NODEF(SIG_X)
};

class SIG_XS : public SIG_X
{
public:
    inline SIG_XS(size_t id):
        SIG_X(id),
        mSpeedToFld(0),
        mSpeedToGui(0)
    {}

protected:
    INT32 mSpeedToFld;
    INT32 mSpeedToGui;

    void procFromFld(INT32 state, INT32 speed);
    void procFromGui(INT32 stateFld, INT32 stateGui, INT32 speed);
    void speedToFld(INT32 speed);

    NOCOPY(SIG_XS)
    NODEF(SIG_XS)
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
    inline SIG_H(size_t id): SIG_X(id) {}

    void fromFld(INT32 state, INT32 speed);
    void fromGui(INT32 state, INT32 speed);

    inline INT32 type() const { return SIG_TYPE_H; }

private:
    void proc_H0();
    void proc_H1();

    NOCOPY(SIG_H)
    NODEF(SIG_H)
};

//  ============================================================
//  SIG_N  support signal with speed indicator
//  handles:
//  - N0
//  - N1
//  - speed
//  ============================================================
class SIG_N : public SIG_XS
{
public:
    inline SIG_N(size_t id): SIG_XS(id) {}

    void fromFld(INT32 state, INT32 speed);
    void fromGui(INT32 state, INT32 speed);

    inline INT32 type() const { return SIG_TYPE_N; }

private:
    void proc_N0(INT32 speed);
    void proc_N1(INT32 speed);

    NOCOPY(SIG_N)
    NODEF(SIG_N)
};

//  ============================================================
//  SIG_H_N  main signal and support signal with speed indicator
//  handles:
//  - H0 N0
//  - H0 N1
//  - H1 N0
//  - H1 N1
//  - speed
//  ============================================================
class SIG_H_N : public SIG_XS
{
public:
    inline SIG_H_N(size_t id): SIG_XS(id) {}

    void fromFld(INT32 state, INT32 speed);
    void fromGui(INT32 state, INT32 speed);

    inline INT32 type() const { return SIG_TYPE_H_N; }

private:
    void proc_H0_N0(INT32 speed);
    void proc_H0_N1(INT32 speed);
    void proc_H1_N0(INT32 speed);
    void proc_H1_N1(INT32 speed);

    NOCOPY(SIG_H_N)
    NODEF(SIG_H_N)
};
#endif // _H
