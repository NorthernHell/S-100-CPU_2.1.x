###############################################################################
# ISaGRAF PRO CjCSmpl module MAKEFILE for QNX
# 13-Nov-1998: ICS Triplex ISaGRAF Inc.
###############################################################################


######## MAKEFILE DEFINITIONS ################################

# GLOBAL DEFINITIONS
include ../../makdefs

# LOCAL DEFINITIONS
ROOT = ../..
SDIR = .

CC_EXTRA_INCLUDE = -I$(ROOT)/IsaSys -I$(ROOT)/IsaKer\
                   -I$(ROOT)/IsaIxl -I$(SDIR)

##############################################################

######## DEPENDANCIES ########################################
RLIST = CFSample.o\
		CBSample.o\
		ScrlStr.o

# Create CjCSmpl library
$(LDIR)/libcjcsmpl.a : $(RLIST)
	$(AR) r $(LDIR)/libcjcsmpl.a $(RLIST)

##############################################################

iodk:
	rm -f *.o
	cp * $(DRVDIR)/

clean:
	rm -f *.o
	rm -f $(LDIR)/libcjcsmpl.a

