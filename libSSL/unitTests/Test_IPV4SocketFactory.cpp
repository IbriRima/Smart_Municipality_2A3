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
#include <IPV4SocketFactory.h>
#include <Mock_SocketAdaptor.h>


using namespace libSSL;

class IPV4SocketFactoryTests : public ::testing::Test
{
public:
    IPV4SocketFactoryTests() {}

    ~IPV4SocketFactoryTests()
    {
        if ( m_socketFactory ) delete m_socketFactory;
    }

protected:
    socketlayer::IPV4SocketFactory *m_socketFactory;
};


TEST_F( IPV4SocketFactoryTests, Constructor_ok )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;
    m_socketFactory = new socketlayer::IPV4SocketFactory( adaptor );
}


TEST_F( IPV4SocketFactoryTests, Create_ok )
{
    Mock_SocketAdaptor *adaptor = new Mock_SocketAdaptor;
    m_socketFactory = new socketlayer::IPV4SocketFactory( adaptor );

    EXPECT_TRUE( m_socketFactory->Create( 2048
                                        , socketlayer::AddressFamily_inet
                                        , socketlayer::SockType_stream ) != NULL );
}
