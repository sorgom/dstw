//  ============================================================
//  class SIG_X implements I_SIG
//  - SIG_Main  main signal
//  - SIG_Supp  support signal with speed indicator
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef SIG_H
#define SIG_H

#include <ifs/I_SIG.h>
#include <baselib/coding.h>

class SIG : public I_SIG
{
public:
    inline SIG(
        UINT32 id
    ):
        mId(id),
        mState1(0),
        mState2(0),
        mState3(0)
    {}

protected:
    const UINT32 mId;
    INT32 mState1;
    INT32 mState2;
    INT32 mState3;

    NOCOPY(SIG)
};

class SIG_Main : public SIG
{
public:
    inline SIG_Main(
        UINT32 id
    ):
        SIG(id)
    {}
    inline void fromGui(INT32 cmd1, INT32 cmd2, INT32 cmd3)
    {
        fromGui(cmd1);
    }
    inline void fromFld(INT32 state1, INT32 state2, INT32 state3)
    {
        fromFld(state1);
    }
    inline INT32 type() const
    {
        return SIG_TYPE_MAIN;
    }
private:
    void fromGui(INT32 cmd);
    void fromFld(INT32 state);

    NOCOPY(SIG_Main)
};

class SIG_Supp : public SIG
{
public:
    inline SIG_Supp(
        UINT32 id
    ):
        SIG(id)
    {}
    inline void fromGui(INT32 cmd1, INT32 cmd2, INT32 cmd3)
    {
        fromGui(cmd1, cmd2);
    }
    inline void fromFld(INT32 state1, INT32 state2, INT32 state3)
    {
        fromFld(state1, state2);
    }
    inline INT32 type() const
    {
        return SIG_TYPE_SUPP;
    }
private:
    void fromGui(INT32 cmd, INT32 speed);
    void fromFld(INT32 state, INT32 speed);

    NOCOPY(SIG_Supp)
};
#endif // _H
