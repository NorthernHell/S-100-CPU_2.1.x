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
RLIST = evro_tcp_evro_tcp_modbus_tcp_server.o evro_tcp_evro_tcp_mts_coil_i.o evro_tcp_evro_tcp_mts_coil_o.o evro_tcp_evro_tcp_mts_holdingr_i.o evro_tcp_evro_tcp_mts_holdingr_o.o evro_tcp_evro_tcp_mts_inp_bits.o evro_tcp_evro_tcp_mts_inp_reg.o 
# Create CjIOSmpl library
$(LDIR)/libevro_tcp.a : $(RLIST)
	$(AR) r $(LDIR)/libevro_tcp.a $(RLIST)

######################################
iodk:
	rm -f *.o
	cp * $(DRVDIR)/

clean:
	rm -f *.o
	rm -f $(LDIR)/libevro_tcp.a

