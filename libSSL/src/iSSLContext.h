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
#ifndef ISSLCONTEXT_H
#define ISSLCONTEXT_H
#include <string>


namespace libSSL
{
namespace secure
{

enum ContextMode
{
    ContextMode_server,
    ContextMode_client
};


class iSSLContext
{
public:
    virtual ~iSSLContext() {}

    virtual void SetCipherList( std::string cipherList ) = 0;

    virtual bool LoadCertificateFile( std::string filename ) = 0;

    virtual bool LoadPrivateKey( std::string filename ) = 0;

    virtual ContextMode GetContextMode() = 0;
};

}   //  namespace secure
}   //  namespace libSSL

#endif  //  #ifndef ISSLCONTEXT_H
