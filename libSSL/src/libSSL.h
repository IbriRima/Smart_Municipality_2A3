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
#ifndef LIBSSL_H
#define LIBSSL_H

#include <string>


namespace libSSL
{

const std::string LibSSLVersion = "0.3.0 (Pre-Alpha)";

bool Initialise();

bool Shutdown();

}   //  namespace libSSL


#endif  //  #ifndef LIBSSL_H
