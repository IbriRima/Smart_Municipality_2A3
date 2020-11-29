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
#ifndef OPENSSLCONNECTION_H
#define OPENSSLCONNECTION_H
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <iSocket.h>
#include <iSSLContext.h>
#include <iSSLConnection.h>


namespace libSSL
{
namespace secure
{

class OpenSSLConnection : public iSSLConnection
{
public:
    OpenSSLConnection( socketlayer::iSocket *rawSocket
                     , iSSLContext *contextObject
                     , SSL *sslOjbject );

    ~OpenSSLConnection();

    int Read( std::string &buffer );

    int Write( std::string buffer, int size );

    int GetLastError() { return m_lastError; }

protected:
    socketlayer::iSocket *m_rawSocket;
    iSSLContext *m_ctx;
    BIO *m_readBIO;
    BIO *m_writeBIO;
    SSL *m_sslObject;
    int m_lastError;
};

}   //  namespace secure
}   //  namespace libSSL

#endif  //  #ifndef OPENSSLCONNECTION_H
