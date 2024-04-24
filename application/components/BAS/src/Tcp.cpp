#include <BAS/Tcp.h>

#ifdef _WIN32
#include <winsock2.h>
#pragma comment(lib, "ws2_32")
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define closesocket close
#endif

INSTANCE_DEF(Tcp)

void Tcp::setSelectTimeout(const UINT32 ms)
{
    mSec = ms / 1000;
    mMicro = (ms % 1000) * 1000;
}

bool Tcp::init()
{
#ifdef _WIN32
    WSADATA wsaData;
    return WSAStartup(MAKEWORD(2, 2), &wsaData) == 0;
#else
    return true;
#endif
}

void Tcp::cleanup()
{
#ifdef _WIN32
    WSACleanup();
#endif
}

INT32 Tcp::socket() const
{
    return ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

bool Tcp::bind(const INT32 socket, const UINT16 port) const
{
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    return ::bind(socket, (const sockaddr*)&addr, sizeof(addr)) >= 0; 
}

bool Tcp::listen(const INT32 socket) const
{
    return ::listen(socket, SOMAXCONN) >= 0;
}

INT32 Tcp::select(const INT32 socket) const
{
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(socket, &readfds);
    timeval timeout;
    timeout.tv_sec = mSec;
    timeout.tv_usec = mMicro;
    INT32 ret = 0;
    if (::select(socket + 1, &readfds, nullptr, nullptr, &timeout) < 0)
    {
        ret = -1;
    }
    else if (FD_ISSET(socket, &readfds))
    {
        ret = 1;
    }
    return ret;
}

INT32 Tcp::accept(const INT32 socket) const
{
    return ::accept(socket, nullptr, nullptr);
}

INT32 Tcp::recv(const INT32 socket, CHAR* const buffer, const size_t size) const
{
    return ::recv(socket, buffer, size, 0);
}

INT32 Tcp::send(const INT32 socket, const CHAR* const buffer, const size_t size) const
{
    return ::send(socket, buffer, size, 0);
}

void Tcp::close(const INT32 socket) const
{
    ::closesocket(socket);
}
