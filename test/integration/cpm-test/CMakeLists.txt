##======================================================================================================================
##  POLYFLOAT - Extended precision floating points
##  Copyright : POLYFLOAT Contributors & Maintainers
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================
cmake_minimum_required(VERSION 3.18)
project(polyfloat-cpm-test LANGUAGES CXX)
enable_testing()

message(STATUS "Testing CPM for branch ${GIT_BRANCH}")

# Setup CPM
include(cpm.cmake)

# Add dependencies
CPMAddPackage ( NAME polyfloat
                GIT_REPOSITORY "https://github.com/jfalcou/polyfloat.git"
                GIT_TAG "${GIT_BRANCH}"
                OPTIONS "POLYFLOAT_BUILD_TEST OFF"
              )

# Use polyfloat
add_executable(test_polyfloat ../main.cpp)
target_link_libraries(test_polyfloat PUBLIC polyfloat::polyfloat eve::eve)
add_test(NAME test_polyfloat COMMAND test_polyfloat)
