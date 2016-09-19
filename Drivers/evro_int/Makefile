###############################################################################
# ISaGRAF PRO CjIOSmpl module MAKEFILE for Linux
# 13-Nov-1998: CJInternational
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
RLIST = evro_int_evro_int_evro_6ai.o  evro_int_evro_int_evro_8tc.o evro_int_evro_int_evro_6rtd.o evro_int_evro_int_evro_4ao.o evro_int_evro_int_evro_16do.o    evro_int_evro_int_evro_8ro.o  evro_int_evro_int_evro_8di.o evro_int_evro_int_evro_8dir.o  evro_int_evro_int_evro_modul_info_.o evro_int_evro_int_evro_modul_info.o evro_int_evro_int_evro_avar_info.o  evro_int_evro_int_evro_temp_info.o evro_int_evro_int_evro_indicate_info.o evro_int_evro_int_evro_16di.o evro_int_evro_int_evro_16dir.o  evro_int_evro_int_evro_8tc_.o  evro_int_evro_int_evro_6ai_.o  evro_int_evro_int_evro_6rtd_.o evro_int_evro_int_evro_4ao_.o evro_int_evro_int_evro_16do_.o    evro_int_evro_int_evro_8ro_.o    evro_int_evro_int_evro_8di_.o    evro_int_evro_int_evro_16di_.o    evro_int_evro_int_status_m.o
# Create CjIOSmpl library
$(LDIR)/libevro_int.a : $(RLIST)
	$(AR) r $(LDIR)/libevro_int.a $(RLIST)

######################################
iodk:
	rm -f *.o
	cp * $(DRVDIR)/

clean:
	rm -f *.o
	rm -f $(LDIR)/libevro_int.a

