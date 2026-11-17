##======================================================================================================================
##  POLYFLOAT - Extended precision floating points
##  Copyright : POLYFLOAT Contributors & Maintainers
##  SPDX-License-Identifier: BSL-1.0

set(TEST_ROOT "${CMAKE_SOURCE_DIR}/test")

## The precompiled header carries polyfloat.hpp, so a file that forgets to include it still builds.
if(POLYFLOAT_USE_PCH)
  set(DOC_PCH PCH polyfloat_doc_pch)
  set(UNIT_PCH PCH polyfloat_pch)
  set(BENCH_PCH PCH polyfloat_bench_pch)
else()
  set(DOC_PCH "")
  set(UNIT_PCH "")
  set(BENCH_PCH "")
endif()

if(POLYFLOAT_BUILD_TEST)
  copa_setup_test_targets()

  ##====================================================================================================================
  ## Documentation tests
  ##====================================================================================================================
  copa_glob_unit(
    QUIET
    PATTERN "doc/core/*.cpp"
    INTERFACE polyfloat_docs ${DOC_PCH}
    EXTERNALS mpfr gmp)
  copa_glob_unit(
    QUIET
    PATTERN "doc/math/*.cpp"
    INTERFACE polyfloat_docs ${DOC_PCH}
    EXTERNALS mpfr gmp)

  ##====================================================================================================================
  ## Unit tests
  ##====================================================================================================================
  copa_glob_unit(
    QUIET
    PATTERN "unit/api/*.cpp"
    INTERFACE polyfloat_test ${UNIT_PCH}
    EXTERNALS mpfr gmp)
  ##copa_glob_unit(QUIET PATTERN "unit/infra/*.cpp" INTERFACE polyfloat_test ${UNIT_PCH}  EXTERNALS mpfr gmp )
  copa_glob_unit(
    QUIET
    PATTERN "unit/core/*.cpp"
    INTERFACE polyfloat_test ${UNIT_PCH}
    EXTERNALS mpfr gmp)
  copa_glob_unit(
    QUIET
    PATTERN "unit/math/*.cpp"
    INTERFACE polyfloat_test ${UNIT_PCH}
    EXTERNALS mpfr gmp)
endif()

if(POLYFLOAT_BUILD_BENCHMARKS)
  ##====================================================================================================================
  ## Performance tests
  ##====================================================================================================================
  add_custom_target("polyfloat-bench" COMMENT "[polyfloat] - Building the benchmarks")
  copa_glob_unit(
    PATTERN "benchmarks/*.cpp"
    DESTINATION benchmarks
    RELATIVE ${TEST_ROOT}
    INTERFACE polyfloat_bench ${BENCH_PCH}
    EXTERNALS mpfr gmp
    TARGET polyfloat-bench)
endif()
