//  ============================================================
//  mocked TCP_Client
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include "M_Base.h"
#include <TCP/TCP_Client.h>
#include <ifs/DataTypes.h>

namespace test
{
    class M_TCP_Client : private M_Base
    {
    public:
        M_TCP_Client(const CONST_C_STRING name) : M_Base(name) {}

        inline void expectRecv(const ComTele& tele) const
        {
            expect("recv").TPARAM(ComTele, tele);
        }
        inline void expectRecv(UINT16 num) const
        {
            expect(num, "recv").IGNORE();
        }

        inline void recv() const
        {
            ComTele tele;
            while (mClient.recv(tele))
            {
                call("recv").TPARAM(ComTele, tele);
            }
        }
        inline void send(const ComTele tele)
        {
            const bool ok = mClient.send( tele );
            L_CHECK_TRUE(ok)
        }

        inline void connect(UINT16 port)
        {
            const bool ok = mClient.connect(port);
            L_CHECK_TRUE(ok)
        }

        inline void close()
        {
            mClient.close();
        }

        NOCOPY(M_TCP_Client)
        NODEF(M_TCP_Client)
    private:
        TCP_Client mClient;
    };

} // namespace
