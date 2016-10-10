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
RLIST = evro_ext_evro_ext_modbus_ai.o evro_ext_evro_ext_io8_tcs.o evro_ext_evro_ext_modbus_do.o evro_ext_evro_ext_io8tcs.o evro_ext_evro_ext_modbus_di.o evro_ext_evro_ext_io8ai.o evro_ext_evro_ext_io16do.o evro_ext_evro_ext_m_ao.o evro_ext_evro_ext_m_ai.o evro_ext_evro_ext_io16di.o evro_ext_evro_ext_io_8ai.o evro_ext_evro_ext_io_8ao.o evro_ext_evro_ext_io_16do.o evro_ext_evro_ext_io_16di.o evro_ext_evro_ext_m_do.o evro_ext_evro_ext_m_di.o evro_ext_evro_ext_io8ao.o evro_ext_evro_ext_io_4ro.o evro_ext_evro_ext_io4ro.o evro_ext_evro_ext_modbusstatus.o evro_ext_evro_ext_modbus_ao.o evro_ext_evro_ext_io_daio.o evro_ext_evro_ext_io4di.o evro_ext_evro_ext_io2do.o evro_ext_evro_ext_io2rtd.o evro_ext_evro_ext_io2ai.o evro_ext_evro_ext_io1ao.o evro_ext_evro_ext_io_6rtd.o evro_ext_evro_ext_io6rtd.o
# Create CjIOSmpl library
$(LDIR)/libevro_ext.a : $(RLIST)
	$(AR) r $(LDIR)/libevro_ext.a $(RLIST)

######################################
iodk:
	rm -f *.o
	cp * $(DRVDIR)/

clean:
	rm -f *.o
	rm -f $(LDIR)/libevro_ext.a

