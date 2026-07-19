##======================================================================================================================
##  POLYFLOAT - Extended precision floating points
##  Copyright : POLYFLOAT Contributors & Maintainers
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================
cmake_minimum_required(VERSION 3.22)
project(polyfloat LANGUAGES CXX)
include(${PROJECT_SOURCE_DIR}/cmake/dependencies.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/compiler.cmake)

##======================================================================================================================
option( POLYFLOAT_BUILD_TEST          "Build tests for POLYFLOAT"   ON  )
option( POLYFLOAT_BUILD_DOCUMENTATION "Build Doxygen for POLYFLOAT" OFF )

##======================================================================================================================
## Project setup via copacabana
##======================================================================================================================
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake ${COPACABANA_SOURCE_DIR}/copacabana/cmake)
include(${COPACABANA_SOURCE_DIR}/copacabana/cmake/copacabana.cmake)
copa_project_version(MAJOR 0 MINOR 1 PATCH 0)

##======================================================================================================================
## Summary Display
##======================================================================================================================
if(NOT POLYFLOAT_QUIET)
  if(CMAKE_BUILD_TYPE)
    message(STATUS "[${PROJECT_NAME}] - Building in ${CMAKE_BUILD_TYPE} mode")
  set(QUIET_OPTION "")
  endif()
  message(STATUS "[${PROJECT_NAME}] - Unit tests : ${POLYFLOAT_BUILD_TEST} (via POLYFLOAT_BUILD_TEST)")
  message(STATUS "[${PROJECT_NAME}] - Doxygen    : ${POLYFLOAT_BUILD_DOCUMENTATION} (via POLYFLOAT_BUILD_DOCUMENTATION)")
  set(QUIET_OPTION "QUIET")
endif()

##======================================================================================================================
## Install Process setup
##======================================================================================================================
copa_setup_install( LIBRARY polyfloat
                    FEATURES cxx_std_20
                    DOC     ${PROJECT_SOURCE_DIR}/LICENSE.md
                    INCLUDE ${PROJECT_SOURCE_DIR}/include/polyfloat
                  )

##======================================================================================================================
## Setup doxygen
##======================================================================================================================
if(POLYFLOAT_BUILD_DOCUMENTATION)
  copa_setup_doxygen(${QUIET_OPTION} DESTINATION "${PROJECT_BINARY_DIR}/doc")
endif()

##======================================================================================================================
## Setup PCH
##======================================================================================================================
copa_setup_pch( TARGET polyfloat        INTERFACES  polyfloat_test  HEADERS include/polyfloat/polyfloat.hpp)
copa_setup_pch( TARGET polyfloat_doc    INTERFACES  polyfloat_docs  HEADERS include/polyfloat/polyfloat.hpp)
copa_setup_pch( TARGET polyfloat_bench  INTERFACES  polyfloat_bench HEADERS include/polyfloat/polyfloat.hpp)

##======================================================================================================================
## Tests setup
##======================================================================================================================
if(POLYFLOAT_BUILD_TEST)
  enable_testing()
  add_subdirectory(test)
endif()
