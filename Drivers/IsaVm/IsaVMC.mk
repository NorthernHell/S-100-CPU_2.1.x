###############################################################################
# ISaGRAF PRO IsaVMC module MAKEFILE for LINUX
# 23-Jan-2002: ICS Triplex ISaGRAF Inc.
###############################################################################


######## MAKEFILE DEFINITIONS #################################################

# GLOBAL DEFINITIONS
include ../makdefs

# LOCAL DEFINITIONS
ROOT = ..
SDIR = .
CC_EXTRA_INCLUDE = -I$(ROOT)/IsaSys -I$(ROOT)/IsaIxl\
                   -I$(ROOT)/IsaKer -I$(SDIR)

###############################################################################

######## DEPENDANCIES #########################################################
RLIST = $(RCDIR)/dipl0lnk.o\
	$(RCDIR)/divm0mai.o\
	$(LDIR)/IsaKerC.o\
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
  $(LDIR)/ISysHbt.o\
	$(RCDIR)/appli.o

#Create IsaVMC task
$(ODIR)/IsaVMC : $(RCDIR) $(RLIST)
	$(LK) -o $(ODIR)/IsaVMC $(RLIST) $(LKFLAGS)

#Create folder for object files
$(RCDIR):
	mkdir $(RCDIR)

######## FILES ################################################################
$(RCDIR)/appli.o : $(SDIR)/appli.c
	$(CC) -o$(RCDIR)/appli.o $(SDIR)/appli.c

$(RCDIR)/divm0mai.o : $(SDIR)/divm0mai.c
	$(CC) -o$(RCDIR)/divm0mai.o $(SDIR)/divm0mai.c

### Add here resource ProgName.c files compilation.

###############################################################################








