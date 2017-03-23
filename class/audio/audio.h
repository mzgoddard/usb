#pragma once

#include <string.h>

typedef struct
{
    const struct
    {
        uint8_t StreamingInterfaceNumber;

        uint8_t DataINEndpointNumber;
        uint16_t DataINEndpointSize;

        uint8_t DataOUTEndpointNumber;
        uint16_t DataOUTEndpointSize;
    } Config;

    struct
    {
        bool InterfaceEnabled;
    } State;
} USB_ClassInfo_Audio_Device_t;

void audio_reset(void);
void audio_error(uint8_t status);
void audio_control_setup(void);
void audio_control_in_completion(void);
void audio_control_out_completion(void);

bool audio_configure_endpoints(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo) ATTR_NON_NULL_PTR_ARG(1);
void audio_process_control_request(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo) ATTR_NON_NULL_PTR_ARG(1);

static inline void audio_usbtask(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo)
                                        ATTR_NON_NULL_PTR_ARG(1) ATTR_ALWAYS_INLINE;
static inline void audio_usbtask(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo)
{
	(void)AudioInterfaceInfo;
}

// static inline bool audio_is_sample_received(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo)
//                                                  ATTR_NON_NULL_PTR_ARG(1) ATTR_ALWAYS_INLINE;
// static inline bool audio_is_sample_received(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo)
// {
//     if ((USB_DeviceState != DEVICE_STATE_Configured) || !(AudioInterfaceInfo->State.InterfaceEnabled))
//       return false;
//
//     Endpoint_SelectEndpoint(AudioInterfaceInfo->Config.DataOUTEndpointNumber);
//     return Endpoint_IsOUTReceived();
// }
//
// static inline bool audio_is_ready_for_next_sample(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo)
//                                                      ATTR_NON_NULL_PTR_ARG(1) ATTR_ALWAYS_INLINE;
// static inline bool audio_is_ready_for_next_sample(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo)
// {
//     if ((USB_DeviceState != DEVICE_STATE_Configured) || !(AudioInterfaceInfo->State.InterfaceEnabled))
//       return false;
//
//     Endpoint_SelectEndpoint(AudioInterfaceInfo->Config.DataINEndpointNumber);
//     return Endpoint_IsINReady();
// }
//
// static inline int8_t audio_read_sample8(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo)
//                                               ATTR_NON_NULL_PTR_ARG(1) ATTR_ALWAYS_INLINE;
// static inline int8_t audio_read_sample8(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo)
// {
//     int8_t Sample;
//
//     (void)AudioInterfaceInfo;
//
//     Sample = Endpoint_Read_Byte();
//
//     if (!(Endpoint_BytesInEndpoint()))
//       Endpoint_ClearOUT();
//
//     return Sample;
// }
//
// static inline int16_t audio_read_sample16(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo)
//                                                 ATTR_NON_NULL_PTR_ARG(1) ATTR_ALWAYS_INLINE;
// static inline int16_t audio_read_sample16(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo)
// {
//     int16_t Sample;
//
//     (void)AudioInterfaceInfo;
//
//     Sample = (int16_t)Endpoint_Read_Word_LE();
//
//     if (!(Endpoint_BytesInEndpoint()))
//       Endpoint_ClearOUT();
//
//     return Sample;
// }
//
// static inline int32_t audio_read_sample24(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo)
//                                                 ATTR_NON_NULL_PTR_ARG(1) ATTR_ALWAYS_INLINE;
// static inline int32_t audio_read_sample24(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo)
// {
//     int32_t Sample;
//
//     (void)AudioInterfaceInfo;
//
//     Sample = (((uint32_t)Endpoint_Read_Byte() << 16) | Endpoint_Read_Word_LE());
//
//     if (!(Endpoint_BytesInEndpoint()))
//       Endpoint_ClearOUT();
//
//     return Sample;
// }
//
// static inline void audio_write_sample8(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo,
//                                              const int8_t Sample) ATTR_NON_NULL_PTR_ARG(1) ATTR_ALWAYS_INLINE;
// static inline void audio_write_sample8(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo,
//                                              const int8_t Sample)
// {
//     Endpoint_Write_Byte(Sample);
//
//     if (Endpoint_BytesInEndpoint() == AudioInterfaceInfo->Config.DataINEndpointSize)
//       Endpoint_ClearIN();
// }
//
// static inline void audio_write_sample16(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo,
//                                               const int16_t Sample) ATTR_NON_NULL_PTR_ARG(1) ATTR_ALWAYS_INLINE;
// static inline void audio_write_sample16(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo,
//                                               const int16_t Sample)
// {
//     Endpoint_Write_Word_LE(Sample);
//
//     if (Endpoint_BytesInEndpoint() == AudioInterfaceInfo->Config.DataINEndpointSize)
//       Endpoint_ClearIN();
// }
//
// static inline void audio_write_sample24(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo,
//                                               const int32_t Sample) ATTR_NON_NULL_PTR_ARG(1) ATTR_ALWAYS_INLINE;
// static inline void audio_write_sample24(USB_ClassInfo_Audio_Device_t* const AudioInterfaceInfo,
//                                               const int32_t Sample)
// {
//     Endpoint_Write_Byte(Sample >> 16);
//     Endpoint_Write_Word_LE(Sample);
//
//     if (Endpoint_BytesInEndpoint() == AudioInterfaceInfo->Config.DataINEndpointSize)
//       Endpoint_ClearIN();
// }
