# Install script for directory: /S-100-CPU_GIT

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
  include("/S-100-CPU_GIT/build/Drivers/evro_tcpc/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/evro_rtus/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/evro_tcp/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/evro_ext/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/evro_int/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/fastarr/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/fastmatrix/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/fda_alarm/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/fda_serv/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/fir/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/iir/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/isaafb/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/isaser/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/iset/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/newtype/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/rtlog/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/rtsched/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/symlib/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/sys/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/Drivers/time/cmake_install.cmake")
  include("/S-100-CPU_GIT/build/IsaVm/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

file(WRITE "/S-100-CPU_GIT/build/${CMAKE_INSTALL_MANIFEST}" "")
foreach(file ${CMAKE_INSTALL_MANIFEST_FILES})
  file(APPEND "/S-100-CPU_GIT/build/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
endforeach()
