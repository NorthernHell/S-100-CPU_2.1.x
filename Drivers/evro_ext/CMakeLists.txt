set (drvname ${CURDRV})
set (${drvname}_SRCS evro_ext_evro_ext_modbus_ai.c evro_ext_evro_ext_io8_tcs.c evro_ext_evro_ext_modbus_do.c evro_ext_evro_ext_io8tcs.c evro_ext_evro_ext_modbus_di.c evro_ext_evro_ext_io8ai.c evro_ext_evro_ext_io16do.c evro_ext_evro_ext_m_ao.c evro_ext_evro_ext_m_ai.c evro_ext_evro_ext_io16di.c evro_ext_evro_ext_io_8ai.c evro_ext_evro_ext_io_8ao.c evro_ext_evro_ext_io_16do.c evro_ext_evro_ext_io_16di.c evro_ext_evro_ext_m_do.c evro_ext_evro_ext_m_di.c evro_ext_evro_ext_io8ao.c evro_ext_evro_ext_io_4ro.c evro_ext_evro_ext_io4ro.c evro_ext_evro_ext_modbusstatus.c evro_ext_evro_ext_modbus_ao.c evro_ext_evro_ext_io_daio.c evro_ext_evro_ext_io4di.c evro_ext_evro_ext_io2do.c evro_ext_evro_ext_io2rtd.c evro_ext_evro_ext_io2ai.c evro_ext_evro_ext_io1ao.c evro_ext_evro_ext_io_6rtd.c evro_ext_evro_ext_io6rtd.c )

set (ALL_SRCS ${${drvname}_SRCS})


SET_SOURCE_FILES_PROPERTIES( ${ALL_SRCS} PROPERTIES LANGUAGE CXX)

include (${CMAKE_CURRENT_SOURCE_DIR}/libdefs.cmake OPTIONAL)

include_directories (${CMAKE_CURRENT_SOURCE_DIR})
add_library (${drvname} ${ALL_SRCS})

