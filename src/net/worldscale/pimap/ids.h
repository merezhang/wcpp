#include "wscPimapLibrary.h"
#include "wscPimapCoder.h"
#include "wscPimapDecoder.h"
#include "wscPimapPacket.h"


WS_IMPL_IID_OF( wsiPimapServer )
WS_IMPL_IID_OF( wsiPimapClient )
WS_IMPL_IID_OF( wsiPimapLibrary )
WS_IMPL_IID_OF( wsiPimapDecoder )
WS_IMPL_IID_OF( wsiPimapCoder )
WS_IMPL_IID_OF( wsiPimapPacket )

WS_IMPL_CID_OF( wscPimapLibrary )

WS_IMPL_ContractID_OF( wscPimapLibrary )

WS_IMPL_ClassName_OF( wscPimapLibrary )


const ws_char * const wscPimapLibrary::t_factory::s_class_name = "net.worldscale.pimap.wscPimapLibrary::t_factory";

