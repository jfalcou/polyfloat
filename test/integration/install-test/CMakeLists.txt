##======================================================================================================================
##  POLYFLOAT - Extended precision floating points
##  Copyright : POLYFLOAT Contributors & Maintainers
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================
cmake_minimum_required(VERSION 3.22)
project(polyfloat-install-test LANGUAGES CXX)
enable_testing()

## Fake install via FetchContent

include(FetchContent)
FetchContent_Declare(eve
  GIT_REPOSITORY "https://github.com/jfalcou/eve.git"
  GIT_TAG main
)

FetchContent_MakeAvailable(eve)

find_package(polyfloat CONFIG REQUIRED)
add_executable(test_polyfloat ../main.cpp)
target_link_libraries(test_polyfloat PUBLIC polyfloat::polyfloat eve::eve)
add_test(NAME test_polyfloat COMMAND test_polyfloat)
