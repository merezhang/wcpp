#pragma once
#include "wscObject.h"
#include "wsiUUID.h"


#define WS_ClassName_OF_wscUUID     "wcpp.lang.wscUUID"


class wscUUID : public wscObject , public wsiUUID
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscUUID )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiUUID )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
public:

	static void ParseUUID(wsiString * aStr, ws_uuid & rUuid);
	static void ToString(const ws_uuid & aUuid, wsiString ** rStr);

private:

	static void SwapBytes(ws_byte * buf, ws_uint i1, ws_uint i2);

	static ws_uint32 StrToU32(const ws_char* const str);
	static ws_uint16 StrToU16(const ws_char* const str);
	static ws_uint8  StrToU8 (const ws_char* const str);

	static void U32ToStr(const ws_uint32 n, ws_char* const buf);
	static void U16ToStr(const ws_uint16 n, ws_char* const buf);
	static void U8ToStr (const ws_uint8  n, ws_char* const buf);

private:
    
    ws_uuid m_uuid;

protected:

	wscUUID(void);
	wscUUID(const ws_uuid & src);
	~wscUUID(void);

protected:

	ws_boolean  InternalEquals    (wsiObject * obj);
	ws_int      InternalHashCode  (void);

    WS_METHOD( ws_result , GetUUID )(ws_uuid & uuid);
    WS_METHOD( ws_result , SetUUID )(const ws_uuid & uuid);

};

