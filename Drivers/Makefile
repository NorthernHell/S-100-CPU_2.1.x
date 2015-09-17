# $Id$

#global definition
include ../makdefs

#examples list
EXAMPLES = cj

#drivers list
DRVLIST=drvlist

#driver descriptions list
DRVSET=drvset.txt

#functionality list
FUNCLIST=drvset.func
EXTRADRV=../Cmds/drivers.list 

ifeq ($(OS),ACE_QNX4)
LSDIR=ls -D -1| grep -v "\."
else 
ifeq ($(OS),ACE_QNX6)
LSDIR=ls -D -1| grep -v "\."
else
LSDIR=ls -p | grep /| tr -d '/'
endif
endif

DIRS=$(shell $(LSDIR))
FILTERED_DIRS=$(shell if [ -f $(DRVLIST) ]; then cat $(DRVLIST)| grep -v \^\#; else false; fi)
AR_NAMES = $(patsubst %, ../Lib/lib%.a,$(FILTERED_DIRS))

.PHONY : all base generate force_look clean clean_all drivers ../makdefs

ifeq ($(FILTERED_DIRS),)
all:
	echo
	echo "DRIVERS LIST IS EMPTY!"
	echo
	echo "#define ISA_DECLARE_DRIVERS " > Drivers.h
	echo "DRVLIB=" > libdefs
	echo  > drivers.tdb
	-rm -f  $(EXTRADRV)
else
all: drivers Drivers.h libdefs drivers.tdb $(EXTRADRV)
endif

drivers: $(AR_NAMES)

$(DRVLIST):
	$(LSDIR)|grep -v '^$(EXAMPLES)' > $(DRVLIST)

generate:
	$(LSDIR)|grep -v '^$(EXAMPLES)' > $(DRVLIST)

base:
	cp $(DRVLIST).base $(DRVLIST) 

force_look:
	true

Drivers.h: Makefile $(DRVLIST)
#creates empty ISA_DECALRE_DRIVERS if no drivers are included, as it should be
	echo -n >  Drivers.h
	for drv in $(FILTERED_DIRS); do echo \#include \"$$drv/pack_$${drv}.h\" >> Drivers.h; done
	echo -n "#define ISA_DECLARE_DRIVERS " >> Drivers.h
	for drv in $(shell echo $(FILTERED_DIRS) | tr '[a-z]' '[A-Z]'); do echo -n "ISA_DECLARE_PACK_$${drv} " >> Drivers.h; done
	echo >> Drivers.h

$(FUNCLIST): Makefile Drivers.h
	cpp Drivers.h 2>| /dev/null | grep -E '(UsfCall|FblClassInit|IosInit)' | sed -r -e 's/.* (.+)(UsfCall|FblClassInit|IosInit)$$/\1/g' > $@

$(EXTRADRV): Makefile $(FUNCLIST) $(DRVSET) force_look
ifdef ADVFUNCCTRL
	../Special/mycrypt $@ $(FUNCLIST) $(DRVSET)
else
	cp $(DRVSET) $@
endif

libdefs: Makefile $(DRVLIST)
#creates empty DRVLIB variable in libdefs if no drivers are included
	echo -n > libdefs
	for drv in $(FILTERED_DIRS); \
	    do if [ -f ../Drivers/$${drv}/libdefs.inc ]; \
		then echo "include ../Drivers/$${drv}/libdefs.inc" >> libdefs; \
		else true; \
	    fi ; \
	done
	echo -n "DRVLIB=" >> libdefs
	for drv in $(FILTERED_DIRS); do echo -n "\$$(LDIR)/lib$${drv}.a " >> libdefs; done

drivers.tdb: Makefile $(DRVLIST)
	echo -n > drivers.tdb
	for drv in $(FILTERED_DIRS); do cat $${drv}/$${drv}.tdb >> drivers.tdb; done

#define rules for drivers compiling
define create_rule
$(patsubst %,../Lib/lib%.a,$(1)): force_look
	if [ -f $(1)/Makefile ]; then make -C $(1); else true; fi
endef
     
$(foreach driverdir,$(FILTERED_DIRS),$(eval $(call create_rule,$(driverdir))))

$(DRVSET): Makefile $(DRVLIST)
	echo -e "This ISaGRAF5++ ACE Target contains the following functional extensions:\n" > $(DRVSET)
	for drv in $(FILTERED_DIRS); do \
	  if [ -s $${drv}/$${drv}.tdb ]; then \
	    echo -n " * $${drv}: " >> $(DRVSET); \
	    if [ -f $${drv}/description.txt ]; then \
		  cat $${drv}/description.txt >> $(DRVSET); \
	    else \
	      echo >> $(DRVSET); \
	    fi; \
	  fi; \
	done

iodk:
	-for drv in $(FILTERED_DIRS); do (mkdir $(DESTDIR)/$$drv; cd $$drv; make iodk DRVDIR=$(DESTDIR)/$$drv); done
	mkdir $(DESTDIR)/cjiosmpl
	mkdir $(DESTDIR)/cjcsmpl
	cp cjiosmpl/* $(DESTDIR)/cjiosmpl/
	cp cjcsmpl/* $(DESTDIR)/cjcsmpl/

clean:
	-for drv in $(FILTERED_DIRS); do (cd $$drv; make clean); done

clean_all:
	-for drv in $(DIRS); do (cd $$drv; make clean); done
	-rm -f Drivers.h
	-rm -f libdefs
	-rm -f drivers.tdb
	-rm -f $(DRVSET)
	-rm -f $(FUNCLIST)
	-rm -f $(EXTRADRV)

