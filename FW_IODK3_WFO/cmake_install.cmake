# Install script for directory: /root/iodk/merk/iodk3

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/evro_tcpc/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/evro_rtus/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/evro_tcp/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/evro_ext/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/evro_int/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/fastmatrix/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/fda_alarm/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/fda_serv/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/isaafb/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/isaser/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/iset/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/newtype/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/rtlog/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/rtsched/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/sys/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/symlib/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/time/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/fir/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/iir/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/Drivers/fastarr/cmake_install.cmake")
  include("/root/iodk/merk/iodk3/FW_IODK3_WFO/IsaVm/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

file(WRITE "/root/iodk/merk/iodk3/FW_IODK3_WFO/${CMAKE_INSTALL_MANIFEST}" "")
foreach(file ${CMAKE_INSTALL_MANIFEST_FILES})
  file(APPEND "/root/iodk/merk/iodk3/FW_IODK3_WFO/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
endforeach()
