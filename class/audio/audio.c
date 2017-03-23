// #include "../../HighLevel/USBMode.h"

// void Audio_Device_ProcessControlRequest(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo)
// {
//     if (!(Endpoint_IsSETUPReceived()))
//       return;
//
//     if (USB_ControlRequest.wIndex != AudioInterfaceInfo->Config.StreamingInterfaceNumber)
//       return;
//
//     switch (USB_ControlRequest.bRequest)
//     {
//         case REQ_SetInterface:
//             if (USB_ControlRequest.bmRequestType == (REQDIR_HOSTTODEVICE | REQTYPE_STANDARD | REQREC_INTERFACE))
//             {
//                 Endpoint_ClearSETUP();
//                 Endpoint_ClearStatusStage();
//
//                 AudioInterfaceInfo->State.InterfaceEnabled = ((USB_ControlRequest.wValue & 0xFF) != 0);
//             }
//
//             break;
//     }
// }
//
// bool Audio_Device_ConfigureEndpoints(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo)
// {
//     memset(&AudioInterfaceInfo->State, 0x00, sizeof(AudioInterfaceInfo->State));
//
//     for (uint8_t EndpointNum = 1; EndpointNum < ENDPOINT_TOTAL_ENDPOINTS; EndpointNum++)
//     {
//         uint16_t Size;
//         uint8_t  Type;
//         uint8_t  Direction;
//
//         if (EndpointNum == AudioInterfaceInfo->Config.DataINEndpointNumber)
//         {
//             Size         = AudioInterfaceInfo->Config.DataINEndpointSize;
//             Direction    = ENDPOINT_DIR_IN;
//             Type         = EP_TYPE_ISOCHRONOUS;
//         }
//         else if (EndpointNum == AudioInterfaceInfo->Config.DataOUTEndpointNumber)
//         {
//             Size         = AudioInterfaceInfo->Config.DataOUTEndpointSize;
//             Direction    = ENDPOINT_DIR_OUT;
//             Type         = EP_TYPE_ISOCHRONOUS;
//         }
//         else
//         {
//             continue;
//         }
//
//         if (!(Endpoint_ConfigureEndpoint(EndpointNum, Type, Direction, Size, ENDPOINT_BANK_DOUBLE)))
//         {
//             return false;
//         }
//     }
//
//     return true;
// }
//
// #endif