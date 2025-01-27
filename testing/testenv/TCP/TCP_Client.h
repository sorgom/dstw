//  ============================================================
//  TCP test client
//  ============================================================
//  created by Manfred Sorgo

#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <BAS/coding.h>

namespace test
{
    class TCP_Client
    {
    public:

        TCP_Client() = default;

        static bool init();
        static void cleanup();

        //  connect to localhost with port
        //  works if test and app run in different processes
        bool connect(UINT16 port);

        //  send structured data
        //  mainly ComTele
        template<typename T>
        inline bool send(const T& data) const
        {
            return send(&data, sizeof(data));
        }

        //  receive structured data
        //  mainly ComTele
        template<typename T>
        inline bool recv(T& data) const
        {
            return recv(&data, sizeof(data));
        }

        //  close connection
        void close();

        NOCOPY(TCP_Client)
    private:
        INT32 mSocket = -1;
        bool send(CPTR data, INT32 size) const;
        bool recv(PTR data, INT32 size) const;
    };
}
#endif // _H
