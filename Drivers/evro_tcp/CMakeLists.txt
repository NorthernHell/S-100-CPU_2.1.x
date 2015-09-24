set (drvname ${CURDRV})
set (${drvname}_SRCS evro_tcp_evro_tcp_modbus_tcp_server.c evro_tcp_evro_tcp_mts_coil_i.c evro_tcp_evro_tcp_mts_coil_o.c evro_tcp_evro_tcp_mts_holdingr_i.c evro_tcp_evro_tcp_mts_holdingr_o.c evro_tcp_evro_tcp_mts_inp_bits.c evro_tcp_evro_tcp_mts_inp_reg.c )
set (ALL_SRCS ${${drvname}_SRCS})


SET_SOURCE_FILES_PROPERTIES( ${ALL_SRCS} PROPERTIES LANGUAGE CXX)

include (${CMAKE_CURRENT_SOURCE_DIR}/libdefs.cmake OPTIONAL)

include_directories (${CMAKE_CURRENT_SOURCE_DIR})
add_library (${drvname} ${ALL_SRCS})

