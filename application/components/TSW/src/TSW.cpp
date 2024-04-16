#include <TSW/TSW.h>
#include <SYS/IL.h>

#include <qnd/useCout.h>

void TSW::process(const ComTeleGui& tele)
{
    const auto state = tele.param1;
    cout << "TSW::process GUI: " << (UINT16) state << endl;
    switch(state)
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
        IL::getLog().log(COMP_TSW, ERR_MATCH);
        break;
    };
}

void TSW::swLeft()
{
    cout << "TSW::swLeft" << endl;
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
    cout << "TSW::swRight" << endl;
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

void TSW::process(const ComTeleFld& tele)
{
    const auto state = tele.param1;
    cout << "TSW::process FLD: " << (UINT16) state << endl;
    switch(state)
    {
    case TSW_STATE_LEFT:
    case TSW_STATE_RIGHT:
    case TSW_STATE_UNDEF:
    case TSW_STATE_DEFECT:
        chgState(state);
        break;
    default:
        IL::getLog().log(COMP_TSW, ERR_MATCH);
        break;
    }
}

void TSW::chgState(const UINT8 state)
{
    if (state != mState)
    {
        cout << "TSW::chgState: " << (UINT16) state << endl;
        mState = state;
        cout << "TSW::toGui: " << (UINT16) mState << endl;
        IL::getDispatcher().dispatch(mId, ComTeleGui(mState));
    }
}

void TSW::toFld(const UINT8 state) const
{
    cout << "TSW::toFld: " << (UINT16) state << endl;
    IL::getDispatcher().dispatch(mId, ComTeleFld(state));
} 
