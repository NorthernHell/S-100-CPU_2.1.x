set (drvname ${CURDRV})
set (${drvname}_SRCS modbus_rtu_server.c modbus_rtu_coil_i_.c modbus_rtu_coil_o_.c modbus_rtu_holding_i_.c modbus_rtu_holding_o_.c modbus_rtu_inp_bits_.c modbus_rtu_inp_reg_.c )
set (ALL_SRCS ${${drvname}_SRCS})


SET_SOURCE_FILES_PROPERTIES( ${ALL_SRCS} PROPERTIES LANGUAGE CXX)

include (${CMAKE_CURRENT_SOURCE_DIR}/libdefs.cmake OPTIONAL)

include_directories (${CMAKE_CURRENT_SOURCE_DIR})
add_library (${drvname} ${ALL_SRCS})

