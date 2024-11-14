//  ============================================================
//  test of COM TCP listeners
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <COM/TCP_Com.h>

namespace test
{

    TEST_GROUP_BASE(COM_02, TestGroupBase)
    {
        constexpr static INT32 validSocket = 0;
        constexpr static INT32 invalidSocket = -1;
        bool ok = false;
        static void expectComerr()
        {
            m_Log().expectLog(COMP_COM, RET_ERR_COM);
        }
    };

    //  test type: equivalence class test
    //  TCP listener field representing base listener
    TEST(COM_02, T01)
    {
        SETUP()
        I_TCP_Listener& listener = TCP_Listener_Fld::instance();

        //  TCP socket returns invalid socket
        STEP(1)
        expectComerr();
        m_TCP().expectSocket(invalidSocket);
        m_TCP().expectClose(invalidSocket);
        ok = listener.listen(tcpPortFld);
        CHECK_N_CLEAR()
        L_CHECK_FALSE(ok)

        //  TCP socket returns valid socket
        //  TCP bind returns false
        STEP(2)
        expectComerr();
        m_TCP().expectSocket(validSocket);
        m_TCP().expectBind(validSocket, tcpPortFld, false);
        m_TCP().expectClose(validSocket);
        ok = listener.listen(tcpPortFld);
        CHECK_N_CLEAR()
        L_CHECK_FALSE(ok)

        //  TCP socket returns valid socket
        //  TCP bind returns true
        //  TCP listen returns false
        STEP(3)
        expectComerr();
        m_TCP().expectSocket(validSocket);
        m_TCP().expectBind(validSocket, tcpPortFld, true);
        m_TCP().expectListen(validSocket, false);
        m_TCP().expectClose(validSocket);
        ok = listener.listen(tcpPortFld);
        CHECK_N_CLEAR()
        L_CHECK_FALSE(ok)

        //  TCP socket returns valid socket
        //  TCP bind returns true
        //  TCP listen returns true
        STEP(4)
        m_TCP().expectSocket(validSocket);
        m_TCP().expectBind(validSocket, tcpPortFld, true);
        m_TCP().expectListen(validSocket, true);
        ok = listener.listen(tcpPortFld);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok)

        //  select returns 0
        STEP(5)
        m_TCP().expectSelect(validSocket, SELECT_NONE);
        ok = listener.select();
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok)

        //  select returns 1
        //  accept returns true
        STEP(6)
        m_TCP().expectSelect(validSocket, SELECT_READY);
        m_TCP_Con_Fld().expectAccept(validSocket, true);
        ok = listener.select();
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok)

        //  select returns -1
        STEP(7)
        expectComerr();
        m_TCP().expectSelect(validSocket, SELECT_ERR);
        m_TCP().expectClose(validSocket);
        ok = listener.select();
        CHECK_N_CLEAR()
        L_CHECK_FALSE(ok)

        //  select returns 1
        //  accept returns false
        STEP(8)
        expectComerr();
        m_TCP().expectSelect(validSocket, SELECT_READY);
        m_TCP_Con_Fld().expectAccept(validSocket, false);
        m_TCP().expectClose(validSocket);
        ok = listener.select();
        CHECK_N_CLEAR()
        L_CHECK_FALSE(ok)

        //  close valid socket
        STEP(9)
        m_TCP().expectClose(validSocket);
        listener.close();
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  TCP listener GUI calling TCP client GUI
    TEST(COM_02, T02)
    {
        SETUP()
        I_TCP_Listener& listener = TCP_Listener_Gui::instance();

        STEP(1)
        m_TCP().expectSocket(validSocket);
        m_TCP().expectBind(validSocket, tcpPortGui, true);
        m_TCP().expectListen(validSocket, true);
        ok = listener.listen(tcpPortGui);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok)

        STEP(2)
        m_TCP().expectSelect(validSocket, SELECT_READY);
        m_TCP_Con_Gui().expectAccept(validSocket, true);
        ok = listener.select();
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok)
    }

    //  test type: equivalence class test
    //  TCP listener CTRL calling TCP client CTRL
    TEST(COM_02, T03)
    {
        SETUP()
        I_TCP_Listener& listener = TCP_Listener_Ctrl::instance();

        STEP(1)
        m_TCP().expectSocket(validSocket);
        m_TCP().expectBind(validSocket, tcpPortGui, true);
        m_TCP().expectListen(validSocket, true);
        ok = listener.listen(tcpPortGui);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok)

        STEP(2)
        m_TCP().expectSelect(validSocket, SELECT_READY);
        m_TCP_Con_Ctrl().expectAccept(validSocket, true);
        ok = listener.select();
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok)
    }
} // namespace
