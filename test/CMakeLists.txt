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
copa_glob_unit(QUIET PATTERN "doc/*.cpp" INTERFACE polyfloat_docs PCH polyfloat_doc_pch)

##======================================================================================================================
## Unit tests
##======================================================================================================================
copa_glob_unit(QUIET PATTERN "unit/*.cpp" INTERFACE polyfloat_test PCH polyfloat_pch)

##======================================================================================================================
## Performance tests
##======================================================================================================================
copa_glob_unit( PATTERN "benchmarks/*.cpp"
                DESTINATION benchmarks
                RELATIVE  ${root}
                INTERFACE polyfloat_bench
                PCH polyfloat_bench_pch
              )
