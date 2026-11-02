#error This file is for documentation only - DO NOT INCLUDE
//! Polyfloat
//! =========
//!
//! **WORK IN PROGRESS : MANY THINGS STILL NOT AVAILABLE**
//!
//!
//! **POLYFLOAT** is an implementation of extended precision floating points numbers
//! using a sequence of (currently) 2 or 3 standard floating points
//! numbers of type (`float` or `double`)
//!
//! Up to now are available for polyfloat numbers:
//!
//!   * most core functions present in **EVE** (circa 200);
//!   * trigonometric, logarithmic and exponential math functions.
//!
//! The main references we use to perform these representations are:
//!
//!   * [D. Bailey](https://www.davidhbailey.com/dhbpapers/qd.pdf)
//!   * [D. K. Zhang](https://dl.acm.org/doi/10.1145/3712285.3759876)
//!   * Many articles from J.M. Muller team describing error-free IEEE operations. For instance
//!     [Emulation of the FMA... ](https://hal.science/hal-04575249)
//!
//! Polyfloat numbers
//! =================
//!
//! As explained in the above articles,
//! Polyfloats are floating-point expansions that represent high-precision numbers as sequences of
//! two, three, or four machine-precision numbers of same standard type with decreasing magnitude (so that
//! they do not overlap) extending the effective precision by a factor two or three
//!  times the native mantissa precision of the standard type, but not modifying the
//!  available exponent range.
//!
//! Up to now, the implementation is limited to 3 machine-precision numbers.
//!
//! Starting from the real numbers (supported by type `T`: `float` or `double`) we define:
//!
//!   - `double_real_t<T>`      (dimension 2) as a pair   of `T`, alias of `polyfloat<T,2>`
//!   - `triple_real_t<T>`      (dimension 3) as a triple of `T`, alias of `polyfloat<T,3>`
//!
//! **SIMD** analog can be used seemlessly
//!
//!   - `double_real_t<eve::wide<T>>`      (dimension 2), alias of  `eve::wide<polyfloat<T,2>>`
//!   - `triple_real_t<eve::wide<T>>`      (dimension 3), alias of  `eve::wide<polyfloat<T,3>>`
//!
//! @note Please observe the crucial reordering of `wide` in the above description : NEVER USE `polyfloat<eve:wide<T>,N>`
//!
//!
//! These datas with different dimensions but same  standard floating-point underlying type can be freely mixed
//! with the obvious semantic that if `N < M` an element of `polyfloat<T,N>` will be considered as having its components
//! from `N` to `M-1` null, as an element of `polyfloat<T,M>`
//!
//! All these types do not extend the exponent range of their underlying type, but their number of effective mantissa bits.
//!   * `double_real_t<float>` have 48 bits of mantissa
//!   * `triple_real_t<float>` have 62 bits of mantissa
//!   * `double_real_t<double>` have 106 bits of mantissa
//!   * `triple_real_t<double>` have 159 bits of mantissa
//!
//! This means that for  `T` `float`, these types can only be useful to obtain `double>` precision equivalent
//! on system where the hardware does not support them or to compute estimations of the error produced by the  `float`
//! call.
//!
//! Contrarily, for  `T` `double`, they can be used to obtain greater precision, especially if standard
//! `long double` has only 64 or 80 bits of storage.
//! And of course they can be used with SIMD which is not available with `long double`.
//!
//! Warnings
//! ========
//!
//!   *  The exponent range is that of the base type `T`. Overflow and underflow happen where `T` overflows and underflows.
//!   *  When some parts of a `polyfloat` are denormal the accuracy cannot be maintained. Below the smallest positive
//!      (non denormal) value only T precision remains.
//!   *  Nans and infinites values are supported. All parts but the highest part are zeros.
//!   *  Constructing a `polyfloat` with 2 (or 3) random `T` is ok, but the parts of the generated `polyfloat` will
//!      not generally contains these values as a renormalization will be done on construction.
//!   *  DO NOT construct a polyfloat by assigning values to its parts,  because the lack of normalization will produces
//!      silent errors
//!
//! What does this implementation provide
//! ======================================
//!
//! Being intended that a `polyfloat_like` is a `polyfloat` or a standard floating-point number,
//! all operators and functions (with a few exceptions restricted to some dimensionnalities constraints)
//! implemented can receive a mix of scalar or  simd of `polyfloat_like` of various dimensionnality
//! (but same underlying type) and are defined in the namespace `plf`.
//!
//!   - Proper `polyfloat` values are those for which dimensionality (number of standard parts) is greater or equal to 2 : they satisfy the
//!     `concepts::polyfloat` concept. They don't satisfy the  `concepts::real` concept;
//!   - scalar and simd standard and **EVE** floating types only satisfy  the `concepts::polyfloat_like` concept, meaning they are interoperable with
//!     proper `polyfloat` values. They also satisfy the `concepts::real` concept.
//!   - Almost all functions involving angles (within the parameters or the results) can receive an option (namely plf::radpi) such that
//!     every angle parameter or result will be expressed in \f$\pi\f$ multiples rather than in mere radians. (This use can be beneficial as some
//!     currently used angles values are small integer multiples of \f$\pi\f$. \f$\pi\f$ is not exactly represented by `polyfloat_like` values;
//!     contrarily to small integers)
//!
//! Of course the algebra operation +, -, * and / are provided.
//!
//! Constructors
//! ------------
//!
//! Proper `polyfloat` can be constructed using callables facilities `double_real_t` and `triple_real_t`.
//!
//! Operators
//! ---------
//!
//! Operators (as said before) `+`, `-`, `*` and `/` can be used in infix form and can mix `polyfloat` values of
//! different dimensionalities. Of course the biggest dimensionnality is recovered in the output. Assigning operators
//! `+=`, `-=`, `*=` and `/=` are also available.
//!
//! Prefix forms are also provided as `add`, `sub`, `mul`, and `div`. These version are multiparameters and can also use **KUMI** tuples
//! as inputs and support options.
//!
//! Also `plus` and `minus` can be used for unary versions.
//!
//! Functions
//! ---------
//!
//! **POLYFLOAT** callables are object functions following the **EVE** scheme. All of them accept at least the two (incompatible)
//! options `raw` and `pedantic`.
//!
//!   - the `raw` option ensures that the speediest computation implemented will be used, perhaps at the price of accuracy or corner
//!     cases values conformity to the standards
//!
//!   - The `pedantic` option ensures that the most accurate and standard conforming computation implemented will be used.
//!     In particular conforming to IEEE754 corner cases if any defined.
//!
//! Often, these two options do nothing more (or less) than the regular (no options) call and their effects are explained in the individual
//! documentations only if it is not the case.
//!
//! Most **POLYFLOAT** callables are usable with all [polyfloat_like](@ref plf::concepts::polyfloat_like) types.
//!
//!   * Callables usable with all `polyfloat` types
//!
//!     Most **EVE** arithmetic and math functions are (or will be eventually) provided for `polyfloat` datas.
//!     Up to now only analogs of **EVE** core and math functions are implemented.
//!
//!     The following tables  present the functions that are already available.
//!
//! Core functions
//! ==============
//!
//!   These are the arithmetic functions that do not involve transcendantal computations, predicates,
//!   and the `sqrt` and `rsqrt` functions.
//!
//!    |                                      |                                           |                                           |                                         |
//!    |--------------------------------------|-------------------------------------------|-------------------------------------------|-----------------------------------------|
//!    |[abs](@ref plf::abs)                  |[absmax](@ref plf::absmax)                 |[absmin](@ref plf::absmin)                 |[add](@ref plf::add)                     |
//!    |[agm](@ref plf::agm)                  |[average](@ref plf::average)               |[ceil](@ref plf::ceil)                     |[chi](@ref plf::chi)                     |
//!    |[clamp](@ref plf::clamp)              |[convert](@ref plf::convert)               |[copysign](@ref plf::copysign)             |[cosine_similarity](@ref plf::cosine_similarity)|
//!    |[covariance](@ref plf::covariance)    |[cumfun](@ref plf::cumfun)                 |[cumprod](@ref plf::cumprod)               |[cumsum](@ref plf::cumsum)               |
//!    |[dec](@ref plf::dec)                  |[diff](@ref plf::diff)                     |[dist](@ref plf::dist)                     |[div](@ref plf::div)                     |
//!    |[dot](@ref plf::dot)                  |[epsilon](@ref plf::epsilon)               |[exponent](@ref plf::exponent)             |[fam](@ref plf::fam)                     |
//!    |[floor](@ref plf::floor)              |[fma](@ref plf::fma)                       |[fmod](@ref plf::fmod)                     |[fms](@ref plf::fms)                     |
//!    |[fnma](@ref plf::fnma)                |[fnms](@ref plf::fnms)                     |[frac](@ref plf::frac)                     |[frexp](@ref plf::frexp)                 |
//!    |[fsm](@ref plf::fsm)                  |[heaviside](@ref plf::heaviside)           |[horner](@ref plf::horner)                 |[hypot](@ref plf::hypot)                 |
//!    |[if_else](@ref plf::if_else)          |[inc](@ref plf::inc)                       |[is_bit_equal](@ref plf::is_bit_equal)     |                                         |
//!    |[is_denormal](@ref plf::is_denormal)  |[is_eqmz](@ref plf::is_eqmz)               |[is_eqpz](@ref plf::is_eqpz)               |[is_equal](@ref plf::is_equal)           |
//!    |[is_eqz](@ref plf::is_eqz)            |[is_even](@ref plf::is_even)               |[is_finite](@ref plf::is_finite)           |[is_flint](@ref plf::is_flint)           |
//!    |[is_greater](@ref plf::is_greater)    |[is_greater_equal](@ref plf::is_greater_equal)|[is_gtz](@ref plf::is_gtz)              |[is_infinite](@ref plf::is_infinite)     |
//!    |[is_less](@ref plf::is_less)          |[is_less_equal](@ref plf::is_less_equal)   |[is_lessgreater](@ref plf::is_lessgreater) |[is_lez](@ref plf::is_lez)               |
//!    |[is_ltz](@ref plf::is_ltz)            |[is_minf](@ref plf::is_minf)               |[is_nan](@ref plf::is_nan)                 |[is_negative](@ref plf::is_negative)     |
//!    |[is_nemz](@ref plf::is_nemz)          |[is_nepz](@ref plf::is_nepz)               |[is_nez](@ref plf::is_nez)                 |[is_ngez](@ref plf::is_ngez)             |
//!    |[is_ngtz](@ref plf::is_ngtz)          |[is_nlez](@ref plf::is_nlez)               |[is_nltz](@ref plf::is_nltz)               |[is_not_denormal](@ref plf::is_not_denormal)|
//!    |[is_not_equal](@ref plf::is_not_equal)|[is_not_finite](@ref plf::is_not_finite)   |[is_not_flint](@ref plf::is_not_flint)     |[is_not_greater](@ref plf::is_not_greater)|
//!    |[is_not_greater_equal](@ref plf::is_not_greater_equal)|[is_not_infinite](@ref plf::is_not_infinite)|[is_not_less](@ref plf::is_not_less)|[is_not_less_equal](@ref plf::is_not_less_equal)|
//!    |[is_not_nan](@ref plf::is_not_nan)    |[is_odd](@ref plf::is_odd)                 |[is_ordered](@ref plf::is_ordered)         |[is_pinf](@ref plf::is_pinf)             |
//!    |[is_positive](@ref plf::is_positive)  |[is_pow2](@ref plf::is_pow2)               |[is_unit](@ref plf::is_unit)               |[is_unordered](@ref plf::is_unordered)   |
//!    |[ldexp](@ref plf::ldexp)              |[lerp](@ref plf::lerp)                     |[mantissa](@ref plf::mantissa)             |[max](@ref plf::max)                     |
//!    |[maxabs](@ref plf::maxabs)            |[maxmag](@ref plf::maxmag)                 |[min](@ref plf::min)                       |[minabs](@ref plf::minabs)               |
//!    |[minmag](@ref plf::minmag)            |[minmax](@ref plf::minmax)                 |[minus](@ref plf::minus)                   |[modf](@ref plf::modf)                   |
//!    |[mul](@ref plf::mul)                  |[nearest](@ref plf::nearest)               |[negabsmax](@ref plf::negabsmax)           |[negabsmin](@ref plf::negabsmin)         |
//!    |[negate](@ref plf::negate)            |[negatenz](@ref plf::negatenz)             |[next](@ref plf::next)                     |[nextafter](@ref plf::nextafter)         |
//!    |`parts`              |[pown](@ref plf::pown)                     |[prev](@ref plf::prev)                     |[prevint](@ref plf::prevint)             |
//!    |[rat](@ref plf::rat)                  |[rec](@ref plf::rec)                       |[reldist](@ref plf::reldist)               |[rem](@ref plf::rem)                     |
//!    |[remainder](@ref plf::remainder)      |[reverse_horner](@ref plf::reverse_horner) |                                           |[rsqrt](@ref plf::rsqrt)                 |
//!    |[sign](@ref plf::sign)                |[sign_alternate](@ref plf::sign_alternate) |[signnz](@ref plf::signnz)                 |                                         |
//!    |[sqr](@ref plf::sqr)                  |[sqrt](@ref plf::sqrt)                     |[sub](@ref plf::sub)                       |[sum_of_prod](@ref plf::sum_of_prod)     |
//!    |[sum_of_squares](@ref plf::sum_of_squares)|[trunc](@ref plf::trunc)               |[variance](@ref plf::variance)             |                                         |
//!
//!
//!   @note All predicates comparing to `zero` and all one parameter predicates (except `is_even`, `is_odd` and `isflint`) are a lot faster than two parameters ones
//!   for which testing the 'hi' part is not sufficient.
//!
//! Core constants
//! ==============
//!
//! These are proper `polyfloat` constant values related to precision internal IEEE representation  or or simple arithmetic constants wrapped from **EVE** .
//!
//!    |   Proper values                         |                                           |                                           |                                         |
//!    |-----------------------------------------|-------------------------------------------|-------------------------------------------|-----------------------------------------|
//!    |[effective_mantissa_bits](@ref plf::effective_mantissa_bits) |[eps](@ref plf::eps)   |[inveps](@ref plf::inveps) |[logeps](@ref plf::logeps) |
//!    |[maxflint](@ref plf::maxflint)           |[oneosqrteps](@ref plf::oneosqrteps)       |[sqrt_2](@ref plf::sqrt_2)                 |[sqrteps](@ref plf::sqrteps) |
//!    |[sqrtvalmax](@ref plf::sqrtvalmax)       |[valmax](@ref plf::valmax) |[valmin](@ref plf::valmin) | |
//!
//!
//!    |   wrapped from **EVE**                  |                                           |                                           |                                         |
//!    |-----------------------------------------|-------------------------------------------|-------------------------------------------|-----------------------------------------|
//!    |[half](@ref plf::half)                   |[inf](@ref plf::inf)                       |[mhalf](@ref plf::mhalf)                   |[mindenormal](@ref plf::mindenormal)     |
//!    |[minexponent](@ref plf::minexponent)     |[minf](@ref plf::minf)                     |[mone](@ref plf::mone)                     |[mzero](@ref plf::mzero)                |
//!    |[nan](@ref plf::nan)                     |[one](@ref plf::one)                       |                                           ||
//!
//!
//! Error free and  augmented accuracy functions
//! ============================================
//!
//! These functions are not of common use but are the inner bases with `fma` of the implementation of `polyfloat` numbers.
//! They generally follow the description given in many articles of the ARENAIRE INRIA team. They return pair of triple of
//! values the first being the operation result main approximation, the others correction that could be virtually added
//! in an infinite precision environnement to get an exact (or for the `approx` ones) at least a still more accurate result.
//!
//!    |                                         |                                           |                                           |                                         |
//!    |-----------------------------------------|-------------------------------------------|-------------------------------------------|-----------------------------------------|
//!    |[dekker_prod](@ref plf::three_add) |[three_add](@ref plf::three_add)     |[three_fma](@ref plf::three_fma)     |[two_add](@ref plf::two_add)       |
//!    |[two_div_approx](@ref plf::two_div_approx)|[two_fma_approx](@ref plf::two_fma_approx)|[two_prod](@ref plf::two_prod)  |[two_split](@ref plf::two_split)   |
//!
//! Math elementary functions
//! =========================
//!
//!   These are the math functions implemented up to now.
//!
//!    |                          |                                        |                                      |                              |
//!    |--------------------------|----------------------------------------|--------------------------------------|------------------------------|
//!    |[acos](@ref acos)         |    [acosh](@ref acosh)                 |    [acoth](@ref acoth)               |    [agd](@ref agd)           |
//!    |[acsc](@ref acsc])        |    [acsch](@ref acsch)                 |    [arg](@ref arg)                   |    [asec](@ref asec)         |
//!    |[asech](@ref asech)       |    [asin](@ref a)                      |    [asinh](@ref asinh)               |    [atan](@ref atan)         |
//!    |[atan2](@ref atan2)       |    [atanh](@ref atanh)                 |    [cbrt](@ref cbrt)                 |    [cos](@ref cos)           |
//!    |[cosh](@ref cosh)         |    [cot](@ref cot)                     |    [coth](@ref coth)                 |    [csc](@ref csc)           |
//!    |[csch](@ref csch)         |    [div_180](@ref div_180)             |    [exp](@ref csch)                  |    [exp10](@ref exp10)       |
//!    |[exp2](@ref exp2)         |    [expm1](@ref expm1)                 |    [gd](@ref gd)                     |    [geommean](@ref geommean) |
//!    |[harmmean](@ref harmmean) |    [kolmmean](@ref kolmmean)           |    [log](@ref log)                   |    [log10](@ref log10)       |
//!    |[log2](@ref log2)         |    [logspace_add](@ref logspace_add)   |    [logspace_sub](@ref logspace_sub) |    [lpnorm](@ref lpnorm)     |
//!    |[mul_pi](@ref mul_pi)     |    [nthroot](@ref nthroot)             |    [pow](@ref pow)                   |    [pow1p](@ref pow1p)       |
//!    |[powm1](@ref powm1)       |    [pow_abs](@ref pow_abs)             |    [radindeg](@ref radindeg)         |    [sigmoid](@ref sigmoid)   |
//!    |[radinpi](@ref radinpi)   |    [sec](@ref sec)                     |    [sech](@ref sech)                 |    [sin](@ref sin)           |
//!    |[sinc](@ref sinc)         |    [sincos](@ref sincos)               |    [sinh](@ref sinh)                 |    [sinhcosh](@ref sinhcosh) |
//!    |[tan](@ref tan)           |    [tanh](@ref tanh)                   |                                      |                              |


//! Math constants
//! ==============
//!
//! These are proper `polyfloat` mathematical constant .
//!
//!   |                                |                            |                          |                                         |
//!   |--------------------------------|----------------------------|--------------------------|-----------------------------------------|
//!   |[catalan](@ref catalan)         |[cbrt_pi](@ref cbrt_pi)     |[cos_1](@ref cos_1)       |[cosh_1](@ref cosh_1)                    |
//!   |[egamma](@ref )                 |[exp_pi](@ref exp_pi)       |[euler](@ref euler)       |[four_minus_pi](@ref four_minus_pi)      |
//!   |[four_pio_3](@ref four_pio_3)   |[invlog_10](@ref invlog_10) |[invlog_2](@ref invlog_2) |[invcbrt_pi](@ref invcbrt_pi)            |
//!   |[inv_e](@ref inv_e)             |[inv_pi](@ref inv_pi)       |[inv_2pi](@ref inv_2pi)   |[log_2](@ref log_2)                      |
//!   |[maxlog](@ref maxlog)           |[oneo_180](@ref oneo_180)   |[pi](@ref pi)             |[pio_2](@ref pio_2)                      |
//!   |[pio_3](@ref pio_3)             |[pio_4](@ref pio_4)         |[pio_6](@ref pio_6)       |[rad2deg](@ref rad2deg)                  |
//!   |[three_pio_4](@ref three_pio_4) |                            |                          |                                         |                                                                                          |

//!
//!
//! Math special functions
//! =========================
//!
//! STILL NOT DONE
//!
//! Testing rationale
//! -----------------
//!
//! The behaviour of `polyfloat` is not the same as standard floating points numbers, for instance
//! for any `polyfloat` the difference between any finite T and the next representable element is
//! the minimum denormal value of the type T, meaning that the intervals are quite more populated.
//!
//! However, the following table shows the number of bits of mantissa available for each scalar
//!  `polyfloat` element as well as an expected machine precision (eps) related to this mantissa bit size
//!
//!    |  base  type |   dimension |   bits number  |   eps            |
//!    |-------------|-------------|----------------|------------------|
//!    | float       |   2         |   48           |   3.5527e-15     |
//!    | float       |   3         |   72           |   2.1176e-22     |
//!    | double      |   2         |   106          |   1.2326e-32     |
//!    | double      |   3         |   159          |   1.3685e-48     |
//!
//! So if an `mpfr` implementation of a fonction is at hand, we generally choose to evaluate
//! the relative absolute error between our computation converted to `mpfr` value
//! of the same mantissa precision and the `mpfr` computation with the converted inputs
//! and be satisfied if it is less than a small mutiple of the corresponding `eps`.
//!
//! The relative error formula between \f$a\f$ and \f$b\f$
//! is chosen to be \f$|a-b|/(\max(|a|,|b|,1)\f$.
