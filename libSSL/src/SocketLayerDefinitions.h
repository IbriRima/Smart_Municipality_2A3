/*
This file is part of the SSL Wrapper Library (libSSL)

libSSL is free software : you can redistribute it and / or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License.

libSSL is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
libSSL.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef SOCKETLAYERDEFINITIONS_H
#define SOCKETLAYERDEFINITIONS_H
#include <vector>

namespace libSSL
{
namespace socketlayer
{

#if _WIN32                //  Windows (Visual Studio etc)
#  define LIBSSL_OS_WIN32
#elif defined( __GNUC__ ) || defined( __GNUG__ )
#  define LIBSSL_OS_WIN32
#else                       //  Default otherwise is Linux
#  error Unknown Operating system
#endif

#define MsgFlag_OOB 0x1
#define MsgFlag_Peek 0x2
#define MsgFlag_WaitAll 0x40

#define SocketSetSize 64

typedef unsigned int Socket;

struct SocketSet
{
    unsigned int fd_count;
    Socket fd_array[SocketSetSize];
};

#define SocketSet_SET(fd, set) do { \
    unsigned int __i; \
    for (__i = 0; __i < ((SocketSet *)(set))->fd_count; __i++) { \
        if (((SocketSet *)(set))->fd_array[__i] == (fd)) { \
            break; \
        } \
    } \
    if (__i == ((SocketSet *)(set))->fd_count) { \
        if (((SocketSet *)(set))->fd_count < SocketSetSize) { \
            ((SocketSet *)(set))->fd_array[__i] = (fd); \
            ((SocketSet *)(set))->fd_count++; \
        } \
    } \
} while(0, 0)

#define SocketSet_ZERO(set) (((SocketSet *)(set))->fd_count=0)

const Socket Invalid_Socket = -1;
const int SocketError = -1;

enum AddressFamily
{
    AddressFamily_unspecified = 0,
    AddressFamily_inet = 2
};

enum SockType
{
    SockType_stream = 1
};

enum SocketProtocol
{
    SocketProtocol_TCP = 6
};

enum SocketOption
{
    SocketOption_ReuseAddr = 0x0004,
    SocketOption_KeepAlive = 0x0008
};

enum ShutdownFlag
{
    ShutdownFlag_Receive = 0,
    ShutdownFlag_Send = 1,
    ShutdownFlag_Both = 2
};

struct Sockaddr
{
    unsigned short sa_family;
    char sa_data[14];
};

struct In_Addr
{
    union
    {
        struct { unsigned char s_b1, s_b2, s_b3, s_b4; } S_un_b;
        struct { unsigned short s_w1, s_w2; } S_un_w;
        unsigned long S_addr;
    } S_un;
};


struct SockAddr_In
{
    unsigned short sin_family;
    unsigned short sin_port;
    In_Addr sin_addr;
    char sin_zero[8];
};

typedef std::vector<SockAddr_In> SockAddrInList;

struct AddrInfo
{
    AddressFamily ai_family;
    SockType ai_socktype;
    SockAddrInList ai_addr;
    size_t ai_addrlen;
};

struct TimeoutValue
{
    long tv_sec;    //  Seconds
    long tv_usec;   //  Microseconds
};

enum SocketMode
{
    SocketMode_Nonblocking
};

}   //  namespace socketlayer
}   //  namespace libSSL


#endif  //  #ifndef SOCKETLAYERDEFINITIONS_H
