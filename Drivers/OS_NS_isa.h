// -*- C++ -*-

#ifndef ACE_OS_NS_ISA_H
# define ACE_OS_NS_ISA_H

# include /**/ "ace/pre.h"
# include "ace/config-all.h"


# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SString.h"
#include "ace/ACE_export.h"

#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export

#if defined ISA_NODEBUG_STREAM || ISA_NODEBUG
	// no streams
#else
	#include "ace/streams.h"
#endif
#include "ace/Log_Msg.h"

#if defined  ACE_LNX
	#if !defined ARM_LINUX
		#include <sys/io.h>
	#endif
	#if defined LSB3
		typedef unsigned short ushort;
		typedef unsigned long  ulong;
	#endif

#endif
ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#ifdef ISA_NODEBUG
  #define ISA_DEBUG(X) do {} while (0)

  class isaMessager
  {
    public:
	isaMessager()
	{
	}

	void init(ACE_CString name="ISA_VM",bool outInFile=false)
	{
	}

	unsigned long getLevelMask(){
		return 0;
	}

	void setLevelMask(unsigned long msk){
	}

	unsigned long setLevel(ACE_Log_Priority level=LM_ERROR)
	{
		return 0;
	}

    };

#else
	#define ISA_DEBUG(X) \
  	do { \
    	int __ace_error = ACE_Log_Msg::last_error_adapter (); \
    	ACE_Log_Msg *ace___ = ACE_Log_Msg::instance (); \
    	ace___->conditional_set (__FILE__, __LINE__, 0, __ace_error); \
    	ace___->log X; \
  	} while (0)

  class isaMessager
  {
	ACE_Log_Msg &log;

    public:
	isaMessager():log(* ACE_Log_Msg::instance())
	{
		init();
	}

	unsigned long getLevelMask(){
		return log.priority_mask(ACE_Log_Msg::PROCESS);
	}

	void setLevelMask(unsigned long msk){
		log.priority_mask(msk,ACE_Log_Msg::PROCESS);
	}

	unsigned long setLevel(ACE_Log_Priority level=LM_ERROR)
	{
 		unsigned long pm =0;
		switch ( level) {
			case LM_TRACE : 	pm |= LM_TRACE;
			case LM_DEBUG : 	pm |= LM_DEBUG;
			case LM_INFO :  	pm |= LM_INFO;
			case LM_NOTICE : 	pm |= LM_NOTICE;
			case LM_WARNING : 	pm |= LM_WARNING;
			case LM_ERROR :		pm |= LM_ERROR;
			case LM_CRITICAL :  pm |= LM_CRITICAL;
			case LM_ALERT :     pm |= LM_ALERT;
			case LM_EMERGENCY : pm |= LM_EMERGENCY;
								break;
			default:
				//error level
				pm = getLevelMask();
				break;
		}
 		unsigned long pmw = log.priority_mask(pm ,ACE_Log_Msg::PROCESS);
		return pmw;
	}

	ACE_Log_Msg & Messager(){return log;}
	#ifndef ISA_NODEBUG_STREAM

	void init(ACE_CString name="ISA_VM",bool outInFile=false)
	{
		if ( outInFile) {
			log.open(name.c_str(),ACE_Log_Msg::OSTREAM);
 			ACE_CString  logfilename = name + ".log";
 			ofstream *logostream=new ofstream(logfilename.c_str(), ios::out);
  			// Check for errors.
		 	if (!logostream->bad ()){
			  // Set the ostream.
 				log.msg_ostream (logostream);
			}
		}else{
			log.open(name.c_str());
		}
		log.file(name.c_str());
	}

	#else         // disabled debug on stream

	void init(ACE_CString name="ISA_VM",bool outInFile=false)
	{
		log.open(name.c_str());
		log.file(name.c_str());
	}

	#endif


	};

#endif



namespace ACE_OS {

  inline
  int eof (FILE* handle);

  inline
  int tinysleep (const ACE_Time_Value &tv);

  inline
  int set_tty_rawmode(ACE_HANDLE hdev);

  inline
  unsigned int get_tty_nbytes(ACE_HANDLE hdev);

  inline
  int set_tty_DTR(ACE_HANDLE hdev,bool state);

  inline
  int set_tty_RTS(ACE_HANDLE hdev,bool state);

  inline
	int setSystemIOmode();

  inline
	int setSystemClockResolution(long us);

  inline
	int setDefaultTaskScheduler();

} /* namespace ACE_OS */

ACE_END_VERSIONED_NAMESPACE_DECL

#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_isa.inl"

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_ISA_H */
