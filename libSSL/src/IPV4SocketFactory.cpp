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
#include <IPV4SocketFactory.h>
#include <IPV4Socket.h>


namespace libSSL
{
namespace socketlayer
{

IPV4SocketFactory::IPV4SocketFactory( iSocketAdaptor *socketAdaptor )
                 : m_socketAdaptor( socketAdaptor )
{
}


IPV4SocketFactory::~IPV4SocketFactory()
{
}


iSocket *IPV4SocketFactory::Create( Socket socketHandle
                                  , AddressFamily family
                                  , SockType type )
{
    return new IPV4Socket( socketHandle, type, m_socketAdaptor );
}


}   //  namespace socketlayer
}   //  namespace libSSL
