/**************************************************************************
File:               dios0def.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      25-June-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        IO objects definitions

***************************************************************************
Modifications: (who / date / description)
---4.02 Released---
EDS/16-Sep-1999/ 'C' conversion funct integration
   Replaced cnv fct strRtIoChan field

---4.12 Released---
VMO/26-Mar-2002/ IOs online modification
   Added ISA_IO_MDF_xxx for IO's MDF types
   Replace field huReserved of strDfIoChan by huChanOrder
   Added IO's driver services declaration
   Enhanced IO's runtime structure

***************************************************************************/
#ifndef _DIOS0DEF_H /* nested Headers management */
#define _DIOS0DEF_H

/* constants **************************************************************/
/* IO objects identification */
#define ISA_IO_OBJID_DRV      1
#define ISA_IO_OBJID_CPXDVC   2
#define ISA_IO_OBJID_SPLDVC   3
#define ISA_IO_OBJID_CHAN     4
#define ISA_IO_OBJID_GET(pvRtIoObj) (*(uint16*)(pvRtIoObj))

/* IO control sub functions */
#define ISA_IO_CTL_CHANLOCK      1 /* Lock channel */
#define ISA_IO_CTL_CHANUNLOCK    2 /* Unlock channel */
#define ISA_IO_CTL_CHANOUTFORCE  3 /* Force channel output */

#ifdef ITGTDEF_MODIF
#define ISA_IO_MDF_CPX_OEM    0x00000010
#define ISA_IO_MDF_SPL_OEM    0x00000008
#define ISA_IO_MDF_CHAN_OEM   0x00000004
#define ISA_IO_MDF_CHAN_PARAM 0x00000002
#define ISA_IO_MDF_CHAN_VAR   0x00000001
#endif

/* Sub services of IOs MDF */
#define ISA_MDF_IO_ACCEPT   1
#define ISA_MDF_IO_GETREADY 2
#define ISA_MDF_IO_DONE     3


/* types ******************************************************************/
/* 
 * Prototype of functions of an IO driver 
 */
/* Subterfuge to avoid struct tag within fct param list */
typedef struct _s_RtIoDrv _ts_RtIoDrv;
typedef struct _s_RtIoSplDvc _ts_RtIoSplDvc;
typedef struct _s_RtIoCpxDvc _ts_RtIoCpxDvc;
typedef struct _s_DfIoSplDvc _ts_DfIoSplDvc;
typedef struct _s_DfIoCpxDvc _ts_DfIoCpxDvc;
typedef struct _s_DfIoChan _ts_DfIoChan;

/* Driver Init */
typedef typSTATUS (*typPFnDrvIosInit)(_ts_RtIoDrv*);

/* Driver Exit */
typedef void (*typPFnDrvIosExit)(_ts_RtIoDrv*);

/* Device Open */
typedef typSTATUS (*typPFnDvcIosOpen)(void*);

/* Device Close */
typedef void  (*typPFnDvcIosClose)(void*);

/* Spl Dvc Read */
typedef void  (*typPFnSplDvcIosRead)(_ts_RtIoSplDvc*);

/* Spl Dvc Write */
typedef void  (*typPFnSplDvcIosWrite)(_ts_RtIoSplDvc*);

/* Spl Dvc Control */
typedef void  (*typPFnSplDvcIosCtl)(uchar, _ts_RtIoSplDvc*, uint16, void*);


#ifdef ITGTDEF_MODIF
/* Driver online modification management */
typedef typSTATUS (*typPFnDrvIosMdf)(uchar, _ts_RtIoDrv*, uint32, void*);

/* Complex device online modification management */
typedef typSTATUS (*typPFnCpxDvcIosMdf)(uchar, 
                                        _ts_RtIoCpxDvc*, uint32, 
                                        _ts_DfIoCpxDvc*, void*);

/* Simple device online modification management */
typedef typSTATUS (*typPFnSplDvcIosMdf)(uchar, 
                                        _ts_RtIoSplDvc*, uint32, 
                                        _ts_DfIoSplDvc*, void*, 
                                        _ts_DfIoChan*, void*);
#endif

/*
 * Workbench definitions of IO structures
 */
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct _s_DfIoDrv
{
   uint16  huDrvNmOfs;     /*!< Offset to driver name */
   uint16  huLev1LstOfs;   /*!< List of level 1 index related to */
   uint16  huNbLev1Dvc;    /*!< Number of level 1 devices managed by the driver */
   uchar   cuIsVirtual;    /*!< Is virtual flag, if true all devices are virtual */
   uchar   cuReserved;     /*!< Reserved */
} strDfIoDrv;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct _s_DfIoCpxDvc
{
   uint16  huCpxDvcNmOfs;  /*!< Offset to complex device name */
   uint16  huCpxDvcOemOfs; /*!< Offset to complex device OEM parameters */
   uint16  huLev1Idx;      /*!< Level 1 index where the complex device is plugged in */
   uint16  huNbSplDvc;     /*!< Number of contained simple devices */
   uchar   cuIsVirtual;    /*!< Is virtual flag, if true all level 2 are virtual */
   uchar   cuReserved;     /*!< Reserved */
   uint16  huReserved;     /*!< Reserved */
} strDfIoCpxDvc;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct _s_DfIoSplDvc
{
   uint16  huSplDvcNmOfs;  /*!< Offset to simple device name */
   uint16  huSplDvcOemOfs; /*!< Offset to simple device OEM parameters */
   typVa   FirstChanVa;    /*!< First channel Va */
   uint16  huLev2Idx;      /*!< Level 2 Index if any, 0 else */
   uint16  huLev1Idx;      /*!< Level 1 Index */
   uint16  huNbChan;       /*!< Number of channels */
   uchar   cuIsVirtual;    /*!< Is virtual flag */
   uchar   cuIsLev2;       /*!< Within a complex device flag */
   uchar   cuDirection;    /*!< Direction (ISA_IO_DIR_INPUT,ISA_IO_DIR_OUTPUT) */
   uchar   cuReserved;     /*!< Reserved */
} strDfIoSplDvc;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct _s_DfIoChan
{
   typVa   KerVa;          /*!< Kernel logical data Va */
   typVa   KerPhyVa;       /*!< Kernel physical data Va */
   uint32  luVarSize;      /*!< Kernel variable size */
   uint16  huLev2Idx;      /*!< Level 2 Index if any, 0 else */
   uint16  huLev1Idx;      /*!< Level 1 Index */
   uint16  huChanNum;      /*!< Channel number */
   uchar   cuDirection;    /*!< Direction (ISA_IO_DIR_INPUT,ISA_IO_DIR_OUTPUT) */
   uchar   cuCnvGainTyp;   /*!< Type of var with cnv Gain, 0 if no cnv gain */
   uint32  luCnvMult;      /*!< Conversion multiplier when cnv applied */
   uint32  luCnvDiv;       /*!< Conversion divisor when cnv applied */
   uint32  luCnvOfs;       /*!< Conversion offset when cnv applied */
   uint16  huCnvNum;       /*!< 'C' Conversion function number if any */
   uint16  huChanOrder;    /*!< Channel order */
} strDfIoChan;

/*
 * Run time IO structures
 */
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct _s_RtIoDrv
{
   uint16  huObjId;        /*!< Object identification: ISA_IO_OBJID_DRV */
   void*   pvDrvRtIoDvcH;  /*!< Head of list of devices managed by the drv */
   char*   psName;         /*!< name */
   uint16  huNbLev1Dvc;    /*!< Nbr of Lev 1 devices managed by the driver */
   uchar   cuIsVirtual;    /*!< Is virtual flag, if true all dvcs are virt */
   uint32  luUser;         /*!< User dedicated field */
#ifdef ITGTDEF_MODIF
   typPFnDrvIosMdf pfnDrvIosMdf; /*!< Driver Mdf management */
#endif
} strRtIoDrv;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct _s_RtIoCpxDvc
{
   uint16          huObjId;        /*!< Object identif: ISA_IO_OBJID_CPXDVC */
   void*           pvDrvRtIoDvcNxt;/*!< Next device of same driver */
   char*           psName;         /*!< name */
   void*           pvOemParam;     /*!< OEM parameters */
   strDfIoCpxDvc*  pDfIoCpxDvc;    /*!< Static definitions */
   strRtIoDrv*     pRtIoDrv;       /*!< Driver managing the device */
   struct _s_RtIoSplDvc*  pRtIoSplDvc; /*!< First simple device description */
   uint16          huNbSplDvc;     /*!< Nbr of contained simple devices */
   uint32          luUser;         /*!< User dedicated field */
#ifdef ITGTDEF_MODIF
   typPFnCpxDvcIosMdf pfnCpxDvcIosMdf; /*!< Complex device Mdf management */
#endif
} strRtIoCpxDvc;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct _s_RtIoSplDvc
{
   uint16          huObjId;        /*!< Object identif: ISA_IO_OBJID_SPLDVC */
   void*           pvDrvRtIoDvcNxt;/*!< Next device of same driver */
                                   /*!< or next one within complex device */
   char*           psName;         /*!< name */
   void*           pvOemParam;     /*!< OEM parameters */
   strDfIoSplDvc*  pDfIoSplDvc;    /*!< Static definitions */
   void*           pvRtIoLevBack;  /*!< One Level Back: */
                                   /*!<  - Drv managing the dvc, if lev 1 */
                                   /*!<  - Cpx dvc it belongs to, if lev 2 */
   struct _s_RtIoChan* pRtIoChan;  /*!< First channel description */
   uint16          huNbChan;       /*!< Number of channels */
   uint16          huNbLocked;     /*!< Number of Locked channels */
   typPFnSplDvcIosCtl pfnSplDvcIosCtl; /*!< Simple device control fct if any */
   uint32          luUser;         /*!< User dedicated field */

#ifdef ITGTDEF_IOCHANOEM
   void*           pvChanOem;      /*!< OEM parameters of first channel */
   uint16          huChanOemSize;  /*!< OEM parameters size of one channel */
#endif /* ITGTDEF_IOCHANOEM */

#ifdef ITGTDEF_MODIF
   typPFnSplDvcIosMdf pfnSplDvcIosMdf; /*!< Simple device Mdf management */
#endif
} strRtIoSplDvc;


/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct _s_RtIoChan
{
   uint16          huObjId;        /*!< Object Identif: ISA_IO_OBJID_CHAN */
   strDfIoChan*    pDfIoChan;      /*!< Static definitions */
   strRtIoSplDvc*  pRtIoSplDvc;    /*!< Simple device it belongs to */
   void*           pvKerData;      /*!< Kernel logical data location */
   void*           pvKerPhyData;   /*!< Kernel physical data location */
   typVa           KerVa;          /*!< Kernel logical data Va */
   uint32          luVarSize;      /*!< Kernel variable size */
   uint16          huChanNum;      /*!< Channel number */
   uchar           cuIsLocked;     /*!< Is Locked flag */
#ifdef ITGTDEF_CNV
#ifdef ITGTDEF_RTIOCNVGAIN
   uchar           cuCnvGainTyp;   /*!< Type of var with conversion Gain, */
                                   /*!< 0 if no conversion gain applied */
   uint32          luCnvMult;      /*!< Cnv multiplier when cnv applied */
   uint32          luCnvDiv;       /*!< Cnv divisor when cnv applied */
   uint32          luCnvOfs;       /*!< Cnv offset when cnv applied */
#endif /* ITGTDEF_RTIOCNV */
   typPFnCnvCall   pfnCnvCall;     /*!< 'C' Conversion fct if any */
#endif /* ITGTDEF_CNV */
   uint32          luUser;         /*!< User dedicated field */
} strRtIoChan;

/* data *******************************************************************/

/* exported services from module   ???    *********************************/



#endif  /* nested Headers management */
/* eof ********************************************************************/
