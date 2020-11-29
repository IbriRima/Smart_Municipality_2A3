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
#include <OpenSSL/OpenSSLObject.h>
#include <IPV4SocketFactory.h>
#include <IPV4SocketLayer.h>
#include <libSSL.h>
#include <iSocketAdaptor.h>
#include <OpenSSL/OpenSSLContext.h>
#include <SocketAdaptorFactory.h>



using namespace libSSL;

secure::OpenSSLContext *contextObject = NULL;

//  Create and configure the OpenSSL context object
bool CreateContextObject ()
{
    contextObject = new secure::OpenSSLContext( secure::ContextMode_client );

    //  Set which ciphers to load
    contextObject->SetCipherList( "AES128-SHA256" );

    return true;
}

int main( int argc, char **argv )
{
    socketlayer::SocketAdaptorFactory *socketAdaptorFactory = NULL;
    socketlayer::iSocketAdaptor *socketAdaptor = NULL;
    socketlayer::IPV4SocketFactory *socketFactory = NULL;
    socketlayer::IPV4SocketLayer *socketlayer = NULL;
    socketlayer::iSocket *socket = NULL;
    int isConnected = false;
    secure::iSSLConnection *conn = NULL;
    secure::OpenSSLObject *sslObject = NULL;

    std::cout << "[INFO] Sample IPV4 SSL client using V" << LibSSLVersion << " of LibSSL library" << std::endl;

    if ( libSSL::Initialise() == false )
    {
        std::cout << "[ERROR] Unable to initialise libSSL library" << std::endl;
        return 0;
    }

    socketAdaptorFactory = new socketlayer::SocketAdaptorFactory;
    socketAdaptor = socketAdaptorFactory->Create();
    socketFactory = new socketlayer::IPV4SocketFactory( socketAdaptor );
    socketlayer = new socketlayer::IPV4SocketLayer( socketFactory, socketAdaptor );

    socket = socketlayer->CreateSocket( socketlayer::SockType_stream );

    socket->SetNonBlocking( true );
    socket->SetSocketOption( socketlayer::SocketOption_KeepAlive, true );

    std::cout << "[INFO] Create and configure the SSL context object" << std::endl;
    if (CreateContextObject () == false) return -1;

    bool connStatus = false;
    socketlayer::TimeoutValue tv = { 0, 1 };

    for ( int i = 0; i < 10; i++ )
    {
        connStatus = socket->Connect( "127.0.0.1", 3490, &tv );
        if ( connStatus ) break;
    }

    std::cout << "[INFO] Connection " << ( ( connStatus == true ) ? "[OK]" : "[FAILED]") << std::endl;

    if ( connStatus == false ) return 0;

    sslObject = new secure::OpenSSLObject( socket
                                         , contextObject);

    std::cout << "[INFO] Establishing a connection..." << std::endl;

    while ( !isConnected )
    {
        conn = sslObject->Connect();

        if ( conn )
        {
            isConnected = true;
            std::cout << "[INFO] SSL connection handshake completed!" << std::endl;
        }
        else
        {
            int err2 = sslObject->GetLastError();

            switch ( err2 )
            {
            case secure::SSLStatus_WantToRead:
                break;

            case secure::SSLStatus_WantToWrite:
                break;

            default:
                char buf[256];
                unsigned long err;

                while ( ( err = ERR_get_error() ) != 0 )
                {
                    ERR_error_string_n( err, buf, sizeof( buf ) );
                    std::cout << "[ERROR] " << buf << std::endl;
                }

                return -1;
                break;
            }
        }
    }

    std::cout << "[INFO] Connection established..." << std::endl;

    std::string awrite = "GET / HTTP/1.0";
    conn->Write( awrite, awrite.size() );

    std::cout << "[INFO] Going into loop                                 [OK]" << std::endl;

    while( 1 )
    {
        Sleep( 1 );
    }

    libSSL::Shutdown();
}
