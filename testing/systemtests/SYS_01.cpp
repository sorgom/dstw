//  ============================================================
//  system tests vol. 1
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>

#include <qnd/useCout.h>

namespace test
{

    TEST_GROUP_BASE(SYS_01, TestGroupBase)
    {
        
    };

    //  test type: blackbox test
    //  
    TEST(SYS_01, T01)
    {
        SETUP()
        GenProjData<> projData;
        mock_FldCom();
        ddi::getLoader().load(projData);

        L_CHECK_TRUE(ddi::getTSW_Provider().has(CAPACITY_TSW - 1))

        STEP(1)
        //  send TSW field state to dispatcher
        FldState fldState;
        genElementName(fldState.name, CAPACITY_TSW, "TSW");
        fldState.state = TSW_FROM_FLD_LEFT;
        cout << fldState.name << endl;


        StateGui stateGui;
        Mem::copy(stateGui.name, fldState.name);
        stateGui.state = TSW_TO_GUI_LEFT;

        m_FldCom().expectSend(stateGui);
        ddi::getDispatcher().dispatch(fldState);


    }


}
