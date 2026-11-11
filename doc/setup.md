Installation {#setup}
============

# Prerequisites

**POLYFLOAT** is a header-only C++20 library with the following requirements:

| Compiler | Minimal version | Tested in CI |
| -------- | --------------- | ------------ |
| g++      | 13 or above     | 15           |
| clang++  | 16 or above     | 20           |

It depends on:

  + [EVE](https://github.com/jfalcou/eve), at compile time, for the SIMD types and the real
    functions.
  + CMake 3.22 or above, for the tests and the documentation only.

A consumer has no build step: the include directory of the library and the one of EVE are
enough.

# Installation

The target to link is `polyfloat::polyfloat`, with `eve::eve` beside it. The integration tests
build each of the three routes.

## With CPM

```cmake
CPMAddPackage ( NAME polyfloat
                GIT_REPOSITORY "https://github.com/jfalcou/polyfloat.git"
                GIT_TAG main
                OPTIONS "POLYFLOAT_BUILD_TEST OFF"
              )

target_link_libraries(my_app PUBLIC polyfloat::polyfloat eve::eve)
```

## With FetchContent

```cmake
include(FetchContent)

FetchContent_Declare(polyfloat GIT_REPOSITORY "https://github.com/jfalcou/polyfloat.git" GIT_TAG main)
FetchContent_Declare(eve       GIT_REPOSITORY "https://github.com/jfalcou/eve.git"       GIT_TAG main)

set(POLYFLOAT_BUILD_TEST    OFF CACHE BOOL "" FORCE)
set(EVE_BUILD_TEST          OFF CACHE BOOL "" FORCE)
set(EVE_BUILD_BENCHMARKS    OFF CACHE BOOL "" FORCE)
set(EVE_BUILD_DOCUMENTATION OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(polyfloat)
FetchContent_MakeAvailable(eve)

target_link_libraries(my_app PUBLIC polyfloat::polyfloat eve::eve)
```

`FetchContent` takes no option per package, so the options each dependency reads are set before
the call. Without them, every dependency adds its own tests to the project.

## With a git clone

```bash
git clone https://github.com/jfalcou/polyfloat.git
cmake -S polyfloat -B build -DCMAKE_INSTALL_PREFIX=<prefix>
cmake --install build
```

then

```cmake
find_package(polyfloat CONFIG REQUIRED)
target_link_libraries(my_app PUBLIC polyfloat::polyfloat eve::eve)
```

# First program

`polyfloat/polyfloat.hpp` declares every type and every function of the library, and includes
EVE. A program that includes it and links `polyfloat::polyfloat` as above compiles and runs:

@godbolt{doc/core/quick_start.cpp}

# Tutorials

  + @ref tutorial-basics "Polyfloat numbers"
  + @ref tutorial-simd "SIMD support"
