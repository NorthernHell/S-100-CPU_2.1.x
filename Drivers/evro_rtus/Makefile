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
RLIST =  modbus_rtu_server.o modbus_rtu_coil_i_.o modbus_rtu_coil_o_.o modbus_rtu_holding_i_.o modbus_rtu_holding_o_.o modbus_rtu_inp_bits_.o modbus_rtu_inp_reg_.o 
# Create CjIOSmpl library
$(LDIR)/libevro_rtus.a : $(RLIST)
	$(AR) r $(LDIR)/libevro_rtus.a $(RLIST)

######################################
iodk:
	rm -f *.o
	cp * $(DRVDIR)/

clean:
	rm -f *.o
	rm -f $(LDIR)/libevro_rtus.a

