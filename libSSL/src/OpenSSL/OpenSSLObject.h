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
#ifndef OPENSSLOBJECT_H
#define OPENSSLOBJECT_H
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <iSSLObject.h>
//#include <iSocketAdaptor.h>
#include <SocketLayerDefinitions.h>  
#include <iSSLConnection.h>
#include <iSSLContext.h>


namespace libSSL
{
namespace secure
{
    
class OpenSSLObject : public iSSLObject
{
public:
    OpenSSLObject( socketlayer::iSocket *rawSocket
                 , iSSLContext *context );

    ~OpenSSLObject();

    iSSLConnection *Accept();

    iSSLConnection *Connect();

    int GetLastError() { return m_lastError; }

protected:
    socketlayer::iSocket *m_rawSocket;
    iSSLContext *m_ctx;
    SSL *m_sslObject;
    int m_lastError;
};

}   //  namespace secure
}   //  namespace libSSL

#endif  //  #ifndef OPENSSLOBJECT_H
