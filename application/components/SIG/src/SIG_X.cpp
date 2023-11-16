#include <SIG/SIG_X.h>
#include <SYS/IL.h>

void SIG_X::procFromFld(const INT32 state, INT32 speed)
{
    //  field values are only forwarded to GUI
    //  if GUI state or GUI speed differs
    bool ok = (mStateToGui != state);

    switch (state)
    {
        case SIG_STATE_UNDEF:
        case SIG_STATE_DEFECT:
            speed = 0;
            break;
        default:
            ok = ok or (
                speedUsed() and
                (mSpeedToGui != speed)
            );
            break;
    }

    if (ok)
    {
        mStateToGui = state;
        mSpeedToGui = speed;
        IL::getSIG_Hub().toGui(mId, mStateToGui, mSpeedToGui);
    }
    else
    {pass();}
}

void SIG_X::procFromGui(const INT32 stateFld, const INT32 stateGui, const INT32 speed)
{
    mStateToFld = stateFld;
    mSpeedToFld = speed;
    mStateToGui = stateGui;
    IL::getSIG_Hub().toFld(mId, mStateToFld, mSpeedToFld);
    IL::getSIG_Hub().toGui(mId, mStateToGui, mSpeedToGui);
}

void SIG_X::speedToFld(const INT32 speed)
{
    switch (mStateToFld)
    {
        case SIG_STATE_UNDEF:
            break;
        default:
            if (speed != mSpeedToFld)
            {
                mSpeedToFld = speed;
                IL::getSIG_Hub().toFld(mId, mStateToFld, mSpeedToFld);
            }
            break;    
    };
}

void SIG_X::logMissmatch()
{
    IL::getLog().log(MOD_SIG, ERR_MATCH);
}

void SIG_H::fromFld(const INT32 state, const INT32 speed)
{
    switch (state)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_DEFECT:
    case SIG_STATE_H0:
    case SIG_STATE_H1:
        procFromFld(state, 0);
        break;    
    default:
        logMissmatch();
        break;    
    };
}

void SIG_H::fromGui(const INT32 state, const INT32 speed)
{
    switch (state)
    {
    case SIG_STATE_H0:
        proc_H0();
        break;    
    case SIG_STATE_H1:
        proc_H1();
        break;    
    default:
        logMissmatch();
        break;    
    };
}

void SIG_H::proc_H0()
{
    switch (mStateToGui)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_H1:
    case SIG_STATE_WAIT_H1:
        procFromGui(SIG_STATE_H0, SIG_STATE_WAIT_H0, 0);
        break;
    default:
        break;
    }
}

void SIG_H::proc_H1()
{
    switch (mStateToGui)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_H0:
    case SIG_STATE_WAIT_H0:
        procFromGui(SIG_STATE_H1, SIG_STATE_WAIT_H1, 0);
        break;
    default:
        break;
    }
}

void SIG_N::fromFld(const INT32 state, const INT32 speed)
{
    switch (state)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_DEFECT:
    case SIG_STATE_N0:
    case SIG_STATE_N1:
        procFromFld(state, speed);
        break;    
    default:
        logMissmatch();
        break;    
    };
}

void SIG_N::fromGui(const INT32 state, const INT32 speed)
{
    switch (state)
    {
    case SIG_STATE_N0:
        proc_N0(speed);
        break;    
    case SIG_STATE_N1:
        proc_N1(speed);
        break;    
    default:
        logMissmatch();
        break;    
    };
}

void SIG_N::proc_N0(const INT32 speed)
{
    switch (mStateToGui)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_N1:
    case SIG_STATE_WAIT_N1:
        procFromGui(SIG_STATE_N0, SIG_STATE_WAIT_N0, speed);
        break;
    default:
        speedToFld(speed);
        break;
    }
}

void SIG_N::proc_N1(const INT32 speed)
{
    switch (mStateToGui)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_N0:
    case SIG_STATE_WAIT_N0:
        procFromGui(SIG_STATE_N1, SIG_STATE_WAIT_N1, speed);
        break;
    default:
        speedToFld(speed);
        break;
    }
}


void SIG_H_N::fromFld(const INT32 state, const INT32 speed)
{
    switch (state)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_DEFECT:
    case SIG_STATE_H0_N0:
    case SIG_STATE_H0_N1:
    case SIG_STATE_H1_N0:
    case SIG_STATE_H1_N1:
        procFromFld(state, speed);
        break;    
    default:
        logMissmatch();
        break;    
    };
}

void SIG_H_N::fromGui(const INT32 state, const INT32 speed)
{
    switch (state)
    {
    case SIG_STATE_H0_N0:
        proc_H0_N0(speed);
        break;    
    case SIG_STATE_H0_N1:
        proc_H0_N1(speed);
        break;    
    case SIG_STATE_H1_N0:
        proc_H1_N0(speed);
        break;    
    case SIG_STATE_H1_N1:
        proc_H1_N1(speed);
        break;    
    default:
        logMissmatch();
        break;    
    };
}

void SIG_H_N::proc_H0_N0(const INT32 speed)
{
    switch (mStateToGui)
    {
    case SIG_STATE_UNDEF:

    case SIG_STATE_H0_N1:
    case SIG_STATE_H1_N0:
    case SIG_STATE_H1_N1:

    case SIG_STATE_WAIT_H0_N1:
    case SIG_STATE_WAIT_H1_N0:
    case SIG_STATE_WAIT_H1_N1:
        procFromGui(SIG_STATE_H0_N0, SIG_STATE_WAIT_H0_N0, speed);
        break;
    default:
        speedToFld(speed);
        break;
    }

}
void SIG_H_N::proc_H0_N1(const INT32 speed)
{
    switch (mStateToGui)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_H0_N0:

    case SIG_STATE_H1_N0:
    case SIG_STATE_H1_N1:
    case SIG_STATE_WAIT_H0_N0:

    case SIG_STATE_WAIT_H1_N0:
    case SIG_STATE_WAIT_H1_N1:
        procFromGui(SIG_STATE_H0_N1, SIG_STATE_WAIT_H0_N1, speed);
        break;
    default:
        speedToFld(speed);
        break;
    }
    
}
void SIG_H_N::proc_H1_N0(const INT32 speed)
{
    switch (mStateToGui)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_H0_N0:
    case SIG_STATE_H0_N1:

    case SIG_STATE_H1_N1:
    case SIG_STATE_WAIT_H0_N0:
    case SIG_STATE_WAIT_H0_N1:

    case SIG_STATE_WAIT_H1_N1:
        procFromGui(SIG_STATE_H1_N0, SIG_STATE_WAIT_H1_N0, speed);
        break;
    default:
        speedToFld(speed);
        break;
    }
    
}
void SIG_H_N::proc_H1_N1(const INT32 speed)
{
    switch (mStateToGui)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_H0_N0:
    case SIG_STATE_H0_N1:
    case SIG_STATE_H1_N0:

    case SIG_STATE_WAIT_H0_N0:
    case SIG_STATE_WAIT_H0_N1:
    case SIG_STATE_WAIT_H1_N0:

        procFromGui(SIG_STATE_H1_N1, SIG_STATE_WAIT_H1_N1, speed);
        break;
    default:
        speedToFld(speed);
        break;
    }
}

