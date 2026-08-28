##======================================================================================================================
##  POLYFLOAT - Extended precision floating points
##  Copyright : POLYFLOAT Contributors & Maintainers
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================
cmake_minimum_required(VERSION 3.22)
project(polyfloat-fetch-test LANGUAGES CXX)
enable_testing()

message(STATUS "Testing FetchContent for branch ${GIT_BRANCH}")

include(FetchContent)

# Retrieve polyfloat from relative git directory
FetchContent_Declare(polyfloat
  GIT_REPOSITORY "https://github.com/jfalcou/polyfloat.git"
  GIT_TAG ${GIT_BRANCH}
)
FetchContent_Declare(eve
  GIT_REPOSITORY "https://github.com/jfalcou/eve.git"
  GIT_TAG main
)

## FetchContent has no per-package OPTIONS: what the dependencies read is pinned here.
set(POLYFLOAT_BUILD_TEST    OFF CACHE BOOL "" FORCE)
set(EVE_BUILD_TEST          OFF CACHE BOOL "" FORCE)
set(EVE_BUILD_BENCHMARKS    OFF CACHE BOOL "" FORCE)
set(EVE_BUILD_DOCUMENTATION OFF CACHE BOOL "" FORCE)

# make available
FetchContent_MakeAvailable(polyfloat)
FetchContent_MakeAvailable(eve)

add_executable(test_polyfloat ../main.cpp)
target_link_libraries(test_polyfloat PUBLIC polyfloat::polyfloat eve::eve)
add_test(NAME test_polyfloat COMMAND test_polyfloat)
