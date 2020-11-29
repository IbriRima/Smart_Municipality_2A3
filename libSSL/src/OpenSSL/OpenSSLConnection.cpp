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
#include <OpenSSL/OpenSSLConnection.h>
#include <OpenSSL/OpenSSLContext.h>


namespace libSSL
{
namespace secure
{

OpenSSLConnection::OpenSSLConnection( socketlayer::iSocket *rawSocket
                                    , iSSLContext *contextObject
                                    , SSL *sslOjbject )
    : m_ctx( contextObject ), m_rawSocket( rawSocket ), m_lastError( 0 )
    , m_sslObject( sslOjbject )
{
    m_readBIO = BIO_new( BIO_s_mem() );
    m_writeBIO = BIO_new( BIO_s_mem() );

    SSL_set_fd( m_sslObject, m_rawSocket->GetSocketHandle() );

    SSL_set_bio( m_sslObject, m_readBIO, m_writeBIO );
}


OpenSSLConnection::~OpenSSLConnection()
{
}


int OpenSSLConnection::Read( std::string &buffer )
{
    char encryptedBuffer[4096];
    int readSize = 0;
    char decryptedBuffer[4096];
    int returnSize = 0;

    readSize = ::recv( m_rawSocket->GetSocketHandle()
                     , encryptedBuffer
                     , sizeof( encryptedBuffer )
                     , 0 );

    if ( readSize > 0 )
    {
        bool bufferSSLReadOK = false;
        int bwrite = 0;

        while ( bufferSSLReadOK == false )
        {
            bwrite = BIO_write( m_readBIO
                              , encryptedBuffer
                              , 4096 );

            bufferSSLReadOK = ( bwrite <= 0 ) ? false : true;

            if ( bwrite <= 0 )
            {
                if ( !BIO_should_retry( m_readBIO ) )
                {
                    return -1;
                }
            }
        }

        bool sslOK = false;
        int sslRead = 0;

        while( !sslOK)
        {
            sslRead = SSL_read( m_sslObject
                , decryptedBuffer
                , sizeof (decryptedBuffer) );

            int lastSSLError = SSL_get_error( m_sslObject, sslRead );

            switch( lastSSLError )
            {
            case SSL_ERROR_NONE:
                sslOK = true;
                decryptedBuffer[sslRead] = '\0';
                buffer = std::string( decryptedBuffer );
                returnSize = readSize;
                break;

            case SSL_ERROR_WANT_READ:
                break;

            default:
                return -1;
            }
        }
    }

    return returnSize;
}


int OpenSSLConnection::Write( std::string buffer, int size )
{
    int returnValue = 0;
    int SSLWritten = 0;
    int BIORead = 0;
    char encryptedBuffer[4096] = { '\0' };

    SSLWritten = SSL_write( m_sslObject
                          , buffer.c_str()
                          , buffer.length() );
    
    if ( SSLWritten > 0 )
    {
        BIORead = BIO_read( m_writeBIO
                          , encryptedBuffer
                          , sizeof( encryptedBuffer ) );

        returnValue = m_rawSocket->Write( ( const char *)encryptedBuffer, BIORead );
    }
    else
    {
        returnValue = -1;
        m_lastError = SSL_get_error( m_sslObject, SSLWritten );
    }

    return returnValue;
}

}   //  namespace secure
}   //  namespace libSSL
