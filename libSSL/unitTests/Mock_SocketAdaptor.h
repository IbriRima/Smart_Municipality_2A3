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
#ifndef MOCK_SOCKETADAPATOR_H
#define MOCK_SOCKETADAPATOR_H
#include <gmock/gmock.h>
#include <iSocketAdaptor.h>


using namespace libSSL::socketlayer;


class Mock_SocketAdaptor : public iSocketAdaptor
{
public:
    MOCK_METHOD0( Initialise, bool() );
    MOCK_METHOD3( socket, Socket( SockType, SocketProtocol, AddressFamily ) );
    MOCK_METHOD4( getaddrinfo, int( std::string, std::string, AddrInfo *, AddrInfo * ) );
    MOCK_METHOD3( inet_ntop, std::string( In_Addr *, std::string &, int ) );
    MOCK_METHOD2( listen, bool( Socket socket, unsigned short backlog ) );
    MOCK_METHOD4( recv, int( Socket, char *, int, int ) );
    MOCK_METHOD4( send, int( Socket, const char *buffer, int, int ) );
    MOCK_METHOD0( GetLastError, int() );
    MOCK_METHOD3( setsockopt, int( Socket, SocketOption, bool ) );
    MOCK_METHOD2( bind, int( Socket, int ) );
    MOCK_METHOD3( connect, int (Socket, const Sockaddr *, int ) );
    MOCK_METHOD2( shutdown, int( Socket, ShutdownFlag ) );
    MOCK_METHOD1( closesocket, int( Socket ) );
    MOCK_METHOD3( accept, Socket( Socket, Sockaddr *, int * ) );
    MOCK_METHOD5( select, int( int, SocketSet *, SocketSet *, SocketSet *, const TimeoutValue * ) );
    MOCK_METHOD3( ioctlsocket, int( Socket, SocketMode, unsigned long * ) );
    MOCK_METHOD2( SocketSet_ISSET, int( Socket, SocketSet *));
};

#endif  //  #ifndef MOCK_SOCKETADAPATOR_H
