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
#include <SocketAdaptorFactory.h>
#include <SocketLayerDefinitions.h>

#ifdef LIBSSL_OS_WIN32
#  include <WinSocketAdaptor.h>
#endif


namespace libSSL
{
namespace socketlayer
{

SocketAdaptorFactory::SocketAdaptorFactory()
{
}


SocketAdaptorFactory::~SocketAdaptorFactory()
{
}


iSocketAdaptor *SocketAdaptorFactory::Create()
{
#ifdef LIBSSL_OS_WIN32
    return new WinSocketAdaptor();
#endif
}


}   //  namespace socketlayer
}   //  namespace libSSL
