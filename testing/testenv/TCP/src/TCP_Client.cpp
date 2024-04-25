#include <TCP/TCP_Client.h>

#ifdef _WIN32
#include <winsock2.h>
#pragma comment(lib, "ws2_32")
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define closesocket close
#endif

#include <thread>
#include <chrono>

namespace test
{
    bool TCP_Client::connect(UINT16 port)
    {
        bool ok = true;
        mSocket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (mSocket < 0)
        {
            ok = false;
        }
        else
        {
            struct sockaddr_in server_addr;
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(port); // Port number
            server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost
            if (::connect(mSocket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
            {
                closesocket(mSocket);
                mSocket = -1;
                ok = false;
            }
        }
        return ok;
    }

    void TCP_Client::t_connect(UINT16 port)
    {
        std::thread(&TCP_Client::_connect, this, port).detach();
    }

    void TCP_Client::_connect(UINT16 port)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(mWait));
        mRes = connect(port);
    }
}