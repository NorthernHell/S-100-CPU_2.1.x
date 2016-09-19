set (drvname ${CURDRV})
set (${drvname}_SRCS evro_int_evro_int_evro_6ai.c  evro_int_evro_int_evro_8tc.c evro_int_evro_int_evro_6rtd.c evro_int_evro_int_evro_4ao.c evro_int_evro_int_evro_16do.c    evro_int_evro_int_evro_8ro.c  evro_int_evro_int_evro_8di.c evro_int_evro_int_evro_8dir.c  evro_int_evro_int_evro_modul_info_.c evro_int_evro_int_evro_modul_info.c evro_int_evro_int_evro_avar_info.c  evro_int_evro_int_evro_temp_info.c evro_int_evro_int_evro_indicate_info.c evro_int_evro_int_evro_16di.c evro_int_evro_int_evro_16dir.c  evro_int_evro_int_evro_8tc_.c  evro_int_evro_int_evro_6ai_.c  evro_int_evro_int_evro_6rtd_.c evro_int_evro_int_evro_4ao_.c evro_int_evro_int_evro_16do_.c    evro_int_evro_int_evro_8ro_.c    evro_int_evro_int_evro_8di_.c    evro_int_evro_int_evro_16di_.c    evro_int_evro_int_status_m.c )

set (ALL_SRCS ${${drvname}_SRCS})


SET_SOURCE_FILES_PROPERTIES( ${ALL_SRCS} PROPERTIES LANGUAGE CXX)

include (${CMAKE_CURRENT_SOURCE_DIR}/libdefs.cmake OPTIONAL)

include_directories (${CMAKE_CURRENT_SOURCE_DIR})
add_library (${drvname} ${ALL_SRCS})

