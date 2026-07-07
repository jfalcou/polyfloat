//======================================================================================================================
/*
  Polyfloat - Extended precision floating points
  Copyright : POLYFLOAT Contributors & Maintainers
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <eve/detail/abi.hpp>

// Faster than std::forward
#define POLYFLOAT_FWD(...) EVE_FWD(__VA_ARGS__)
#define POLYFLOAT_FORCEINLINE EVE_FORCEINLINE
#define POLYFLOAT_NOINLINE EVE_NOINLINE
