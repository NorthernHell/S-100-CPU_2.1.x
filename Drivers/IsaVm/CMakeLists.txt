set (IsaVM_SRCS dipl0lnk.c divm0mai.c)

set (ALL_SRCS ${IsaVM_SRCS})
SET_SOURCE_FILES_PROPERTIES( ${ALL_SRCS} PROPERTIES LANGUAGE CXX)

include_directories (${ACE_INCLUDE_DIR} "${CMAKE_SOURCE_DIR}/IsaSys" "${CMAKE_SOURCE_DIR}/IsaKer" "${CMAKE_SOURCE_DIR}/IsaRsi" "${CMAKE_SOURCE_DIR}/IsaIxl" "${CMAKE_SOURCE_DIR}/IsaVM" "${CMAKE_SOURCE_DIR}/Etcp")

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Cmds")

add_executable (IsaVM ${IsaVM_SRCS} $<TARGET_OBJECTS:JitSL>)
target_link_libraries (IsaVM IsaKer IsaSrv IsaIxl IsxlHsd IsxlEtcp IsxlRsi IsaNwl EtcpCmon RsiCmon IKvbHsd IKvbEtcp IsaSys ISysSoc)
message(STATUS "IsaVM DRVLIB: " ${DRVLIB})
target_link_libraries (IsaVM ${DRVLIB})
#target_link_libraries (IsaVM IsaKer IsaSrv IsaIxl IsxlHsd IsxlEtcp IsxlRsi IsaNwl EtcpCmon RsiCmon IKvbHsd IKvbEtcp IsaSys ISysSoc libJIT)