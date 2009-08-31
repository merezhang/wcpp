#include "wscPimapDecoder.h"
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/net/wsiDatagramPacket.h>
#include "wsiPimapPacket.h"
#include <wcpp/lang/wscString.h>


/*
************************************************************************************************************************
*   PimapDecoderReader
************************************************************************************************************************
*/


class PimapDecoderReader
{
private:
    const ws_int                m_length;
    const ws_byte * const       m_buffer;
    ws_int                      m_pos;
public:
    PimapDecoderReader( const ws_byte * buf , ws_int len );
    ~PimapDecoderReader(void);
public:
    ws_boolean IsCheckOK(void);
    ws_boolean IsEOF(void);
    ws_uint8  ReadUint8 (ws_boolean & err);
    ws_uint16 ReadUint16(ws_boolean & err);
    ws_uint32 ReadUint32(ws_boolean & err);
    void      ReadString(wsiString ** ret , ws_boolean & err);
};


PimapDecoderReader::PimapDecoderReader(const ws_byte *buf, ws_int len) : m_length(len) , m_buffer(buf) , m_pos(0)
{
}


PimapDecoderReader::~PimapDecoderReader(void)
{
}


void PimapDecoderReader::ReadString(wsiString **ret, ws_boolean &err)
{
    const ws_int pos1 = m_pos;
    m_pos += 2;
    if (m_pos > m_length) {
        err = WS_TRUE;
        return;
    }
    ws_uint16 len = 0;
    len <<= 8;      len |= m_buffer[pos1 + 0];
    len <<= 8;      len |= m_buffer[pos1 + 1];

    const ws_int pos2 = m_pos;
    m_pos += len;
    if (m_pos > m_length) {
        err = WS_TRUE;
        return;
    }
    wscString::Allocate( ret , ((const ws_char*)m_buffer)+pos2 , len );
}


ws_uint16 PimapDecoderReader::ReadUint16(ws_boolean &err)
{
    const ws_int pos = m_pos;
    m_pos += 2;
    if (m_pos > m_length) {
        err = WS_TRUE;
        return 0;
    }
    ws_uint16 ret = 0;
    ret <<= 8;      ret |= m_buffer[pos + 0];
    ret <<= 8;      ret |= m_buffer[pos + 1];
    return ret;
}


ws_uint32 PimapDecoderReader::ReadUint32(ws_boolean &err)
{
    const ws_int pos = m_pos;
    m_pos += 4;
    if (m_pos > m_length) {
        err = WS_TRUE;
        return 0;
    }
    ws_uint32 ret = 0;
    ret <<= 8;      ret |= m_buffer[pos + 0];
    ret <<= 8;      ret |= m_buffer[pos + 1];
    ret <<= 8;      ret |= m_buffer[pos + 2];
    ret <<= 8;      ret |= m_buffer[pos + 3];
    return ret;
}


ws_uint8 PimapDecoderReader::ReadUint8(ws_boolean &err)
{
    const ws_int pos = m_pos;
    m_pos += 1;
    if (m_pos > m_length) {
        err = WS_TRUE;
        return 0;
    }
    return m_buffer[pos];
}


ws_boolean PimapDecoderReader::IsCheckOK(void)
{
    ws_byte sum = 0;
    for (ws_int i=(m_length-1) ; i>=0 ; i--) {
        sum ^= m_buffer[i];
    }
    return (sum == 17);
}


ws_boolean PimapDecoderReader::IsEOF(void)
{
    return ( m_length <= m_pos );
}


/*
************************************************************************************************************************
*   wscPimapDecoder
************************************************************************************************************************
*/


WS_IMPL_ClassName_OF( wscPimapDecoder )


wscPimapDecoder::wscPimapDecoder(void)
{
}


wscPimapDecoder::~wscPimapDecoder(void)
{
}


ws_result wscPimapDecoder::Decode(wsiDatagramPacket * src, wsiPimapPacket * dest)
{
    if ((src==WS_NULL) || (dest==WS_NULL)) return WS_RLT_NULL_POINTER;

    ws_ptr<wsiByteArray> bArray;
    ws_result rlt = src->GetData( &bArray );
    if (rlt != WS_RLT_SUCCESS) return rlt;
    const ws_int srcbufsz = bArray->Length();
    const ws_int srclen   = src->GetLength();
    const ws_byte * const srcbuf = bArray->Data();
    if ( (srclen <= 0) || (srcbufsz < srclen) || (srcbuf == WS_NULL) ) {
        return WS_RLT_FAILED;
    }
    PimapDecoderReader reader( srcbuf , srclen );

    if (!reader.IsCheckOK()) return WS_RLT_FAILED;

    ws_boolean err = WS_FALSE;
    dest->SetVersion ( reader.ReadUint8(err) );
    dest->SetFlag    ( reader.ReadUint8(err) );
    dest->SetXOR     ( reader.ReadUint8(err) );
    dest->SetTransID ( reader.ReadUint8(err) );
    dest->SetUserID  ( reader.ReadUint32(err) );
    dest->SetKey     ( reader.ReadUint32(err) );
    dest->SetFunction( reader.ReadUint16(err) );
    dest->SetAddLen  ( reader.ReadUint16(err) );
    while ( ! reader.IsEOF() ) {
        const ws_uint8 param_id   = reader.ReadUint8(err);
        const ws_uint8 param_type = reader.ReadUint8(err);
        switch (param_type) {
            case wsiPimapPacket::TYPE_STRING:
                {
                    ws_ptr<wsiString> str;
                    reader.ReadString( &str , err );
                    dest->PutParam( param_id , param_type , str );
                }
                break;
            case wsiPimapPacket::TYPE_UINT16:
                dest->PutParam( param_id , param_type , reader.ReadUint16(err) );
                break;
            case wsiPimapPacket::TYPE_UINT32:
                dest->PutParam( param_id , param_type , reader.ReadUint32(err) );
                break;
            case wsiPimapPacket::TYPE_UINT8:
                dest->PutParam( param_id , param_type , reader.ReadUint8(err) );
                break;
            default:
                err = WS_TRUE;
        }
    }
    if (err) return WS_RLT_FAILED;

    return WS_RLT_SUCCESS;
}

