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
#ifndef WINSOCKETADAPATOR_H
#define WINSOCKETADAPATOR_H
#include <iSocketAdaptor.h>
#include <iSocket.h>


namespace libSSL
{
namespace socketlayer
{

class WinSocketAdaptor : public iSocketAdaptor
{
public:
    WinSocketAdaptor();

    ~WinSocketAdaptor();

    bool Initialise();

    Socket socket( SockType type, SocketProtocol protocol
                 , AddressFamily family );

    int getaddrinfo( std::string domain
                   , std::string service
                   , AddrInfo *hints
                   , AddrInfo *result );

    std::string inet_ntop( In_Addr *sockAddr
                         , std::string &stringBuf
                         , int stringBufSize );

    bool listen( Socket socket, unsigned short backlog );

    int recv( Socket socket
            , char *buffer
            , int bufferLength
            , int flags );

    int send( Socket socket
            , const char *buffer
            , int bufferLength
            , int flags );

    int setsockopt( Socket socket
                  , SocketOption option
                  , bool state );

    int bind( Socket socket, int port );

    int connect( Socket socket
               , const Sockaddr *name
               , int namelen );

    int shutdown( Socket socket, ShutdownFlag flag );

    int closesocket( Socket socket );

    Socket accept( Socket m_socket
                 , Sockaddr *addr
                 , int *addrlen );

    int select( int nfds
              , SocketSet *readfds
              , SocketSet *writefds
              , SocketSet *exceptfds
              , const TimeoutValue *timeout );

    int GetLastError() { return m_lastError; }

    int ioctlsocket( Socket socket, SocketMode mode
                   , unsigned long *argp );

    int SocketSet_ISSET( Socket socket, SocketSet *set );

protected:
    int m_lastError;
};


}   //  namespace socketlayer
}   //  namespace libSSL


#endif  //  #ifndef WINSOCKETADAPATOR_H
