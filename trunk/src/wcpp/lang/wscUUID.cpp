#include "wscUUID.h"
#include "wsiString.h"
#include "wscThrowable.h"


void wscUUID::SwapBytes(ws_byte * buf, ws_uint i1, ws_uint i2)
{
	const ws_byte m1 = buf[i1];
	const ws_byte m2 = buf[i2];
	buf[i1] = m2;
	buf[i2] = m1;
}


void wscUUID::ParseUUID(wsiString * aStr, ws_uuid & rUuid)
{
	//  0         1         2         3
	//  0123456789012345678901234567890123456789
	// "{12345678-1234-1234-1234-1234567890ab}";
    if (aStr==WS_NULL) {
        WS_THROW( wseNullPointerException, "Parse UUID with a null string." );
    }
	const ws_char * str_buf = aStr->GetBuffer();
	const ws_int    str_len = aStr->Length();
    if (str_len != 38) {
		WS_THROW( wseNumberFormatException , "ParseUUID with a bad string format." );
    }
	if (
		(str_buf[ 0] != '{') ||
		(str_buf[ 9] != '-') ||
		(str_buf[14] != '-') ||
		(str_buf[19] != '-') ||
		(str_buf[24] != '-') ||
		(str_buf[37] != '}') 
		) {
		WS_THROW( wseNumberFormatException , "ParseUUID with a bad string format." );
	}

    ws_uuid uuid;
	uuid.m0   = StrToU32( str_buf + 1 );
	uuid.m1   = StrToU16( str_buf + 10 );
	uuid.m2   = StrToU16( str_buf + 15 );
	uuid.m3[0] = StrToU8( str_buf + 20 );
	uuid.m3[1] = StrToU8( str_buf + 22 );
	uuid.m3[2] = StrToU8( str_buf + 25 );
	uuid.m3[3] = StrToU8( str_buf + 27 );
	uuid.m3[4] = StrToU8( str_buf + 29 );
	uuid.m3[5] = StrToU8( str_buf + 31 );
	uuid.m3[6] = StrToU8( str_buf + 33 );
	uuid.m3[7] = StrToU8( str_buf + 35 );
	rUuid = uuid;
}


void wscUUID::ToString(const ws_uuid & aUuid, wsiString ** rStr)
{
	//  0         1         2         3
	//  0123456789012345678901234567890123456789
	// "{12345678-1234-1234-1234-1234567890ab}";
    if (rStr==WS_NULL) {
        WS_THROW( wseNullPointerException , "the retrieval string cannot be null." );
    }
	ws_char buf [48];
	U32ToStr( aUuid.m0, buf+1 );
	U16ToStr( aUuid.m1, buf+10 );
	U16ToStr( aUuid.m2, buf+15 );
	U8ToStr( aUuid.m3[0], buf+20 );
	U8ToStr( aUuid.m3[1], buf+22 );
	U8ToStr( aUuid.m3[2], buf+25 );
	U8ToStr( aUuid.m3[3], buf+27 );
	U8ToStr( aUuid.m3[4], buf+29 );
	U8ToStr( aUuid.m3[5], buf+31 );
	U8ToStr( aUuid.m3[6], buf+33 );
	U8ToStr( aUuid.m3[7], buf+35 );
	buf[ 0] = '{';
	buf[ 9] = '-';
	buf[14] = '-';
	buf[19] = '-';
	buf[24] = '-';
	buf[37] = '}';
	buf[38] = 0;
	ws_str str( buf, 38 );
    str.CopyTo( rStr );
}



	
ws_uint32 wscUUID::StrToU32(const ws_char* const str)
{
	ws_uint32 ret = 0;
	for (int i=0; i<8; i++) {
		const ws_char c = str[i];
		ws_byte v = 0;
		if      (('0' <= c) && (c <= '9')) {	v = (c - '0');			}
		else if (('a' <= c) && (c <= 'f')) {	v = (c - 'a') + 0x0a;	}
		else if (('A' <= c) && (c <= 'F')) {	v = (c - 'A') + 0x0a;	}
		else {	WS_THROW( wseNumberFormatException , "ParseUUID with a bad string format." );	}
		ret <<= 4;
		ret  |= v;
	}
	return ret;
}


ws_uint16 wscUUID::StrToU16(const ws_char* const str)
{
	ws_uint16 ret = 0;
	for (int i=0; i<4; i++) {
		const ws_char c = str[i];
		ws_byte v = 0;
		if      (('0' <= c) && (c <= '9')) {	v = (c - '0');			}
		else if (('a' <= c) && (c <= 'f')) {	v = (c - 'a') + 0x0a;	}
		else if (('A' <= c) && (c <= 'F')) {	v = (c - 'A') + 0x0a;	}
		else {	WS_THROW( wseNumberFormatException , "ParseUUID with a bad string format." );	}
		ret <<= 4;
		ret  |= v;
	}
	return ret;
}


ws_uint8 wscUUID::StrToU8(const ws_char* const str)
{
	ws_uint8 ret = 0;
	for (int i=0; i<2; i++) {
		const ws_char c = str[i];
		ws_byte v = 0;
		if      (('0' <= c) && (c <= '9')) {	v = (c - '0');			}
		else if (('a' <= c) && (c <= 'f')) {	v = (c - 'a') + 0x0a;	}
		else if (('A' <= c) && (c <= 'F')) {	v = (c - 'A') + 0x0a;	}
		else {	WS_THROW( wseNumberFormatException , "ParseUUID with a bad string format." );	}
		ret <<= 4;
		ret  |= v;
	}
	return ret;
}

	
void wscUUID::U32ToStr(const ws_uint32 n, ws_char* const buf)
{
	static const ws_char char_template[] = "0123456789abcdef";
	ws_uint32 numb = n;
	for (int i=7; i>=0; i--) {
		buf[i] = char_template[numb & 0x0f];
		numb>>=4;
	}
}


void wscUUID::U16ToStr(const ws_uint16 n, ws_char* const buf)
{
	static const ws_char char_template[] = "0123456789abcdef";
	ws_uint16 numb = n;
	for (int i=3; i>=0; i--) {
		buf[i] = char_template[numb & 0x0f];
		numb>>=4;
	}
}


void wscUUID::U8ToStr(const ws_uint8 n, ws_char* const buf)
{
	static const ws_char char_template[] = "0123456789abcdef";
	ws_uint8 numb = n;
	for (int i=1; i>=0; i--) {
		buf[i] = char_template[numb & 0x0f];
		numb>>=4;
	}
}




wscUUID::wscUUID(void)
{
}


wscUUID::wscUUID(const ws_uuid & src) : m_uuid(src)
{
}


wscUUID::~wscUUID(void)
{
}


ws_boolean wscUUID::InternalEquals(wsiObject * obj)
{
    if (obj) {
        ws_ptr<wsiUUID> puuid;
        obj->QueryInterface( puuid.GetIID() , (void**)(&puuid) );
        if (!(!puuid)) {
            ws_uuid uuid;
            if (puuid->GetUUID(uuid)==WS_RLT_SUCCESS) {
                return (uuid == m_uuid);
            }
        }
    }
    return WS_FALSE;
}


ws_int wscUUID::InternalHashCode(void)
{
    const ws_uint32 * buf =(const ws_uint32 *) (&m_uuid);
    ws_uint32 ret = buf[0] ^ buf[1] ^ buf[2] ^ buf[3];
    return ret;
}


ws_result wscUUID::GetUUID(ws_uuid & uuid)
{
    uuid = m_uuid;
    return WS_RLT_SUCCESS;
}


ws_result wscUUID::SetUUID(const ws_uuid & uuid)
{
    m_uuid = uuid;
    return WS_RLT_SUCCESS;
}

