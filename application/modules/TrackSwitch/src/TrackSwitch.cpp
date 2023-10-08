
#include <TrackSwitch/TrackSwitch.h>

E_Result TrackSwitch::WU()
{
    switch(mState)
    {
    case TSW_TO_GUI_LEFT:
        mPort.toFld(TSW_TO_FLD_RIGHT);
        chgState(TSW_TO_GUI_WAIT_RIGHT);
        break;
    case TSW_TO_GUI_RIGHT:
        mPort.toFld(TSW_TO_FLD_LEFT);
        chgState(TSW_TO_GUI_WAIT_LEFT);
        break;
    case TSW_TO_GUI_WAIT_LEFT:
    case TSW_TO_GUI_WAIT_RIGHT:
    case TSW_TO_GUI_UNDEF:
        break;
    default:
        break;    
    };
    return RES_OK;
}

void TrackSwitch::fromFld(E_TswTromFld rcv)
{
    switch(rcv)
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

void TrackSwitch::chgState(E_TswToGui state)
{
    if (state != mState)
    {
        mState = state;
        mPort.toGui(mState);
    }
}