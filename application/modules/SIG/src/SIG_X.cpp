#include <SIG/SIG_X.h>
#include <ddi/ddi.h>

void SIG::toGui() const
{
    ddi::getSIG_Hub().toGui(mId, mStateGui, mSpeed);
}

void SIG::toFld(const INT32 state, const INT32 speed) const
{
    ddi::getSIG_Hub().toFld(mId, state, speed);
}

void SIG_H::fromFld(const INT32 state, const INT32 speed)
{
    switch (state)
    {
    case SIG_STATE_H0:
    case SIG_STATE_H1:
    case SIG_STATE_UNDEF:
    case SIG_STATE_DEFECT:
        if (state != mStateGui)
        {
            mStateGui = state;
            toGui();
        }
    default:
        break;    
    };
}

void SIG_H::fromGui(const INT32 state, const INT32 speed)
{
    switch (state)
    {
    case SIG_STATE_H0:
    case SIG_STATE_H1:
        if (state != mStateGui)
        {
            toFld(state, 0);
            mStateGui = SIG_STATE_WAIT;
            toGui();
        }
    default:
        break;    
    };
}

void SIG_N::fromFld(const INT32 state, const INT32 speed)
{
    switch (state)
    {
    case SIG_STATE_N0:
    case SIG_STATE_N1:
    case SIG_STATE_UNDEF:
    case SIG_STATE_DEFECT:
        if ((state != mStateGui) or (speed != mSpeed))
        {
            mStateGui = state;
            mSpeed = speed;
            toGui();
        }
    default:
        break;    
    };
}

void SIG_N::fromGui(const INT32 state, const INT32 speed)
{
    switch (state)
    {
    case SIG_STATE_N0:
    case SIG_STATE_N1:
        if ((state != mStateGui) or (speed != mSpeed))
        {
            toFld(state, speed);
            mStateGui = SIG_STATE_WAIT;
            toGui();
        }
    default:
        break;    
    };
}

void SIG_H_N::fromFld(const INT32 state, const INT32 speed)
{
    switch (state)
    {
    case SIG_STATE_H0_N0:
    case SIG_STATE_H0_N1:
    case SIG_STATE_H1_N0:
    case SIG_STATE_H1_N1:
    case SIG_STATE_UNDEF:
    case SIG_STATE_DEFECT:
        if ((state != mStateGui) or (speed != mSpeed))
        {
            mStateGui = state;
            mSpeed = speed;
            toGui();
        }
     default:
        break;    
   };
}

void SIG_H_N::fromGui(const INT32 state, const INT32 speed)
{
    switch (state)
    {
    case SIG_STATE_H0_N0:
    case SIG_STATE_H0_N1:
    case SIG_STATE_H1_N0:
    case SIG_STATE_H1_N1:
        if ((state != mStateGui) or (speed != mSpeed))
        {
            toFld(state, speed);
            mStateGui = SIG_STATE_WAIT;
            toGui();
        }
    default:
        break;    
    };
}
