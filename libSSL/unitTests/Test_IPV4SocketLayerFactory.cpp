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
#include <IPV4SocketLayerFactory.h>


using namespace libSSL;

class IPV4SocketLayerFactoryTests : public ::testing::Test
{
public:
    IPV4SocketLayerFactoryTests() {}

    ~IPV4SocketLayerFactoryTests()
    {
        if ( m_socketLayeFactory ) delete m_socketLayeFactory;
    }

protected:
    socketlayer::IPV4SocketLayerFactory *m_socketLayeFactory;
};


TEST_F( IPV4SocketLayerFactoryTests, Constructor_ok )
{
    m_socketLayeFactory = new socketlayer::IPV4SocketLayerFactory;
}


TEST_F( IPV4SocketLayerFactoryTests, Create_ok )
{
    m_socketLayeFactory = new socketlayer::IPV4SocketLayerFactory;

    EXPECT_TRUE( m_socketLayeFactory->Create() != NULL );
}
