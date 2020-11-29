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
#include <IPV4Socket.h>
#include <socketLayerIncs.h>

namespace libSSL
{
namespace socketlayer
{


IPV4Socket::IPV4Socket( Socket socketDescriptor
                      , SockType type 
                      , iSocketAdaptor *socketAdaptor )
    : m_socket( socketDescriptor )
    , m_socketType( type )
    , m_isConnected( false )
    , m_socketAdaptor( socketAdaptor )
{
}


IPV4Socket::~IPV4Socket()
{
}


iSocket *IPV4Socket::Accept( TimeoutValue *timeout )
{
    SocketSet set;
    Socket newSocketHandle = 0;

    //  Clear master sockets set
    SocketSet_ZERO( &set );

    //  Add listening socket to the master set
    SocketSet_SET( m_socket, &set );

    if ( m_socketAdaptor->select( SocketSetSize, &set, 0, &set, timeout ) > 0 )
    {
        newSocketHandle = m_socketAdaptor->accept( m_socket, NULL, NULL );

        if ( newSocketHandle == Invalid_Socket )
        {
            return NULL;
        }

        return new IPV4Socket( newSocketHandle, m_socketType, m_socketAdaptor );
    }

    return NULL;
}


bool IPV4Socket::Bind( int port )
{
    int retVal = m_socketAdaptor->bind( m_socket
                                  , port );

    return (retVal == SocketError ) ? false : true;
}


void IPV4Socket::Close()
{
    m_socketAdaptor->shutdown( m_socket, ShutdownFlag_Both );
    m_socketAdaptor->closesocket( m_socket );
}


bool IPV4Socket::Connect( std::string hostname
                        , unsigned short remotePort
                        , TimeoutValue *timeout )
{
    AddrInfo getResults;
    AddrInfo getaddrinfoHints;
    int connReturn = 0;
    SockAddr_In *addrData;
    bool connectSuccess = false;
    std::string service = std::to_string( remotePort );

    getaddrinfoHints.ai_family = AddressFamily_inet;
    getaddrinfoHints.ai_socktype = SockType_stream;

    if ( m_socketAdaptor->getaddrinfo( hostname
                                     , service
                                     , &getaddrinfoHints
                                     , &getResults ) != 0 )
    {
        return false;
    }

    addrData = (SockAddr_In *)&( *getResults.ai_addr.begin() );

    connReturn = m_socketAdaptor->connect( m_socket
                                         , (const Sockaddr *)addrData
                                         , (int)getResults.ai_addrlen );

    if ( connReturn == SocketError)
    {
        int m_lastErrorCode = m_socketAdaptor->GetLastError();

        //  Connection error : FATAL 
        if ( ( m_lastErrorCode != SockErr_EWOULDBLOCK) &&
             ( m_lastErrorCode != SockErr_EALREADY ) )
        {
            connectSuccess = false;
        }
        else
        {
            SocketSet writeFDS;
            SocketSet exceptFDS;
            int selectReturn = 0;

            //  Clear all the socket FDS structures
            SocketSet_ZERO( &writeFDS );
            SocketSet_ZERO( &exceptFDS );

            //  Put the socket into the FDS structures
            SocketSet_SET( m_socket, &writeFDS );
            SocketSet_SET( m_socket, &exceptFDS );

            selectReturn = m_socketAdaptor->select( -1
                                                  , NULL
                                                  , &writeFDS
                                                  , &exceptFDS
                                                  , timeout );

            if ( selectReturn == SocketError )
            {
                //  Any errors are bad
                connectSuccess = false;
            }
            else if ( selectReturn > 0 )
            {
                //  Check for error (exception) first
                if ( m_socketAdaptor->SocketSet_ISSET( m_socket, &exceptFDS ) )
                {
                    connectSuccess = false;
                }
                else if ( m_socketAdaptor->SocketSet_ISSET( m_socket, &writeFDS ) )
                {
                    //   Select returned 'writable', we're connected!
                    connectSuccess = true;
                    m_isConnected = true;
                }
            }
        }
    }
    else
    {
        connectSuccess = true;
        m_isConnected = true;
    }

    return connectSuccess;
}


bool IPV4Socket::Listen( unsigned short backlog )
{
    return m_socketAdaptor->listen( m_socket, backlog );
}


int IPV4Socket::Read( char *buffer, int size )
{
    int bytesRead = -1;

    // If the socket is not open then read cannot happen return error (-1)
    if (m_socket == Invalid_Socket) return -1;

    bytesRead = m_socketAdaptor->recv( m_socket, buffer, size, 0 );

    if (bytesRead < 0)
    {
        int errorCode = m_socketAdaptor->GetLastError ();
        bytesRead = (errorCode == SockErr_EWOULDBLOCK) ? 0 : -1;
    }

    return bytesRead;
}


int IPV4Socket::Read( std::string &buffer, int size )
{
    int bytesRead = -1;
    char *rawBuffer = new char[size+1];

    // If the socket is not open then read cannot happen return error (-1)
    if ( m_socket == Invalid_Socket ) return -1;

    bytesRead = m_socketAdaptor->recv( m_socket, rawBuffer, size, 0 );

    if ( bytesRead < 0 )
    {
        int errorCode = m_socketAdaptor->GetLastError();
        bytesRead = ( errorCode == SockErr_EWOULDBLOCK ) ? 0 : -1;
    }
    else
    {
        rawBuffer[bytesRead] = '\0';
        buffer = std::string( rawBuffer, bytesRead );
    }

    delete rawBuffer;

    return bytesRead;
}


int IPV4Socket::Write( std::string buffer, int size )
{
    int bytesWritten = -1;

    // If the socket is not open then write cannot happen return error (-1)
    if ( m_socket == Invalid_Socket ) return -1;

    bytesWritten = m_socketAdaptor->send( m_socket, buffer.c_str(), size, 0 );

    if ( bytesWritten < 0 )
    {
        int errorCode = m_socketAdaptor->GetLastError();
        bytesWritten = ( errorCode == SockErr_EWOULDBLOCK ) ? 0 : -1;
    }

    return bytesWritten;
}


int IPV4Socket::Write( const char *buffer, int size )
{
    int bytesWritten = -1;

    // If the socket is not open then write cannot happen return error (-1)
    if ( m_socket == Invalid_Socket ) return -1;

    bytesWritten = m_socketAdaptor->send( m_socket, buffer, size, 0 );

    if ( bytesWritten < 0 )
    {
        int errorCode = m_socketAdaptor->GetLastError ();
        bytesWritten = ( errorCode == SockErr_EWOULDBLOCK ) ? 0 : -1;
    }

    return bytesWritten;
}


bool IPV4Socket::SetSocketOption( SocketOption option
                                , bool state )
{
    int sockoptReturn = 0;

    sockoptReturn = m_socketAdaptor->setsockopt( m_socket
                                               , option
                                               , state );
    return ( sockoptReturn == SocketError ) ? false : true;
}


bool IPV4Socket::SetNonBlocking( bool state )
{
    int returnValue = -1;
    unsigned long argp = 1;

    returnValue = m_socketAdaptor->ioctlsocket( m_socket
                                              , SocketMode_Nonblocking
                                              , &argp );

    return ( returnValue == SocketError ) ? false : true;
}


PollType IPV4Socket::PollConnectionState( TimeoutValue *timeout )
{
    PollType returnValue = PollType_newData;
    SocketSet socketSet;
    int selectState = 0;

    SocketSet_ZERO( &socketSet );
    SocketSet_SET( m_socket, &socketSet );

    selectState = m_socketAdaptor->select( m_socket + 1
                                         , &socketSet
                                         , NULL
                                         , NULL
                                         , timeout );

    if ( selectState == SocketError )
    {
        //  Error state : 'SOCKET_ERROR'
        returnValue = PollType_errorState;
    }
    else if (selectState == 0)
    {
        //  Poll result of '0' means timeout or no data.
        returnValue = PollType_noData;
    }
    else
    {
        //  Otherwise new data.
        returnValue = PollType_newData;
    }

    return returnValue;
}


bool IPV4Socket::HasNewConnection( TimeoutValue *timeout )
{
    SocketSet read_fd_set;

    SocketSet_ZERO( &read_fd_set );
    SocketSet_SET( m_socket, &read_fd_set );

    if ( m_socketAdaptor->select( SocketSetSize
                                , &read_fd_set
                                , NULL
                                , NULL
                                , timeout ) < 0 )
    {
        throw( std::string( "::select() failed, unable to continue." ) );
    }

    if ( m_socketAdaptor->SocketSet_ISSET( m_socket, &read_fd_set ) )
    {
        return true;
    }

    return false;
}


bool IPV4Socket::IsConnected()
{
    return m_isConnected;
}

}   //  namespace socketlayer
}   //  namespace libSSL
