Building for Testing {#building}
====================

The tests and the documentation of **POLYFLOAT** are built from a clone of its repository. A
project that uses the library builds neither, and installs it as in @ref setup.

# CMake setup

`CMakePresets.json` holds the configurations of the CI, and a preset reproduces one of them:

| Preset | Configuration |
| ------ | ------------- |
| `gcc`, `clang` | the compiler, every other setting at its default |
| `gcc-avx2`, `clang-avx2` | the same with AVX2 enabled |
| `gcc-no-pch` | without the precompiled header, which detects a missing include |
| `gcc-sanitize`, `clang-sanitize` | AddressSanitizer and UndefinedBehaviorSanitizer |
| `gcc-coverage`, `clang-coverage` | coverage instrumentation |
| `clang-compile-cost` | the compilation time and memory of every test unit |
| `clang-macos`, `clang-macos-libc++` | macOS, against libstdc++ and libc++ |

```bash
cmake --preset=gcc
```

Each preset also sets the generator, a build directory named after the preset, and `Debug` as
the default configuration. The compilers it names are those of the CI image, a Docker image
described on [EVE's development environment page](https://jfalcou.github.io/eve/dev_environment.html).

The equivalent configuration without a preset is:

```bash
cmake -S . -B build -G Ninja \
      -DCMAKE_CXX_COMPILER=g++ \
      -DCMAKE_CXX_FLAGS="-O0 -DEVE_NO_FORCEINLINE"
```

`EVE_NO_FORCEINLINE` removes the forced inlining of the functions of EVE, which the tests do not
need and which dominates their compilation time otherwise. `clang++` replaces `g++`, in any
version that meets the requirements of @ref setup.

Six options select the targets, and the presets set them:

| Option | Default | Effect |
| ------ | ------- | ------ |
| `POLYFLOAT_BUILD_TEST` | `ON` | declare the test targets |
| `POLYFLOAT_USE_PCH` | `ON` | build the tests against a precompiled header |
| `POLYFLOAT_BUILD_DOCUMENTATION` | `OFF` | declare the `polyfloat-doxygen` target |
| `POLYFLOAT_ENABLE_SANITIZERS` | `OFF` | AddressSanitizer and UndefinedBehaviorSanitizer |
| `POLYFLOAT_ENABLE_COVERAGE` | `OFF` | coverage instrumentation |
| `POLYFLOAT_COMPILE_COST` | `OFF` | measure the compilation of every test unit |

# Compiling the tests

The tests are named targets outside of `all`, so `--target all` builds nothing. The whole suite
is `polyfloat-test`, and every directory of `test/` has a target of its own, named after its path
with the separators replaced by dots:

| Target | Content |
| ------ | ------- |
| `polyfloat-test` | every test |
| `unit.exe` | all unit tests |
| `unit.api.exe` | unit tests of the types, the traits, and the operators |
| `unit.core.exe` | unit tests of the core functions |
| `unit.math.exe` | unit tests of the elementary functions |
| `doc.exe` | every example of the documentation |
| `doc.core.exe` | the examples of the core functions and of the tutorials |
| `doc.math.exe` | the examples of the elementary functions |
| `doc.<module>.<function>.exe` | the example of one function, `doc.core.sqrt.exe` and so on |

The unit test of plf::acos is one file, compiled by its own target:

```bash
ninja -C build unit.math.acos.exe
```

`unit.exe` and `polyfloat-test` compile hundreds of units, while the target of one function
compiles one.

# Running the tests

The executables are written to `build/unit`, and each one runs on its own:

```bash
./build/unit/unit.math.acos.exe
```

`ctest` runs them all, with the build directory or with the preset of the build:

```bash
ctest --test-dir build
ctest --preset=gcc
```

# Building the documentation

```bash
cmake -S . -B build -G Ninja -DPOLYFLOAT_BUILD_TEST=OFF -DPOLYFLOAT_BUILD_DOCUMENTATION=ON
cmake --build build --target polyfloat-doxygen
```

The pages are written to `build/doc`. The configuration downloads the tag file of EVE, through
which the `eve::` references resolve. Without network access, they render as plain text, and a
warning reports it.
