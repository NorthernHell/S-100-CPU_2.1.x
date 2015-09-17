/**************************************************************************
File:               iectypes.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:20
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _IECTYPES_H /* nested Headers management */
#define _IECTYPES_H

/* WARNING!
Definition of arrays is different in "C" or IEC
The index of the first element may be different from 0 in IEC
The declared array size supposes that first elemnt as index 0 in "C"
For example, if you declare in IEC:
	MyArray[2..10]
It will be in "C":
	MyArray[9]
And element [2] in IEC corresponds to element [0] in "C"

Three extra bytes are allocated for each STRING item
For example, if you declare in IEC:
	STRING(10)
It will be in "C":
	char[13]
*/

typedef struct _tag_strIecGain_pid
{
   uchar DirectActing;
   float ProportionalGain;
   float TimeIntegral;
   float TimeDerivative;
   float DerivativeGain;
} strIecGain_pid;
typedef strIecGain_pid * PstrIecGain_pid;

typedef struct _tag_strIecTimespec
{
   int32 Sec;
   int32 Nsec;
} strIecTimespec;
typedef strIecTimespec * PstrIecTimespec;

typedef char typIecReserved_ae_context[88];
typedef typIecReserved_ae_context * PtypIecReserved_ae_context;

typedef struct _tag_strIecQuality
{
   char Value;
} strIecQuality;
typedef strIecQuality * PstrIecQuality;

typedef struct _tag_strIecError
{
   int32 Layer;
   int32 Number;
} strIecError;
typedef strIecError * PstrIecError;

typedef struct _tag_strIecCond_p_bool
{
   int32 state;
   strIecTimespec activeTime;
   strIecTimespec inactiveTime;
   strIecTimespec ackTime;
   int32 timeout;
   uchar enable;
   uchar acknowledge;
   char mode;
   typIecReserved_ae_context reserved;
} strIecCond_p_bool;
typedef strIecCond_p_bool * PstrIecCond_p_bool;

typedef struct _tag_strIecCond_p_dint
{
   int32 state;
   strIecTimespec activeTime;
   strIecTimespec inactiveTime;
   strIecTimespec ackTime;
   int32 timeout;
   uchar enable;
   uchar acknowledge;
   int32 level;
   int32 hysteresis;
   int32 deadband;
   int32 period;
   int32 deviation;
   typIecReserved_ae_context reserved;
} strIecCond_p_dint;
typedef strIecCond_p_dint * PstrIecCond_p_dint;

typedef struct _tag_strIecEvent_p_bool
{
   uchar enable;
   char mode;
   typIecReserved_ae_context reserved;
} strIecEvent_p_bool;
typedef strIecEvent_p_bool * PstrIecEvent_p_bool;

typedef struct _tag_strIecEvent_p_dint
{
   uchar enable;
   int32 deadband;
   typIecReserved_ae_context reserved;
} strIecEvent_p_dint;
typedef strIecEvent_p_dint * PstrIecEvent_p_dint;

typedef struct _tag_strIecAt_param
{
   float Load;
   float Deviation;
   float Step;
   float ATDynaSet;
   uchar ATReset;
} strIecAt_param;
typedef strIecAt_param * PstrIecAt_param;

typedef struct _tag_strIecCond_p_real
{
   int32 state;
   strIecTimespec activeTime;
   strIecTimespec inactiveTime;
   strIecTimespec ackTime;
   int32 timeout;
   uchar enable;
   uchar acknowledge;
   float level;
   float hysteresis;
   float deadband;
   int32 period;
   float deviation;
   typIecReserved_ae_context reserved;
} strIecCond_p_real;
typedef strIecCond_p_real * PstrIecCond_p_real;

typedef struct _tag_strIecEvent_p_real
{
   uchar enable;
   float deadband;
   typIecReserved_ae_context reserved;
} strIecEvent_p_real;
typedef strIecEvent_p_real * PstrIecEvent_p_real;

typedef struct _tag_strIecAlarm_setting
{
   float HighLimit;
   float HighAlarm;
   float HighWarning;
   float LowWarning;
   float LowAlarm;
   float LowLimit;
   float DeadBand;
   float HighDeviation;
   float LowDeviation;
   float RateOfChangePeriod;
   float RateOfChangeUp;
   float RateOfChangeDown;
   float DelayInTime;
   float DelayOutTime;
   uchar HighLimitEnable;
   uchar HighAlarmEnable;
   uchar HighWarningEnable;
   uchar LowWarningEnable;
   uchar LowAlarmEnable;
   uchar LowLimitEnable;
   uchar HighDeviationEnable;
   uchar LowDeviationEnable;
   uchar RateOfChangeUpEnable;
   uchar RateOfChangeDownEnable;
   uchar RingBack;
} strIecAlarm_setting;
typedef strIecAlarm_setting * PstrIecAlarm_setting;

#endif /* _IECTYPES_H */

/* eof ********************************************************************/

