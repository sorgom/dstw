//  ============================================================
//  test of COM TCP clients
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <COM/TCP_Cons.h>

namespace test
{

    TEST_GROUP_BASE(COM_03, TestGroupBase)
    {
        constexpr static INT32 validSocket = 0;
        constexpr static INT32 invalidSocket = -1;
        bool ok = false;
    };

    //  test type: equivalence class test
    //  TCP client field representing base client
    TEST(COM_03, T01)
    {
        SETUP()
        I_TCP_Con& client = TCP_Con_Fld::instance();

        //  accept returns invalid socket
        STEP(1)
        m_TCP().expectClose();
        m_TCP().expectAccept(validSocket, invalidSocket);
        ok = client.accept(validSocket);
        CHECK_N_CLEAR()
        L_CHECK_FALSE(ok)

        //  select should return true without action
        STEP(2)
        ok = client.select();
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok)

        //  send telegram to invalid socket
        //  should not send
        STEP(3)
        {
            const ComTele tele{{}, {101, 202}};
            client.send(tele);
            CHECK_N_CLEAR()
        }

        //  accept returns valid socket
        STEP(4)
        m_TCP().expectClose();
        m_TCP().expectAccept(validSocket, validSocket);
        ok = client.accept(validSocket);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok)

        //  select returns 0 no activity
        STEP(5)
        m_TCP().expectSelect(validSocket, 0);
        ok = client.select();
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok)

        //  select returns 1 activity
        //  recv returns valid data
        //  Dispatcher gets data from field
        STEP(6)
        {
            const ComTele tele{{}, {101, 202}};
            m_TCP().expectSelect(validSocket, 1);
            m_TCP().expectRecv(validSocket, tele);
            m_Dispatcher().expectFromFld(tele);
            ok = client.select();
            CHECK_N_CLEAR()
            L_CHECK_TRUE(ok)
        }

        //  select returns -1 error
        STEP(7)
        m_TCP().expectSelect(validSocket, -1);
        m_TCP().expectClose();
        ok = client.select();
        CHECK_N_CLEAR()
        L_CHECK_FALSE(ok)
    }

    //  test type: equivalence class test
    //  TCP client GUI representing base client
    TEST(COM_03, T02)
    {
        SETUP()
        I_TCP_Con& client = TCP_Con_Gui::instance();

        //  accept returns valid socket
        STEP(1)
        m_TCP().expectClose();
        m_TCP().expectAccept(validSocket, validSocket);
        ok = client.accept(validSocket);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok)

        //  select returns 1 activity
        //  recv returns valid data
        //  Dispatcher gets data from GUI
        STEP(2)
        {
            const ComTele tele{{}, {111, 212}};
            m_TCP().expectSelect(validSocket, 1);
            m_TCP().expectRecv(validSocket, tele);
            m_Dispatcher().expectFromGui(tele);
            ok = client.select();
            CHECK_N_CLEAR()
            L_CHECK_TRUE(ok)
        }

        //  send telegram to valid socket
        STEP(3)
        {
            const ComTele tele{{}, {131, 232}};
            m_TCP().expectSend(validSocket, sizeof(ComTele));
            client.send(tele);
            CHECK_N_CLEAR()
        } 

        //  select returns 1 activity
        //  recv returns close event
        STEP(4)
        m_TCP().expectSelect(validSocket, 1);
        m_TCP().expectRecv(validSocket, sizeof(ComTele), 0);
        m_TCP().expectClose();
        ok = client.select();
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok)
    }
    //  test type: equivalence class test
    //  TCP client CTRL representing base client
    TEST(COM_03, T03)
    {
        SETUP()
        I_TCP_Con& client = TCP_Con_Ctrl::instance();

        //  accept returns valid socket
        STEP(1)
        m_TCP().expectClose();
        m_TCP().expectAccept(validSocket, validSocket);
        ok = client.accept(validSocket);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok)

        //  select returns 1 activity
        //  recv returns valid data
        //  that don't contain both COM_CTRL_STOP
        STEP(2)
        {
            const ComTele tele1{{}, {COM_CTRL_STOP, COM_CTRL_STOP - 1}};
            m_TCP().expectSelect(validSocket, 1);
            m_TCP().expectRecv(validSocket, tele1);
            ok = client.select();
            CHECK_N_CLEAR()
            L_CHECK_TRUE(ok)

            const ComTele tele2{{}, {COM_CTRL_STOP - 1, COM_CTRL_STOP}};
            m_TCP().expectSelect(validSocket, 1);
            m_TCP().expectRecv(validSocket, tele2);
            ok = client.select();
            CHECK_N_CLEAR()
            L_CHECK_TRUE(ok)
        }

        //  select returns 1 activity
        //  recv returns valid data
        //  that contains both COM_CTRL_STOP
        //  Com receives stop
        STEP(3)
        {
            const ComTele tele1{{}, {COM_CTRL_STOP, COM_CTRL_STOP}};
            m_TCP().expectSelect(validSocket, 1);
            m_TCP().expectRecv(validSocket, tele1);
            m_Com().expectStop();
            ok = client.select();
            CHECK_N_CLEAR()
            L_CHECK_TRUE(ok)
        }

        //  recv returns invalid size
        STEP(4)
        m_TCP().expectSelect(validSocket, 1);
        m_TCP().expectRecv(validSocket, sizeof(ComTele), sizeof(ComTele) - 1);
        m_TCP().expectClose();
        ok = client.select();
        CHECK_N_CLEAR()
        L_CHECK_FALSE(ok)
    }
} // namespace
