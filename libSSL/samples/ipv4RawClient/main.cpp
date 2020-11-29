#include <iostream>
#include <IPV4Socket.h>
#include <ipv4SocketLayer.h>
#include <IPV4SocketFactory.h>
#include <WinSocketAdaptor.h>


using namespace libSSL;

int main ( int argc, char **argv )
{
    socketlayer::iSocket *socket = NULL;
    socketlayer::IPV4SocketLayer *socketlayer = NULL;
    socketlayer::IPV4SocketFactory *socketFactory = NULL;
    socketlayer::WinSocketAdaptor *socketAdaptor = NULL;

    std::cout << "Sample IPV4 raw client" << std::endl;
    std::cout << "======================" << std::endl;

    socketAdaptor = new socketlayer::WinSocketAdaptor;
    socketFactory = new socketlayer::IPV4SocketFactory( socketAdaptor );

    socketlayer = new socketlayer::IPV4SocketLayer( socketFactory, socketAdaptor );
    socket = socketlayer->CreateSocket( socketlayer::SockType_stream );

    socket->SetNonBlocking( true );
    socket->SetSocketOption( socketlayer::SocketOption_KeepAlive, true );

    bool connStatus = false;
    socketlayer::TimeoutValue tv = { 0, 1 };

    for ( int i = 0; i < 10; i++)
    {
        connStatus = socket->Connect( "127.0.0.1", 3490, &tv );
        if ( connStatus ) break;
    }

    std::cout << "Connection " << ( ( connStatus == true ) ? "[OK]" : "[FAILED]" ) << std::endl;
  
    if ( connStatus == false ) return 0;

    std::string recvStr;
    std::string sendStr;
    bool hasRead = false;

    while (1)
    {  
        if ( !hasRead && socket->IsConnected() )
        {
            int readBytes = socket->Read (recvStr, 48);

            std::cout << "[INFO] Read " << readBytes << " bytes of data!" << std::endl;

            if ( readBytes)
            {
                std::cout << "[INFO] " << readBytes << " bytes of data!" << std::endl;
                std::cout << "[DATA] " << recvStr << std::endl;
            }
            hasRead = ( readBytes == 48 ) ? true : false;
        }
    }

    return 0;
}
