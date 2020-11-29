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
#include <WinSocketAdaptor.h>
#include <IPV4SocketFactory.h>
#include <IPV4SocketLayer.h>
#include <OpenSSL/OpenSSLContext.h>
#include <libSSL.h>


const std::string CertificateFile = "server.pem";


using namespace libSSL;

socketlayer::iSocket *serverSocket = NULL;
secure::OpenSSLContext *contextObject = NULL;


void CreateRawSocket()
{
    socketlayer::iSocket *acceptedSocket = NULL;
    socketlayer::IPV4SocketLayer *socketlayer = NULL;
    socketlayer::IPV4SocketFactory *socketFactory = NULL;
    socketlayer::WinSocketAdaptor *socketAdaptor = NULL;

    socketAdaptor = new socketlayer::WinSocketAdaptor;
    socketFactory = new socketlayer::IPV4SocketFactory( socketAdaptor );

    socketlayer = new socketlayer::IPV4SocketLayer( socketFactory, socketAdaptor );
    serverSocket = socketlayer->CreateSocket( socketlayer::SockType_stream );

    //  Set to non-blocking at the raw socket level, this will simplify calls!
    serverSocket->SetNonBlocking( true );

    serverSocket->Bind( 3490 );

    serverSocket->Listen( 5 );
    
    delete socketFactory;   //  This will be passed  into ssl eventually
}


//  Create and configure the OpenSSL context object
bool CreateContextObject()
{
    contextObject = new secure::OpenSSLContext( secure::ContextMode_server );

    //  Set which ciphers to load
    contextObject->SetCipherList( "AES128-SHA256" );

    //  Load the certificate file
    if (!contextObject->LoadCertificateFile( CertificateFile ) )
    {
        std::cout << "[ERROR] Failed to load the certificate file!" << std::endl;
        return false;
    }

    //  Load the private file
    if (!contextObject->LoadPrivateKey( CertificateFile ) )
    {
        std::cout << "[ERROR] Failed to load private key" << std::endl;
        return false;
    }

    return true;
}


int main( int argc, char **argv )
{
    socketlayer::iSocket *acceptedSocket = NULL;
    secure::OpenSSLObject *sslObject = NULL;
    bool connectStatusShown = false;

    std::cout << "[INFO] Sample IPV4 SSL server using V" << LibSSLVersion << " of LibSSL library" << std::endl;

    CreateRawSocket();

    if (libSSL::Initialise () == false)
    {
        std::cout << "[ERROR] Unable to initialise libSSL library" << std::endl;
        return 0;
    }

    std::cout << "[INFO] Create and configure the SSL context object" << std::endl;
    if ( CreateContextObject() == false ) return -1;

    secure::iSSLConnection *conn = NULL;

    socketlayer::TimeoutValue newConnTimeout = { 0, 1 };
    std::string recvStr;
    bool hasRead = false;

    std::cout << "[INFO] Awaiting new connection..." << std::endl;

    while( acceptedSocket == NULL )
    {
        if ( serverSocket->HasNewConnection( &newConnTimeout ) )
        {
            acceptedSocket = serverSocket->Accept (&newConnTimeout);

            if ( acceptedSocket )
            {
                std::cout << "[INFO] A new (raw) connection has been established..." << std::endl;
            }

        }

        Sleep (1);
    }

    std::cout << "[INFO] New connection established, starting OpenSSL handshake..." << std::endl;

    //  Create core OpenSSL object, used to accept connections with
    sslObject = new secure::OpenSSLObject( acceptedSocket, contextObject );

    bool handshakeComplete = false;

    while ( handshakeComplete == false )
    {
        conn = sslObject->Accept();

        handshakeComplete = (conn) ? true : false;

        int acceptReturnVal = sslObject->GetLastError();

        if ( acceptReturnVal == -1 )
        {
            int lastError = sslObject->GetLastError();
            std::cout << "[ERROR] SSL Error detected : " << lastError << std::endl;
            char buf[256];
            unsigned long errCode = 0;

            while ( ( errCode = ERR_get_error() ) != 0 ) 
            {
                ERR_error_string_n( errCode, buf, sizeof( buf ) );
                printf ("*** %s\n", buf);
            }
            return -1;
        }
    }

    std::cout << "[INFO] OpenSSL complete..." << std::endl;


    while( 1 )
    {
        if ( !hasRead && acceptedSocket )
        {
            int bytesRead = conn->Read( recvStr );

            if ( bytesRead > 0 ) std::cout << "[DEBUG] Received '" <<  recvStr 
                <<  "'" << std::endl;

            hasRead = ( bytesRead > 0 ) ? true : false;
        }
    }

    return 0;
}
