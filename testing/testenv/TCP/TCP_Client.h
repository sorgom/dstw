//  ============================================================
//  TCP test client
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include <BAS/coding.h>

namespace test
{
    class TCP_Client
    {
    public:
        TCP_Client() = default;
        //  connect to localhost with port
        //  works if test and app run in different processes
        bool connect(UINT16 port);

        //  send structured data
        //  mainly ComTele
        template<typename T>
        inline bool send(const T& data)
        {
            return send(&data, sizeof(data));
        }

        //  receive structured data
        //  mainly ComTele
        template<typename T>
        inline bool recv(T& data)
        {
            return recv(&data, sizeof(data));
        }

        //  close connection
        void close();

        NOCOPY(TCP_Client)
    private:
        INT32 mSocket = -1;
        bool send(CPTR data, INT32 size);
        bool recv(PTR data, INT32 size);
    };

}