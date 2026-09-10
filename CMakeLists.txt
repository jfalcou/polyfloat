##======================================================================================================================
##  POLYFLOAT - Extended precision floating points
##  Copyright : POLYFLOAT Contributors & Maintainers
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================
cmake_minimum_required(VERSION 3.22)
project(polyfloat LANGUAGES CXX)
include(${PROJECT_SOURCE_DIR}/cmake/dependencies.cmake)

##======================================================================================================================

##======================================================================================================================
## Project setup via copacabana
##======================================================================================================================
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake ${COPACABANA_SOURCE_DIR}/copacabana/cmake)
include(${COPACABANA_SOURCE_DIR}/copacabana/cmake/copacabana.cmake)

copa_add_option(POLYFLOAT_BUILD_TEST "Build tests for POLYFLOAT" ON LABEL "Unit tests")
copa_add_option(POLYFLOAT_BUILD_DOCUMENTATION "Build Doxygen for POLYFLOAT" OFF LABEL "Doxygen")
copa_add_option(POLYFLOAT_ENABLE_SANITIZERS "Build tests with AddressSanitizer + UndefinedBehaviorSanitizer" OFF LABEL "Sanitizers")
copa_add_option(POLYFLOAT_ENABLE_COVERAGE "Build tests with code coverage instrumentation" OFF LABEL "Coverage")
copa_add_option(POLYFLOAT_USE_PCH "Build tests with precompiled headers" ON)
copa_add_option(POLYFLOAT_COMPILE_COST "Measure what every test unit costs to compile" OFF)
copa_project_version(MAJOR 0 MINOR 1 PATCH 0 REPOSITORY https://github.com/jfalcou/polyfloat)

##======================================================================================================================
## Summary Display
##======================================================================================================================
copa_show_options()

if(NOT POLYFLOAT_QUIET)
  set(QUIET_OPTION "")
else()
  set(QUIET_OPTION "QUIET")
endif()

##======================================================================================================================
## Install Process setup
##======================================================================================================================
copa_setup_install( LIBRARY polyfloat
                    FEATURES cxx_std_20
                    CONFIG  ${PROJECT_SOURCE_DIR}/cmake/polyfloat-config.cmake.in
                    DOC     ${PROJECT_SOURCE_DIR}/LICENSE.md
                    INCLUDE ${PROJECT_SOURCE_DIR}/include/polyfloat
                  )

## The public headers include <eve/eve.hpp>, so the interface target has to hand EVE to whoever
## links it. Without this, a consumer using FetchContent or CPM compiles against polyfloat's headers
## alone and stops on the first include.
target_link_libraries(polyfloat_lib INTERFACE eve::eve)

##======================================================================================================================
## Setup doxygen
##======================================================================================================================
if(POLYFLOAT_BUILD_DOCUMENTATION)
  copa_setup_doxygen(${QUIET_OPTION}
                     DESTINATION "${PROJECT_BINARY_DIR}/doc"
                     GODBOLT_LIBRARIES polyfloat eve
                     GODBOLT_COMPILER clang1600
                     GODBOLT_OPTIONS "-O3 -std=c++20 -DNDEBUG"
                     COLOR_HUE 329
                     COLOR_SATURATION 62
                     COLOR_LIGHTNESS 44
                     TAGFILES eve=https://jfalcou.github.io/eve)
endif()

##======================================================================================================================
## Tests setup
##======================================================================================================================
if(POLYFLOAT_BUILD_TEST)
  CPMGetPackage(TTS)
  include(${PROJECT_SOURCE_DIR}/cmake/compiler.cmake)

  ## After compiler.cmake, which declares the interfaces the precompiled headers are attached to.
  copa_setup_pch( TARGET polyfloat        INTERFACES  polyfloat_test  HEADERS include/polyfloat/polyfloat.hpp)
  copa_setup_pch( TARGET polyfloat_doc    INTERFACES  polyfloat_docs  HEADERS include/polyfloat/polyfloat.hpp)
  copa_setup_pch( TARGET polyfloat_bench  INTERFACES  polyfloat_bench HEADERS include/polyfloat/polyfloat.hpp)

  if(POLYFLOAT_ENABLE_SANITIZERS)
    copa_setup_sanitizers(polyfloat_docs ENABLE_ASAN ENABLE_UBSAN)
  endif()

  enable_testing()
  add_subdirectory(test)

  # After the test targets exist, so the coverage targets can depend on them
  if(POLYFLOAT_ENABLE_COVERAGE)
    copa_setup_coverage(polyfloat_docs)
  endif()

  # clang only: -fproc-stat-report is its flag. After the test targets, as the measurement rebuilds them.
  if(POLYFLOAT_COMPILE_COST)
    copa_setup_compile_cost(polyfloat_test)
  endif()
endif()
