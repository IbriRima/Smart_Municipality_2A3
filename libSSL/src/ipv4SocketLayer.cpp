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
#include <ipv4SocketLayer.h>


namespace libSSL
{
namespace socketlayer
{

IPV4SocketLayer::IPV4SocketLayer( iSocketFactory *socketFactory
                                , iSocketAdaptor *socketAdaptor )
    : m_socketFactory( socketFactory ), m_socketFamily( AddressFamily_inet )
    , m_socketAdaptor( socketAdaptor )
{
    if ( m_socketAdaptor->Initialise() == false )
    {
        throw(std::string( "Unable to locate usable WinSock DLL" ) );
    }
}


IPV4SocketLayer::~IPV4SocketLayer()
{
}


iSocket *IPV4SocketLayer::CreateSocket( SockType type )
{
    Socket socketDescriptor = Invalid_Socket;

    socketDescriptor = m_socketAdaptor->socket( type 
                                              , SocketProtocol_TCP
                                              , AddressFamily_inet );

    //  Validate the return of the call, to ensure that it created successfully
    if ( socketDescriptor == Invalid_Socket ) return NULL;

    return m_socketFactory->Create( socketDescriptor, m_socketFamily, type );
}


std::string IPV4SocketLayer::ConvertDomainNameToIP( std::string domain )
{
    std::string hostAddress;
    AddrInfo hints;
    int returnValue = 0;
    AddrInfo results;
    SockAddr_In *h;

    hints.ai_family = AddressFamily_unspecified;
    hints.ai_socktype = SockType_stream;
    
    returnValue = m_socketAdaptor->getaddrinfo( domain
                                              , "http"
                                              , &hints
                                              , &results );

    //  If getaddrinfo returned false then call failed....
    if ( returnValue != 0) return std::string( "" );

    h = (SockAddr_In *)&( *results.ai_addr.begin() );

    m_socketAdaptor->inet_ntop( &h->sin_addr
                              , hostAddress
                              , sizeof( SockAddr_In ) );

    return hostAddress;
}


AddressFamily IPV4SocketLayer::GetAddressFamily()
{
    return m_socketFamily;
}

}   //  namespace socketlayer
}   //  namespace libSSL
