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
#include <IPV4SocketLayerFactory.h>
#include <WinSocketAdaptor.h>
#include <IPV4SocketFactory.h>
#include <IPV4SocketLayer.h>


namespace libSSL
{
namespace socketlayer
{


IPV4SocketLayerFactory::IPV4SocketLayerFactory()
{
    m_socketAdaptor = new socketlayer::WinSocketAdaptor;
    m_socketFactory = new socketlayer::IPV4SocketFactory( m_socketAdaptor );
}


IPV4SocketLayerFactory::~IPV4SocketLayerFactory()
{
    if ( m_socketAdaptor ) delete m_socketAdaptor;
    if ( m_socketFactory ) delete m_socketFactory;
}


iSocketLayer *IPV4SocketLayerFactory::Create()
{
    return new socketlayer::IPV4SocketLayer( m_socketFactory
                                           , m_socketAdaptor );
}


}   //  namespace socketlayer
}   //  namespace libSSL
