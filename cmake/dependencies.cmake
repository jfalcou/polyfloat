##======================================================================================================================
##  Polyfloat - Extended precision floating points
##  Copyright : POLYFLOAT Contributors & Maintainers
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================

##======================================================================================================================
## Take the dependencies from the environment, without CPM
##======================================================================================================================
option(POLYFLOAT_EXTERNAL_DEPENDENCIES "Take dependencies from the environment instead of fetching them" OFF)

##======================================================================================================================
## Retrieve a package declared below, from the environment or by CPM
##======================================================================================================================
macro(polyfloat_get_package name)
  if(POLYFLOAT_EXTERNAL_DEPENDENCIES)
    find_package(${name} CONFIG REQUIRED)
  else()
    CPMGetPackage(${name})
  endif()
endmacro()

if(POLYFLOAT_EXTERNAL_DEPENDENCIES)
  if(NOT COPACABANA_SOURCE_DIR)
    message(FATAL_ERROR "[POLYFLOAT] - POLYFLOAT_EXTERNAL_DEPENDENCIES needs COPACABANA_SOURCE_DIR")
  endif()
  find_package(EVE CONFIG REQUIRED)
  return()
endif()

##======================================================================================================================
## CPM is vendored: the download bootstrap reports nothing on a failure and leaves an empty file.
##======================================================================================================================
include(${CMAKE_CURRENT_LIST_DIR}/CPM.cmake)

##======================================================================================================================
## Retrieve dependencies
##
## This file runs before the project can declare an option, copa_add_option arriving with copacabana, so a package
## wanted only under an option is declared here and fetched after the options, in CMakeLists.txt. EVE stays
## unconditional: the exported target links eve::eve, so it is needed by an install without tests.
##======================================================================================================================
CPMAddPackage(NAME COPACABANA GITHUB_REPOSITORY jfalcou/copacabana GIT_TAG e96014671dfb262482346ddcaa3a1a810b3eebaf)

CPMDeclarePackage(
  TTS
  NAME TTS
  GITHUB_REPOSITORY jfalcou/tts
  GIT_TAG 5b268b654b0af9aa46406710f23e5297a7658605
  SYSTEM YES
  OPTIONS "TTS_BUILD_TEST OFF" "TTS_BUILD_DOCUMENTATION OFF" "TTS_QUIET ON")
CPMAddPackage(
  NAME EVE
  GITHUB_REPOSITORY jfalcou/eve
  GIT_TAG 09dde6f5c9acab312228c78d7281621a86a87988
  SYSTEM YES
  OPTIONS "EVE_BUILD_TEST OFF" "EVE_BUILD_BENCHMARKS OFF" "EVE_BUILD_DOCUMENTATION OFF")
