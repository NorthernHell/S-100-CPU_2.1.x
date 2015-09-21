###############################################################################
# ISaGRAF PRO IsaVM module MAKEFILE for LINUX
# 23-Jan-2002: ICS Triplex ISaGRAF Inc.
###############################################################################


######## MAKEFILE DEFINITIONS #################################################

# GLOBAL DEFINITIONS

OBJCOPY=objcopy

# LOCAL DEFINITIONS
ROOT = ..
SDIR = .

include $(ROOT)/version
include $(ROOT)/makdefs
include $(ROOT)/Drivers/libdefs

#USE_TDB=true

ifdef USE_TDB
    TARGET_DEF = $(RDIR)/target_definition.o
    INCLUDE_TDB = -DTDB_ENABLED
else
    TARGET_DEF = 
    INCLUDE_TDB = 
endif

CC_EXTRA_INCLUDE += -I$(ROOT)/IsaSys -I$(ROOT)/IsaKer\
                   -I$(ROOT)/IsaIxl -I$(ROOT)/IsaSrv\
                   -I$(ROOT)/Etcp -I$(SDIR) $(INCLUDE_TDB)

.PHONY: all drivers

###############################################################################

######## DEPENDANCIES #########################################################
RLIST = $(RDIR)/dipl0lnk.o\
	$(RDIR)/divm0mai.o\
	$(TARGET_DEF)\
	$(LDIR)/IsaKer.o\
	$(LDIR)/IsaSrv.o\
	$(LDIR)/IsaIXL.o\
	$(LDIR)/IsxlHsd.o\
	$(LDIR)/IsxlEtcp.o\
	$(LDIR)/IsxlRsi.o\
	$(LDIR)/IsaNwl.o\
	$(LDIR)/EtcpCmon.o\
	$(LDIR)/RsiCmon.o\
	$(LDIR)/IKvbHsd.o\
	$(LDIR)/IKvbEtcp.o\
	$(LDIR)/IsaSys.o\
	$(LDIR)/ISysSoc.o\
	$(LDIR)/libJIT.a

#MAP=-Wl,-Map -Wl,IsaVM.map
MAP=

all: $(ODIR)/IsaVM

drivers:
	make -C $(ROOT)/Drivers

#Create IsaVM task
$(ODIR)/IsaVM:  $(ROOT)/AceLarge.tdb $(RDIR) $(RLIST) $(DRVLIB)
	$(LK) -o $(ODIR)/IsaVM $(RLIST) $(DRVLIB) $(LKFLAGS) $(MAP)

#Create folder for object files
$(RDIR):
	mkdir $(RDIR)

######## FILES ################################################################
$(RDIR)/dipl0lnk.o : $(SDIR)/dipl0lnk.c $(ROOT)/Drivers/Drivers.h
	$(CC) -o$(RDIR)/dipl0lnk.o $(SDIR)/dipl0lnk.c

$(RDIR)/divm0mai.o : $(SDIR)/divm0mai.c $(ROOT)/Drivers/Drivers.h
	$(CC) -o$(RDIR)/divm0mai.o $(SDIR)/divm0mai.c

$(ROOT)/AceLarge.tdb: $(ROOT)/base.tdb $(ROOT)/Drivers/drivers.tdb
	cat $+ >$@
	cp $@ $(ODIR)/

#$(ROOT)/Drivers/drivers.tdb:
#	make -C$(ROOT)/Drivers drivers.tdb

$(RDIR)/target_definition.o: $(ROOT)/AceLarge.tdb
	#save original file size to archive - this will help in allocating buffer	for bzip2
	./encode_length.sh $< > tdb.bz2
	bzip2 -c $< >> tdb.bz2
	$(LD) -r -b binary -o $@ tdb.bz2
	rm tdb.bz2
	#convert section to read-only
	#$(OBJCOPY) --rename-section .data=.rodata,alloc,load,readonly,data,contents	$@ $@


###############################################################################
$(ROOT)/Drivers/libdefs: force_look
	if [ ! -f $@ ]; then touch $@; else true; fi


#$(ROOT)/Drivers/libdefs: force_look
#	make -C $(ROOT)/Drivers libdefs

#$(ROOT)/Drivers/Drivers.h: force_look
#	make -C $(ROOT)/Drivers Drivers.h

force_look:
	true

clean:
	rm -f Rels/*.o
	rm -f ../Cmds/IsaVM
	rm -f err.log
	rm -f ..Drivers/libdefs
