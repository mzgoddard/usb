#pragma once

#include <string.h>

#include <usb_standard.h>

#if !defined(AUDIO_TOTAL_SAMPLE_RATES)
    #define AUDIO_TOTAL_SAMPLE_RATES    1
#endif

#define NO_DESCRIPTOR 0

#define LANGUAGE_ID_ENG 0x0409

#define VERSION_TENS(x) (int)((x) / 10)
#define VERSION_ONES(x) (int)((x) - (10 * VERSION_TENS(x)))
#define VERSION_TENTHS(x) (int)(((x) - (int)(x)) * 10)
#define VERSION_HUNDREDTHS(x) (int)((((x) - (int)(x)) * 100) - (10 * VERSION_TENTHS(x)))

#define VERSION_BCD(x) ((((VERSION_TENS(x) << 4) | VERSION_ONES(x)) << 8) | \
                       ((VERSION_TENTHS(x) << 4) | VERSION_HUNDREDTHS(x)))

#define AUDIO_REQUEST_TYPE 0xA1

#define AUDIO_REQ_GET_CUR 0x81
#define AUDIO_REQ_SET_CUR 0x01
#define AUDIO_REQ_GET_MIN 0x82
#define AUDIO_REQ_SET_MIN 0x02
#define AUDIO_REQ_GET_MAX 0x83
#define AUDIO_REQ_SET_MAX 0x03
#define AUDIO_REQ_GET_RES 0x84
#define AUDIO_REQ_SET_RES 0x04

#define AUDIO_CHANNEL_LEFT_FRONT (1 << 0)
#define AUDIO_CHANNEL_RIGHT_FRONT (1 << 1)
#define AUDIO_CHANNEL_CENTER_FRONT (1 << 2)
#define AUDIO_CHANNEL_LOW_FREQ_ENHANCE (1 << 3)
#define AUDIO_CHANNEL_LEFT_SURROUND (1 << 4)
#define AUDIO_CHANNEL_RIGHT_SURROUND (1 << 5)
#define AUDIO_CHANNEL_LEFT_OF_CENTER (1 << 6)
#define AUDIO_CHANNEL_RIGHT_OF_CENTER (1 << 7)
#define AUDIO_CHANNEL_SURROUND (1 << 8)
#define AUDIO_CHANNEL_SIDE_LEFT (1 << 9)
#define AUDIO_CHANNEL_SIDE_RIGHT (1 << 10)
#define AUDIO_CHANNEL_TOP (1 << 11)

#define AUDIO_FEATURE_MUTE (1 << 0)
#define AUDIO_FEATURE_VOLUME (1 << 1)
#define AUDIO_FEATURE_BASS (1 << 2)
#define AUDIO_FEATURE_MID (1 << 3)
#define AUDIO_FEATURE_TREBLE (1 << 4)
#define AUDIO_FEATURE_GRAPHIC_EQUALIZER (1 << 5)
#define AUDIO_FEATURE_AUTOMATIC_GAIN (1 << 6)
#define AUDIO_FEATURE_DELAY (1 << 7)
#define AUDIO_FEATURE_BASS_BOOST (1 << 8)
#define AUDIO_FEATURE_BASS_LOUDNESS (1 << 9)

#define AUDIO_TERMINAL_UNDEFINED 0x0100
#define AUDIO_TERMINAL_STREAMING 0x0101
#define AUDIO_TERMINAL_VENDOR 0x01FF
#define AUDIO_TERMINAL_IN_UNDEFINED 0x0200
#define AUDIO_TERMINAL_IN_MIC 0x0201
#define AUDIO_TERMINAL_IN_DESKTOP_MIC 0x0202
#define AUDIO_TERMINAL_IN_PERSONAL_MIC 0x0203
#define AUDIO_TERMINAL_IN_OMNIDIR_MIC 0x0204
#define AUDIO_TERMINAL_IN_MIC_ARRAY 0x0205
#define AUDIO_TERMINAL_IN_PROCESSING_MIC 0x0206
#define AUDIO_TERMINAL_IN_OUT_UNDEFINED 0x0300
#define AUDIO_TERMINAL_OUT_SPEAKER 0x0301
#define AUDIO_TERMINAL_OUT_HEADPHONES 0x0302
#define AUDIO_TERMINAL_OUT_HEAD_MOUNTED 0x0303
#define AUDIO_TERMINAL_OUT_DESKTOP 0x0304
#define AUDIO_TERMINAL_OUT_ROOM 0x0305
#define AUDIO_TERMINAL_OUT_COMMUNICATION 0x0306
#define AUDIO_TERMINAL_OUT_LOWFREQ 0x0307

#define AUDIO_SAMPLE_FREQ(freq) {((uint32_t)freq & 0x00FFFF), (((uint32_t)freq >> 16) & 0x0000FF)}

#define AUDIO_EP_FULL_PACKETS_ONLY (1 << 7)
#define AUDIO_EP_ACCEPTS_SMALL_PACKETS (0 << 7)

enum Audio_CSInterface_AC_SubTypes_t
{
    AUDIO_DSUBTYPE_CSInterface_Header = 0x01,
    AUDIO_DSUBTYPE_CSInterface_InputTerminal = 0x02,
    AUDIO_DSUBTYPE_CSInterface_OutputTerminal = 0x03,
    AUDIO_DSUBTYPE_CSInterface_Mixer = 0x04,
    AUDIO_DSUBTYPE_CSInterface_Selector = 0x05,
    AUDIO_DSUBTYPE_CSInterface_Feature = 0x06,
    AUDIO_DSUBTYPE_CSInterface_Processing = 0x07,
    AUDIO_DSUBTYPE_CSInterface_Extension = 0x08,
};

enum Audio_CSInterface_AS_SubTypes_t
{
    AUDIO_DSUBTYPE_CSInterface_General = 0x01,
    AUDIO_DSUBTYPE_CSInterface_FormatType = 0x02,
    AUDIO_DSUBTYPE_CSInterface_FormatSpecific = 0x03,
};

enum Audio_CSEndpoint_SubTypes_t
{
    AUDIO_DSUBTYPE_CSEndpoint_General = 0x01,
};

// typedef struct
// {
//     USB_DescriptorHeader Header;
//     uint8_t Subtype;
//
//     uint8_t TerminalID;
//     uint16_t TerminalType;
//     uint8_t AssociatedOutputTerminal;
//     uint8_t TotalChannels;
//     uint16_t ChannelConfig;
//
//     uint8_t ChannelStrIndex;
//     uint8_t TerminalStrIndex;
// } USB_AudioInputTerminalDescriptor;

typedef struct
{
    uint8_t bLength;
    uint8_t bDescriptorType;

    uint8_t bDescriptorSubtype;
    uint8_t bTerminalID;
    uint16_t wTerminalType;
    uint8_t bAssocTerminal;
    uint8_t bNrChannels;
    uint16_t wChannelConfig;

    uint8_t iChannelNames;
    uint8_t iTerminal;
} __attribute__((packed)) USB_AudioInputTerminal;

// typedef struct
// {
//     USB_DescriptorHeader Header;
//     uint8_t Subtype;
//
//     uint8_t TerminalID;
//     uint16_t TerminalType;
//     uint8_t AssociatedInputTerminal;
//     uint8_t SourceID;
//
//     uint8_t TerminalStrIndex;
// } USB_Audio_Descriptor_OutputTerminal_t;

typedef struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;

	uint8_t bDescriptorSubtype;
	uint8_t bTerminalID;
	uint16_t wTerminalType;
	uint8_t bAssocTerminal;
	uint8_t bSourceID;

	uint8_t iTerminal;
} __attribute__((packed)) USB_AudioOutputTerminal;

// typedef struct
// {
//     USB_DescriptorHeader Header;
//     uint8_t Subtype;
//
//     uint16_t ACSpecification;
//     uint16_t TotalLength;
//
//     uint8_t InCollection;
//     uint8_t InterfaceNumber;
// } USB_Audio_Descriptor_Interface_AC_t;

typedef struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;

	uint8_t bDescriptorSubtype;

	uint16_t bcdADC;
	uint16_t wTotalLength;

	uint8_t bInCollection;
    uint8_t bInterfaceNumbers[8];
} __attribute__((packed)) USB_AudioControl;

// typedef struct
// {
//     USB_DescriptorHeader Header;
//     uint8_t Subtype;
//
//     uint8_t UnitID;
//     uint8_t SourceID;
//
//     uint8_t ControlSize;
//     uint8_t ChannelControls[3];
//
//     uint8_t FeatureUnitStrIndex;
// } USB_AudioFeatureUnit;

typedef struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;

	uint8_t bDescriptorSubtype;

	uint8_t bUnitID;
	uint8_t bSourceID;

	uint8_t bControlSize;
	uint8_t bmaControls[3];

	uint8_t iFeature;
} __attribute__((packed)) USB_AudioFeatureUnit;

// typedef struct
// {
//     USB_DescriptorHeader Header;
//     uint8_t Subtype;
//
//     uint8_t TerminalLink;
//
//     uint8_t FrameDelay;
//     uint16_t AudioFormat;
// } USB_Audio_Descriptor_Interface_AS_t;

typedef struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;

	uint8_t bDescriptorSubtype;

	uint8_t bTerminalLink;

	uint8_t bDelay;
	uint16_t wFormatTag;
} __attribute__((packed)) USB_AudioStream;

/** \brief 24-Bit Audio Frequency Structure.
 *
 *  Type define for a 24bit audio sample frequency structure. GCC does not contain a built in 24bit datatype,
 *  this this structure is used to build up the value instead. Fill this structure with the \ref AUDIO_SAMPLE_FREQ() macro.
 */
typedef struct
{
	uint16_t LowWord; /**< Low 16 bits of the 24-bit value. */
	uint8_t  HighByte; /**< Upper 8 bits of the 24-bit value. */
} __attribute__((packed)) USB_AudioSampleFreq;

// typedef struct
// {
//     USB_DescriptorHeader Header;
//     uint8_t Subtype;
//
//     uint8_t FormatType;
//     uint8_t Channels;
//
//     uint8_t SubFrameSize;
//     uint8_t BitResolution;
//
//     uint8_t SampleFrequencyType;
//     USB_Audio_SampleFreq_t SampleFrequencies[AUDIO_TOTAL_SAMPLE_RATES];
// } USB_Audio_Descriptor_Format_t;

typedef struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;

	uint8_t bDescriptorSubtype;

	uint8_t bFormatType;
	uint8_t bNrChannels;

	uint8_t bSubFrameSize;
	uint8_t bBitResolution;

	uint8_t bSampleFrequencyType;
	uint8_t SampleFrequencies[AUDIO_TOTAL_SAMPLE_RATES * 3];
} __attribute__((packed)) USB_AudioFormat;

// typedef struct
// {
//     USB_Descriptor_Endpoint_t Endpoint;
//
//     uint8_t Refresh;
//     uint8_t SyncEndpointNumber;
// } USB_Audio_Descriptor_StreamEndpoint_Std_t;

typedef struct
{
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bEndpointAddress;
    uint8_t bmAttributes;
    uint16_t wMaxPacketSize;
    uint8_t bInterval;

    uint8_t bRefresh;
    uint8_t bSynchAddress;
} __attribute__((packed)) USB_AudioEndpoint;

// typedef struct
// {
//     USB_DescriptorHeader Header;
//     uint8_t Subtype;
//
//     uint8_t Attributes;
//
//     uint8_t LockDelayUnits;
//     uint16_t LockDelay;
// } USB_Audio_Descriptor_StreamEndpoint_Spc_t;

typedef struct
{
    uint8_t bLength;
    uint8_t bDescriptorType;

    uint8_t bDescriptorSubtype;

    uint8_t bmAttributes;

    uint8_t bLockDelayUnits;
    uint16_t wLockDelay;
} __attribute__((packed)) USB_AudioStreamEndpoint;
