// -*- C++ -*-

#include "ace/OS_NS_errno.h"
#include "ace/Sched_Params.h"
#include "ace/os_include/os_stropts.h"

#ifdef ACE_QNX6
  #include <sys/neutrino.h>
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE int
ACE_OS::eof(FILE* handle)
{
  ACE_OS_TRACE ("ACE_OS::eof");
  ACE_OSCALL_RETURN (feof (handle),int,-1);
}

ACE_INLINE int
ACE_OS::tinysleep (const ACE_Time_Value &tv)
{
  ACE_OS_TRACE ("ACE_OS::tinysleep");
#if defined (ACE_WIN32)
  ::Sleep (tv.msec ());
  return 0;
#else
# if defined (ACE_HAS_NONCONST_SELECT_TIMEVAL)
  // Copy the timeval, because this platform doesn't declare the timeval
  // as a pointer to const.
  timeval tv_copy = tv;
  ACE_OSCALL_RETURN (::select (0, 0, 0, 0, &tv_copy), int, -1);
# else  /* ! ACE_HAS_NONCONST_SELECT_TIMEVAL */
  const timeval *tvp = tv;
  ACE_OSCALL_RETURN (::select (0, 0, 0, 0, tvp), int, -1);
# endif /* ACE_HAS_NONCONST_SELECT_TIMEVAL */
#endif /* ACE_WIN32 */
}

#if !defined ACE_WIN32
#include <termios.h>
#include <unistd.h>
#endif

ACE_INLINE int
ACE_OS::set_tty_rawmode(ACE_HANDLE hdev)
{
#if !defined ACE_WIN32
	struct termios devpar;
	if(::tcgetattr(hdev, &devpar) != -1 )
	{
#ifndef QNX4_SOURCE
		devpar.c_lflag &= ~(ICANON | ECHO |ECHOE| ECHOK|ECHONL|ECHOCTL|ECHOKE|ISIG);
#else
		devpar.c_lflag &= ~(ICANON | ECHO |ECHOE| ECHOK|ECHONL|ISIG);
#endif
		devpar.c_oflag &= ~OPOST;

		return ::tcsetattr(hdev, TCSANOW, &devpar);
	}else
		return -1;
#else
	return 0;
#endif
}

ACE_INLINE unsigned int
ACE_OS::get_tty_nbytes(ACE_HANDLE hdev)
{
#if !defined ACE_WIN32
	int bytes;
	ioctl(hdev, FIONREAD, &bytes);
	return bytes;
#else
	return 0;
#endif	
}


#ifdef QNX4_SOURCE
#define TIOCM_DTR	0x002
#define TIOCM_RTS	0x004
#endif

ACE_INLINE int
ACE_OS::set_tty_DTR(ACE_HANDLE hdev,bool state)
{
#if !defined ACE_WIN32
	int st = TIOCM_DTR;
	return state ? 
		::ioctl(hdev,TIOCMBIS,&st) :
		::ioctl(hdev,TIOCMBIC,&st);
#else
	return 0;
#endif	
}

ACE_INLINE int
ACE_OS::set_tty_RTS(ACE_HANDLE hdev,bool state)
{
#if !defined ACE_WIN32
	int st = TIOCM_RTS;
	return state ? 
		::ioctl(hdev,TIOCMBIS,&st) :
		::ioctl(hdev,TIOCMBIC,&st);
#else
	return 0;
#endif	
}


ACE_INLINE int
ACE_OS::setSystemIOmode()
{
int res=0;
#if defined ACE_QNX6
         res=ThreadCtl(_NTO_TCTL_IO,0) == -1 ? -1 : 0;
#elif defined  ACE_LNX
	#if (!defined ARM_LINUX) && (!defined MOTOROLA) && (!defined LSB3)
		res= iopl(3) == 0 ? 0 : -1;
	#endif
#endif
         return res;
}

ACE_INLINE int
ACE_OS::setSystemClockResolution(long us)
{
int res=0;
#if defined ACE_QNX6
 struct   _clockperiod newclock;
		newclock.nsec=us*1000;
		newclock.fract=0;
		res=ClockPeriod( CLOCK_REALTIME, &newclock,0 ,0) == -1 ? -1 : 0;
#else
// nothing
#endif
         return res;
}

ACE_INLINE int
ACE_OS::setDefaultTaskScheduler()
{
#if defined ACE_QNX6
    ACE_Sched_Priority prio=ACE_Sched_Params::priority_min(ACE_SCHED_OTHER,ACE_SCOPE_PROCESS);
#else
    ACE_Sched_Priority prio=(ACE_Sched_Params::priority_min(ACE_SCHED_OTHER,ACE_SCOPE_PROCESS)+
	ACE_Sched_Params::priority_max(ACE_SCHED_OTHER,ACE_SCOPE_PROCESS))/2;
#endif
    return ACE_OS::sched_params(ACE_Sched_Params(ACE_SCHED_OTHER,prio,ACE_SCOPE_PROCESS));
}

ACE_END_VERSIONED_NAMESPACE_DECL
