#include <ace/ACE.h>
#include <ace/Mem_Map.h>
#include <ace/SString.h>

#if !defined (PROC_MUTEX) && !defined (PROC_SEMAPHORE)
	#include <ace/Synch.h>
	typedef ACE_Mutex		Process_Mutex;
	#define CreateProcessMutex(name) new Process_Mutex(USYNC_PROCESS,(name))
#elif defined PROC_MUTEX 
	#include <ace/Process_Mutex.h>
	typedef ACE_Process_Mutex	Process_Mutex;
	#define CreateProcessMutex(name) new Process_Mutex((name))
#elif defined PROC_SEMAPHORE	// for QNX4 system ! 
	#include <ace/Process_Semaphore.h>
	typedef ACE_Process_Semaphore	Process_Mutex;
	#define CreateProcessMutex(name) new Process_Mutex(1,(name))

#endif

#define REFNILL 	-1	// NILL reference

#ifdef ACE_QNX4
	#define DEVSHMFULL 		"/dev/shmem"	// in qnx4 - shared name = '/' but real name = '/dev/shmem'
#else
	#define DEVSHMFULL 		""
#endif

template <long MODHASH=5000,typename keytype_t=unsigned long,typename reftype_t=long>
class ACE_shm_hash
{
struct shm_item {
	reftype_t prev,next;                // reference to shared pool item
	keytype_t key;
	char	  data[0];		    // erizable array
};

struct shm_hash_body {
	unsigned long   special_data;
	unsigned short 	datasz;
	unsigned int   	maxitems;
	unsigned int   	numbuckets;
	unsigned int	count,maxcount;
	int   		freecnt;
	reftype_t 	freelist;
	reftype_t 	buckets[MODHASH];
	int    		buckcnt[MODHASH];
	shm_item   	pool[0];

	unsigned int 	getCountHash() {return count;}
	unsigned int 	getMaxCountHash() {return maxcount;}
	shm_item * 	PoolElem(unsigned int i) {return (shm_item*)((char*)pool + i*(sizeof(shm_item) +  datasz));}

	void appendItemToFreeList(reftype_t i)
	{
		if ( freelist == REFNILL) {  // first free
			PoolElem(i)->next=REFNILL;
		}else{
			PoolElem(i)->next=freelist;
		}
		freelist = i;
		freecnt++;
	}

	reftype_t getItemFromFreeList()
	{
	reftype_t free_id=0;

		if ( freelist == REFNILL) // no  free items
			return REFNILL;

		free_id=freelist;
		freelist=PoolElem(free_id)->next;
		freecnt--;
		return free_id;
	}

	bool appendItemToBucketList(int id_buc,keytype_t key,const void *data)
	{
	reftype_t id_new=getItemFromFreeList();
	shm_item *newItem;

		if ( id_new == REFNILL)	return false;
		newItem=PoolElem(id_new);
		newItem->key=key;
		newItem->prev=REFNILL;
		ACE_OS::memcpy(newItem->data,data,datasz);

		if ( buckets[id_buc] == REFNILL) {  // first in bucket
			buckets[id_buc] = id_new;
			newItem->next=REFNILL;
		}else{                          // bucket list
			PoolElem(buckets[id_buc])->prev=id_new;
			newItem->next=buckets[id_buc];
			buckets[id_buc]=id_new;
		}
		count++;
		if (count > maxcount) maxcount=count;
		buckcnt[id_buc]++;
		return true;
	}

	void	removeItemFromBucketListAndFree(int id_buc,reftype_t wasfound)
	{
	reftype_t next=PoolElem(wasfound)->next;
	reftype_t prev=PoolElem(wasfound)->prev;
		if ( next != REFNILL) {
			PoolElem(next)->prev=prev;
		}
		if ( prev != REFNILL) {
			PoolElem(prev)->next=next;
		}else{                          // first in bucket
			buckets[id_buc]=next;
		}
		appendItemToFreeList(wasfound);
		count--;
		buckcnt[id_buc]--;
	}

	void restoreFirstItemFromBucketList(int id_buc,keytype_t *key,void *data)
	{
	reftype_t point=buckets[id_buc];
	shm_item *pitem=PoolElem(point);

		buckets[id_buc]=pitem->next;

		ACE_OS::memcpy(key,&(pitem->key),sizeof(keytype_t));
		if(data)
		    ACE_OS::memcpy(data,pitem->data,datasz);
		appendItemToFreeList(point);
		count--;
		buckcnt[id_buc]--;
	}

	reftype_t findItemInBucketList(int id_buc,keytype_t key)
	{
	reftype_t next=buckets[id_buc];
		while(next != REFNILL){
			if ( PoolElem(next)->key == key) return next;
			next=PoolElem(next)->next;
		}
		return REFNILL; // not found
	}
	
	reftype_t nextItemInBucketList(reftype_t mark)
	{
		return PoolElem(mark)->next;
	}
   	
	void readItemFromBucketList(reftype_t mark,keytype_t *key,void *data)
	{
		if (mark == REFNILL) return;
		shm_item *pitem=PoolElem(mark);
		ACE_OS::memcpy(key,&(pitem->key),sizeof(keytype_t));
		ACE_OS::memcpy(data,pitem->data,datasz);
	}
	
};

#define hash_func(hp,key) (key % MODHASH)


	ACE_Mem_Map	*shm;
	Process_Mutex	*mutex;
	shm_hash_body	*hash;
	unsigned int    cursor;
	signed 	  int 	 readmarkBuck;
	reftype_t 		 readmarkList;
	bool		err;
public:
// if create_mode==TRUE
// make empty hash table in shared memory, link it and store pointer
// set err=TRUE if no memory
// args - h_factor default as  H_FACTOR for more speed user may set H_FACTOR/2,H_FACTOR/5

// if create_mode==FALSE and table exist
// link hash table in shared memory and store pointer
// set err=TRUE if no this table in shared memory or another datasize
    
    bool FileExist(char *name){
        ACE_stat  StatFile;
        return ACE_OS::stat(name, &StatFile) == 0;
    }


    ACE_shm_hash(ACE_CString path, ACE_CString tblname,unsigned short datasize,unsigned int maxitems,bool create_mode=false)
	{
    err=false;
    mutex=0;
    cursor=0;
	readmarkBuck=-1;
	readmarkList=REFNILL;
    shm=0;

    ACE_CString hshname=path+tblname;
    ACE_CString mtxname=tblname+".mtx";


	if (create_mode){
    mutex = CreateProcessMutex(ACE_TEXT_CHAR_TO_TCHAR(mtxname.c_str()));
    if (!mutex){
#ifdef DEBUG
	ACE_OS::printf("ACEShmHash -> error: can't create shared mutex\n");
#endif
	err=true;
	return;
    }
	// if new table
	// make empty hash table in shared memory, link it and store pointer
	// return FALSE if no memory

	if ( maxitems < MODHASH) maxitems=MODHASH;

    unsigned int  nbucks=MODHASH;
    unsigned long msize=sizeof(shm_hash_body) + (sizeof(shm_item)+datasize)*maxitems ;

    shm = new ACE_Mem_Map(ACE_TEXT_CHAR_TO_TCHAR(hshname.c_str()),msize,O_RDWR|O_CREAT,ACE_DEFAULT_FILE_PERMS,PROT_RDWR,ACE_MAP_SHARED);
    if (!shm){
#ifdef DEBUG
		ACE_OS::printf("ACEShmHash -> error: can't create shared block %s\n",hshname.c_str());
#endif
		err=true;
		return;
    }

    mutex->acquire();
    hash = (shm_hash_body*)shm->addr();
    if(hash==MAP_FAILED)
    {
#ifdef DEBUG
		ACE_OS::printf("ACEShmHash -> error: can't map shared block %s\n",hshname.c_str());
#endif
		err=true;
		return;
    }

    hash->freelist=REFNILL;
    hash->freecnt=0;
    hash->numbuckets=nbucks;
    hash->datasz=datasize;
    hash->maxitems=maxitems;
    hash->special_data=0;
    hash->count=0;
    hash->maxcount=0;

    for(unsigned int i=0;i<nbucks;i++) {
		hash->buckets[i]=REFNILL;
		hash->buckcnt[i]=0;
    }

    for(unsigned int i=0;i<hash->maxitems;i++)
    {
		hash->PoolElem(i)->prev=hash->PoolElem(i)->next=REFNILL;
		hash->appendItemToFreeList(i);
    }
    mutex->release();

	}else{ // open mode
            if (!FileExist((char*)((DEVSHMFULL + hshname).c_str()))) {
		err=true;
		return;
            }
    mutex = CreateProcessMutex(ACE_TEXT_CHAR_TO_TCHAR(mtxname.c_str()));
    if (!mutex){
#ifdef DEBUG
	ACE_OS::printf("ACEShmHash -> error: can't create shared mutex\n");
#endif
	err=true;
	return;
    }
    unsigned long msize=sizeof(shm_hash_body);
    shm  = new ACE_Mem_Map(ACE_TEXT_CHAR_TO_TCHAR(hshname.c_str()),msize,O_RDWR,ACE_DEFAULT_FILE_PERMS,PROT_RDWR,ACE_MAP_SHARED);
    if (!shm){
#ifdef DEBUG
		ACE_OS::printf("ACEShmHash -> error: can't open shared block %s\n",hshname.c_str());
#endif
		err=true;
		return;
    }

    mutex->acquire();

    // check sizes
    hash = (shm_hash_body*)shm->addr();
    if(hash == MAP_FAILED)
    {
#ifdef DEBUG
		ACE_OS::printf("ACEShmHash -> error: can't map shared block %s\n",hshname.c_str());
#endif
		err=true;
		mutex->release();
		return;
    }
    if (hash->datasz != datasize) {
		err = true;
		mutex->release();
		return;
    }

    maxitems=hash->maxitems;
    msize=sizeof(shm_hash_body) + (sizeof(shm_item)+datasize)*maxitems;

    shm->unmap();

    // reopen
    int res=shm->map((int)msize,PROT_RDWR,ACE_MAP_SHARED,(void*)0);
    if (res){
#ifdef DEBUG
		ACE_OS::printf("ShmHash -> error: can't reopen shared block %s\n",hshname.c_str());
#endif
		err= true;
		mutex->release();
		return;
    }
    hash=(shm_hash_body*)shm->addr();
    if (hash->datasz != datasize){
		err = true;
		mutex->release();
		return;
    }

    mutex->release();
	} // end if open
	}

    ~ACE_shm_hash(){}

unsigned int getCount() {return hash->count;}
unsigned int getMaxCount() {return hash->maxcount;}
unsigned int getMaxItems(){return hash->maxitems;}
bool	  error(){return err;}

void	global_lock(){
#if defined  GLOBAL_LOCK 
	mutex->acquire();
#endif	
}
void 	global_unlock(){
#if defined  GLOBAL_LOCK 
	mutex->release();
#endif	
}

// put key-data pair into shared hash
// if  key was exist => replace data body
// return FALSE if new key and no left space in free
bool store(keytype_t key,const void *data)
{

bool res=false;
keytype_t id_buc=hash_func(h,key);

	if (err || !hash || !mutex) return false;
#if !defined  GLOBAL_LOCK 
	mutex->acquire();
#endif	
	if ( hash->buckets[id_buc] == REFNILL) {
		res=hash->appendItemToBucketList(id_buc,key,data);

	}else {
		reftype_t wasfound=hash->findItemInBucketList(id_buc,key);
		if ( wasfound == REFNILL)
		{      // not found
			res=hash->appendItemToBucketList(id_buc,key,data);
		}
		else{ // key found -> replace data
			ACE_OS::memcpy(hash->PoolElem(wasfound)->data,data,hash->datasz);
			res=true;
		}
	}
#if !defined  GLOBAL_LOCK 
	mutex->release();
#endif
	return res;
}

// get data for key and delete this from shared hash
// return FALSE if no this key-data pair
bool restore(keytype_t key,void *data)
{
bool res=false;
keytype_t id_buc=hash_func(h,key);
	if (err || !hash || !mutex) return false;
	
#if !defined  GLOBAL_LOCK 
	mutex->acquire();
#endif
	if ( hash->buckets[id_buc] == REFNILL)
			res=false;
	else{
		reftype_t wasfound=hash->findItemInBucketList(id_buc,key);
		if ( wasfound == REFNILL)      // not found
			res=false;
		else {
			ACE_OS::memcpy(data,hash->PoolElem(wasfound)->data,hash->datasz);
			removeItemFromBucketListAndFree(hash,id_buc,wasfound);
			res=true;
		}
	}

#if !defined  GLOBAL_LOCK 
	mutex->release();
#endif
	return res;
}

// get data for key and NO delete this from shared hash
// return FALSE if no this key-data pair
bool find(keytype_t key,void *data)
{
bool res=false;
keytype_t id_buc=hash_func(h,key);

	if (err || !hash || !mutex) return false;
#if !defined  GLOBAL_LOCK 
	mutex->acquire();
#endif
	if ( hash->buckets[id_buc] == REFNILL)
			res=false;
	else{
		reftype_t wasfound=hash->findItemInBucketList(id_buc,key);
		if ( wasfound == REFNILL)      // not found
			res=false;
		else {
			ACE_OS::memcpy(data,hash->PoolElem(wasfound)->data,hash->datasz);
			res=true;
		}
	}
#if !defined  GLOBAL_LOCK 
	mutex->release();
#endif
	return res;
}


// get next key-data pair and delete this from shared hash
// return FALSE if no more any key-data pair
void init_iterator(){
	cursor=0;
}

bool restore_next(keytype_t *key,void *data)
{
bool res=false;
	if (err || !hash || !mutex) return false;
#if !defined  GLOBAL_LOCK 
	mutex->acquire();
#endif
	// skip cursor on next non-empty bucket
	while ( cursor < MODHASH){
	    	if (hash->buckets[cursor] != REFNILL) break;
		cursor++;
	}

	if (cursor >= MODHASH){
	    res= false;
	    cursor=0; // init cursor
	}else{
	    hash->restoreFirstItemFromBucketList(cursor,key,data);
	    res= true;
    	//if (hash->buckets[cursor] == REFNILL) cursor++;
	}

#if !defined  GLOBAL_LOCK 
	mutex->release();
#endif
	return res;
}

// next function - for reading without deleting !!!
void init_readdata()
{
	readmarkBuck=-1;
	readmarkList=REFNILL;
}	

bool skip_readdata()
{
bool res=false;
	if (err || !hash || !mutex) return false;
#if !defined  GLOBAL_LOCK 
	mutex->acquire();
#endif
	
	if (readmarkBuck != -1 && readmarkList != REFNILL){
		readmarkList=hash->nextItemInBucketList(readmarkList);
		if (readmarkList != REFNILL){
			res = true;
			goto theEnd;
		}
	}
	
	readmarkBuck++;
	// skip cursor on next non-empty bucket
	while ( readmarkBuck < MODHASH){
    		if (hash->buckets[readmarkBuck] != REFNILL) break;
			readmarkBuck++;
	}

	if (readmarkBuck >= MODHASH){
	    	res= false; // end of data
	    	readmarkBuck=-1; // init read marker
			readmarkList=REFNILL;
	}else{
	    	readmarkList=hash->buckets[readmarkBuck];
	    	res= true;
	}

theEnd:	
#if !defined  GLOBAL_LOCK 
	mutex->release();
#endif
	return res;
}
	
bool skip_readdata_nolock()
{
bool res=false;
	if (err || !hash || !mutex) return false;

	if (readmarkBuck != -1 && readmarkList != REFNILL){
		readmarkList=hash->nextItemInBucketList(readmarkList);
		if (readmarkList != REFNILL){
			res = true;
			goto theEnd;
		}
	}
	
	readmarkBuck++;
	// skip cursor on next non-empty bucket
	while ( readmarkBuck < MODHASH){
    		if (hash->buckets[readmarkBuck] != REFNILL) break;
			readmarkBuck++;
	}

	if (readmarkBuck >= MODHASH){
	    	res= false; // end of data
	    	readmarkBuck=-1; // init read marker
			readmarkList=REFNILL;
	}else{
	    	readmarkList=hash->buckets[readmarkBuck];
	    	res= true;
	}

theEnd:	
	return res;
}

bool readdata(keytype_t *key,void *data)
{
bool res=false;
	if (err || !hash || !mutex) return false;
#if !defined  GLOBAL_LOCK 
	mutex->acquire();
#endif
	if (skip_readdata_nolock()){
    	hash->readItemFromBucketList(readmarkList,key,data);
    	res= true;
	}

#if !defined  GLOBAL_LOCK 
	mutex->release();
#endif
	return res;
}

// special message exchange
bool put_special_data(unsigned long data)
{
	if (err || !hash || !mutex) return false;
#if !defined  GLOBAL_LOCK 
	mutex->acquire();
#endif
	hash->special_data=data;
#if !defined  GLOBAL_LOCK 
	mutex->release();
#endif
	return true;
}

unsigned long get_special_data()
{
unsigned long res=0;
	if (err || !hash || !mutex) return 0;
#if !defined  GLOBAL_LOCK 
	mutex->acquire();
#endif	
	res=hash->special_data;
	hash->special_data=0;
#if !defined  GLOBAL_LOCK 
	mutex->release();
#endif	
	return res;
}

// close hash table in shared memory
// and unlink it if last
// return FALSE if error
bool destroy()
{
	if (!mutex) return true;
	mutex->acquire();
	shm->remove();
	delete shm;
	mutex->remove();
	delete mutex;
	return true;
}

// close hash table in shared memory
// return FALSE if error
bool	close()
{
	if (!mutex) return true;
	mutex->acquire();
	shm->close();
	delete shm;
	mutex->release();
	delete mutex;
	return true;
}

};
