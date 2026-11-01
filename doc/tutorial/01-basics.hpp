#error This file is for documentation only - DO NOT INCLUDE
//! @page tutorial-polyfloat Polyfloat numbers
//!
//! # Naming a type
//!
//! A polyfloat number over `double` is written `kyosu::double_real_t<double>` or triplereal_t<double>. The `_t` is not
//! decoration: it is an alias for a polyfoat value.
//!
//! @godbolt{doc/core/tut_polyfloat_basics.cpp}
//!
//!  - Note the printing convention. A value comes out as a sum of parts that are decreasing in absolute values and that
//!    do not overlap. The {non-overlap' thing is mandatory even if we enter a sequence of three perhaps non decreasing and
//!    overlapping values, the first thing done by the constructor is to normalize them and the internal represention will
//!   always satisfies that every two successive parts x and y (which are standard floating values) will verify `x+y == x`.
//!
//!  - z2 and z3 are equal as mathematical real values but applying sqrt does not compute them with the same precision.
//!
//!  - `plf::sqrt(2.0)` returns a double. Its argument is a plain `double`, and the answer
//!     is a `double`, but `plf::sqrt(double_real_t<double(2.0)` returns a double_real_t<double>
//!     which exhibits greater precision.
//!
//!  - after_curious init retablish the normalized situation. Always use the proper constructor if you provides sequences that does not
//!    satisfy the decrease and non-overlap conditions.
//!
//! Almost all functions you would expect are there, under the name you would expect, in namespace `plf`, extending *EVE*.
//! Two hundred of them, from the arithmetic to the elementary math functions.
//! Caveat : up to now, the special functions are still not implemented.
//!
//! # What of invalid values
//!
//! polyfoat support inf, -inf and (quiet) nan values, the only non zero component of such a value is the high part.
//!
//! @godbolt{doc/tut_polyfloat_invalids.cpp}
//!
//! As it appears everything works fine even inverse computation and mixing integers with polyfloats.
//! However this is not recommended `plf::rec(z)` is faster than `1/z`.
//!
//! # What of denormal values
//!
//! Denormals are treated as well as possible. In fact a denormal has its high part denormal and the
//! others are necessarily 0 because of the decreasing values and the non-overlap properties..
//!
//! @godbolt{doc/tut_polyfloat_denormals.cpp}
//!
//! <div class="section_buttons">
//!
//! | Previous                  |                                    Next |
//! |:--------------------------|----------------------------------------:|
//! | [Quick Start](@ref setup) | [Many values at once](@ref tutorial-simd) |
//!
//! @godbolt{doc/tut_polyfloat_denormals.cpp}
//!
//! </div>
