/*
This file is part of the SSL Wrapper Library (libSSL)

Foobar is free software : you can redistribute it and / or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Foobar is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Foobar.If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef ISSLOBJECT_H
#define ISSLOBJECT_H
#include <string>
#include <iSocket.h>
#include <iSSLConnection.h>


namespace libSSL
{
namespace secure
{

enum SSLMode
{
    SSLMode_server,
    SSLMode_client
};

const int SSLStatus_Failure = -1;
const int SSLStatus_OK = 0;
const int SSLStatus_SSL = 1;
const int SSLStatus_WantToRead = 2;
const int SSLStatus_WantToWrite = 3;
const int SSLStatus_WantX509Lookup = 4;
const int SSLStatus_SYSCALL = 5;
const int SSLStatus_ZeroReturn = 6;


class iSSLObject
{
public:
    virtual ~iSSLObject() {}

    virtual iSSLConnection *Accept() = 0;

    virtual iSSLConnection *Connect() = 0;

    virtual int GetLastError() = 0;
};

}   //  namespace secure
}   //  namespace libSSL

#endif  //  #ifndef ISSLOBJECT_H
