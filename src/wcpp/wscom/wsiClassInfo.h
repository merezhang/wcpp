#pragma once
#include <wcpp/lang/wsiobject.h>
#include <wcpp/wspr/ws_type.h>
#include <wcpp/wspr/ws_id.h>



class wsiString;
class wsiIIDsArray;




#define WS_IID_OF_wsiClassInfo      \
    { 0x7e8d273a, 0x40df, 0x45f0, { 0x97, 0xa, 0xfd, 0x8f, 0xb6, 0xb0, 0x1c, 0xbe } }
// {7E8D273A-40DF-45f0-970A-FD8FB6B01CBE}




class wsiClassInfo : public wsiObject
{
public:

	static const ws_iid sIID;

public:

    WS_METHOD( ws_result , GetHelperForLanguage      )(wsiObject ** ret , ws_uint32 aLanguage) = 0; // This method returns a language mapping specific helper object that may assist in using objects of this class in a specific language. 
    WS_METHOD( ws_result , GetInterfaces             )(wsiIIDsArray ** ret) = 0;                    // This method returns an ordered list of interfaces IIDs that instances of the class promise to implement. 
    WS_METHOD( ws_result , GetClassDescription       )(wsiString ** ret) = 0;                       // Specifies a human readable string naming the class or null. 
    WS_METHOD( ws_result , GetClassID                )(ws_cid & rClassID) = 0;                      // Specifies a ClassID through which an instance of this class can be created. 
    WS_METHOD( ws_result , GetContractID             )(wsiString ** rContractID) = 0;               // Specifies a ContractID through which an instance of this class can be created. 
    WS_METHOD( ws_uint32 , GetFlags                  )(void) = 0;                                   // Specifies various binary properties of this class. 
    WS_METHOD( ws_uint32 , GetImplementationLanguage )(void) = 0;                                   // Specifies the language type in which this class is implemented. 

};



