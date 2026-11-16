#error This file is for documentation only - DO NOT INCLUDE
//! @page tutorial-basics Polyfloat numbers
//!
//! A floating-point expansion represents a real number as the unevaluated sum of floating-point
//! numbers of decreasing magnitude, which do not overlap. **POLYFLOAT** represents an expansion of
//! two parts by `plf::double_real_t<T>`, and one of three parts by `plf::triple_real_t<T>`, with
//! `T` either `float` or `double`. About two hundred functions apply to them, in namespace `plf`,
//! under the names of their EVE counterparts: the @ref core "core functions", from the arithmetic
//! to the predicates, and the @ref math "elementary functions". The @ref constants "constants",
//! plf::pi, plf::euler for \f$e\f$, or plf::sqrt_2, are given at the precision of each type. The
//! special functions are not implemented yet.
//!
//! # Construction and printing
//!
//! A value is built by the constructor of plf::polyfloat from as many values as its dimension at
//! most, each converted to its base type. The default constructor gives zero. A single value of a
//! wider type, a `double` into a polyfloat of `float`, is split over the parts, and rounded when
//! they hold fewer bits than its mantissa.
//!
//! The function plf::from_string reads a decimal or hexadecimal number exactly,
//! `plf::from_string("0.1", eve::as<plf::double_real_t<double>>())`, and returns a NaN when the
//! string is malformed, a space or any character outside the number included. Under plf::pedantic,
//! it returns instead a [`std::optional`](https://en.cppreference.com/w/cpp/utility/optional) that
//! holds no value for a malformed string, which tells it apart from `nan`. The digit separator `'`
//! of C++ may stand between two digits, as in `3'125.256'966`, and a third argument names another
//! separator, or none with 0. The high part is the number rounded to nearest, ties to even, and
//! each next part rounds in the same way what the previous parts leave, computed exactly. A
//! `double` literal such as `0.1` is instead rounded to `double` before any part is built.
//!
//! A value prints as one number, the exact sum of its parts rounded to nearest, under the
//! precision, the format flags, the locale, and the width of the stream, as a `double` prints:
//!
//! - `std::setprecision(n)` shows n significant digits.
//! - `std::hexfloat` shows the value exactly.
//! - plf::showparts shows the parts instead, joined by `+` or `-`, `1.41421 - 9.66729e-17` for
//!   instance, the largest first, each with the precision and the format of the stream, until
//!   plf::noshowparts.
//!
//! In EVE and **POLYFLOAT**, a constant is called with `eve::as<T>()`, where `T` is the type of the
//! value it returns, so `eve::eps(eve::as<double>())` is the machine epsilon of `double`. A
//! function such as plf::sqrt returns a value of the type of its argument, with the precision of
//! that type:
//!
//! @godbolt{doc/core/tut_polyfloat_basics.cpp}
//!
//! @warning A value whose parts lie far apart, \f$1 + 2^{-1000}\f$ in
//! `plf::double_real_t<double>`, prints as 1 at 32 digits. `std::hexfloat` shows it exactly, and
//! plf::showparts shows its two parts.
//!
//! # Normalization
//!
//! The constructors from values normalize their arguments: two successive parts \f$x\f$ and \f$y\f$
//! of the result satisfy \f$x + y = x\f$ in the base type, two NaN comparing equal. The condition
//! is stronger than the absence of overlap, which \f$(1, 0.5)\f$ satisfies and the condition
//! rejects. The parts of a value differ from the arguments of its constructor when these overlap,
//! and plf::is_normalized tests the property:
//!
//! @godbolt{doc/core/tut_polyfloat_normalization.cpp}
//!
//! @warning A part written directly, through plf::hi, plf::md, or plf::lo, can leave the value
//! unnormalized, and the functions then can return wrong results without any error. The
//! constructor from a product type takes its parts as they are, and the constructors from values
//! normalize arbitrary parts.
//!
//! # Mixed dimensions
//!
//! An operation accepts operands of different dimensions over the same base type, a `double` being
//! of dimension 1, each operand satisfying plf::concepts::polyfloat_like. The result has the
//! largest dimension, with zero in the missing parts of the other operands, and plf::dimension_v
//! gives the dimension of a type:
//!
//! @godbolt{doc/core/tut_polyfloat_mixed.cpp}
//!
//! # Infinities and NaN
//!
//! A polyfloat value represents \f$+\infty\f$, \f$-\infty\f$, and the quiet NaN, whose high part
//! is the special value and whose other parts are zero. The exponent range is the one of the base
//! type, and the arithmetic on the infinities follows IEEE 754. An integer operand is converted to
//! the base type, and can be rounded once its magnitude exceeds \f$2^{53}\f$ for `double`. plf::rec
//! computes the inverse faster than `1 / y`:
//!
//! @godbolt{doc/core/tut_polyfloat_invalids.cpp}
//!
//! # Denormal values
//!
//! A denormal high part leaves no room below it for the other parts, which are zero. The second
//! part becomes denormal once the magnitude of the high part falls under \f$2^{e_{min} + p}\f$,
//! \f$2^{-969}\f$ for `double` and \f$2^{-102}\f$ for `float`, and the third part \f$2^p\f$ above,
//! \f$p\f$ being the precision of the base type and \f$e_{min}\f$ its smallest exponent. The
//! extra precision decreases from there, and below the smallest positive normal value the high
//! part has fewer bits than the base type. plf::mindenormal of a polyfloat type is the smallest denormal of its base type, in the
//! high part:
//!
//! @godbolt{doc/core/tut_polyfloat_denormal.cpp}
//!
//! <div class="section_buttons">
//!
//! | Previous                   |                               Next |
//! |:---------------------------|-----------------------------------:|
//! | [Installation](@ref setup) | [SIMD support](@ref tutorial-simd) |
//!
//! </div>
