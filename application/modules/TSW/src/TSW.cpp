#include <TSW/TSW.h>
#include <ddi/ddi.h>

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
        break;
    };
}

void TSW::swLeft()
{
    switch (mState)
    {
    case TSW_TO_GUI_LEFT:
    case TSW_TO_GUI_WAIT_LEFT:
        break;
    default:
        toFld(TSW_TO_FLD_LEFT);
        chgState(TSW_TO_GUI_WAIT_LEFT);
        break;
    }
}

void TSW::swRight()
{
    switch (mState)
    {
    case TSW_TO_GUI_RIGHT:
    case TSW_TO_GUI_WAIT_RIGHT:
        break;
    default:
        toFld(TSW_TO_FLD_RIGHT);
        chgState(TSW_TO_GUI_WAIT_RIGHT);
        break;
    }
}

void TSW::wu()
{
    switch(mState)
    {
    case TSW_TO_GUI_LEFT:
        toFld(TSW_TO_FLD_RIGHT);
        chgState(TSW_TO_GUI_WAIT_RIGHT);
        break;
    case TSW_TO_GUI_RIGHT:
        toFld(TSW_TO_FLD_LEFT);
        chgState(TSW_TO_GUI_WAIT_LEFT);
        break;
    default:
        break;
    };
}

void TSW::fromFld(const INT32 state)
{
    switch(state)
    {
    case TSW_FROM_FLD_LEFT:
        chgState(TSW_TO_GUI_LEFT);
        break;
    case TSW_FROM_FLD_RIGHT:
        chgState(TSW_TO_GUI_RIGHT);
        break;
    case TSW_FROM_FLD_UNDEF:
        chgState(TSW_TO_GUI_UNDEF);
        break;
    case TSW_FROM_FLD_DEFECT:
        chgState(TSW_TO_GUI_DEFECT);
        break;
    default:
        break;
    }
}

void TSW::chgState(INT32 state)
{
    if (state != mState)
    {
        mState = state;
        ddi::getTSW_Hub().toGui(mId, mState);
    }
}

void TSW::toFld(INT32 state) const
{
    ddi::getTSW_Hub().toFld(mId, state);
} 
