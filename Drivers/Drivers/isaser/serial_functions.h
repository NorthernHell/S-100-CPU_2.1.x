/**************************************************************************
File:               serial_functions.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      23-January-2002
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/


#ifndef _FBP_SERIAL_FUNCTIONS_H_
#define _FBP_SERIAL_FUNCTIONS_H_

#include <drsi0com.h>
#include <dsys0soc.h>

/* constants **************************************************************/
#define COMM_SERVER						'S'
#define COMM_CLIENT						'C'
#define RX_RINGBUF_SIZE					10240
#define RX_RINGBUF_READ_SIZE			1024
#define LINGER_TIMEOUT					5
#define MAX_BACKLOG						5
#define MAX_TCPADDRESS					16

#define LAST_ERRNO						(errno)

/* types ******************************************************************/
typedef struct
{
	typRSICOM_ID hSerialPort;
	char UseHandshake;
	char UseModemLink;
	char UseEcho;
	struct
	{
		uchar *buf;	/* RX_RINGBUF_SIZE */
		uint32 read_idx;
		uint32 write_idx;
	} rxbuf;
} sPCP_SER;

typedef struct
{
	typSOC_ID hSocket;
	typSOC_ID DataSocket;
	uint16 TcpPort;
	char TcpAddress[MAX_TCPADDRESS];
	char FirstConnect;
	int32  Errno;
} sPCP_IP;

typedef struct
{
	char IsSocketHandle;
	char UseTrace;
	char Mode;	/* COMM_CLIENT or COMM_SERVER */
	char *PortStr;
	union
	{
		sPCP_SER ser;
		sPCP_IP ip;
	}commtype;
} SERIAL_PACK;
typedef SERIAL_PACK* SERIAL_PACK_HANDLE;

 
/* function prototype */

void setIsaString
(
	void *isa_str,
	char *new_string
);

uchar ipCommOpen
	(
	SERIAL_PACK_HANDLE serial_pack_handle
	);

uchar ipCommConnect
	(
	SERIAL_PACK_HANDLE serial_pack_handle,
	char mode,
	char *msgbuf
	);

uchar ipCommDisconnect
	(
	SERIAL_PACK_HANDLE serial_pack_handle,
	char flush
	);

uchar ipCommSend
	(
	SERIAL_PACK_HANDLE serial_pack_handle,
	uchar *msg_to_send,
	int32 msg_len
	);

uchar ipCommReceive
	(
	SERIAL_PACK_HANDLE serial_pack_handle,
	uchar *isa_str_buffer,
	int32 length,
	int32 timeout_s
	);

typSTATUS ipCommClose
	(
	SERIAL_PACK_HANDLE serial_pack_handle
	);


#endif /* _FBP_SERIAL_FUNCTIONS_H_ */

/* eof ********************************************************************/

