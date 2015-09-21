#ifndef _DKER0ADV_H
#define _DKER0ADV_H

//#define ADVFUNCCTRL

#define MYCRYPT_PASSWD1  "\x01\x12\x34\x52\x24\x46\x37\x26"
#define MYCRYPT_PASSWD2  "\x65\x62\x48\x26\x57\x19\x73\x03"

#define MYCRYPT_SECTION "[EDL]"
#define MYCRYPT_FILENAME "drivers.list"

inline int mycr(char* buf, int size, char* mask, int msize)
{
    for(int i=0;i<size;i++)
    {
    	for(int j=0;j<msize && ((i+j)<size);j++)
	    *(buf+i+j) ^= *(mask+j);
	i+= (msize-1);
    }
    return 0;
}


int InitAdvFunc(void);
int FindAdvFunc(const char* funcname);

#endif
