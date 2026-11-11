//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

//======================================================================================================================
//! @defgroup constants Constants
//! @brief Constants of every polyfloat type, from the limits of the representation to the mathematical constants.
//!
//! A constant takes the type of its result, `plf::pi(eve::as<plf::double_real_t<double>>())`. The constants are of
//! three kinds:
//!
//! - the limits of the representation, plf::eps, plf::valmax, or plf::effective_mantissa_bits,
//! - the arithmetic constants of EVE, plf::half, plf::inf, or plf::mindenormal, whose high part is the EVE value,
//! - the mathematical constants, plf::pi, plf::euler, or plf::catalan, rounded to the precision of the type.
//======================================================================================================================

#include <polyfloat/module/core/constants/wrapped.hpp>
#include <polyfloat/module/core/constants/effective_mantissa_bits.hpp>
#include <polyfloat/module/core/constants/eps.hpp>
#include <polyfloat/module/core/constants/inf.hpp>
#include <polyfloat/module/core/constants/inveps.hpp>
#include <polyfloat/module/core/constants/logeps.hpp>
#include <polyfloat/module/core/constants/maxflint.hpp>
#include <polyfloat/module/core/constants/minf.hpp>
#include <polyfloat/module/core/constants/nan.hpp>
#include <polyfloat/module/core/constants/oneosqrteps.hpp>
#include <polyfloat/module/core/constants/sqrt_2.hpp>
#include <polyfloat/module/core/constants/sqrteps.hpp>
#include <polyfloat/module/core/constants/sqrtvalmax.hpp>
#include <polyfloat/module/core/constants/valmax.hpp>
#include <polyfloat/module/core/constants/valmin.hpp>
