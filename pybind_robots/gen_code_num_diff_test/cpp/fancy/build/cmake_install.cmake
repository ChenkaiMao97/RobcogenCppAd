# Install script for directory: /home/csg/Desktop/robcogen-0.4ad.0/run/gen_code/cpp/fancy

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/include/iit/robots/fancy/declarations.h;/usr/local/include/iit/robots/fancy/link_data_map.h;/usr/local/include/iit/robots/fancy/joint_data_map.h;/usr/local/include/iit/robots/fancy/transforms.h;/usr/local/include/iit/robots/fancy/kinematics_parameters.h;/usr/local/include/iit/robots/fancy/jacobians.h;/usr/local/include/iit/robots/fancy/traits.h;/usr/local/include/iit/robots/fancy/jsim.h;/usr/local/include/iit/robots/fancy/inverse_dynamics.h;/usr/local/include/iit/robots/fancy/forward_dynamics.h;/usr/local/include/iit/robots/fancy/inertia_properties.h;/usr/local/include/iit/robots/fancy/dynamics_parameters.h;/usr/local/include/iit/robots/fancy/miscellaneous.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/include/iit/robots/fancy" TYPE FILE FILES
    "/home/csg/Desktop/robcogen-0.4ad.0/run/gen_code/cpp/fancy/./declarations.h"
    "/home/csg/Desktop/robcogen-0.4ad.0/run/gen_code/cpp/fancy/./link_data_map.h"
    "/home/csg/Desktop/robcogen-0.4ad.0/run/gen_code/cpp/fancy/./joint_data_map.h"
    "/home/csg/Desktop/robcogen-0.4ad.0/run/gen_code/cpp/fancy/./transforms.h"
    "/home/csg/Desktop/robcogen-0.4ad.0/run/gen_code/cpp/fancy/./kinematics_parameters.h"
    "/home/csg/Desktop/robcogen-0.4ad.0/run/gen_code/cpp/fancy/./jacobians.h"
    "/home/csg/Desktop/robcogen-0.4ad.0/run/gen_code/cpp/fancy/./traits.h"
    "/home/csg/Desktop/robcogen-0.4ad.0/run/gen_code/cpp/fancy/./jsim.h"
    "/home/csg/Desktop/robcogen-0.4ad.0/run/gen_code/cpp/fancy/./inverse_dynamics.h"
    "/home/csg/Desktop/robcogen-0.4ad.0/run/gen_code/cpp/fancy/./forward_dynamics.h"
    "/home/csg/Desktop/robcogen-0.4ad.0/run/gen_code/cpp/fancy/./inertia_properties.h"
    "/home/csg/Desktop/robcogen-0.4ad.0/run/gen_code/cpp/fancy/./dynamics_parameters.h"
    "/home/csg/Desktop/robcogen-0.4ad.0/run/gen_code/cpp/fancy/./miscellaneous.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/libiitgenfancy.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/libiitgenfancy.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/lib/libiitgenfancy.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/libiitgenfancy.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/lib" TYPE SHARED_LIBRARY FILES "/home/csg/Desktop/robcogen-0.4ad.0/run/gen_code/cpp/fancy/build/libiitgenfancy.so")
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib/libiitgenfancy.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/libiitgenfancy.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/lib/libiitgenfancy.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/csg/Desktop/robcogen-0.4ad.0/run/gen_code/cpp/fancy/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
