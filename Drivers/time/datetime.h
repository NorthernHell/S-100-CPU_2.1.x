/**************************************************************************
File:               datetime.h
Author:             Lipovets
Creation date:      08/04/2008 - 20:04
***************************************************************************/
#ifndef _DATETIME_H /* nested Headers management */
#define _DATETIME_H


typedef struct _tag_strIecDatetime
{
   int32 Day;
   int32 Month;
   int32 Year;
   int32 Hour;
   int32 Minute;
   int32 Second;
   int32 Weekday;
} strIecDatetime;
typedef strIecDatetime * PstrIecDatetime;


#endif /* _DATETIME_H */

/* eof ********************************************************************/

