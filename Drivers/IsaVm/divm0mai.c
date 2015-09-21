/**************************************************************************
File:               divm0mai.c
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      11-July-2001
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Virtual machine Main

 This file contains the main entry of the virtual machine if the macro
 ITGTDEF_NOKERMAIN is defined in dsys0def.h.
 If the macro is not defined it is not used.
 
***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/

#include <dsys0def.h>
#include <dker0mai.h>
#include <dlnx0pro.h>

#include <stdio.h>
#include <stdlib.h>
#ifdef TDB_ENABLED
    #include <bzlib.h>
#endif
/* constants **************************************************************/

/* types ******************************************************************/

/* static data ************************************************************/

/* exported data [NOT RECOMMENDED!] ***************************************/

/* imported data [NOT RECOMMENDED!] ***************************************/

extern unsigned int _binary_tdb_bz2_start;
extern int  _binary_tdb_bz2_size;
//extern int _binary_tdb_bz2_end;

/* callback services implemented in this file *****************************/

/* exported services ******************************************************/

/* imported services ******************************************************/

/* static services ********************************************************/

isaMessager isam; // for ISA_DEBUG messaging

/****************************************************************************
function    : main
description : Main Entry point (if not using threads)
parameters  :
   (input) int  argc :      Number of arguments. 
   (input) char *argv[] :   Array of arguments. 
return value: int : Zero if ok, non zero else.
warning     : 
****************************************************************************/
int ACE_TMAIN//main
   (
   int   argc,      /* In: Number of arguments */ 
   ACE_TCHAR* argv[]     /* In: Array of arguments */  
   )  
{
	ACE_OS::sleep( 1);  // for debug 
	
	uint32 log_mode=0; // default LM_ERROR level, no file
						// 1 - LM_TRACE level, no file
						// 2 - LM_ERROR level in file
						// 3 - LM_TRACE level in file

  /* Initialize arguments management */
 	XsysArgInit(argc, argv);
	
 	if (dsysArgGet(ISA_ARG_GET_INFO,0,"logMode",0,0,0,0) != BAD_RET)
   	{
      /* Get the argument */
      dsysArgGet(ISA_ARG_GET_UINT32, 0, "logMode", &log_mode, 0, 0, 0);
	  printf("Set log mode to %d\n",log_mode);
	}	
#ifdef TDB_ENABLED
  char *tdb_filename=NULL;
  const char *default_tdb_filename="AceLarge.tdb";
  int tdb_filename_length=0;
  if (dsysArgGet(ISA_ARG_GET_INFO,0,"export-tdb",0,0,0,0) != BAD_RET)
  {
    // check how much memory we have to allocate for parameter
    // dsysArgGet returns 4 in parameter is empty =(
    tdb_filename_length = dsysArgGet(ISA_ARG_GET_STRING, 0, "export-tdb", tdb_filename, 0, 0, 0) + 1; // +1 for NULL character
    //printf ("filename_length=%i\n",tdb_filename_length);

    if ((tdb_filename = (char*) calloc (tdb_filename_length,sizeof(char))) == NULL)
    {
      printf ("malloc has failed\n");
      //ldgRCleanUp();
      return(BAD_RET);
    }

    if ((tdb_filename_length = dsysArgGet (ISA_ARG_GET_STRING, 0, "export-tdb", tdb_filename, tdb_filename_length, 0, 0)) == 0 )
    {
      //dsysArgGet bug - zero return size means we really have empty parameter, and should use default one
      free (tdb_filename);
      tdb_filename = (char*) default_tdb_filename;
    }

    printf ("Saving target definition to %s\n",tdb_filename);
    
    /*
     * decompress
     */
    FILE *fp;
    //decompressed file size is written in the first 4 bytes
    unsigned int size=ACE_NTOHL(_binary_tdb_bz2_start);
    char *dest=(char*)malloc (size); //output buffer
    if (dest == NULL)
    {
      printf ("malloc() has failed\n");
      return (BAD_RET);
    }
    //printf ("size=%d\n",size);

    //start decompressin from start+4 (in order to skip file size from input stream)
    int res=BZ2_bzBuffToBuffDecompress(dest, &size, (char*)&_binary_tdb_bz2_start+4,(int)&_binary_tdb_bz2_size,0,0);
    if (res != BZ_OK)
    {
      printf ("BZ2_bzBuffToBuffDecompress() failed with res=%d\n",res);
      return (BAD_RET);
    }

    /*
     * export 
     */
     
    if ((fp = fopen (tdb_filename, "w")) == NULL )
    {
      perror ("fopen()");
      //ldgRCleanUp();
      return(BAD_RET);
    }
    //printf ("file created ok, writing\n");
    //printf ("size=%i\n",&_binary____tdb_bz2_size);
    //printf ("start ptr=%p\n",&_binary____tdb_bz2_start);

    if (fwrite (dest, sizeof(dest[0]), size, fp) != size)
    {
      perror ("fwrite");
      fclose (fp);
      //ldgRCleanUp();
      return(BAD_RET);
    }

    fclose (fp);

    /*
     * export end
     */

    //clean tdb_filename_length if it wasn't already done due to DsysArgGet bug
    if (tdb_filename_length != 0)
      free (tdb_filename);

    //ldgRCleanUp();
    return(BAD_RET);
  }
#endif
	if (log_mode > 5){
		isam.init("ISA_VM",true); // messaging in file "ISA_VM.log"
	}
	if (log_mode == 1 || log_mode == 7){
		isam.setLevel(LM_WARNING); // next messaging level
	}else if (log_mode == 2 || log_mode == 8){
		isam.setLevel(LM_NOTICE);
	}else if (log_mode == 3 || log_mode == 9){
		isam.setLevel(LM_INFO);
	}else if (log_mode == 4 || log_mode == 10){
		isam.setLevel(LM_DEBUG);
	}else if (log_mode == 5 || log_mode == 11){
		isam.setLevel(LM_TRACE);
	}else{
		isam.setLevel(LM_ERROR); // min messaging level
	}

#ifdef WINCE
//	::MessageBoxW(0,L"IsaVM",L"111",MB_OK);
	CeSetThreadQuantum(GetCurrentThread(),1); // set thread quantum to 1ms
	if (argc>1)
	 return( dkerMain(argc-1, &argv[1]) );
	else
	 return( dkerMain(argc, argv) );
#else
   return( dkerMain(argc, argv) );
#endif
}

/* eof ********************************************************************/
