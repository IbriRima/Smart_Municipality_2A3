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
#ifndef OPENSSLCONTEXT_H
#define OPENSSLCONTEXT_H
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <iSSLContext.h>


namespace libSSL
{
namespace secure
{

class OpenSSLContext : public iSSLContext
{
public:
    OpenSSLContext( ContextMode mode );

    ~OpenSSLContext();

    void SetCipherList( std::string cipherList );
 
    bool LoadCertificateFile( std::string filename );

    bool LoadPrivateKey( std::string filename );

    ContextMode GetContextMode() { return m_contextMode; }

    SSL_CTX *GetContext() { return m_ctx; }

protected:
    SSL_CTX *m_ctx;
    ContextMode m_contextMode;
};

}   //  namespace secure
}   //  namespace libSSL

#endif  //  #ifndef OPENSSLCONTEXT_H
