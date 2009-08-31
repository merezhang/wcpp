#include "wscPimapCoder.h"
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/lang/wscArray.h>
#include "wscPimapConfig.h"
#include <wcpp/net/wsiDatagramPacket.h>
#include "wsiPimapPacket.h"


/*
*******************************************************************************************************************
*   PimapCoderWriter
*******************************************************************************************************************
*/


class PimapCoderWriter
{
private:
    ws_byte * const m_buffer;
    const ws_int m_length;
    ws_int m_pos;
public:
    PimapCoderWriter(ws_byte * buf, ws_int buflen);
    ~PimapCoderWriter(void);
    
    ws_boolean IsEOF();
    ws_int GetCurrentPos(void);
    ws_int SetCurrentPos(ws_int pos);

    void WriteUint32(ws_uint32 n);
    void WriteUint16(ws_uint16 n);
    void WriteUint8 (ws_uint8 n);
    void WriteString(wsiString * str);
};


PimapCoderWriter::PimapCoderWriter(ws_byte * buf , ws_int buflen)
:   m_buffer(buf) , m_length(buflen) , m_pos(0)
{
}


PimapCoderWriter::~PimapCoderWriter(void)
{
}


ws_boolean PimapCoderWriter::IsEOF(void)
{
    return (m_length < m_pos);
}


ws_int PimapCoderWriter::GetCurrentPos(void)
{
    return m_pos;
}


ws_int PimapCoderWriter::SetCurrentPos(ws_int pos)
{
    if ((0 <= pos) && (pos <= m_length)) {
        m_pos = pos;
    }
    return m_pos;
}


void PimapCoderWriter::WriteUint32(ws_uint32 n)
{
    const ws_int pos = m_pos;
    m_pos += 4;
    if (m_length < m_pos) return;
    m_buffer[pos+0] = ((n>>24) & 0x000000ff);
    m_buffer[pos+1] = ((n>>16) & 0x000000ff);
    m_buffer[pos+2] = ((n>>8)  & 0x000000ff);
    m_buffer[pos+3] = ((n>>0)  & 0x000000ff);
}


void PimapCoderWriter::WriteUint16(ws_uint16 n)
{
    const ws_int pos = m_pos;
    m_pos += 2;
    if (m_length < m_pos) return;
    m_buffer[pos+0] = ((n>>8) & 0x00ff);
    m_buffer[pos+1] = ((n>>0) & 0x00ff);
}


void PimapCoderWriter::WriteUint8(ws_uint8 n)
{
    const ws_int pos = m_pos;
    m_pos += 1;
    if (m_length < m_pos) return;
    m_buffer[pos] = n;
}


void PimapCoderWriter::WriteString(wsiString * str)
{
    if (str==WS_NULL) return;
    const ws_int len = str->GetLength();
    const ws_char * const buf = str->GetBuffer();
    if ((len<0)||(0xffff<len)) return;
    WriteUint16( (ws_uint16) len );
    const ws_int pos = m_pos;
    m_pos += len;
    if (m_length < m_pos) return;
    wspr::ws_memcpy( m_buffer+pos , buf , len );
}


/*
*******************************************************************************************************************
*   wscPimapCoder
*******************************************************************************************************************
*/


WS_IMPL_ClassName_OF( wscPimapCoder )


wscPimapCoder::wscPimapCoder(void)
{
}


wscPimapCoder::~wscPimapCoder(void)
{
}


ws_result wscPimapCoder::Code(wsiPimapPacket * src, wsiDatagramPacket * dest)
{
    if ((src==WS_NULL) || (dest==WS_NULL)) {
        return WS_RLT_NULL_POINTER;
    }
    ws_result rlt(0);

    ws_ptr<wsiByteArray> bArray;
    rlt = dest->GetData( &bArray );
    if (!bArray) {
        rlt = NewObj<wscByteArray>( &bArray , wscPimapConfig::MAX_PACKET_SIZE );
        if (rlt!=WS_RLT_SUCCESS) return rlt;
    }
    rlt = dest->SetData( bArray );
    if (rlt!=WS_RLT_SUCCESS) return rlt;
    ws_byte * const buf = bArray->Data();
    const ws_int buflen = bArray->Length();
    PimapCoderWriter writer( buf , buflen );

    writer.WriteUint8( src->GetVersion() );
    writer.WriteUint8( src->GetFlag() );
    writer.WriteUint8( 0 );
    writer.WriteUint8( src->GetTransID() );
    //
    writer.WriteUint32( src->GetUserID() );
    writer.WriteUint32( src->GetKey() );
    //
    writer.WriteUint16( src->GetFunction() );
    writer.WriteUint16( 0 );
    //
    for (ws_uint8 id=0 ; id<250 ; id++ ) {
        ws_uint8  type = 0;
        ws_uint32 value = 0;
        ws_ptr<wsiString> str;
        if (src->GetParam(id,type,value,&str)!=WS_RLT_SUCCESS) {
            id = 250;
        }
        else {
            switch (type) {
                case wsiPimapPacket::TYPE_STRING :
                    writer.WriteUint8( id );
                    writer.WriteUint8( type );
                    writer.WriteString( str );
                    break;
                case wsiPimapPacket::TYPE_UINT8 :
                    writer.WriteUint8( id );
                    writer.WriteUint8( type );
                    writer.WriteUint8( (ws_uint8) value );
                    break;
                case wsiPimapPacket::TYPE_UINT16 :
                    writer.WriteUint8( id );
                    writer.WriteUint8( type );
                    writer.WriteUint16( (ws_uint16) value );
                    break;
                case wsiPimapPacket::TYPE_UINT32 :
                    writer.WriteUint8( id );
                    writer.WriteUint8( type );
                    writer.WriteUint32( value );
                    break;
                default:;
            }
        }
    }
    if (writer.IsEOF()) return WS_RLT_ARRAY_INDEX_OUT_OF_BOUNDS;
    const ws_int total_len = writer.GetCurrentPos();
    dest->SetLength( total_len );
    writer.SetCurrentPos( 14 );
    writer.WriteUint16( (ws_uint16) (total_len-16) );
    //
    ws_uint8 xor = 17;
    for ( ws_int i=(total_len-1) ; i>=0 ; i-- ) {
        xor ^= buf[i];
    }
    writer.SetCurrentPos( 2 );
    writer.WriteUint8( xor );
    return WS_RLT_SUCCESS;
}

