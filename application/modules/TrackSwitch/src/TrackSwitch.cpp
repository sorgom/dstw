
#include <TrackSwitch/TrackSwitch.h>

E_Result TrackSwitch::WU()
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
    case TSW_TO_GUI_WAIT_LEFT:
    case TSW_TO_GUI_WAIT_RIGHT:
    case TSW_TO_GUI_UNDEF:
        break;
//  NO_COV >>
    default:
        break;
//  << NO_COV
    };
    return RESULT_OK;
}

void TrackSwitch::fromFld(const INT32 rcv)
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

void TrackSwitch::chgState(INT32 state)
{
    if (state != mState)
    {
        mState = state;
        ddi::getTrackSwitchPort().toGui(mId, mState);
    }
}

void TrackSwitch::toFld(INT32 state) const
{
    ddi::getTrackSwitchPort().toFld(mId, state);
} 


