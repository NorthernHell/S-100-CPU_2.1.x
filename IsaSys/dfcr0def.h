/**************************************************************************
File:               dfcr0def.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      20-October-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Error File.      

Format description of defines:
#define ISA_ER_.............              ISA_ER_BASE + 0x....
 Description:  
?....message....................................
?...............................................

- Only lines that begin by "?" can be extracted.
- The number is in hexadecimal and uppercase.
***************************************************************************
Modifications: (who / date / description)
---4.01 Released---
JFO/27-Apr-1999/ Browse symbols implementation.
   Added ISA_ER_IXL_SYM_END.
EDS/28-May-1999/ 
   Corrected ISA_ER_DSA_NAME comment: no name --> invalid name

---4.02 Released---
JFO/07-Oct-1999/
   Added ISA_ER_ISXL_NEEDWAIT.
   Added ISA_ER_IXL_SYM_CORRUPTED.
   Added ISA_ER_IXL_SYM_ALREADYLOADED.
EDS/09-Nov-1999/
   Added some errno (IXD,IPC,ISXS,RSI), marked some ETCP obsolete, formated.
EDS/06-Jan-2000/
   Added ISA_ER_ISXL_RTG_NOTIMPLEM errno.

---4.03 Released---
EDS/25-Aug-2000/ Allow adding of variables in MDF
   Added ISA_ER_MDF_NOTALLOWED errno
JFO/14-Sep-2000/ Add IOs in symbols
   Added ISA_ER_IXL_SYM_LOADING.
   Added ISA_ER_IXL_SYM_BADVERSION.
   Added ISA_ER_IXL_SYM_DEV_UNKNOWN.
   Added ISA_ER_IXL_SYM_BADSYNTAX.
JFO/11-Oct-2000/
   Added ISA_ER_DSA_NOTEXIST.
JFO/23-Oct-2000/ Integration of a system socket interface.
   Added ISA_ER_SOC_...errno.
EDS/18-Nov-2000/ Mono task implementation
   Added ISA_ER_SRV_TRCERROR
EDS/08-Jan-2001/
   Added ISA_ER_ISXL_WRITE (isxl drv isa3 devlpmt)

---4.11 Released---
VMO/12-Mar-2002/ Hot restart 
   Added ISA_ER_IXL_SYM_NOTCOMPLETE

---4.12 Released---
VMO/12-June-2002/ SFC function block
   Added ISA_ER_SFCFBL_XXX

---4.13 Released---
JFO/04-Jul-2001/ Improve download.
   Added ISA_ER_IXD_CNXTIMEOUT.
   Added ISA_ER_IXD_NIDTIMEOUT.

***************************************************************************/

#ifndef _DFCR0DEF_H  /* nested Headers management */
#define _DFCR0DEF_H 


/* constants **************************************************************/

/* MAX Number of reserved Errno */
#define ISA_ER_MAXRESERVED   0x1000U

#define ISA_ER_ADDBASE(FctErrno)   ((FctErrno) + ISA_ER_BASE)
#define ISA_ER_RMBASE(FctErrno)    ((FctErrno) - ISA_ER_BASE)
#define ISA_ER_ISSYSTEM(FctErrno)  ((FctErrno) < ISA_ER_BASE)


/**************************************************************************

         INTERNAL ERRORS

**************************************************************************/
#define ISA_ER_INTERNAL                   (ISA_ER_BASE + 0x0000)
/* Description error:     
?Internal error.
*/





/**************************************************************************

         BASIC SYSTEM LAYER ERRORS

**************************************************************************/
#define ISA_ER_SYS_TOOMANYINIT            (ISA_ER_BASE + 0x0001)
/* Description error:     
?SYS: Too many inits have been done.
*/

#define ISA_ER_SYS_OWNERNUM               (ISA_ER_BASE + 0x0002)
/* Description error:     
?SYS: Bad owner number (generaly to high).
*/

#define ISA_ER_SYS_USERNUM                (ISA_ER_BASE + 0x0003)
/* Description error:     
?SYS: Bad user number (generaly to high).
*/

#define ISA_ER_SYS_OBJNUM                 (ISA_ER_BASE + 0x0004)
/* Description error:     
?SYS: Bad object number (generaly to high).
*/





/**************************************************************************

         SPACE ERRORS

**************************************************************************/
#define ISA_ER_SPC_ID                     (ISA_ER_BASE + 0x0010)
/* Description error:        
?SPC: Invalid space identifier.
*/

#define ISA_ER_0x0011                     (ISA_ER_BASE + 0x0011)
/* Description error:       
?error 0x0011.
*/

#define ISA_ER_SPC_CREATE                 (ISA_ER_BASE + 0x0012)
/* Description error:
?SPC: Cannot create memory block.
*/

#define ISA_ER_SPC_CREATE_ALREADYEXIST    (ISA_ER_BASE + 0x0013)
/* Description error:
?SPC: Cannot create memory block when already exists.
*/

#define ISA_ER_SPC_DELETE                 (ISA_ER_BASE + 0x0014) 
/* Description error:
?SPC: Cannot delete memory block.
*/

#define ISA_ER_SPC_LINK                   (ISA_ER_BASE + 0x0015)
/* Description error:
?SPC: Cannot link with memory block. The memory block has been deleted
?or not exist.
*/

#define ISA_ER_SPC_UNLINK                 (ISA_ER_BASE + 0x0016)
/* Description error:
?SPC: Cannot unlink with memory block.
*/

#define ISA_ER_SPC_SAVE                   (ISA_ER_BASE + 0x0017)
/* Description error:
?SPC: Cannot save memory block into the file.
*/

#define ISA_ER_SPC_LOAD                   (ISA_ER_BASE + 0x0018)
/* Description error:
?SPC: Cannot load space into memory block.
*/

#define ISA_ER_SPC_LOAD_NOTEXIST          (ISA_ER_BASE + 0x0019)
/* Description error:
?SPC: Cannot load space, space does not exist.
*/

#define ISA_ER_SPC_BKUP_REMOVE            (ISA_ER_BASE + 0x001A)
/* Description error:
?SPC: Cannot remove saved space.
*/





/**************************************************************************

         SEMAPHORE ERRORS

**************************************************************************/
#define ISA_ER_SEM_ID                     (ISA_ER_BASE + 0x0020)
/* Description error:       
?SEM: Invalid semaphore identifier.
*/

#define ISA_ER_SEM_0x0021                 (ISA_ER_BASE + 0x0021)
/* Description error:       
?error 0x0021.
*/

#define ISA_ER_SEM_CREATE                 (ISA_ER_BASE + 0x0022)
/* Description error:       
?SEM: Cannot create semaphore.
*/

#define ISA_ER_SEM_CREATE_ALREADYEXIST    (ISA_ER_BASE + 0x0023)
/* Description error:       
?SEM: Cannot create semaphore when already exists.
*/

#define ISA_ER_SEM_DELETE                 (ISA_ER_BASE + 0x0024)
/* Description error:       
?SEM: Cannot delete semaphore.
*/

#define ISA_ER_SEM_OPEN                   (ISA_ER_BASE + 0x0025)
/* Description error:       
?SEM: Cannot link with semaphore. The sempahore has been deleted or not exist.
*/

#define ISA_ER_SEM_CLOSE                  (ISA_ER_BASE + 0x0026)
/* Description error:       
?SEM: Cannot close semaphore.
*/

#define ISA_ER_SEM_TAKE                   (ISA_ER_BASE + 0x0027)
/* Description error:       
?SEM: Cannot take semaphore.
*/

#define ISA_ER_SEM_TAKETIMEOUT            (ISA_ER_BASE + 0x0028)
/* Description error:       
?SEM: Cannot take semaphore (time out).
*/

#define ISA_ER_SEM_GIVE                   (ISA_ER_BASE + 0x0029)
/* Description error:       
?SEM: Cannot give semaphore.
*/





/**************************************************************************

         MESSAGE QUEUE ERRORS

**************************************************************************/
#define ISA_ER_MSGQ_ID                    (ISA_ER_BASE + 0x0030)
/* Description error:
?MSGQ: Invalid message queue identifier.
*/

#define ISA_ER_MSGQ_CREATE                (ISA_ER_BASE + 0x0031)
/* Description error:       
?MSGQ: Cannot create message queue.
*/

#define ISA_ER_MSGQ_CREATE_ALREADYEXIST   (ISA_ER_BASE + 0x0032)
/* Description error:
?MSGQ: Cannot Create message queue when already exist.
*/

#define ISA_ER_MSGQ_CREATE_SIZE           (ISA_ER_BASE + 0x0033)
/* Description error:
?MSGQ: Cannot create message queue, the size of message queue is too large.
*/

#define ISA_ER_MSGQ_CREATE_MSGTOOLONG     (ISA_ER_BASE + 0x0034)
/* Description error:
?MSGQ: Cannot create message queue, the length of messages is too large.
*/

#define ISA_ER_MSGQ_DEL                   (ISA_ER_BASE + 0x0035)
/* Description error:     
?MSGQ: Cannot delete message queue.
*/

#define ISA_ER_MSGQ_OPEN                  (ISA_ER_BASE + 0x0036)
/* Description error:
?MSGQ: Cannot link with message queue. The message queue has been
?deleted or not exist.
*/

#define ISA_ER_MSGQ_CLOSE                 (ISA_ER_BASE + 0x0037)
/* Description error:     
?MSGQ: Cannot close message queue.
*/

#define ISA_ER_MSGQ_SEND                  (ISA_ER_BASE + 0x0038)
/* Description error:     
?MSGQ: Cannot send message to message queue.
*/

#define ISA_ER_MSGQ_SEND_TIMEOUT          (ISA_ER_BASE + 0x0039)
/* Description error:
?MSGQ: Cannot send message, time out.
*/

#define ISA_ER_MSGQ_SEND_TOOLONG          (ISA_ER_BASE + 0x003A)
/* Description error:
?MSGQ: Cannot send message, message is too large.
*/

#define ISA_ER_MSGQ_SEND_PRIORITY         (ISA_ER_BASE + 0x003B)
/* Description error:
?MSGQ: Priority to send message is unknown.
*/

#define ISA_ER_MSGQ_RCV                   (ISA_ER_BASE + 0x003C)
/* Description error:
?MSGQ: Cannot read message from message queue.
*/

#define ISA_ER_MSGQ_RCV_TIMEOUT           (ISA_ER_BASE + 0x003D)
/* Description error:       
?MSGQ: Time out is reached in receive message.
*/

#define ISA_ER_MSGQ_DISCARDED             (ISA_ER_BASE + 0x003E)
/* Description error:
?MSGQ: The message is discarded. The buffer is too small.
*/

#define ISA_ER_MSGQ_SEND_OVERFLOW         ISA_ER_BASE + 0x003F
/* Description error:
?MSGQ: Cannot send message, no more message available from pool.
*/



/**************************************************************************

         NOTIFICATION ERRORS

**************************************************************************/
#define ISA_ER_NTF_INSTALL                (ISA_ER_BASE + 0x0050)
/* Description error:       
?NTF: Cannot install handler routine.
*/

#define ISA_ER_NTF_OPEN                   (ISA_ER_BASE + 0x0051)
/* Description error:
?NTF: Cannot open notification.
*/

#define ISA_ER_NTF_SIGNAL                 (ISA_ER_BASE + 0x0052)
/* Description error:
?NTF: Cannot send notification, invalid notif signal identifier.
*/





/**************************************************************************

         DATA SEQUENTIAL ACCESS ERRORS

**************************************************************************/
#define ISA_ER_DSA_NAME                   (ISA_ER_BASE + 0x0060)
/* Description error:       
?DSA: Invalid name.
*/

#define ISA_ER_DSA_OPEN                   (ISA_ER_BASE + 0x0061)
/* Description error:       
?DSA: Cannot open DSA.
*/

#define ISA_ER_DSA_REMOVE                 (ISA_ER_BASE + 0x0062)
/* Description error:       
?DSA: Cannot remove DSA.
*/

#define ISA_ER_DSA_CREATE                 (ISA_ER_BASE + 0x0063)
/* Description error:       
?DSA: Cannot create DSA.
*/

#define ISA_ER_DSA_WRITE                  (ISA_ER_BASE + 0x0064)
/* Description error:       
?DSA: Error in writing DSA.
*/

#define ISA_ER_DSA_READ                   (ISA_ER_BASE + 0x0065)
/* Description error:       
?DSA: Error in reading DSA.
*/

#define ISA_ER_DSA_NOTEXIST               (ISA_ER_BASE + 0x0066)
/* Description error:       
?DSA: DSA do not exist.
*/

#define ISA_ER_DSA_INIT                   (ISA_ER_BASE + 0x0067)
/* Description error:       
?DSA: DSA do not exist.
*/

#define ISA_ER_DSA_SEEK                   (ISA_ER_BASE + 0x0068)
/* Description error:       
?DSA: Error in reading DSA.
*/




/**************************************************************************

         TASK ERRORS

**************************************************************************/
#define ISA_ER_TSK_NOTRUNNING             (ISA_ER_BASE + 0x0070)
/* Description error:       
?TSK: Task is not running.
*/

#define ISA_ER_TSK_CREATE                 (ISA_ER_BASE + 0x0071)
/* Description error:       
?TSK: Cannot create task.
*/

#define ISA_ER_TSK_TERMINATE              (ISA_ER_BASE + 0x0072)
/* Description error:       
?TSK: Cannot terminate task.
*/

#define ISA_ER_THR_CREATE                 (ISA_ER_BASE + 0x0073)
/* Description error:
?THR: Cannot create thread.
*/

#define ISA_ER_THR_TERMINATE              (ISA_ER_BASE + 0x0074)
/* Description error:
?THR: Cannot terminate thread.
*/

#ifdef ITGTDEF_IEC61850_SRV
#define ISA_ER_TSK_IEC61850_RESTART       (ISA_ER_BASE + 0x0075)
/* Description error:
?THR: 61850 Server Restarting.
*/

#define ISA_ER_TSK_IEC61850_STOP		  (ISA_ER_BASE + 0x0076)
/* Description error:
?THR: 61850 Server stopping.
*/
#endif

/**************************************************************************

         SOCKET ERRORS

**************************************************************************/
#define ISA_ER_SOC_INIT                   (ISA_ER_BASE + 0x0080)
/* Description error:       
?SOC: Socket initialization failed.
*/

#define ISA_ER_SOC_CREATE                 (ISA_ER_BASE + 0x0081)
/* Description error:       
?SOC: Cannot create socket.
*/

#define ISA_ER_SOC_BIND                   (ISA_ER_BASE + 0x0082)
/* Description error:       
?SOC: Cannot bind socket.
*/

#define ISA_ER_SOC_LISTEN                 (ISA_ER_BASE + 0x0083)
/* Description error:       
?SOC: Cannot listen socket.
*/

#define ISA_ER_SOC_ACCEPT                 (ISA_ER_BASE + 0x0084)
/* Description error:       
?SOC: Accept connection failed.
*/

#define ISA_ER_SOC_ADDRESS                (ISA_ER_BASE + 0x0085)
/* Description error:       
?SOC: Invalid address.
*/

#define ISA_ER_SOC_CONNECT                (ISA_ER_BASE + 0x0086)
/* Description error:       
?SOC: Connect has failed.
*/

#define ISA_ER_SOC_BROKEN                 (ISA_ER_BASE + 0x0087)
/* Description error:       
?SOC: Connection is broken.
*/

#define ISA_ER_SOC_RECEIVE                (ISA_ER_BASE + 0x0088)
/* Description error:       
?SOC: Receive has failed.
*/

#define ISA_ER_SOC_SEND                   (ISA_ER_BASE + 0x0089)
/* Description error:       
?SOC: Send has failed.
*/

#define ISA_ER_SOC_OPTION                 (ISA_ER_BASE + 0x008A)
/* Description error:       
?SOC: Change option has failed.
*/

#define ISA_ER_SOC_NOTIMPLEMENTED         (ISA_ER_BASE + 0x008B)
/* Description error:       
?SOC: Command not implemented.
*/





/**************************************************************************

         KERNEL CORE ERRORS 

**************************************************************************/
/* 0x100 to 0x200*/
/**************************************************************************

   KERNEL RDCC CHECK ERRORS 

**************************************************************************/
#define ISA_ER_RDCC_BADTGTNAME            (ISA_ER_BASE + 0x0100)
/* Description error:     
?RDCC: Target name mismatch.
*/

#define ISA_ER_RDCC_BADRDCCVERS           (ISA_ER_BASE + 0x0101)
/* Description error:     
?RDCC: Version of generated code & conf mismatch.
*/

#define ISA_ER_RDCC_BADRDBCRC             (ISA_ER_BASE + 0x0102)
/* Description error:     
?RDCC: Data base CRC mismatch.
*/

#define ISA_ER_RDCC_BADMODNAME            (ISA_ER_BASE + 0x0103)
/* Description error:     
?RDCC: Module name mismatch.
*/

#define ISA_ER_RDCC_BADRESNAME            (ISA_ER_BASE + 0x0104)
/* Description error:     
?RDCC: Resource name mismatch.
*/

#define ISA_ER_RDCC_CORRUPTMODULE         (ISA_ER_BASE + 0x0105)
/* Description error:     
?RDCC: Corrupted module.
*/

/**************************************************************************

   KERNEL LOADING ERRORS 

**************************************************************************/
#define ISA_ER_LDG_TGTNONSGMTD            (ISA_ER_BASE + 0x0110)
/* Description error:     
?K_LDG: Target segmentation mismatch.
*/

#define ISA_ER_LDG_TOOMANYBLK             (ISA_ER_BASE + 0x0111)
/* Description error:     
?K_LDG: Too many blocks of memory to allocate.
*/

#define ISA_ER_LDG_SYSVAOVERLAP           (ISA_ER_BASE + 0x0112)
/* Description error:     
?K_LDG: System variables overlap.
*/

/**************************************************************************

   KERNEL VARIABLE BINDING ERRORS 

**************************************************************************/
#define ISA_ER_KVB_MEMTOOSHORT            (ISA_ER_BASE + 0x0120)
/* Description error:     
?KVB: Memory allocated is too short.
*/

#define ISA_ER_KVB_DRIVERLOAD             (ISA_ER_BASE + 0x0121)
/* Description error:     
?KVB: Cannot load driver.
*/

#define ISA_ER_KVB_DRVNOTLOADED           (ISA_ER_BASE + 0x0122)
/* Description error:     
?KVB: Driver is not loaded.
*/

#define ISA_ER_KVB_DRVINVALID             (ISA_ER_BASE + 0x0123)
/* Description error:     
?KVB: Invalid driver.
*/

/**************************************************************************

   KERNEL ON LINE MODIF ERRORS 

**************************************************************************/
#define ISA_ER_MDF_NOTINIT                (ISA_ER_BASE + 0x0130)
/* Description error:     
?K_MDF: On line modification not initialized.
*/

#define ISA_ER_MDF_ZERODATA               (ISA_ER_BASE + 0x0131)
/* Description error:     
?K_MDF: Cannot on line modifiate zero size delta.
*/

#define ISA_ER_MDF_MEMTOOSHORT            (ISA_ER_BASE + 0x0132)
/* Description error:     
?K_MDF: Not enough memory for on line modifications.
*/

#define ISA_ER_MDF_NOMODIF                (ISA_ER_BASE + 0x0133)
/* Description error:     
?K_MDF: No new modifications to update.
*/

#define ISA_ER_MDF_CHKPOUOBJ              (ISA_ER_BASE + 0x0134)
/* Description error:     
?K_MDF: Cannot update Pou (new objects within it).
*/

#define ISA_ER_MDF_SAVENOCODE             (ISA_ER_BASE + 0x0135)
/* Description error:     
?K_MDF: Cannot save modifications, code is not saved. 
*/

#define ISA_ER_MDF_NOTALLOWED             (ISA_ER_BASE + 0x0136)
/* Description error:     
?K_MDF: Changes are not allowed.
*/

/**************************************************************************

   SFC FUNCTION BLOCK ERRORS 

**************************************************************************/
#define ISA_ER_SFCFBL_SPC_PRESENT          (ISA_ER_BASE + 0x0140)
/* Description error:     
?SFCFBL: Error when initializing SFC function block. Space is present.
*/

#define ISA_ER_SFCFBL_SPC_ALLOC            (ISA_ER_BASE + 0x0141)
/* Description error:     
?SFCFBL: Error when initializing SFC function block. Space allocation failed
*/

#define ISA_ER_SFCFBL_TBL_CORRUPTED        (ISA_ER_BASE + 0x0142)
/* Description error:     
?SFCFBL: Table are corrupted
*/

/**************************************************************************

   KERNEL MISCELLANEOUS ERRORS 

**************************************************************************/
#define ISA_ER_KER_BADSLAVENUM            (ISA_ER_BASE + 0x0180)
/* Description error:
?KER: Slave number not allowed.
*/

#define ISA_ER_KER_BADSTATE               (ISA_ER_BASE + 0x0181)
/* Description error:     
?KER: kernel is not in appropriate state.
*/

#define ISA_ER_KMP_BADPARAM               (ISA_ER_BASE + 0x0182)
/* Description error:     
?KMP: Bad parameters in request.
*/





/**************************************************************************

         SERVER ERRORS

**************************************************************************/
#define ISA_ER_SRV_MEMORY                 (ISA_ER_BASE + 0x0200)
/* Description error:
?SRV: Cannot allocate memory for server.
*/

#define ISA_ER_SRV_MSGQ                   (ISA_ER_BASE + 0x0201)
/* Description error:
?SRV: Cannot create message queue for connection to server.
*/

#define ISA_ER_SRV_LENGTHBUFFER           (ISA_ER_BASE + 0x0202)
/* Description error:
If maximum length of buffer is less than length of connect 
message then exit with error from server.
?SRV: Size of server buffer is smaller than connection message.
*/

#define ISA_ER_SRV_DELCNX                 (ISA_ER_BASE + 0x0203)
/* Description error:
?SRV: Cannot remove connection from server
*/

#define ISA_ER_SRV_FULLCONNECT            (ISA_ER_BASE + 0x0204)
/* Description error:
?SRV: No more connection available.
*/

#define ISA_ER_SRV_LINKMSGQ               (ISA_ER_BASE + 0x0205)
/* Description error:
?SRV: Cannot link with client's message queue.
*/

#define ISA_ER_SRV_BADCNX                 (ISA_ER_BASE + 0x0206)
/* Description error:
?SRV: Invalid connection identifier. Try to read a message from an
?invalid connection.
*/

#define ISA_ER_SRV_MSGDISCARDED           (ISA_ER_BASE + 0x0207)
/* Description error:
The question that the server read is larger than its buffer.
?SRV: The question is discarded.
*/

#define ISA_ER_SRV_RCVTIMEOUT             (ISA_ER_BASE + 0x0208)
/* Description error:
?SRV: Time out in received message. 
*/

#define ISA_ER_SRV_TRCERROR               (ISA_ER_BASE + 0x0209)
/* Description error:
?SRV: Server has replied with a bad TRC.
*/




/**************************************************************************

         CONFIGURATION MANAGER ERRORS

**************************************************************************/
/* 0x0300 to 0x0400 */
#define ISA_ER_CMG_KER_START              (ISA_ER_BASE + 0x0300)
/* Description error:
?CMG: Cannot start new kernel. 
*/

#define ISA_ER_CMG_KER_ALREADYRUNNING     (ISA_ER_BASE + 0x0301)
/* Description error:
?CMG: Kernel is already running. 
*/

#define ISA_ER_CMG_KER_NOTRUNNING         (ISA_ER_BASE + 0x0302)
/* Description error:
?CMG: Kernel is not running.
*/

#define ISA_ER_CMG_MIS_START              (ISA_ER_BASE + 0x0310)
/* Description error:
?CMG: Cannot start task.
*/





/**************************************************************************

         ISAGRAF EXCHANGE DISPATCHER ERRORS

**************************************************************************/
#define ISA_ER_IXD_ALLOC                  (ISA_ER_BASE + 0x0400)
/* Description error:     
?IXD: Allocation error.
*/
#define ISA_ER_IXD_RES_NOT_FOUND          (ISA_ER_BASE + 0x0401)
/* Description error:     
?IXD: Trying to connect to unknown resource.
*/

#define ISA_ER_IXD_CFG_NOT_LOAD           (ISA_ER_BASE + 0x0402)       
/* Description error:     
?IXD: Network configuration not loaded 
*/
#define ISA_ER_IXD_CFG_NOT_FOUND          (ISA_ER_BASE + 0x0403)
/* Description error:     
?IXD: Network configuration not found.
*/
#define ISA_ER_IXD_SYSTEM                 (ISA_ER_BASE + 0x0404) 
/* Description error:     
?IXD: Operation fails due to system error.
*/

#define ISA_ER_IXD_DATA_TO_CLOSED_CX      (ISA_ER_BASE + 0x0405)
/* Description error:     
?IXD: Received data for a closed connection.
*/

#define ISA_ER_IXD_NO_CNX_AVAILABLE       (ISA_ER_BASE + 0x0406)
/* Description error:     
?IXD: No more connection available.
*/

#define ISA_ER_IXD_BAD_CNX_ID             (ISA_ER_BASE + 0x0407)
/* Description error:     
?IXD: Bad connection identifier.
*/

#define ISA_ER_IXD_TOOMANY_MSG_ATATIME    (ISA_ER_BASE + 0x0408)
/* Description error:     
?IXD: Too many pending message at a time.
*/

#define ISA_ER_IXD_MSGOVERFLOW            (ISA_ER_BASE + 0x0409)
/* Description error: 
?IXD: IXD buffer is too short.
*/

#define ISA_ER_IXD_CNXTIMEOUT             (ISA_ER_BASE + 0x040A)
/* Description error: 
?IXD: Connection timeout.
*/

#define ISA_ER_IXD_NIDTIMEOUT             (ISA_ER_BASE + 0x040B)
/* Description error: 
?IXD: Request timeout.
*/


/**************************************************************************

         CHANNEL REPLACEMENT UNIT ERRORS

**************************************************************************/
#define ISA_ER_CRU_BAD_CH_ID              (ISA_ER_BASE + 0x0410)
/* Description error:     
?CRU: Bad channel identifier.
*/
#define ISA_ER_CRU_CH_TABLE_FULL          (ISA_ER_BASE + 0x0411)
/* Description error:     
?CRU: Channel table full.
*/
#define ISA_ER_CRU_CX_REFUSED             (ISA_ER_BASE + 0x0412)
/* Description error:     
?CRU: Connection refused.
*/
#define ISA_ER_CRU_NO_EFFECT              (ISA_ER_BASE + 0x0413)
/* Description error:     
?CRU: Operation has no effect.
*/
#define ISA_ER_CRU_CLOSED_CX              (ISA_ER_BASE + 0x0414)
/* Description error:     
?CRU: Attempt to access to closed socket.
*/
#define ISA_ER_CRU_NO_IXD                 (ISA_ER_BASE + 0x0415)
/* Description error:     
?CRU: No IXD to accept connection.
*/
#define ISA_ER_CRU_OUT_OF_SPACE           (ISA_ER_BASE + 0x0416)
/* Description error:     
?CRU: Connection refused (out of space).
*/

#define ISA_ER_CRU_BAD_PARAM              (ISA_ER_BASE + 0x0417)
/* Description error:     
?CRU: Bad parameters related to channel operation.
*/
#define ISA_ER_CRU_OVERLOADED             (ISA_ER_BASE + 0x0418)
/* Description error:     
?CRU: Server is overloaded: Retry later.
*/



/**************************************************************************

         VARIABLES REPLACEMENT UNIT ERRORS

**************************************************************************/
#define ISA_ER_VRU_DXS_FULL               (ISA_ER_BASE + 0x0420)
/* Description error:     
?VRU: Error during binding: common Data eXchange Space full.
*/

#define ISA_ER_VRU_BIND_FAIL              (ISA_ER_BASE + 0x0421)
/* Description error:     
?VRU: Cannot link to producer.
*/
#define ISA_ER_VRU_BAD_PARAM              (ISA_ER_BASE + 0x0422)
/* Description error:     
?VRU: Bad binding parameter.
*/



/**************************************************************************

         NETWORK ERRORS

**************************************************************************/
#define ISA_ER_NET_CFG_NOT_LOADED         (ISA_ER_BASE + 0x0430)
/* Description error:     
?NET-CFG: There is no network configuration table.
*/

#define ISA_ER_NET_RES_NOT_FOUND          (ISA_ER_BASE + 0x0431)
/* Description error:     
?NET: Resource not found.
*/

#define ISA_ER_NET_CONVFAILED             (ISA_ER_BASE + 0x0432)
/* Description error:     
?NET: Variable conversion failed.
*/



/**************************************************************************

         IPC ERRORS

**************************************************************************/
#define ISA_ER_IPC_TIMEOUT               (ISA_ER_BASE + 0x0440)
/* Description error:     
?IPC: IPC is in Timeout mode.
*/

#define ISA_ER_IPC_DQ_ALREADY_CONNECTED  (ISA_ER_BASE + 0x0441)
/* Description error:      
?IPC: The IPC server is already connected to a default queue.
*/

#define ISA_ER_IPC_NO_CNX_AVALAIBLE      (ISA_ER_BASE + 0x0442)
/* Description error:      
?IPC: The IPC server is full.
*/





/**************************************************************************

         ISXL ERRORS

**************************************************************************/
#define ISA_ER_ISXL_CONFIG                (ISA_ER_BASE + 0x0500)
/* Description error:
?ISXL: Memory block allocated for configuration is too short.
*/

#define ISA_ER_ISXL_CONNECT               (ISA_ER_BASE + 0x0501) 
/* Description error: 
?ISXL: Cannot establishe connection.
*/

#define ISA_ER_ISXL_DISCONNECT            (ISA_ER_BASE + 0x0502)  
/* Description error:
?ISXL: Cannot remove connection.
*/

#define ISA_ER_ISXL_READ                  (ISA_ER_BASE + 0x0503)  
/* Description error:   
?ISXL: Cannot read variables.
*/

#define ISA_ER_ISXL_CFG_TOOLATE           (ISA_ER_BASE + 0x0504)
/* Description error:     
?ISXL: Too late too change configuration (may be connection already 
?      established).
*/

#define ISA_ER_ISXL_CONFIGPARAM           (ISA_ER_BASE + 0x0505)
/* Description error:  
?ISXL: Cannot set configuration parameters.
*/

#define ISA_ER_ISXL_CONNECTMEM            (ISA_ER_BASE + 0x0506)
/* Description error:  
?ISXL: The memory block allocated for connection is too short.
*/

#define ISA_ER_ISXL_TIMEOUT               (ISA_ER_BASE + 0x0507)
/* Description error: 
?ISXL: Time out.
*/

#define ISA_ER_ISXL_TRANSPORTFAILED       (ISA_ER_BASE + 0x0508)
/* Description error:
?ISXL: An error occur during the transport of message.
*/

#define ISA_ER_ISXL_RQ                    (ISA_ER_BASE + 0x0509)
/* Description error:  
?ISXL: The RQ code not coresponding.
*/

#define ISA_ER_ISXL_OVERFLOW              (ISA_ER_BASE + 0x050A)
/* Description error:   
?ISXL: The maximum capacity of the buffer is reached.
*/

#define ISA_ER_ISXL_NOTIFID               (ISA_ER_BASE + 0x050B)
/* Description error: 
?ISXL: The notification identifier is wrong.
*/

#define ISA_ER_ISXL_RC                    (ISA_ER_BASE + 0x050C)
/* Description error: 
?ISXL: Bad return check or error during the transport.
*/

#define ISA_ER_ISXL_DELCNX                (ISA_ER_BASE + 0x050D)
/* Description error:  
?ISXL: Cannot remove connection.
*/

#define ISA_ER_ISXL_HEADERTOOSMALL        (ISA_ER_BASE + 0x050E)
/* Description error:
?ISXL: This function required a header for the buffer.
*/

#define ISA_ER_ISXL_UNKNOWNTYPE           (ISA_ER_BASE + 0x050F)
/* Description error:  
?ISXL: Unknow type.
*/

#define ISA_ER_ISXL_BADVANUMBER           (ISA_ER_BASE + 0x0510)
/* Description error:  
?ISXL: Bad index number.
*/

#define ISA_ER_ISXL_STRTDLG               (ISA_ER_BASE + 0x0511)
/* Description error:  
?ISXL: Start dialog is not allowed (maybe dialog is already established).
*/

#define ISA_ER_ISXL_STPDLG                (ISA_ER_BASE + 0x0512)
/* Description error:
?ISXL: Stop dialog is not allowed.
*/

#define ISA_ER_ISXL_STRTDLGFAILED         (ISA_ER_BASE + 0x0513)
/* Description error:       
?ISXL: Start dialog has failed.
*/

#define ISA_ER_ISXL_STPDLGFAILED          (ISA_ER_BASE + 0x0514)
/* Description error:
?ISXL: An error has occurred during stop dialog procedure.
*/

#define ISA_ER_ISXL_STRTINPROG            (ISA_ER_BASE + 0x0515)
/* Description error:
?ISXL: Start not in progress.
*/

#define ISA_ER_ISXL_STPINPROG             (ISA_ER_BASE + 0x0516)
/* Description error:
?ISXL: Stop not in progress.
*/

#define ISA_ER_ISXL_DLG_NOT_STARTED       (ISA_ER_BASE + 0x0518)
/* Description error:     
?ISXL: Dialog is not established.
*/

#define ISA_ER_ISXL_VARDESC               (ISA_ER_BASE + 0x0519)
/* Description error:
?ISXL: Error in variable description.
*/

#define ISA_ER_ISXL_MTH_NO_AVBLE          (ISA_ER_BASE + 0x051A)
/* Description error:
?ISXL: Method not provided by the driver or invalid method.
*/

#define ISA_ER_ISXL_SERVICE               (ISA_ER_BASE + 0x051B)
/* Description error:
?ISXL: Service not provided by the driver or invalid service.
*/

#define ISA_ER_ISXL_DATAOVERFLOW          (ISA_ER_BASE + 0x051C)
/* Description error:
?ISXL: Size allowed for this variable is too short.
*/

#define ISA_ER_ISXL_CNX_1BYRESOURCE       (ISA_ER_BASE + 0x051D)
/* Description error :      
?ISXL: Only one connection by resource and by method allowed.
*/

#define ISA_ER_ISXL_CNX_EXTRAPARAM        (ISA_ER_BASE + 0x051F)
/* Description error:     
?ISXL: Bad extra parameters for connection.
*/

#define ISA_ER_ISXL_NEEDWAIT              (ISA_ER_BASE + 0x0520)
/* Description error:     
?ISXL: Request cannot be proceeded, retry later.
*/

#define ISA_ER_ISXS_NO_FREE_CNX           (ISA_ER_BASE + 0x0521)
/* Description error:      
?ISXS: Cannot establishe connection, No more free IXS connection available.
*/

#define ISA_ER_ISXL_RTG_NOTIMPLEM         (ISA_ER_BASE + 0x0522)
/* Description error:      
?ISXL: Routing feature is not implemented.
*/

#define ISA_ER_ISXL_WRITE                 (ISA_ER_BASE + 0x0523)  
/* Description error:   
?ISXL: Cannot write variables.
*/





/**************************************************************************

         ISAGRAF EXCHANGE LAYER ERRORS

**************************************************************************/
#define ISA_ER_IXL_ID                     (ISA_ER_BASE + 0x0530)
/* Description error:   
?IXL: Invalid IXL identifier.
*/

#define ISA_ER_IXL_TOOMANYINIT            (ISA_ER_BASE + 0x0531)
/* Description error:     
?IXL: Too many call to IXL init.
*/

#define ISA_ER_IXL_INITCLIENTNUM          (ISA_ER_BASE + 0x0532)
/* Description error:     
?IXL: Clients cannot have the same number.
*/

#define ISA_ER_IXL_REGISTRATIONOK         (ISA_ER_BASE + 0x0533)
/* Description error:
?IXL: The configuration completed successfully.
*/

#define ISA_ER_IXL_REGISTERNAME           (ISA_ER_BASE + 0x0534)
/* Description error:     
?IXL: Cannot register the driver, its name is invalid.
*/

#define ISA_ER_IXL_REGISTER               (ISA_ER_BASE + 0x0535)
/* Description error:   
?IXL: Cannot register the driver, a parameter is NULL.
*/

#define ISA_ER_IXL_MAXDRV                 (ISA_ER_BASE + 0x0536)
/* Description error:
?IXL: Cannot register driver, maximum driver is reached.
*/

#define ISA_ER_IXL_CONFIGDRIVER           (ISA_ER_BASE + 0x0537)
/* Description error:      
?IXL: Cannot configure all drivers.
*/

#define ISA_ER_IXL_BADCNXID               (ISA_ER_BASE + 0x0538)
/* Description error:      
?IXL: Invalid connection identifier.
*/

#define ISA_ER_IXL_MAXCNX                 (ISA_ER_BASE + 0x0539)
/* Description error:      
?IXL: Cannot establishe connection, maximum connection is reached.
*/

#define ISA_ER_IXL_UNKNOWNDRV             (ISA_ER_BASE + 0x053A)
/* Description error: 
?IXL: Cannot establishe connection, driver is unknown.
*/

#define ISA_ER_IXL_MSGOVERFLOW            (ISA_ER_BASE + 0x053B)
/* Description error: 
?IXL: IXL buffer is too short.
*/

#define ISA_ER_IXL_BADCAPS                (ISA_ER_BASE + 0x053C)
/* Description error:  
?IXL: This capability is not implemented.
*/

#define ISA_ER_IXL_PARAM                  (ISA_ER_BASE + 0x053D)
/* Description error:
?IXL: Parameters are bad.
*/

#define ISA_ER_IXL_RQ                     (ISA_ER_BASE + 0x053E)
/* Description error:
?IXL: Bad RQ.
*/

#define ISA_ER_IXL_RC                     (ISA_ER_BASE + 0x053F)
/* Description error:     
?IXL: Kernel problem in executing request.
*/

#define ISA_ER_IXL_SYM_NOTLOADED          (ISA_ER_BASE + 0x0540)
/* Description error:     
?IXL: Symbol table is not loaded.
*/

#define ISA_ER_IXL_SYM_ITERATIONMAX       (ISA_ER_BASE + 0x0541)
/* Description error:       
?IXL: Maximum iteration is reached in symbol management.
*/

#define ISA_ER_IXL_SYM_VAR_UNKNOWN        (ISA_ER_BASE + 0x0542)
/* Description error:       
?IXL: Variable is unknown.
*/

#define ISA_ER_IXL_SYM_TYP_UNKNOWN        (ISA_ER_BASE + 0x0543)
/* Description error:       
?IXL: Type or Sub-type is unknown.
*/

#define ISA_ER_IXL_SYM_MISMATCH           (ISA_ER_BASE + 0x0544)
/* Description error:       
?IXL: Symbols mismatch.
*/

#define ISA_ER_IXL_SYM_CRC                (ISA_ER_BASE + 0x0545)
/* Description error:       
?IXL: Symbols mismatch, bad CRC.
*/

#define ISA_ER_IXL_SYM_RESNAME            (ISA_ER_BASE + 0x0546)
/* Description error:       
?IXL: Symbols mismatch, bad resource name.
*/

#define ISA_ER_IXL_SYM_END                (ISA_ER_BASE + 0x0547)
/* Description error:       
?IXL: End of symbols is reached or stop is required.
*/

#define ISA_ER_IXL_SYM_CORRUPTED          (ISA_ER_BASE + 0x0548)
/* Description error:       
?IXL: Symbols are corrupted.
*/

#define ISA_ER_IXL_SYM_ALREADYLOADED      (ISA_ER_BASE + 0x0549)
/* Description error:       
?IXL: Symbols are already loaded.
*/

#define ISA_ER_IXL_SYM_LOADING            (ISA_ER_BASE + 0x054A)
/* Description error:       
?IXL: Symbols are currently loading.
*/

#define ISA_ER_IXL_SYM_BADVERSION         (ISA_ER_BASE + 0x054B)
/* Description error:       
?IXL: Both IXL version can not coexist.
*/

#define ISA_ER_IXL_SYM_DEV_UNKNOWN        (ISA_ER_BASE + 0x054C)
/* Description error:       
?IXL: Device is unknown.
*/

#define ISA_ER_IXL_SYM_BADSYNTAX          (ISA_ER_BASE + 0x054D)
/* Description error:       
?IXL: Syntax error.
*/

#define ISA_ER_IXL_SYM_NOTCOMPLETE        (ISA_ER_BASE + 0x054E)
/* Description error:       
?IXL: Symbols table is imcomplete, it is reduced one.
*/


/**************************************************************************

         HOST SYSTEM DRIVER ERRORS

**************************************************************************/
/**************************************************************************

   HOST SYSTEM DRIVER BINDING ERRORS

**************************************************************************/
#define ISA_ER_HSD_KVB_CRC                (ISA_ER_BASE + 0x0630)
/* Description error:     
?Host System Driver Binding:
?Incompatible version of binding table (Bad CRC).
*/

#define ISA_ER_HSD_KVB_TIMEOUT            (ISA_ER_BASE + 0x0631)
/* Description error:     
?Host System Driver Binding:
?Produced variables are not refresh since the maximum time allowed.
*/

#define ISA_ER_HSD_KVB_KERNELSTOP         (ISA_ER_BASE + 0x0632)
/* Description error:     
?Host System Driver Binding:
?There is no producer.
*/

#define ISA_ER_HSD_KVB_SERVICE            (ISA_ER_BASE + 0x0633)
/* Description error:     
?Host System Driver Binding:
?Service not implemented.
*/





/**************************************************************************

         RSI COMMUNICATION  ERRORS

**************************************************************************/
#define ISA_ER_RSI_INIT                   (ISA_ER_BASE + 0x0640)
/* Description error:     
?RSI: Cannot initialize serial device.
*/

#define ISA_ER_RSI_OPEN                   (ISA_ER_BASE + 0x0641)
/* Description error:     
?RSI: Cannot open serial device.
*/

#define ISA_ER_RSI_READ                   (ISA_ER_BASE + 0x0642)
/* Description error:     
?RSI: Cannot read serial device.
*/

#define ISA_ER_RSI_WRITE                  (ISA_ER_BASE + 0x0643)
/* Description error:     
?RSI: Cannot write serial device.
*/

#define ISA_ER_RSI_BADPARAM               (ISA_ER_BASE + 0x0644)
/* Description error:     
?RSI: Bad parameters.
*/





/**************************************************************************

         ETCP COMMUNICATION ERRORS

**************************************************************************/
/**************************************************************************

   TCP/IP ABSTRACTION LAYER ERRORS

**************************************************************************/
#define ISA_ER_TAL_SOCKET                 (ISA_ER_BASE + 0x0700)
/* Description error:     
?TAL: Fails to create socket.
*/

#define ISA_ER_TAL_CLOSE                  (ISA_ER_BASE + 0x0701)
/* Description error:     
?TAL: Fail to close socket.
*/

#define ISA_ER_TAL_MAKESERVER             (ISA_ER_BASE + 0x0702)
/* Description error:     
?TAL: Fails to launch ISaGRAF server.
*/
#define ISA_ER_TAL_CONNECT                (ISA_ER_BASE + 0x0703)
/* Description error:     
?TAL: Fail to connect to remote node.
*/
#define ISA_ER_TAL_READ                   (ISA_ER_BASE + 0x0704)
/* Description error:     
?TAL: Can't read in socket.
*/
#define ISA_ER_TAL_ACCEPT                 (ISA_ER_BASE + 0x0705)
/* Description error:     
?TAL: Error during remote client connection.
*/
#define ISA_ER_TAL_INITFAIL               (ISA_ER_BASE + 0x0706)
/* Description error:     
?TAL: FAIL TO INITIALIZE THE TCP/IP STACK.
*/
#define ISA_ER_TAL_CHGBLOCKING            (ISA_ER_BASE + 0x0707)
/* Description error:     
?TAL: Fail to change socket status.
*/
#define ISA_ER_TAL_BROKEN_CX              (ISA_ER_BASE + 0x0708)
/* Description error:     
?TAL: Broken connection.
*/
#define ISA_ER_TAL_WRITE                  (ISA_ER_BASE + 0x0709)
/* Description error:     
?TAL: Error during socket write.
*/

#define ISA_ER_TAL_BAD_ADR                (ISA_ER_BASE + 0x070A)
/* Description error:     
?TAL: Received data are not coherent.
*/

#define ISA_ER_TAL_REP_CNX_ERR            (ISA_ER_BASE + 0x070B)
/* Description error:     
?TAL: TAL: Remote ETCP connection fails.
*/

/**************************************************************************

   ETCP ERRORS

**************************************************************************/
/* Obsolete errors see IPC errors ****************************************/
#define ISA_ER_ETCP_TIMEOUT               (ISA_ER_BASE + 0x0710)
/* Description error:     
?ETCP: ETCP is in Timeout mode.
*/

#define ISA_ER_ETCP_DQ_ALREADY_CONNECTED  (ISA_ER_BASE + 0x0711)
/* Description error:      
?ETCP: The ETCP server is already connected to a default queue.
*/

#define ISA_ER_ETCP_NO_CNX_AVALAIBLE      (ISA_ER_BASE + 0x0712)
/* Description error:      
?ETCP: The ETCP server is full.
*/
/* End obsolete errors ***************************************************/

/**************************************************************************

   ETCP BINDING ERRORS

**************************************************************************/
#define ISA_ER_ETCP_KVB_ADDRESS           (ISA_ER_BASE + 0x0730)
/* Description error :      
?ETCP-KVB: Host address not resolved.
*/

#define ISA_ER_ETCP_KVB_RES_LOCAL         (ISA_ER_BASE + 0x0731)
/* Description error:     
?ETCP-KVB: No remote resource found.
*/
#define ISA_ER_ETCP_KVB_NO_SERVER         (ISA_ER_BASE + 0x0732)
/* Description error:     
?ETCP-KVB: ETCP Server is not running.
*/

#define ISA_ER_ETCP_KVB_NO_VARIABLES      (ISA_ER_BASE + 0x0733)
/* Description error:      
?ETCP-KVB: This resource has no variables to bind!
*/

#define ISA_ER_ETCP_KVB_SERVICE           (ISA_ER_BASE + 0x0734)
/* Description error: 
?ETCP-KVB: Service not implemented.
*/

#define ISA_ER_ETCP_KVB_VA_NOT_FOUND      (ISA_ER_BASE + 0x0735)
/* Description error :      
?ETCP-KVB: This variable is not bound by the ETCP driver.
*/

#define ISA_ER_ETCP_KVB_RES_NOT_FOUND     (ISA_ER_BASE + 0x0736)
/* Description error :      
?ETCP-KVB: This resource is not bound by the ETCP driver.
*/

#ifdef _ISA3 /* Do NOT define _ISA3. _ISA3 is used only by ICS Triplex
                to build ISA3 libraries used by the Workbench */

/**************************************************************************

         ISA3 COMMUNICATION ERRORS

**************************************************************************/
#define ISA_ER_ISA3_NO_APPL               (ISA_ER_BASE + 0x0740)
/* Description error:     
?ISA3: No application or application inactive.
*/

#define ISA_ER_ISA3_MEDIA_BUSY            (ISA_ER_BASE + 0x0741)
/* Description error:     
?ISA3: Media is busy, retry later.
*/
#endif

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module          *********************************/

#endif   /* nested Headers management */

/* eof ********************************************************************/
