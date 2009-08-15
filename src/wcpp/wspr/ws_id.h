// wsid.h

#ifndef __wsid_h__
#define __wsid_h__

#include "ws_type.h"




typedef struct t_ws_uuid
{
	ws_uint32 m0;
	ws_uint16 m1;
	ws_uint16 m2;
	ws_uint8  m3[8];

	ws_int cmp(const t_ws_uuid & obj) const
    {
		const ws_byte* _that = reinterpret_cast<const ws_byte*>(&obj);
		const ws_byte* _this = reinterpret_cast<const ws_byte*>(this);
		for (ws_int i=0; i<sizeof(t_ws_uuid); i++) {
            const ws_byte a = _this[i];
            const ws_byte b = _that[i];
            if (a < b) return -1;
            else if (a > b) return 1;
		}
		return 0;
    }

	ws_boolean operator<(const t_ws_uuid & obj) const
	{
        return (cmp(obj) < 0);
	}

	ws_boolean operator>(const t_ws_uuid & obj) const
	{
        return (cmp(obj) > 0);
	}

	ws_boolean operator==(const t_ws_uuid & obj) const
	{
        return (cmp(obj) == 0);
	}

}
ws_uuid;


typedef struct t_ws_iid
{
	ws_uuid uuid;

	ws_boolean operator==(const t_ws_iid & obj) const		{	return (uuid == obj.uuid);	}
	ws_boolean operator<(const t_ws_iid & obj) const		{	return (uuid < obj.uuid);	}
	ws_boolean operator>(const t_ws_iid & obj) const		{	return (uuid > obj.uuid);	}

}
ws_iid;


typedef struct t_ws_cid
{
	ws_uuid uuid;

	ws_boolean operator==(const t_ws_cid & obj) const		{	return (uuid == obj.uuid);	}
	ws_boolean operator<(const t_ws_cid & obj) const		{	return (uuid < obj.uuid);	}
	ws_boolean operator>(const t_ws_cid & obj) const		{	return (uuid > obj.uuid);	}

}
ws_cid;





#define WS_IMPL_IID_OF(_iname_) const ws_iid _iname_::sIID = WS_IID_OF_##_iname_;
#define WS_IMPL_CID_OF(_cname_) const ws_cid _cname_::sCID = WS_CID_OF_##_cname_;


#define WS_IMPL_ContractID_OF(_cname_)   const ws_char * const _cname_::sContractID  = WS_ContractID_OF_##_cname_;
#define WS_IMPL_ClassName_OF(_cname_)    const ws_char * const _cname_::s_class_name = WS_ClassName_OF_##_cname_;


#endif // __wsid_h__
