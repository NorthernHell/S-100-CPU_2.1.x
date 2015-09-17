/**************************************************************************
File:               isaser_package.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
***************************************************************************
Attached documents: 

***************************************************************************
Description:			Package identification

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/
#ifndef _ISASER_PACKAGE_H /* nested Headers management */
#define _ISASER_PACKAGE_H

/* include item definition */

#include "serialset.h" /* "isa_serial_set */
#include "serialreceive.h" /* "isa_serial_receive */
#include "serialsend.h" /* "isa_serial_send */
#include "serialopen.h" /* "isa_serial_open */
#include "serialdisconnect.h" /* "isa_serial_disconnect */
#include "serialstatus.h" /* "isa_serial_status */
#include "serialconnect.h" /* "isa_serial_connect */
#include "serialclose.h" /* "isa_serial_close */

/* package definition */

#define ISA_DECLARE_PACK_ISASER \
ISA_DECLARE_PACKNAME("isaser_package") \
ISA_DECLARE_HANDLE("isa_serial_setUsfCall", isa_serial_setUsfCall) \
ISA_DECLARE_HANDLE("isa_serial_receiveUsfCall", isa_serial_receiveUsfCall) \
ISA_DECLARE_HANDLE("isa_serial_sendUsfCall", isa_serial_sendUsfCall) \
ISA_DECLARE_HANDLE("isa_serial_openUsfCall", isa_serial_openUsfCall) \
ISA_DECLARE_HANDLE("isa_serial_disconnectUsfCall", isa_serial_disconnectUsfCall) \
ISA_DECLARE_HANDLE("isa_serial_statusUsfCall", isa_serial_statusUsfCall) \
ISA_DECLARE_HANDLE("isa_serial_connectUsfCall", isa_serial_connectUsfCall) \
ISA_DECLARE_HANDLE("isa_serial_closeUsfCall", isa_serial_closeUsfCall)

#endif /* _ISASER_PACKAGE_H */

/* eof ********************************************************************/

