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
#ifndef ISSLCONNECTION_H
#define ISSLCONNECTION_H


namespace libSSL
{
namespace secure
{

class iSSLConnection
{
public:
    virtual ~iSSLConnection() {}

    virtual int Read( std::string &buffer ) = 0;

    virtual int Write( std::string buffer, int size ) = 0;

    virtual int GetLastError() = 0;
};

}   //  namespace secure
}   //  namespace libSSL

#endif  //  #ifndef ISSLCONNECTION_H
