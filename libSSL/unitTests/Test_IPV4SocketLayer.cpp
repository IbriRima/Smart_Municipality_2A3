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
#include <gtest/gtest.h>
#include <ipv4SocketLayer.h>
#include <IPV4SocketFactory.h>
#include <IPV4Socket.h>
#include <WinSocketAdaptor.h>
#include <Mock_SocketAdaptor.h>
#include <Mock_SocketFactory.h>


using namespace libSSL;

class IPV4SocketLayerTests : public ::testing::Test
{
public:
    IPV4SocketLayerTests() {}

    ~IPV4SocketLayerTests()
    {
        if ( m_socketlayer ) delete m_socketlayer;
    }

protected:
    socketlayer::IPV4SocketLayer *m_socketlayer;
};


TEST_F( IPV4SocketLayerTests, Constructor_ok )
{
    socketlayer::WinSocketAdaptor *adaptor = NULL;
    socketlayer::IPV4SocketFactory *socketFactory = NULL;

    adaptor = new socketlayer::WinSocketAdaptor;
    socketFactory = new socketlayer::IPV4SocketFactory( adaptor );
    m_socketlayer = new socketlayer::IPV4SocketLayer( socketFactory, adaptor );

    ASSERT_EQ( m_socketlayer->GetAddressFamily(), socketlayer::AddressFamily_inet );
}


TEST_F (IPV4SocketLayerTests, Constructor_failed )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;
    socketlayer::IPV4SocketFactory *socketFactory = NULL;
    socketFactory = new socketlayer::IPV4SocketFactory( adaptor );

    EXPECT_CALL( *adaptor, Initialise() )
        .WillRepeatedly( testing::Return( false ) );

    ASSERT_THROW( socketlayer::IPV4SocketLayer( socketFactory, adaptor )
                                              , std::string );

    try
    {
        m_socketlayer = new socketlayer::IPV4SocketLayer (socketFactory, adaptor);
    }
    catch( std::string str )
    {
        ASSERT_EQ( str.compare( "Unable to locate usable WinSock DLL" ), 0 );
    }

    delete socketFactory;
    delete adaptor;
}


TEST_F( IPV4SocketLayerTests, ConvertDomainNameToIP_validName )
{
    socketlayer::WinSocketAdaptor *adaptor = new socketlayer::WinSocketAdaptor;
    m_socketlayer = new socketlayer::IPV4SocketLayer( NULL, adaptor );

    ASSERT_EQ(m_socketlayer->ConvertDomainNameToIP( "ns1.bbc.co.uk" )
                                                  , "132.185.132.21" );
}


TEST_F( IPV4SocketLayerTests, ConvertDomainNameToIP_invalidName )
{
    socketlayer::WinSocketAdaptor *adaptor = new socketlayer::WinSocketAdaptor;
    m_socketlayer = new socketlayer::IPV4SocketLayer( NULL, adaptor );

    ASSERT_EQ (m_socketlayer->ConvertDomainNameToIP( "invalid.hostname" )
                                                   , "" );
}


TEST_F( IPV4SocketLayerTests, CreateSocket_failedInvalidSocketLayer )
{
    socketlayer::IPV4SocketFactory *socketFactory = NULL;
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    socketFactory = new socketlayer::IPV4SocketFactory( adaptor );
    
    EXPECT_CALL( *adaptor, Initialise() )
        .WillRepeatedly( testing::Return( true ) );

    EXPECT_CALL( *adaptor, socket( testing::_, testing::_, testing::_ ) )
        .WillRepeatedly( testing::Return( Invalid_Socket ) );

    m_socketlayer = new socketlayer::IPV4SocketLayer( socketFactory, adaptor );

    ASSERT_EQ( NULL, m_socketlayer->CreateSocket( socketlayer::SockType_stream ) );

    delete socketFactory;
    delete adaptor;
}


TEST_F( IPV4SocketLayerTests, CreateSocket_failedCreate )
{
    Mock_SocketFactory *socketFactory = new Mock_SocketFactory;
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;

    EXPECT_CALL( *adaptor, Initialise() )
        .WillRepeatedly( testing::Return( true ) );

    EXPECT_CALL( *adaptor, socket( testing::_, testing::_, testing::_ ) )
        .WillRepeatedly (testing::Return( 1234 ) );

    EXPECT_CALL( *socketFactory, Create( testing::_, testing::_, testing::_ ) )
        .WillRepeatedly( testing::ReturnNull() );

    m_socketlayer = new socketlayer::IPV4SocketLayer (socketFactory, adaptor);

    ASSERT_EQ (NULL, m_socketlayer->CreateSocket (socketlayer::SockType_stream));

    delete socketFactory;
    delete adaptor;
}



TEST_F( IPV4SocketLayerTests, CreateSocket_ok )
{
    Mock_SocketFactory *socketFactory = new Mock_SocketFactory;
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;
    IPV4Socket *socket = new IPV4Socket( 2020, SockType_stream, adaptor );

    EXPECT_CALL( *adaptor, Initialise() )
        .WillRepeatedly( testing::Return ( true ) );

    EXPECT_CALL( *adaptor, socket( testing::_, testing::_, testing::_ ) )
        .WillRepeatedly( testing::Return( 1234 ) );

    EXPECT_CALL( *socketFactory, Create( testing::_, testing::_, testing::_ ) )
        .WillRepeatedly( testing::Return( socket ) );

    m_socketlayer = new socketlayer::IPV4SocketLayer( socketFactory, adaptor );

    ASSERT_EQ( socket, m_socketlayer->CreateSocket( socketlayer::SockType_stream ) );

    delete socketFactory;
    delete adaptor;
}
