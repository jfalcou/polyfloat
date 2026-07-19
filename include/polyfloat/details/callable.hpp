//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once
#include <polyfloat/details/abi.hpp>
#include <eve/traits/overload.hpp>

namespace plf::_    { EVE_CALLABLE_NAMESPACE(); }

//  EVE-related macro that use polyfloat::_ as the deferred namespace
#define POLYFLOAT_CALLABLE_OBJECT(TYPE, NAME) EVE_CALLABLE_OBJECT_FROM(plf::_,TYPE, NAME)
#define POLYFLOAT_CALL(...)                   EVE_DISPATCH_CALL(__VA_ARGS__)
#define POLYFLOAT_DELAY()                     EVE_REQUIRES(eve::cpu_)
