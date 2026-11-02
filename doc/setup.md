Installation & Quick Start {#setup}
==========================

# Pre-requisites

**POLYFLOAT** is a header-only C++20 library. It is built on top of
[EVE](https://github.com/jfalcou/eve), which it needs at compile time and which shares its
compiler requirements:

| Compiler | Minimal version | Tested in CI |
| -------- | --------------- | ------------ |
| g++      | 13 or above     | 15           |
| clang++  | 16 or above     | 20           |

CMake 3.22 or above is required to build the tests and the documentation. Consuming the library
needs no build step of its own: adding the include directory is enough, provided EVE is reachable
too.

# Getting POLYFLOAT

Whichever route you take, the target to link against is `polyfloat::polyfloat`, and EVE must be linked
alongside it. The three snippets below are the ones exercised by the integration tests, so they
are known to work.

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
FetchContent_Declare(eve   GIT_REPOSITORY "https://github.com/jfalcou/eve.git"   GIT_TAG main)

set(POLYFLOAT_BUILD_TEST        OFF CACHE BOOL "" FORCE)
set(EVE_BUILD_TEST          OFF CACHE BOOL "" FORCE)
set(EVE_BUILD_BENCHMARKS    OFF CACHE BOOL "" FORCE)
set(EVE_BUILD_DOCUMENTATION OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(polyfloat)
FetchContent_MakeAvailable(eve)

target_link_libraries(my_app PUBLIC polyfloat::polyfloat eve::eve)
```

`FetchContent` carries no per-package options, so the settings each dependency reads are pinned
before the call. Left out, every dependency registers its own test suite in your project.

## From an installed copy

```bash
git clone https://github.com/jfalcou/polyfloat.git
cmake -S polyfloat -B build -DCMAKE_INSTALL_PREFIX=/where/you/want
cmake --install build
```

then

```cmake
find_package(polyfloat CONFIG REQUIRED)
target_link_libraries(my_app PUBLIC polyfloat::polyfloat eve::eve)
```

# Your first program

A single header brings in everything:

@godbolt{doc/core/quick_start.cpp}

Two things are worth noticing already.

 -  `plf::sqrt` is applied to a value that is a representation of a real
     number and returns one anyway, so the square root of a negative real is a Nan.
 -  1.0+ eps/2 is exactly 1.0 in double arithmetic, but not in double_real or triple real one. It can be noticed that
    the precision is related to the type of the input.

So `plf::sqrt` can accept standard floating value (float or double) as well as a double_real or a triple_real
 without any change of spelling. But take care that the output will be of the same type.

All these features are the subject of the tutorials that follow.

# Where to go next

  + @ref tutorial-basics — polyfloats : what you have to  know.
  + @ref tutorial-simd — the same code applied to many values at once.
