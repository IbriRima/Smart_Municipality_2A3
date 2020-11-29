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
#include <iterator>
#include <gtest/gtest.h>
#include <IPV4Socket.h>
#include <Mock_SocketAdaptor.h>
#include <Mock_Socket.h>


using namespace libSSL;

ACTION_TEMPLATE (SetArgNPointeeTo,
    HAS_1_TEMPLATE_PARAMS (unsigned, uIndex),
    AND_2_VALUE_PARAMS (pData, uiDataSize))
{
    std::memcpy (std::get<uIndex> (args), pData, uiDataSize);
}


class IPV4SocketTests : public ::testing::Test
{
public:
    IPV4SocketTests() {}

    ~IPV4SocketTests()
    {
        if (m_socket ) delete m_socket;
    }

protected:
    socketlayer::IPV4Socket *m_socket;
};


TEST_F( IPV4SocketTests, Constructor_ok)
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;
    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );
}


TEST_F( IPV4SocketTests, Write_invalidSocket )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor, GetLastError() )
        .WillRepeatedly( testing::Return( SockErr_ERNOTSUPPORTED ) );

    EXPECT_CALL( *adaptor, send (testing::_, testing::_, testing::_, testing::_ ) )
        .WillRepeatedly( testing::Return( -1 ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( -1, m_socket->Write( "", 1 ) );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, Write_SockErr_EWOULDBLOCK )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor, GetLastError() )
        .WillRepeatedly( testing::Return( SockErr_EWOULDBLOCK ) );

    EXPECT_CALL( *adaptor, send (testing::_, testing::_, testing::_, testing::_ ) )
        .WillRepeatedly( testing::Return( -1 ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( 0, m_socket->Write( "", 1 ) );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, Write_SockErr_otherError )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor, GetLastError() )
        .WillRepeatedly( testing::Return( SockErr_EMSGSIZE ) );

    EXPECT_CALL( *adaptor, send( testing::_, testing::_, testing::_, testing::_ ) )
        .WillRepeatedly( testing::Return( -1 ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ (-1, m_socket->Write ("", 1));

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, Write_stdStringOK )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;
    std::string writeBuffer = "libSSL is being tested here...";

    EXPECT_CALL( *adaptor, send( testing::_, testing::_, testing::_, testing::_ ) )
        .WillRepeatedly( testing::Return( writeBuffer.length () ) );

    m_socket = new socketlayer::IPV4Socket( 2099
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( writeBuffer.length(), m_socket->Write( writeBuffer, 1 ) );

    if ( adaptor ) delete adaptor;
}


TEST_F (IPV4SocketTests, Write_charPointerOK)
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;
    const char writeBuffer[] = "libSSL is being tested here...";

    EXPECT_CALL( *adaptor, send( testing::_, testing::_, testing::_, testing::_ ) )
        .WillRepeatedly( testing::Return( strlen (writeBuffer) ) );

    m_socket = new socketlayer::IPV4Socket( 2099
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( strlen( writeBuffer ), m_socket->Write( writeBuffer, 1 ) );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, Read_invalidSocket )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;
    std::string readBuffer;

    m_socket = new socketlayer::IPV4Socket( Invalid_Socket
                                          , socketlayer::SockType_stream
                                          , adaptor);

    EXPECT_EQ( -1, m_socket->Read( readBuffer, 10 ) );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, Read_SockErr_EWOULDBLOCK )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;
    std::string readBuffer;

    EXPECT_CALL( *adaptor, GetLastError() )
        .WillRepeatedly( testing::Return( SockErr_EWOULDBLOCK ) );

    EXPECT_CALL( *adaptor, recv( testing::_, testing::_, testing::_, testing::_ ) )
        .WillRepeatedly( testing::Return( -1 ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( 0, m_socket->Read( readBuffer, 1 ) );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, Read_SockErr_otherError )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;
    std::string readBuffer;

    EXPECT_CALL( *adaptor, GetLastError() )
        .WillRepeatedly( testing::Return( SockErr_EMSGSIZE ) );

    EXPECT_CALL( *adaptor, recv( testing::_, testing::_, testing::_, testing::_ ) )
        .WillRepeatedly( testing::Return( -1 ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( -1, m_socket->Read( readBuffer, 1 ) );

    if (adaptor) delete adaptor;
}


TEST_F( IPV4SocketTests, Read_ok )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;
    char rcvBuffer[] = "testingRcvWorks";
    size_t bufferSize = sizeof ("testingRcvWorks");
    char readBuffer[100] = "\0";

    EXPECT_CALL( *adaptor, recv( testing::_, testing::_, testing::_, testing::_ ) )
        .WillRepeatedly( testing::DoAll(
            SetArgNPointeeTo<1>( std::begin( rcvBuffer ), bufferSize ),
            testing::Return( strlen( rcvBuffer ) ) ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( strlen( rcvBuffer ), m_socket->Read( readBuffer, bufferSize) );
    EXPECT_STREQ( rcvBuffer, readBuffer );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, Connect_getaddrinfoFailed )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor
               , getaddrinfo( testing::_, testing::_, testing::_, testing::_) )
        .WillRepeatedly( testing::Return( -1 ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( false, m_socket->Connect( "localhost", 10, NULL ) );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, Connect_ok )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;
    AddrInfo getaddrinfoResults;
    SockAddr_In addrData;

    getaddrinfoResults.ai_addr.push_back( addrData );

    EXPECT_CALL( *adaptor
               , getaddrinfo( testing::_, testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::DoAll(
            testing::SetArgPointee<3>( getaddrinfoResults ),
            testing::Return ( 0 ) ) );

    EXPECT_CALL( *adaptor
               , connect( testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( 0 ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( true, m_socket->Connect( "localhost", 10, NULL ) );
    EXPECT_EQ( true, m_socket->IsConnected() );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, Connect_fatalError )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;
    AddrInfo getaddrinfoResults;
    SockAddr_In addrData;

    getaddrinfoResults.ai_addr.push_back (addrData);

    EXPECT_CALL( *adaptor, GetLastError() )
        .WillRepeatedly( testing::Return( SockErr_EMSGSIZE ) );

    EXPECT_CALL( *adaptor
        , getaddrinfo( testing::_, testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::DoAll(
            testing::SetArgPointee<3>( getaddrinfoResults ),
            testing::Return( 0 ) ) );

    EXPECT_CALL( *adaptor
               , connect( testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( SocketError ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( false, m_socket->Connect( "localhost", 10, NULL ) );
    EXPECT_EQ( false, m_socket->IsConnected() );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, Connect_WouldBlockSelectError )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;
    AddrInfo getaddrinfoResults;
    SockAddr_In addrData;

    getaddrinfoResults.ai_addr.push_back( addrData );

    EXPECT_CALL( *adaptor, GetLastError() )
        .WillRepeatedly( testing::Return( SockErr_EWOULDBLOCK ) );

    EXPECT_CALL( *adaptor
               , getaddrinfo( testing::_, testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::DoAll(
            testing::SetArgPointee<3>( getaddrinfoResults ),
            testing::Return( 0 ) ) );

    EXPECT_CALL( *adaptor
               , connect( testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( SocketError ) );

    EXPECT_CALL( *adaptor
               , select( testing::_, testing::_, testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( SocketError ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( false, m_socket->Connect( "localhost", 10, NULL ) );
    EXPECT_EQ( false, m_socket->IsConnected() );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, Connect_WouldBlockSelectException )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;
    AddrInfo getaddrinfoResults;
    SockAddr_In addrData;

    getaddrinfoResults.ai_addr.push_back( addrData );

    EXPECT_CALL( *adaptor, GetLastError() )
        .WillOnce( testing::Return( SockErr_EWOULDBLOCK ) );

    EXPECT_CALL( *adaptor
               , getaddrinfo( testing::_, testing::_, testing::_, testing::_ ) )
        .WillOnce (testing::DoAll(
            testing::SetArgPointee<3>( getaddrinfoResults ),
            testing::Return( 0 ) ) );

    EXPECT_CALL( *adaptor
               , connect( testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( SocketError ) );

    EXPECT_CALL( *adaptor
               , select( testing::_, testing::_, testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( 100 ) );
 
    EXPECT_CALL( *adaptor
               , SocketSet_ISSET( testing::_, testing::_ ) )
        .WillOnce( testing::Return( 10 ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( false, m_socket->Connect( "localhost", 10, NULL ) );
    EXPECT_EQ( false, m_socket->IsConnected() );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, Connect_WouldBlockThenConnected )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;
    AddrInfo getaddrinfoResults;
    SockAddr_In addrData;

    getaddrinfoResults.ai_addr.push_back( addrData );

    EXPECT_CALL( *adaptor, GetLastError() )
        .WillOnce( testing::Return( SockErr_EWOULDBLOCK ) );

    EXPECT_CALL( *adaptor
               , getaddrinfo( testing::_, testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::DoAll(
                   testing::SetArgPointee<3>( getaddrinfoResults ),
                   testing::Return( 0 ) ) );

    EXPECT_CALL( *adaptor
               , connect( testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( SocketError ) );

    EXPECT_CALL( *adaptor
               , select( testing::_, testing::_, testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( 100 ) );

    EXPECT_CALL( *adaptor
               , SocketSet_ISSET( testing::_, testing::_ ) )
        .WillOnce( testing::Return( 0 ) )
        .WillOnce( testing::Return( 10 ) );


    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( true, m_socket->Connect( "localhost", 10, NULL ) );
    EXPECT_EQ( true, m_socket->IsConnected() );

    if ( adaptor ) delete adaptor;
}        


TEST_F( IPV4SocketTests, SetNonBlocking_ok )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );
 
    EXPECT_CALL( *adaptor
               , ioctlsocket( testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( 10 ) );

    EXPECT_EQ( true, m_socket->SetNonBlocking( true ) );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, SetNonBlocking_failed )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_CALL( *adaptor
               , ioctlsocket (testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( SocketError ) );

    EXPECT_EQ( false, m_socket->SetNonBlocking( true ) );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, Accept_ok )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;
    iSocket *socket = NULL;

    EXPECT_CALL( *adaptor
               , select( testing::_, testing::_
                       , testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( 4000 ) );

    EXPECT_CALL( *adaptor, accept( testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( 1234 ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    socket = m_socket->Accept( NULL );
    EXPECT_TRUE( socket != NULL );
    EXPECT_EQ( 1234, socket->GetSocketHandle() );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, Accept_selectFailed )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor
               , select( testing::_, testing::_
               , testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( 0 ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( NULL, m_socket->Accept( NULL ) );

    if (adaptor) delete adaptor;
}


TEST_F( IPV4SocketTests, Accept_acceptFailed )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor
                , select( testing::_, testing::_
                , testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( 100 ) );

    EXPECT_CALL( *adaptor, accept( testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( Invalid_Socket ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( NULL, m_socket->Accept( NULL ) );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, Close_ok )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor, closesocket( testing::_ ) )
        .Times( 1 );
    EXPECT_CALL( *adaptor, shutdown( testing::_, testing::_ ) )
        .Times( 1 );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    m_socket->Close();

    if (adaptor) delete adaptor;
}


TEST_F( IPV4SocketTests, PollConnectionState_errorState )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor
               , select( testing::_, testing::_
               , testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( SocketError ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );
   
    EXPECT_EQ( PollType_errorState, m_socket->PollConnectionState( NULL ) );

    if (adaptor) delete adaptor;
}


TEST_F( IPV4SocketTests, PollConnectionState_newData )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor
               , select( testing::_, testing::_
               , testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( 100 ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                           , socketlayer::SockType_stream
                                           , adaptor);

    EXPECT_EQ( PollType_newData, m_socket->PollConnectionState( NULL ) );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, PollConnectionState_noData )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor
               , select( testing::_, testing::_
               , testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( 0 ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( PollType_noData, m_socket->PollConnectionState( NULL ) );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, Bind_ok )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor
               , bind( testing::_, testing::_ ) )
        .WillOnce( testing::Return( 100 ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( true, m_socket->Bind( 1701 ) );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, Bind_failed )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor
               , bind( testing::_, testing::_ ) )
        .WillOnce( testing::Return( SocketError ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( false, m_socket->Bind( 1701 ) );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, listen_backlogExceeded )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor
               , listen( testing::_, testing::_ ) )
        .WillOnce( testing::Return( false ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( false, m_socket->Listen( 6 ) );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, listen_socketError )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor
               , listen( testing::_, testing::_ ) )
        .WillOnce( testing::Return( false ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( false, m_socket->Listen( 5 ) );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, listen_ok )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor
               , listen( testing::_, testing::_ ) )
        .WillOnce( testing::Return( true ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( true, m_socket->Listen( 5 ) );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, HasNewConnection_selectFailed )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor
               , select( testing::_, testing::_
               , testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( SocketError ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );
  
    try
    {
        m_socket->HasNewConnection( NULL );
        FAIL();
    }
    catch( std::string &e )
    {
        EXPECT_STREQ( "::select() failed, unable to continue.", e.c_str() );
    }

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, HasNewConnection_noConnection )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor
               , select( testing::_, testing::_
               , testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( 200 ) );

    EXPECT_CALL( *adaptor
               , SocketSet_ISSET( testing::_, testing::_ ) )
        .WillOnce( testing::Return( 0 ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( false, m_socket->HasNewConnection( NULL ) );

    if (adaptor) delete adaptor;
}


TEST_F( IPV4SocketTests, HasNewConnection_Connection )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor
               , select( testing::_, testing::_
               , testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( 100 ) );

    EXPECT_CALL( *adaptor
               , SocketSet_ISSET( testing::_, testing::_ ) )
        .WillOnce( testing::Return( 100 ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( true, m_socket->HasNewConnection( NULL ) );

    if ( adaptor ) delete adaptor;
}


TEST_F( IPV4SocketTests, SetSocketOption_ok )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor
               , setsockopt( testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( 100 ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( true, m_socket->SetSocketOption( SocketOption_ReuseAddr
                                              , true ) );

    if (adaptor) delete adaptor;
}


TEST_F( IPV4SocketTests, SetSocketOption_failed )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor
               , setsockopt( testing::_, testing::_, testing::_ ) )
        .WillOnce( testing::Return( SocketError ) );

    m_socket = new socketlayer::IPV4Socket( 1234
                                          , socketlayer::SockType_stream
                                          , adaptor );

    EXPECT_EQ( false, m_socket->SetSocketOption( SocketOption_ReuseAddr
                                               , true ) );

    if ( adaptor ) delete adaptor;
}


