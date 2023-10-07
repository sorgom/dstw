
#include <TrackSwitch/TrackSwitch.h>

E_Result TrackSwitch::WU()
{
    switch(mState)
    {
    case TSW_TO_GUI_LEFT:
        mTrackSwitchToField.cmd(TSW_TO_FLD_RIGHT);
        chngState(TSW_TO_GUI_WAIT_RIGHT);
        break;
    case TSW_TO_GUI_RIGHT:
        mTrackSwitchToField.cmd(TSW_TO_FLD_LEFT);
        chngState(TSW_TO_GUI_WAIT_LEFT);
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

void TrackSwitch::rcv(E_RcvTswTromFld rcv)
{
    switch(rcv)
    {
    case TSW_FROM_FLD_LEFT:
        chngState(TSW_TO_GUI_LEFT);
        break;
    case TSW_FROM_FLD_RIGHT:
        chngState(TSW_TO_GUI_RIGHT);
        break;
    case TSW_FROM_FLD_UNDEF:
        chngState(TSW_TO_GUI_UNDEF);
        break;
    case TSW_FROM_FLD_DEFECT:
        chngState(TSW_TO_GUI_DEFECT);
        break;
    default:
        break;
    }
}

void TrackSwitch::chngState(E_CmdTswToGui state)
{
    if (state != mState)
    {
        mState = state;
        mTrackSwitchToGui.cmd(mState);
    }
}