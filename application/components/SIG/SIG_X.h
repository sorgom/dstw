//  ============================================================
//  classes SIG_(X) implement signal elements
//  ============================================================
//  created by Manfred Sorgo

#ifndef SIG_X_H
#define SIG_X_H

#include <ifs/values.h>
#include <ifs/I_Elem.h>
#include <BAS/coding.h>

class SIG_X : public I_Elem
{
public:
    void toGui() const override;

    NOCOPY(SIG_X)
    NODEF(SIG_X)

protected:
    inline SIG_X(size_t id):
        mId(id),
        mStateToFld(SIG_STATE_UNDEF),
        mStateToGui(SIG_STATE_UNDEF)
    {}

    const size_t mId;
    UINT8 mStateToFld;
    UINT8 mStateToGui;

    void procFromFld(UINT8 state);
    void procFromGui(UINT8 stateFld, UINT8 stateGui);

    void toFld(UINT8 state, UINT8 speed = PARAM_UNDEF) const;

    static void logMismatch();
};

class SIG_XS : public SIG_X
{
public:
    void toGui() const override;

    NOCOPY(SIG_XS)
    NODEF(SIG_XS)

protected:
    inline SIG_XS(size_t id):
        SIG_X(id),
        mSpeedToFld(0),
        mSpeedToGui(0)
    {}

    UINT8 mSpeedToFld;
    UINT8 mSpeedToGui;

    void procFromFld(UINT8 state, UINT8 speed);
    void procFromGui(UINT8 stateFld, UINT8 stateGui, UINT8 speed);
    void speedToFld(UINT8 speed);
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

    void fromFld(const ComData& data) override;
    void fromGui(const ComData& data) override;

    NOCOPY(SIG_H)
    NODEF(SIG_H)

private:
    void proc_H0();
    void proc_H1();
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

    void fromFld(const ComData& data) override;
    void fromGui(const ComData& data) override;

    NOCOPY(SIG_N)
    NODEF(SIG_N)

private:
    void proc_N0(UINT8 speed);
    void proc_N1(UINT8 speed);
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

    void fromFld(const ComData& data) override;
    void fromGui(const ComData& data) override;

    NOCOPY(SIG_H_N)
    NODEF(SIG_H_N)

private:
    void proc_H0_N0(UINT8 speed);
    void proc_H0_N1(UINT8 speed);
    void proc_H1_N0(UINT8 speed);
    void proc_H1_N1(UINT8 speed);
};
#endif // _H
