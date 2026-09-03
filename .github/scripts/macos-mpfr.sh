#!/usr/bin/env bash
##======================================================================================================================
##  POLYFLOAT - Flexible multiprecision types
##  Copyright : POLYFLOAT Project Contributors
##  SPDX-License-Identifier: BSL-1.0
##======================================================================================================================
## Sourced before the configure of a macOS row. MPFR C++ is a single header fetched next to the sources, and the
## presets read the two brew prefixes from the environment, which is only known at run time: exported for this step,
## and written to GITHUB_ENV for the ones that follow.
set -e
curl -sSLO https://raw.githubusercontent.com/advanpix/mpreal/master/mpreal.h
export GMP_PREFIX="$(brew --prefix gmp)"
export MPFR_PREFIX="$(brew --prefix mpfr)"
{
  echo "GMP_PREFIX=$GMP_PREFIX"
  echo "MPFR_PREFIX=$MPFR_PREFIX"
} >> "$GITHUB_ENV"
