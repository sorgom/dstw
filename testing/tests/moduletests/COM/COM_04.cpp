//  ============================================================
//  test of COM TCP runtime
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <COM/Com.h>

namespace test
{

    TEST_GROUP_BASE(COM_04, TestGroupBase)
    {
        void expectStartupOk()
        {
            m_Reader().expectGetComSetup();
            m_TCP().expectInit(true);
            m_TCP_Listener_Fld().expectListen(tcpPortFld, true);
            m_TCP_Listener_Gui().expectListen(tcpPortGui, true);
            m_TCP_Listener_Ctrl().expectListen(tcpPortCtrl, true);
            m_TCP().expectSetTimeout(tcpTimeout);
        }

        void expectExit()
        {
            m_TCP_Listener_Fld().expectClose();
            m_TCP_Listener_Gui().expectClose();
            m_TCP_Listener_Ctrl().expectClose();
            m_TCP_Con_Fld().expectClose();
            m_TCP_Con_Gui().expectClose();
            m_TCP_Con_Ctrl().expectClose();
            m_TCP().expectCleanup();
        }

        void expectExitStartup()
        {
            m_Log().expectLog(COMP_COM, RET_ERR_STARTUP);
            expectExit();
        }

        void expectExitRuntime()
        {
            m_Log().expectLog(COMP_COM, RET_ERR_COM);
            expectExit();
        }
    };

    //  test type: equivalence class test
    //  Com startup failures
    TEST(COM_04, T01)
    {
        SETUP()
        I_Com& com = Com::instance();

        //  TCP init fails
        STEP(1)
        m_Reader().expectGetComSetup();
        m_TCP().expectInit(false);
        expectExitStartup();
        com.run();
        CHECK_N_CLEAR()

        //  listener field fails
        STEP(2)
        m_Reader().expectGetComSetup();
        m_TCP().expectInit(true);
        m_TCP_Listener_Fld().expectListen(tcpPortFld, false);
        expectExitStartup();
        com.run();
        CHECK_N_CLEAR()

        //  listener GUI fails
        STEP(3)
        m_Reader().expectGetComSetup();
        m_TCP().expectInit(true);
        m_TCP_Listener_Fld().expectListen(tcpPortFld, true);
        m_TCP_Listener_Gui().expectListen(tcpPortGui, false);
        expectExitStartup();
        com.run();
        CHECK_N_CLEAR()

        //  listener control fails
        STEP(4)
        m_Reader().expectGetComSetup();
        m_TCP().expectInit(true);
        m_TCP_Listener_Fld().expectListen(tcpPortFld, true);
        m_TCP_Listener_Gui().expectListen(tcpPortGui, true);
        m_TCP_Listener_Ctrl().expectListen(tcpPortCtrl, false);
        expectExitStartup();
        com.run();
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  Com startup success and runtime select failing
    TEST(COM_04, T02)
    {
        SETUP()
        I_Com& com = Com::instance();

        //  select on listener field fails
        STEP(1)
        expectStartupOk();
        expectExitRuntime();
        m_TCP_Listener_Fld().expectSelect(false);
        com.run();
        CHECK_N_CLEAR()

        //  select on listener GUI fails
        STEP(2)
        expectStartupOk();
        expectExitRuntime();
        m_TCP_Listener_Fld().expectSelect(true);
        m_TCP_Listener_Gui().expectSelect(false);
        com.run();
        CHECK_N_CLEAR()

        //  select on listener control fails
        STEP(3)
        expectStartupOk();
        expectExitRuntime();
        m_TCP_Listener_Fld().expectSelect(true);
        m_TCP_Listener_Gui().expectSelect(true);
        m_TCP_Listener_Ctrl().expectSelect(false);
        com.run();
        CHECK_N_CLEAR()

        //  select on client field fails
        STEP(4)
        expectStartupOk();
        expectExitRuntime();
        m_TCP_Listener_Fld().expectSelect(true);
        m_TCP_Listener_Gui().expectSelect(true);
        m_TCP_Listener_Ctrl().expectSelect(true);
        m_TCP_Con_Fld().expectSelect(false);
        com.run();
        CHECK_N_CLEAR()

        //  select on client GUI fails
        STEP(5)
        expectStartupOk();
        expectExitRuntime();
        m_TCP_Listener_Fld().expectSelect(true);
        m_TCP_Listener_Gui().expectSelect(true);
        m_TCP_Listener_Ctrl().expectSelect(true);
        m_TCP_Con_Fld().expectSelect(true);
        m_TCP_Con_Gui().expectSelect(false);
        com.run();
        CHECK_N_CLEAR()

        //  select on client control fails
        STEP(6)
        expectStartupOk();
        expectExitRuntime();
        m_TCP_Listener_Fld().expectSelect(true);
        m_TCP_Listener_Gui().expectSelect(true);
        m_TCP_Listener_Ctrl().expectSelect(true);
        m_TCP_Con_Fld().expectSelect(true);
        m_TCP_Con_Gui().expectSelect(true);
        m_TCP_Con_Ctrl().expectSelect(false);
        com.run();
        CHECK_N_CLEAR()

        //  all selects pass for 1st time than listener field fails
        STEP(7)
        expectStartupOk();
        expectExitRuntime();
        m_TCP_Listener_Fld().expectSelect(true);
        m_TCP_Listener_Gui().expectSelect(true);
        m_TCP_Listener_Ctrl().expectSelect(true);
        m_TCP_Con_Fld().expectSelect(true);
        m_TCP_Con_Gui().expectSelect(true);
        m_TCP_Con_Ctrl().expectSelect(true);
        m_TCP_Listener_Fld().expectSelect(false);
        com.run();
        CHECK_N_CLEAR()

        //  coverage: stop
        STEP(8)
        com.stop();
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  Com to field / to GUI
    TEST(COM_04, T03)
    {
        SETUP()
        I_Com& com = Com::instance();

        STEP(1)
        {
            const ComTele tf {{}, {101, 202}};
            m_TCP_Con_Fld().expectSend(tf);
            com.toFld(tf);
            CHECK_N_CLEAR()
        }
        STEP(2)
        {
            const ComTele tg {{}, {111, 212}};
            m_TCP_Con_Gui().expectSend(tg);
            com.toGui(tg);
            CHECK_N_CLEAR()
        }
    }

} // namespace
