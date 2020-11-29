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
#include <OpenSSL/OpenSSLContext.h>

namespace libSSL
{
namespace secure
{

OpenSSLContext::OpenSSLContext( ContextMode mode )
    : m_contextMode( mode )
{
    switch( mode )
    {
    case ContextMode_server:
        m_ctx = SSL_CTX_new( TLSv1_2_server_method() );
        break;

    case ContextMode_client:
        m_ctx = SSL_CTX_new( TLSv1_2_client_method() );
        break;
    }

    if ( !m_ctx )
    {
        throw std::string( "Internal error: Failed to create context object!" );
    }
}


OpenSSLContext::~OpenSSLContext()
{
    if ( m_ctx ) delete m_ctx;
}


void OpenSSLContext::SetCipherList( std::string cipherList )
{
    SSL_CTX_set_cipher_list( m_ctx, cipherList.c_str() );
}


bool OpenSSLContext::LoadCertificateFile( std::string filename )
{
    bool returnStatus = true;

    if ( !SSL_CTX_use_certificate_file( m_ctx
                                      , filename.c_str()
                                      , SSL_FILETYPE_PEM ) )
    {
        returnStatus = false;
    }

    return returnStatus;
}


bool OpenSSLContext::LoadPrivateKey( std::string filename )
{
    bool returnStatus = true;

    if ( !SSL_CTX_use_PrivateKey_file( m_ctx
                                     , filename.c_str()
                                     , SSL_FILETYPE_PEM ) )
    {
        returnStatus = false;
    }

    return returnStatus;
}

}   //  namespace secure
}   //  namespace libSSL
