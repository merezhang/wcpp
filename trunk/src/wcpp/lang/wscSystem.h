// wscSystem.h
#ifndef __wscSystem_h__
#define __wscSystem_h__

#include "wscObject.h"
#include "wsiSystem.h"
#include "wsiString.h"


class wsiSystemService;



class wscSystem : public wscObject , public wsiSystem
{
public:
	static void GetErr(wsiPrintStream ** ret);
	static void GetIn (wsiInputStream ** ret);
	static void GetOut(wsiPrintStream ** ret);
    static void SetErr(wsiPrintStream * aPrintStream);
	static void SetIn (wsiInputStream * aInputStream);
	static void SetOut(wsiPrintStream * aPrintStream);

	static void    ArrayCopy(wsiObject * src, ws_int src_position, wsiObject * dst, ws_int dst_position, ws_int length);
	static ws_long CurrentTimeMillis(void);
	static void    Exit(ws_int status);
	static void    Gc(void);
	static void    GetProperty(wsiString * key, wsiString ** rString);
	static ws_int  IdentityHashCode(wsiObject * x);
private:
    static void GetSystemService(wsiSystemService ** ret);
};


#endif // __wsSystem_h__
