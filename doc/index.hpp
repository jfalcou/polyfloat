#error This file is for documentation only - DO NOT INCLUDE
//! \mainpage SIMD-Aware Extended Precision Floating-Point
//!
//! **POLYFLOAT** is a C++20 library of floating-point expansions. A value is the unevaluated sum
//! of two or three `float` or `double` of decreasing magnitude, which do not overlap. It carries
//! two or three times the mantissa bits of its base type, within the exponent range of that type,
//! as @ref implementation_precisions "Precision" details.
//! About two hundred functions of [EVE](https://jfalcou.github.io/eve/) apply to these values,
//! the arithmetic and the elementary functions, and every function accepts a scalar and a SIMD
//! register alike.
//!
//! @warning The library is a work in progress: the special functions are not implemented yet.
//!
//! # Features
//!
//! ## Precision
//!
//! A value of plf::double_real_t or plf::triple_real_t keeps the parts of a computation that its
//! base type rounds away. The functions take it under the names of their EVE counterparts, in
//! namespace `plf`.
//!
//! @godbolt{doc/core/tut_polyfloat_basics.cpp}
//!
//! ## Mixed limb counts
//!
//! An operation accepts a `float` or a `double` and polyfloat values of different limbs counts over
//! the same base type. The result has the largest limbs count of its operands, the missing parts
//! being zero.
//!
//! @godbolt{doc/core/tut_polyfloat_mixed.cpp}
//!
//! ## SIMD registers
//!
//! A function takes one value or an `eve::wide` of values under the same name.
//!
//! @godbolt{doc/core/tut_simd_wide_plf.cpp}
//!
//! ## Options
//!
//! An option is given between brackets, `plf::sqrt[plf::pedantic](x)`. The options of
//! [EVE](https://jfalcou.github.io/eve/), such as eve::pedantic and eve::raw, keep their names in
//! the namespace `plf` and the meaning the reference of EVE gives them. Most functions behave the
//! same with eve::raw or eve::pedantic and without them, and the reference entry of a function
//! describes an option only when it changes its result.
//!
//! ## Half-turns
//!
//! With the option `plf::radpi`, `plf::cos[plf::radpi](x)`, the functions on angles read and return
//! an angle as a multiple of \f$\pi\f$ instead of radians. A small integer is exact in a polyfloat value, while \f$\pi\f$ is
//! not.
//!
//! # Types
//!
//! **POLYFLOAT** defines two types over a base type `T`, `float` or `double`:
//!
//! | Type                      | limbs     | Alias of               |
//! |---------------------------|-----------|------------------------|
//! | `plf::double_real_t<T>`   | 2         | `plf::polyfloat<T,2>`  |
//! | `plf::triple_real_t<T>`   | 3         | `plf::polyfloat<T,3>`  |
//!
//! The SIMD forms take a register as argument:
//!
//! - `plf::double_real_t<eve::wide<T>>` is the type `eve::wide<plf::polyfloat<T,2>>`,
//! - `plf::triple_real_t<eve::wide<T>>` is the type `eve::wide<plf::polyfloat<T,3>>`.
//!
//! @warning A register of polyfloat values is `eve::wide<plf::polyfloat<T,N>>`. The type
//! `plf::polyfloat<eve::wide<T>,N>` is not supported.
//!
//! Three concepts classify the operands:
//!
//! - plf::concepts::polyfloat_like holds for `float`, `double`, their EVE registers, and the
//!   polyfloat values, which the functions accept, except a few restricted to some limbs counts,
//! - plf::concepts::polyfloat holds for the values of limbs counts 2 or more,
//! - plf::concepts::real holds for `float`, `double`, and their registers, of limbs count 1.
//!
//! # References
//!
//! The representation and the algorithms come from the floating-point expansions of
//! the @ref biblio "QD library" of Hida, Li, and Bailey, of Joldes, Marty, Muller, and Popescu,
//! and of Zhang and Aiken, and the error-free transformations from the Handbook of Floating-Point
//! Arithmetic and from Graillat and Muller.
//!
//! # License
//!
//! **POLYFLOAT** is distributed under the @ref licence "Boost Software License 1.0".
