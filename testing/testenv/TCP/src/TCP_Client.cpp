#include <TCP/TCP_Client.h>

#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define closesocket close
#endif

namespace test
{
    bool TCP_Client::init()
    {
#ifdef _WIN32
        WSADATA wsaData;
        return WSAStartup(MAKEWORD(2, 2), &wsaData) == 0;
#else
        return true;
#endif
    }

    void TCP_Client::cleanup()
    {
#ifdef _WIN32
        WSACleanup();
#endif
    }

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
                ::closesocket(mSocket);
                mSocket = -1;
                ok = false;
            }
        }
        return ok;
    }

    bool TCP_Client::send(CPTR data, INT32 size) const
    {
        return ::send(mSocket, static_cast<const char*>(data), size, 0) == size;
    }

    bool TCP_Client::recv(PTR data, INT32 size) const
    {
        fd_set readfds;
#ifdef _WIN32
#pragma warning(disable:4389)
#endif
        FD_ZERO(&readfds);
        FD_SET(mSocket, &readfds);
#ifdef _WIN32
#pragma warning(default:4389)
#endif
        timeval timeout{0, 50000};
        bool ok = false;
        if (
            (::select(mSocket + 1, &readfds, nullptr, nullptr, &timeout) >= 0) and
            (FD_ISSET(mSocket, &readfds))
        )
        {
            ok = ::recv(mSocket, static_cast<char*>(data), size, 0) == size;
        }
        return ok;
    }

    void TCP_Client::close()
    {
        if (mSocket >= 0)
        {
            ::closesocket(mSocket);
            mSocket = -1;
        }
    }
}
