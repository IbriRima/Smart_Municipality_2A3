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
#include <OpenSSL/OpenSSLObject.h>
#include <openssl/OpenSSLContext.h>
#include <openssl/OpenSSLConnection.h>


namespace libSSL
{
namespace secure
{


OpenSSLObject::OpenSSLObject( socketlayer::iSocket *rawSocket 
                            , iSSLContext *context )
    : m_rawSocket( rawSocket ), m_lastError( 0 )
    , m_ctx( context )
{
    SSL_load_error_strings();
    SSL_library_init();

    //  Add ciphers and message digests
    OpenSSL_add_ssl_algorithms();

    SSL_CTX *ctx = static_cast<OpenSSLContext *>(m_ctx)->GetContext();

    m_sslObject = SSL_new( ctx );
    SSL_set_fd( m_sslObject, m_rawSocket->GetSocketHandle() );
}


OpenSSLObject::~OpenSSLObject()
{
}


iSSLConnection *OpenSSLObject::Accept()
{
    OpenSSLConnection *newConn = NULL;

    //  Reset last error code
    m_lastError = SSLStatus_OK;

    int sslAcceptStatus = SSL_accept( m_sslObject );

    //  If SSL_accept returned 0 (The TLS/SSL handshake was not successful) or
    //  <0 (The TLS/SSL handshake was not successful because a fatal error
    //  occurred either at the protocol level or a connection failure occurred)
    //  then an error was detected.
    int lastError = SSL_get_error( m_sslObject, sslAcceptStatus );

    switch( lastError )
    {
    case SSL_ERROR_NONE:
        newConn = new OpenSSLConnection( m_rawSocket, m_ctx, m_sslObject );
        break;

    case SSL_ERROR_WANT_WRITE:
    case SSL_ERROR_WANT_READ:
    case SSL_ERROR_WANT_X509_LOOKUP:
        m_lastError = lastError;
        break;

    case SSL_ERROR_SYSCALL:
    case SSL_ERROR_SSL:
    case SSL_ERROR_ZERO_RETURN:
        m_lastError = lastError;
        break;
    }

    return newConn;
}


iSSLConnection *OpenSSLObject::Connect()
{
    bool returnStatus = true;
    OpenSSLConnection *conn = NULL;

    int connectStatus = SSL_connect( m_sslObject );

    if ( connectStatus != 1 )
    {
        returnStatus = false;
        m_lastError = SSL_get_error( m_sslObject, connectStatus );
    }
    else
    {
        conn = new OpenSSLConnection( m_rawSocket, m_ctx, m_sslObject );
    }

    return conn;
}

}   //  namespace secure
}   //  namespace libSSL
