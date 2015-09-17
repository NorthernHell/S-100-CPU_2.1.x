#include <ace/os_include/os_string.h>
#include <ace/OS_NS_arpa_inet.h>
#include <ace/OS_Memory.h>
#include <rtlogtype.h>

#define ALARMDBG
#define ALARMMSG "FDA_ALARM: "
#define ALARMVER "2.0"
#ifndef ALARM
	#define ALARM 5
#endif

#ifndef ACE_WIN32 
	#define USEFCNTL
#endif	

int InsertVarInQueue(void* addr);
