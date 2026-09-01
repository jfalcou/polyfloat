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
option( POLYFLOAT_ENABLE_SANITIZERS   "Build tests with AddressSanitizer + UndefinedBehaviorSanitizer" OFF )
option( POLYFLOAT_ENABLE_COVERAGE     "Build tests with code coverage instrumentation"                 OFF )

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
  endif()
  message(STATUS "[${PROJECT_NAME}] - Unit tests : ${POLYFLOAT_BUILD_TEST} (via POLYFLOAT_BUILD_TEST)")
  message(STATUS "[${PROJECT_NAME}] - Doxygen    : ${POLYFLOAT_BUILD_DOCUMENTATION} (via POLYFLOAT_BUILD_DOCUMENTATION)")
  message(STATUS "[${PROJECT_NAME}] - Sanitizers : ${POLYFLOAT_ENABLE_SANITIZERS} (via POLYFLOAT_ENABLE_SANITIZERS)")
  message(STATUS "[${PROJECT_NAME}] - Coverage   : ${POLYFLOAT_ENABLE_COVERAGE} (via POLYFLOAT_ENABLE_COVERAGE)")
  set(QUIET_OPTION "")
else()
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
  ## Doxygen never fetches anything itself, so eve's tagfile has to be on disk before the target runs. The Doxyfile
  ## reaches it through $(DOXYGEN_OUPUT), the only handle copacabana exports that points into the build tree. Without
  ## it the eve:: references stay unresolved.
  file(DOWNLOAD "https://jfalcou.github.io/eve/eve.tag" "${PROJECT_BINARY_DIR}/eve.tag" STATUS EVE_TAG_STATUS)
  list(GET EVE_TAG_STATUS 0 EVE_TAG_CODE)
  if(NOT EVE_TAG_CODE EQUAL 0)
    message(WARNING "[${PROJECT_NAME}] - eve.tag could not be fetched (${EVE_TAG_STATUS}), the eve:: links will be dead")
  endif()

  copa_setup_doxygen(${QUIET_OPTION}
                     DESTINATION "${PROJECT_BINARY_DIR}/doc"
                     URL "https://github.com/jfalcou/polyfloat"
                     GODBOLT_LIBRARIES polyfloat eve
                     GODBOLT_COMPILER clang1600
                     GODBOLT_OPTIONS "-O3 -std=c++20 -DNDEBUG"
                     COLOR_HUE 41
                     COLOR_SATURATION 47
                     COLOR_LIGHTNESS 54)
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
  if(POLYFLOAT_ENABLE_SANITIZERS)
    copa_setup_sanitizers(polyfloat_docs ENABLE_ASAN ENABLE_UBSAN)
  endif()

  enable_testing()
  add_subdirectory(test)

  # After the test targets exist, so the coverage targets can depend on them
  if(POLYFLOAT_ENABLE_COVERAGE)
    copa_setup_coverage(polyfloat_docs)
  endif()
endif()
