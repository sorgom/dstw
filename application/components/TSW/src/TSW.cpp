#include <TSW/TSW.h>
#include <SYS/IL.h>

void TSW::fromGui(const INT32 cmd)
{
    switch(cmd)
    {
    case TSW_GUI_GMD_WU:
        wu();
        break;
    case TSW_GUI_GMD_LEFT:
        swLeft();
        break;
    case TSW_GUI_GMD_RIGHT:
        swRight();
        break;
    default:
        IL::getLog().log(MOD_TSW, ERR_MATCH);
        break;
    };
}

void TSW::swLeft()
{
    switch (mState)
    {
    case TSW_STATE_LEFT:
    case TSW_STATE_WAIT_LEFT:
    case TSW_STATE_DEFECT:
        break;
    default:
        toFld(TSW_STATE_LEFT);
        chgState(TSW_STATE_WAIT_LEFT);
        break;
    }
}

void TSW::swRight()
{
    switch (mState)
    {
    case TSW_STATE_RIGHT:
    case TSW_STATE_WAIT_RIGHT:
    case TSW_STATE_DEFECT:
        break;
    default:
        toFld(TSW_STATE_RIGHT);
        chgState(TSW_STATE_WAIT_RIGHT);
        break;
    }
}

void TSW::wu()
{
    switch(mState)
    {
    case TSW_STATE_LEFT:
        toFld(TSW_STATE_RIGHT);
        chgState(TSW_STATE_WAIT_RIGHT);
        break;
    case TSW_STATE_RIGHT:
        toFld(TSW_STATE_LEFT);
        chgState(TSW_STATE_WAIT_LEFT);
        break;
    default:
        break;
    };
}

void TSW::fromFld(const INT32 state)
{
    switch(state)
    {
    case TSW_STATE_LEFT:
    case TSW_STATE_RIGHT:
    case TSW_STATE_UNDEF:
    case TSW_STATE_DEFECT:
        chgState(state);
        break;
    default:
        IL::getLog().log(MOD_TSW, ERR_MATCH);
        break;
    }
}

void TSW::chgState(INT32 state)
{
    if (state != mState)
    {
        mState = state;
        IL::getTSW_Hub().toGui(mId, mState);
    }
}

void TSW::toFld(INT32 state) const
{
    IL::getTSW_Hub().toFld(mId, state);
} 
