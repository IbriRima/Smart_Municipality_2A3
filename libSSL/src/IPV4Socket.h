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
#ifndef IPV4SOCKET_H
#define IPV4SOCKET_H
#include <iSocket.h>
#include <iSocketAdaptor.h>


namespace libSSL
{
namespace socketlayer
{

class IPV4Socket : public iSocket
{
public:
    IPV4Socket( Socket socketDescriptor
              , SockType type
              , iSocketAdaptor *socketAdaptor );

    ~IPV4Socket();

    iSocket *Accept( TimeoutValue *timeout );

    bool Bind( int port );

    void Close();

    bool Connect( std::string hostname
                , unsigned short remotePort
                , TimeoutValue *timeout );

    bool Listen( unsigned short backlog );

    int Read( char *buffer, int size );

    int Read( std::string &buffer, int size );

    int Write( std::string buffer, int size );

    int Write ( const char *buffer, int size );

    PollType PollConnectionState( TimeoutValue *timeout );

    bool SetSocketOption( SocketOption option
                        , bool state );

    bool SetNonBlocking( bool state );

    bool HasNewConnection( TimeoutValue *timeout );

    Socket GetSocketHandle() { return m_socket; }

    bool IsConnected();

protected:
    Socket m_socket;
    SockType m_socketType;
    bool m_isConnected;
    iSocketAdaptor *m_socketAdaptor;
};


}   //  namespace socketlayer
}   //  namespace libSSL

#endif  //  #ifndef IPV4SOCKET_H
