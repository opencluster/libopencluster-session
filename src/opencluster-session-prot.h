#ifndef __OPENCLUSTER_SESSION_PROT_H
#define __OPENCLUSTER_SESSION_PROT_H


//--------------------------------------------------------------------------------------------------
// The Commands that are part of the protocol.

// 1 byte integer - 0x0000 to 0x0fff         0 000 xxxx xxxx xxxx (8-bit)
// 2 byte integer - 0x1000 to 0x1fff         0 001 xxxx xxxx xxxx (16-bit)
// 4 byte integer - 0x2000 to 0x2fff         0 010 xxxx xxxx xxxx (32-bit)
#define SESSION_CMD_MAX_PACKET               0x2000
#define SESSION_CMD_DATA_LENGTH              0x2001
#define SESSION_CMD_VERIFICATION_SHA256      0x2002

// 8 byte integer - 0x3000 to 0x3fff         0 011 xxxx xxxx xxxx (64-bit)
// 16 byte integer - 0x4000 to 0x4fff        0 100 xxxx xxxx xxxx (128-bit)
// 32 byte integer - 0x5000 to 0x5fff        0 101 xxxx xxxx xxxx (256-bit)
// 64 byte integer - 0x6000 to 0x6fff        0 110 xxxx xxxx xxxx (512-bit)
// No Parameters - 0x7000 to 0x7fff          0 111 xxxx xxxx xxxx
#define SESSION_CMD_NOP                      0x7000

// 1 byte-length string - 0x8000 to 0x8fff   1 000 xxxx xxxx xxxx (max 255 bytes)
#define SESSION_CMD_CERTIFICATE_ID           0x8000

// 2 byte-length string - 0x9000 to 0x9fff   1 001 xxxx xxxx xxxx (max 32k)
#define SESSION_CMD_USERNAME                 0x9000
#define SESSION_CMD_CERTIFICATE              0x9001
#define SESSION_CMD_SESSION_KEY              0x9002


// 4 byte-length string - 0xa000 to 0xafff   1 010 xxxx xxxx xxxx (max 4g)
#define SESSION_CMD_DATA                     0xa002

// 8 byte-length string - 0xb000 to 0xbfff   1 011 xxxx xxxx xxxx
// No Parameters - 0xc000 to 0xffff          1 1xx xxxx xxxx xxxx



#endif

