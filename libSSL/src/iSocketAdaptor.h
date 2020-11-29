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
#ifndef ISOCKETADAPATOR_H
#define ISOCKETADAPATOR_H
#include <vector>
#include <SocketLayerDefinitions.h>


namespace libSSL
{
namespace socketlayer
{

const int SockErr_EINTR = 4;
const int SockErr_EACCES = 13;
const int SockErr_EFAULT = 14;
const int SockErr_EINVAL = 22;
const int SockErr_EMFILE = 24;
const int SockErr_EWOULDBLOCK = 35;
const int SockErr_EINPROGRESS = 36;
const int SockErr_EALREADY = 37;
const int SockErr_ENOTSOCK = 38;
const int SockErr_EMSGSIZE = 40;
const int SockErr_ENOPROTOOPT = 42;
const int SockErr_EOPNOSUPPORT = 45;
const int SockErr_EADDRINUSE = 48;
const int SockErr_EADDRNOTAVAIL = 49;
const int SockErr_ENETDOWN = 50;
const int SockErr_ENETUNREACH = 51;
const int SockErr_ENETRESET = 52;
const int SockErr_ECONNABORTED = 53;
const int SockErr_ECONNRESET = 54;
const int SockErr_ENOBUFS = 55;
const int SockErr_EISCONN = 56;
const int SockErr_ENOTCONN = 57;
const int SockErr_ESHUTDOWN = 58;
const int SockErr_ETIMEDOUT = 60;
const int SockErr_ECONNREFUSED = 61;
const int SockErr_ERNOTSUPPORTED = 93;
const int SockErr_NOTINITIALISED = 93;


class iSocketAdaptor
{
public:
    virtual ~iSocketAdaptor() {}

    virtual bool Initialise() = 0;

    virtual Socket socket( SockType type
                         , SocketProtocol protocol
                         , AddressFamily family ) = 0;

    virtual int getaddrinfo( std::string domain
                           , std::string service
                           , AddrInfo *hints
                           , AddrInfo *result ) = 0;

    virtual std::string inet_ntop( In_Addr *sockAddr
                                 , std::string &stringBuf
                                 , int stringBufSize) = 0;

    virtual bool listen( Socket socket
                       , unsigned short backlog ) = 0;

    virtual int recv( Socket socket
                    , char *buffer
                    , int bufferLength
                    , int flags ) = 0;

    virtual int send( Socket socket
                    , const char *buffer
                    , int bufferLength
                    , int flags ) = 0;

    virtual int setsockopt( Socket socket
                          , SocketOption option
                          , bool state ) = 0;
    
    virtual int bind( Socket socket
                    , int port ) = 0;

    virtual int connect( Socket socket
                       , const Sockaddr *name
                       , int namelen ) = 0;
        
    virtual int GetLastError() = 0;

    virtual int shutdown( Socket socket, ShutdownFlag flag ) = 0;

    virtual int closesocket( Socket socket ) = 0;

    virtual Socket accept(Socket m_socket, Sockaddr *addr, int *addrlen ) = 0;

    virtual int select( int nfds
                      , SocketSet *readfds
                      , SocketSet *writefds
                      , SocketSet *exceptfds
                      , const TimeoutValue *timeout ) = 0;

    virtual int ioctlsocket( Socket socket, SocketMode mode
                           , unsigned long *argp ) = 0;

    virtual int SocketSet_ISSET( Socket socket, SocketSet *set ) = 0;
};


}   //  namespace socketlayer
}   //  namespace libSSL




#endif  //  #ifndef ISOCKETADAPATOR_H
