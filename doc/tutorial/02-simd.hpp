#error This file is for documentation only - DO NOT INCLUDE
//! @page tutorial-simd SIMD support
//!
//! **POLYFLOAT** is built on [EVE](https://github.com/jfalcou/eve), and every function accepts an
//! `eve::wide` where it accepts a scalar. An `eve::wide<T>` is a SIMD register of `T`, whose
//! operators apply to every lane as they apply to a scalar. `polyfloat/polyfloat.hpp` also includes
//! EVE, so `eve::wide` and the constants of EVE need no header of their own.
//!
//! @note The [EVE documentation](https://jfalcou.github.io/eve/) and its
//! [tutorials](https://jfalcou.github.io/eve/intro-01.html) cover SIMD programming: the registers,
//! the masks, the algorithms, and the architectures.
//!
//! # Registers of reals
//!
//! `eve::wide<double>` holds as many `double` as a register of the target machine:
//!
//! - two on x86-64 with SSE2,
//! - four with AVX,
//! - eight with AVX-512.
//!
//! The width is selected at compile time from the target, and the source never names it.
//!
//! A register is built from a function of two arguments, the lane index and the width, called once
//! per lane, or from one value copied into every lane, `eve::wide<double>(2.0)`.
//! `eve::wide<double>::size()` is the number of `double` in the register, `x.get(i)` reads lane
//! `i`, and `x.set(i, v)` writes it. Below, a
//! [lambda](https://en.cppreference.com/w/cpp/language/lambda) puts \f$-1 + k\f$ in lane \f$k\f$
//! and leaves the width unused:
//!
//! @godbolt{doc/core/tut_simd_wide_floats.cpp}
//!
//! # Registers of polyfloat values
//!
//! `eve::wide<plf::double_real_t<double>>` is a register of polyfloat values, with as many lanes as
//! `eve::wide<double>`. It is built in the same way, and the functions apply to all its lanes, the
//! source differing from the scalar case only by the type of the values:
//!
//! @godbolt{doc/core/tut_simd_wide_plf.cpp}
//!
//! @warning A register of polyfloat values is `eve::wide<plf::polyfloat<T,N>>`, the same type as
//! `plf::double_real_t<eve::wide<T>>` or `plf::triple_real_t<eve::wide<T>>`. The type
//! `plf::polyfloat<eve::wide<T>,N>` is not supported.
//!
//! # Generic code
//!
//! A [function template](https://en.cppreference.com/w/cpp/language/function_template) accepts
//! scalars and registers of every dimension with the same body. It is instantiated once for each
//! argument type, and `energy` below returns a value of the type of its argument, a scalar or a
//! register, of dimension 1, 2, or 3, with no code written per width or per dimension:
//!
//! @godbolt{doc/core/tut_simd_generic.cpp}
//!
//! <div class="section_buttons">
//!
//! | Previous                                   |                                          Next |
//! |:-------------------------------------------|----------------------------------------------:|
//! | [Polyfloat numbers](@ref tutorial-basics)  | [Precision](@ref implementation_precisions)   |
//!
//! </div>
