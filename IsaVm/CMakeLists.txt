set (IsaVM_SRCS dipl0lnk.c divm0mai.c)

find_package(Threads)

set (ALL_SRCS ${IsaVM_SRCS})
SET_SOURCE_FILES_PROPERTIES( ${ALL_SRCS} PROPERTIES LANGUAGE CXX)

include_directories (${ACE_INCLUDE_DIR} "${CMAKE_SOURCE_DIR}/IsaSys" "${CMAKE_SOURCE_DIR}/IsaKer" "${CMAKE_SOURCE_DIR}/IsaRsi" "${CMAKE_SOURCE_DIR}/IsaIxl" "${CMAKE_SOURCE_DIR}/IsaVM" "${CMAKE_SOURCE_DIR}/Etcp")

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Cmds")

add_executable (IsaVM ${ACEWIN32EXE} ${IsaVM_SRCS})

message(STATUS "IsaVM DRVLIB: " ${DRVLIB})
target_link_libraries (IsaVM ${DRVLIB} ${ACE_LIBRARIES})

set (ISAGRAF_LIBS ISysSoc IsaKer IsaSrv IsaIxl IsxlHsd IsxlEtcp IsxlRsi IKvbHsd IKvbEtcp EtcpCmon RsiCmon IsaSys IsaNwl ${LICENSE_LIBS} )
foreach (isalib ${ISAGRAF_LIBS})
	add_library (${isalib} STATIC IMPORTED)
	set_target_properties (${isalib} PROPERTIES IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/Lib/${CMAKE_STATIC_LIBRARY_PREFX}${isalib}${CMAKE_STATIC_LIBRARY_SUFFIX}")	
endforeach()
target_link_libraries (IsaVM ${ISAGRAF_LIBS})
target_link_libraries (IsaVM ${CUSTOM_LINKER_LIBS})
target_link_libraries (IsaVM ${CMAKE_THREAD_LIBS_INIT})

target_link_libraries (IsaVM ${libdefs})
