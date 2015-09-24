set (drvname ${CURDRV})
set (${drvname}_SRCS evro_tcpc_evro_tcpc_mtcp_ai.c evro_tcpc_evro_tcpc_mtcp_di.c evro_tcpc_evro_tcpc_mtcp_ao.c evro_tcpc_evro_tcpc_mtcp_do.c evro_tcpc_evro_tcpc_modbus_tcp_status.c evro_tcpc_evro_tcpc_modbus_tcp_client_do.c evro_tcpc_evro_tcpc_modbus_tcp_client_ao.c evro_tcpc_evro_tcpc_modbus_tcp_client_di.c evro_tcpc_evro_tcpc_modbus_tcp_client_ai.c )
set (ALL_SRCS ${${drvname}_SRCS})


SET_SOURCE_FILES_PROPERTIES( ${ALL_SRCS} PROPERTIES LANGUAGE CXX)

include (${CMAKE_CURRENT_SOURCE_DIR}/libdefs.cmake OPTIONAL)

include_directories (${CMAKE_CURRENT_SOURCE_DIR})
add_library (${drvname} ${ALL_SRCS})

