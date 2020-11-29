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
#include <string>
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <WinSocketAdaptor.h>


namespace libSSL
{
namespace socketlayer
{


WinSocketAdaptor::WinSocketAdaptor() : m_lastError( 0 )
{
}


WinSocketAdaptor::~WinSocketAdaptor()
{
}


bool WinSocketAdaptor::Initialise()
{
    WORD wVersionRequested;
    WSADATA wsaData;
    bool returnStatus = true;

    wVersionRequested = MAKEWORD( 2, 2 );

    // Check for a usable WinSock DLL.
    if ( WSAStartup( wVersionRequested, &wsaData ) == 0 )
    {
        // Confirm that the WinSock DLL supports 2.2.
        // Note that if the DLL supports versions greater than 2.2 in addition
        // to 2.2, it will still return 2.2 in wVersion since it's version 
        // requested.
        if ( LOBYTE( wsaData.wVersion ) != 2 ||
             HIBYTE( wsaData.wVersion ) != 2 )
        {
            // Tell the user that we could not find a usable WinSock DLL.
            WSACleanup();
            returnStatus = false;
        }
    }
    else
    {
        returnStatus = false;
    }

    return returnStatus;
}


SOCKET WinSocketAdaptor::socket( SockType type
                               , SocketProtocol protocol
                               , AddressFamily family )

{
    SOCKET socketDescriptor = INVALID_SOCKET;

    socketDescriptor = ::socket( family, type, protocol );

    //  Validate the return of the call, to ensure that it created successfully
    if ( socketDescriptor == INVALID_SOCKET ) return INVALID_SOCKET;

    return socketDescriptor;
}


int WinSocketAdaptor::getaddrinfo( std::string domain
                                 , std::string service
                                 , AddrInfo *hints
                                 , AddrInfo *result )
{
    int returnValue = 0;
    addrinfo addrHints;
    addrinfo *actualResult;
    addrinfo *srvInfo;
    const char *domainName = ( domain.size() == 0 ) ? NULL : domain.c_str();
    const char *serviceName = ( service.size() == 0) ? NULL : service.c_str();

    memset ( &addrHints, 0, sizeof addrHints );

    if ( hints )
    {
        addrHints.ai_family = hints->ai_family;
        addrHints.ai_socktype = hints->ai_socktype;
    }

    if ( ( returnValue = ::getaddrinfo( domainName
                                      , serviceName
                                      , &addrHints
                                      , &actualResult ) ) != 0 )
    {
        return returnValue;
    }

     result->ai_addrlen = sizeof( Sockaddr );
     result->ai_family = hints->ai_family;
     result->ai_socktype = hints->ai_socktype;

    for ( srvInfo = actualResult; srvInfo != NULL; srvInfo = srvInfo->ai_next )
    {
        SockAddr_In *current = (SockAddr_In *)srvInfo->ai_addr;
        SockAddr_In sa;

        memcpy( &sa, current, sizeof( SockAddr_In ) );

        result->ai_addr.push_back( sa );
    }

    freeaddrinfo( actualResult );

    return returnValue;
}


std::string WinSocketAdaptor::inet_ntop( In_Addr *sockAddr
                                       , std::string &stringBuf
                                       , int stringBufSize )
{
    const char *result = NULL;
    char buffer[50] = "\0";
   
    result = ::inet_ntop( AF_INET
                        , sockAddr
                        , buffer
                        , stringBufSize );
    
    if ( result == NULL ) return std::string( "" );

    stringBuf = std::string( buffer );

    return std::string( result );
}


bool WinSocketAdaptor::listen( Socket socket
                             , unsigned short backlog )
{
    //  SOMAXCONN is 5, can't exceed that!
    if ( backlog > 5 ) return false;

    return ( ::listen( socket, backlog ) == SOCKET_ERROR ) ? false : true;
}


int WinSocketAdaptor::recv( Socket socket
                          , char *buffer
                          , int bufferLength
                          , int flags )
{
    int bytesRead = -1;

    bytesRead = ::recv( socket, buffer, bufferLength, flags );

    if ( bytesRead < 0 )
    {
        int errorCode = WSAGetLastError();
        m_lastError = ( errorCode > 10000 ) ? errorCode - 10000 : errorCode;
    }
    else
    {
        buffer[bytesRead] = '\0';
    }

    return bytesRead;
}


int WinSocketAdaptor::send( Socket socket
                          , const char *buffer
                          , int bufferLength
                          , int flags)
{
    int bytesWritten = -1;

    bytesWritten = ::send( socket, buffer, bufferLength, flags );

    if ( bytesWritten < 0 )
    {
        int errorCode = WSAGetLastError();
        m_lastError = ( errorCode > 10000 ) ? errorCode - 10000 : errorCode;
    }

    return bytesWritten;
}


int WinSocketAdaptor::setsockopt( Socket socket
                                , SocketOption option
                                , bool state )
{
    char flag = ( state == true ) ? '1' : '0';

    int sockoptReturn = ::setsockopt( socket
                                    , SOL_SOCKET
                                    , option
                                    , &flag
                                    , sizeof( flag ) );

    if ( sockoptReturn == SOCKET_ERROR )
    {
        int errorCode = WSAGetLastError();
        m_lastError = (errorCode > 10000) ? errorCode - 10000 : errorCode;
    }

    return sockoptReturn;
}


int WinSocketAdaptor::bind( Socket socket, int port )
{
    int returnValue = 0;
    sockaddr_in sockAddr;

    //  This needs to be fixed and be passed in
    //  especially 'sockAddr.sin_addr.s_addr'
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons( port );
    sockAddr.sin_addr.s_addr = INADDR_ANY; 

    returnValue = ::bind( socket
                        , reinterpret_cast<const sockaddr *>( &sockAddr )
                        , sizeof( sockAddr ) );

    if ( returnValue  == SOCKET_ERROR )
    {
        int errorCode = WSAGetLastError();
        m_lastError = ( errorCode > 10000 ) ? errorCode - 10000 : errorCode;
    }

    return returnValue;
}


int WinSocketAdaptor::connect( Socket socket
                             , const Sockaddr *name
                             , int namelen )
{
    int connReturn = 0;

    connReturn = ::connect( socket, (const sockaddr *)name, namelen );

    if ( connReturn == SOCKET_ERROR )
    {
        int errorCode = WSAGetLastError();
        m_lastError = ( errorCode > 10000 ) ? errorCode - 10000 : errorCode;
    }

    return connReturn;
}


int WinSocketAdaptor::shutdown( Socket socket, ShutdownFlag flag )
{
    int returnValue = 0;

    returnValue = ::shutdown( socket, flag );

    if ( returnValue == SOCKET_ERROR )
    {
        int errorCode = WSAGetLastError();
        m_lastError = ( errorCode > 10000 ) ? errorCode - 10000 : errorCode;
    }

    return returnValue;
}


int WinSocketAdaptor::closesocket( Socket socket )
{
    int returnValue = 0;

    returnValue = ::closesocket( socket );

    if ( returnValue == SOCKET_ERROR )
    {
        int errorCode = WSAGetLastError();
        m_lastError = ( errorCode > 10000 ) ? errorCode - 10000 : errorCode;
    }

    return returnValue;
}


Socket WinSocketAdaptor::accept( Socket m_socket
                               , Sockaddr *addr
                               , int *addrlen )
{
    Socket newSocket = Invalid_Socket;

    newSocket = ::accept( m_socket, (sockaddr *)addr, addrlen );

    if (newSocket == INVALID_SOCKET )
    {
        int errorCode = WSAGetLastError();
        m_lastError = ( errorCode > 10000 ) ? errorCode - 10000 : errorCode;
    }

    return newSocket;
}


int WinSocketAdaptor::select( int nfds
                            , SocketSet *readfds
                            , SocketSet *writefds
                            , SocketSet *exceptfds
                            , const TimeoutValue *timeout )
{
    int returnValue = SOCKET_ERROR;

    returnValue = ::select( nfds
                          , (fd_set *)readfds
                          , (fd_set *)writefds
                          , (fd_set *)exceptfds
                          , (const timeval *)timeout );

    if ( returnValue == INVALID_SOCKET )
    {
        int errorCode = WSAGetLastError();
        m_lastError = ( errorCode > 10000 ) ? errorCode - 10000 : errorCode;
    }

    return returnValue;
}


int WinSocketAdaptor::ioctlsocket( Socket m_socket
                                 , SocketMode mode
                                 , unsigned long *argp )
{
    int returnValue = -1;
    long socketMode = 0;

    switch (mode)
    {
    case SocketMode_Nonblocking:
        socketMode = FIONBIO;
        break;

    default:
        socketMode = FIONBIO;
    }

    returnValue = ::ioctlsocket( m_socket, socketMode, argp );

    if ( returnValue == INVALID_SOCKET )
    {
        int errorCode = WSAGetLastError();
        m_lastError = ( errorCode > 10000 ) ? errorCode - 10000 : errorCode;
    }

    return returnValue;
}


int WinSocketAdaptor::SocketSet_ISSET( Socket socket, SocketSet *set )
{ 
    return ::FD_ISSET( socket, set );
}

}   //  namespace socketlayer
}   //  namespace libSSL
