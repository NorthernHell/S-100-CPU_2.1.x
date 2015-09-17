/* ========================================================================== */
/*                                                                            */
/*   iset.h                                                                   */
/*   (c) 2008 @lexx_                                                          */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */
#ifndef _ISET_H
   #define ISET_H
#include <ace/OS_Memory.h>
#include <ace/Containers_T.h>
#include <dsys0def.h>
#include <dsys0df2.h>
#include <dker0def.h>
#define ISETNAME "ISaSET"

//ACE_Unbounded_Set < uint32 > UBSetType;

class ISET
{
  protected:
      char fname[255];
      enum {SETVARNUM = 1024};
      ACE_HANDLE fdesc;
      bool isready;
      int offset;
      union  logdata
      {
		   char	byte;
		   short	sword;
		   long	dword;
		   float	rword;
		   unsigned long udword;
		   unsigned char ubyte;
		   unsigned short usword;
		   unsigned long long uldword;
		   long long ldword;
		   time_t	date;
		   double lrword;
      };
      struct regset
      {
        unsigned long _addr;
        unsigned char _type;
	bool operator == (const regset& o) const
	 {
	    if(_addr == o._addr && _type == o._type) return 1;
	    else return 0;
	 }
      };
      struct setondisk
      {
        unsigned long _addr;
        unsigned char _type;
        logdata _store;
      };

      ACE_Unbounded_Set < regset > UBSet;
      setondisk* fileset;
      void storeSet(setondisk *pvar);
      void restoreSet(setondisk *pvar);
      void cleanOldData();
      void Reset();
  public:
      ISET();
      ~ISET();
      void init();
      bool inited();
      int appendSet(unsigned long addr, unsigned char type);
     int openDataFile(char *filename, bool check=true);
    int readSetFromFile();
    int saveSetToFile();
};

extern ISET Iset;

#endif
