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
#ifndef MOCK_SOCKET_H
#define MOCK_SOCKET_H
#include <gmock/gmock.h>
#include <iSocket.h>


using namespace libSSL::socketlayer;


class Mock_Socket : public iSocket
{
public:
    MOCK_METHOD1( Accept, iSocket *( TimeoutValue * ) );
    MOCK_METHOD1( Bind, bool( int ) );
    MOCK_METHOD0( Close, void() );
    MOCK_METHOD3( Connect, bool( std::string, unsigned short, TimeoutValue * ) );
    MOCK_METHOD1( Listen, bool( unsigned short ) );
    MOCK_METHOD2( Read, int( std::string &, int ) );
    MOCK_METHOD2( Write, int( std::string, int ) );
    MOCK_METHOD1( PollConnectionState, PollType( TimeoutValue * ) );
    MOCK_METHOD2( SetSocketOption, bool( SocketOption, bool ) );
    MOCK_METHOD1( SetNonBlocking, bool( bool ) );
    MOCK_METHOD1( HasNewConnection, bool( TimeoutValue * ) );
    MOCK_METHOD0( GetSocketHandle, Socket() );
    MOCK_METHOD0( IsConnected, bool() );
};

#endif  //  #ifndef MOCK_SOCKET_H
