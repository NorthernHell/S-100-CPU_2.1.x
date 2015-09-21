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
RLIST =  evro_tcpc_evro_tcpc_mtcp_ai.o evro_tcpc_evro_tcpc_mtcp_di.o evro_tcpc_evro_tcpc_mtcp_ao.o evro_tcpc_evro_tcpc_mtcp_do.o evro_tcpc_evro_tcpc_modbus_tcp_status.o evro_tcpc_evro_tcpc_modbus_tcp_client_do.o evro_tcpc_evro_tcpc_modbus_tcp_client_ao.o evro_tcpc_evro_tcpc_modbus_tcp_client_di.o evro_tcpc_evro_tcpc_modbus_tcp_client_ai.o 
# Create CjIOSmpl library
$(LDIR)/libevro_tcpc.a : $(RLIST)
	$(AR) r $(LDIR)/libevro_tcpc.a $(RLIST)

######################################
iodk:
	rm -f *.o
	cp * $(DRVDIR)/

clean:
	rm -f *.o
	rm -f $(LDIR)/libevro_tcpc.a

