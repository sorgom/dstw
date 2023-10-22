#include <SIG/SIG.h>

E_Result SIG::HN0()
{
    mHub.toFld(SIG_TO_FLD_HN0);
    chgState(SIG_TO_GUI_WAIT_HN0);
    return RESULT_OK;
}

E_Result SIG::HN1()
{
    mHub.toFld(SIG_TO_FLD_HN1);
    chgState(SIG_TO_GUI_WAIT_HN1);
    return RESULT_OK;
}

void SIG::fromFld(E_SigTromFld rcv)
{
    switch(rcv)
    {
    case SIG_FROM_FLD_HN0:
        chgState(SIG_TO_GUI_HN0);
        break;
    case SIG_FROM_FLD_HN1:
        chgState(SIG_TO_GUI_HN1);
        break;
    case SIG_FROM_FLD_UNDEF:
        chgState(SIG_TO_GUI_UNDEF);
        break;
    case SIG_FROM_FLD_DEFECT:
        chgState(SIG_TO_GUI_DEFECT);
        break;
//  NO_COV >>
    default:
        break;
//  << NO_COV
    }
}

void SIG::chgState(E_SigToGui state)
{
    if (state != mState)
    {
        mState = state;
        mHub.toGui(mState);
    }
}
