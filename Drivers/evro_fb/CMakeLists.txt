set (drvname ${CURDRV})
set (${drvname}_SRCS pid_evro.c)
set (ALL_SRCS ${${drvname}_SRCS})


SET_SOURCE_FILES_PROPERTIES( ${ALL_SRCS} PROPERTIES LANGUAGE CXX)

include (${CMAKE_CURRENT_SOURCE_DIR}/libdefs.cmake OPTIONAL)

include_directories (${CMAKE_CURRENT_SOURCE_DIR})
add_library (${drvname} ${ALL_SRCS})

