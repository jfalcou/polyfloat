##======================================================================================================================
##  POLYFLOAT - Extended precision floating points
##  Copyright : POLYFLOAT Contributors & Maintainers
##  SPDX-License-Identifier: BSL-1.0

copa_setup_test_targets()
add_custom_target("polyfloat-bench")
set(root "${CMAKE_SOURCE_DIR}/test")

##======================================================================================================================
## Documentation tests
##======================================================================================================================
copa_glob_unit(QUIET PATTERN "doc/core/*.cpp" INTERFACE polyfloat_docs PCH polyfloat_doc_pch  EXTERNALS mpfr gmp )
copa_glob_unit(QUIET PATTERN "doc/math/*.cpp" INTERFACE polyfloat_docs PCH polyfloat_doc_pch  EXTERNALS mpfr gmp )

##======================================================================================================================
## Unit tests
##======================================================================================================================
copa_glob_unit(QUIET PATTERN "unit/api/*.cpp" INTERFACE polyfloat_test PCH polyfloat_pch  EXTERNALS mpfr gmp )
##copa_glob_unit(QUIET PATTERN "unit/infra/*.cpp" INTERFACE polyfloat_test PCH polyfloat_pch  EXTERNALS mpfr gmp )
copa_glob_unit(QUIET PATTERN "unit/core/*.cpp" INTERFACE polyfloat_test PCH polyfloat_pch  EXTERNALS mpfr gmp )
copa_glob_unit(QUIET PATTERN "unit/math/*.cpp" INTERFACE polyfloat_test PCH polyfloat_pch  EXTERNALS mpfr gmp )

##======================================================================================================================
## Performance tests
##======================================================================================================================
copa_glob_unit( PATTERN "benchmarks/*.cpp"
                DESTINATION benchmarks
                RELATIVE  ${root}
                INTERFACE polyfloat_bench
                PCH polyfloat_bench_pch
                EXTERNALS mpfr gmp
              )
