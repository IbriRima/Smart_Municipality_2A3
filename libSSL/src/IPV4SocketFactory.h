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
#ifndef IPV4SOCKETFACTORY_H
#define IPV4SOCKETFACTORY_H
#include <iSocketFactory.h>
#include <iSocketAdaptor.h>


namespace libSSL
{
namespace socketlayer
{

class IPV4SocketFactory : public iSocketFactory
{
public:
    IPV4SocketFactory( iSocketAdaptor *socketAdaptor );

    ~IPV4SocketFactory();

    iSocket *Create( Socket socketHandle
                   , AddressFamily family
                   , SockType type );

private:
    iSocketAdaptor *m_socketAdaptor;
};


}   //  namespace socketlayer
}   //  namespace libSSL

#endif  //  #ifndef IPV4SOCKETFACTORY_H
