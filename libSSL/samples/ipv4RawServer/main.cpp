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
#include <iostream>
#include <IPV4Socket.h>
#include <ipv4SocketLayer.h>
#include <IPV4SocketFactory.h>
#include <WinSocketAdaptor.h>


using namespace libSSL;

int main ( int argc, char **argv )
{
    socketlayer::iSocket *socket = NULL;
    socketlayer::iSocket *acceptedSocket = NULL;
    socketlayer::IPV4SocketLayer *socketlayer = NULL;
    socketlayer::IPV4SocketFactory *socketFactory = NULL;
    socketlayer::WinSocketAdaptor *socketAdaptor = NULL;

    std::cout << "Sample IPV4 raw server" << std::endl;
    std::cout << "======================" << std::endl;

    socketAdaptor = new socketlayer::WinSocketAdaptor;
    socketFactory = new socketlayer::IPV4SocketFactory( socketAdaptor );

    socketlayer = new socketlayer::IPV4SocketLayer( socketFactory, socketAdaptor );
    socket = socketlayer->CreateSocket( socketlayer::SockType_stream );

    socket->SetNonBlocking( true );

    socket->Bind( 3490 );

    socket->Listen( 5 );

    socketlayer::TimeoutValue newConnTimeout = { 0, 1 };
    std::string recvStr;
    std::string sendStr = "This is a test string to ensure everything is ok";
    bool hasWritten = false;

    while( 1 )
    {
        if ( socket->HasNewConnection( &newConnTimeout ) )
        {
            std::cout << "[INFO] A new connection is waiting...." << std::endl;

            acceptedSocket = socket->Accept( &newConnTimeout );

            if ( acceptedSocket )
            {
                std::cout << "[INFO] A new connection has been received...." << std::endl;
            }
        }
       
        if ( !hasWritten && acceptedSocket )
        {
            int writtenBytes = acceptedSocket->Write( sendStr, sendStr.size() );

            std::cout << "[INFO] Written " << writtenBytes << " out of "
                      << sendStr.size () << " bytes!" << std::endl;

            hasWritten = ( writtenBytes == sendStr.size() ) ? true : false;
        }
    }

    return 0;
}
