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
#ifndef ISOCKET_H
#define ISOCKET_H
#include <string>
#include <SocketLayerDefinitions.h>


namespace libSSL
{
namespace socketlayer
{

enum PollType
{
    PollType_newData,
    PollType_errorState,
    PollType_noData,
};


// ***********************************************************************
// Definition of Socket interface class
// ***********************************************************************
class iSocket
{
public:
    virtual ~iSocket() {}

    virtual iSocket *Accept( TimeoutValue *timeout ) = 0;

    virtual bool Bind( int port ) = 0;

    virtual void Close() = 0;

    virtual bool Connect( std::string hostname
                        , unsigned short remotePort
                        , TimeoutValue *timeout) = 0;

    virtual bool Listen( unsigned short backlog ) = 0;

    virtual int Read( char *buffer, int size ) = 0;

    virtual int Read( std::string &buffer, int size ) = 0;

    virtual int Write( std::string buffer, int size ) = 0;

    virtual int Write (const char *buffer, int size) = 0;

    virtual PollType PollConnectionState( TimeoutValue *timeout ) = 0;

    virtual bool SetSocketOption( SocketOption option
                                , bool state) = 0;

    virtual bool SetNonBlocking( bool state ) = 0;

    virtual bool HasNewConnection ( TimeoutValue *timeout ) = 0;

    virtual Socket GetSocketHandle() = 0;

    virtual bool IsConnected() = 0;
};

}   //  namespace socketlayer
}   //  namespace libSSL

#endif  //  #ifndef ISOCKET_H
