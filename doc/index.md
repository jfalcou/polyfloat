Polyfloat
=========

**WORK IN PROGRESS : MANY THINGS STILL NOT AVAILABLE**

**POLYFLOAT** is an implementation of extended precision floating points numbers
using a sequence of (currently) 2 or 3 standard floating points
numbers of type (`float` or `double`)

Most standard library fonctions  in **scalar** and **SIMD** form mimicking **EVE** calls
are implemented or will be.

The main references we use to perform these representations are:

  * [D. Bailey](https://www.davidhbailey.com/dhbpapers/qd.pdf)
  * [D. K. Zhang](https://dl.acm.org/doi/10.1145/3712285.3759876)
  * Many articles from J.M. Muller team describing error-free IEEE operations. For instance
    [Emulation of the FMA... ](https://hal.science/hal-04575249)

Polyfloat numbers
=================

As explained in the above articles,
Polyfloats are floating-point expansions that represent high-precision numbers as sequences of
two, three, or four machine-precision numbers of same standard type with decreasing magnitude (so that
they minimaly overlap) extending the effective precision to two,
three, or four times the native mantissa precision of the standard type, but not modifying the
 available exponent range.

Up to now, the implementation is limited to 3 machine-precision numbers.

Starting from the real numbers (supported by type `T`: `float` or `double`) we define:

  - `double_real_t<T>`      (dimension 2) as a pair   of `T`, alias of `polyfloat<T,2>`
  - `triple_real_t<T>`      (dimension 3) as a triple of `T`, alias of `polyfloat<T,3>`

**SIMD** analog can be used seemlessly

  - `double_real_t<eve::wide<T>>`      (dimension 2), alias of  `eve::wide<polyfloat<T,2>>`
  - `triple_real_t<eve::wide<T>>`      (dimension 3), alias of  `eve::wide<polyfloat<T,3>>`

@note Please observe the crucial reordering of `wide` in the above description : NEVER USE `polyfloat<eve:wide<T>,N>`


These datas with different dimensions but same  standard floating-point underlying type can be freely mixed
with the obvious semantic that if `N < M` an element of `polyfloat<T,N>` will be considered as having its components
from `N` to `M-1` null, as an element of `polyfloat<T,M>`

All these types do not extend the exponent range of their underlying type, but their number of effective mantissa bits.
  * `double_real_t<float>` have 48 bits of mantissa
  * `triple_real_t<float>` have 62 bits of mantissa
  * `double_real_t<double>` have 106 bits of mantissa
  * `triple_real_t<double>` have 159 bits of mantissa

This means that for  `T` `float`, these types can only be useful to obtain `double>` precision equivalent
on system where the hardware does not support them.

Contrarily, for  `T` `double`, they can be used to obtain greater precision, especially if standard
`long double` has only 64 or 80 bits of storage.
And of course they can be used with SIMD which is not available with `long double`.

Warnings
========

  *  The exponent range is that of the base type `T`. Overflow and underflow happen where `T` overflows and underflows.
  *  When some parts of a `polyfloat` are denormal the accuracy cannot be maintained. Below the smallest positive
     (non denormal) value only T precision remains.
  *  Nans and infinites values are supported. All parts but the highest part are zeros.
  *  Constructing a `polyfloat` with 2 (or 3) random `T` is ok, but the parts of the generated `polyfloat` will
     not generally contains these values as a renormalization will be done on construction.

What does this implementation provide
======================================

Being intended that a `polyfloat_like` is a `polyfloat` or a standard floating-point number,
all operators and functions (with a few exceptions restricted to some dimensionnalities constraints)
implemented can receive a mix of scalar or  simd of `polyfloat_like` of various dimensionnality
(but same underlying type) and are defined in the namespace `plf`.

  - Proper `polyfloat` values are those for which dimensionality (number of standard parts) is greater or equal to 2 : they satisfy the
    `concepts::polyfloat` concept. They don't satisfy the  `concepts::real` concept;
  - scalar and simd standard and **EVE** floating types only satisfy  the `concepts::polyfloat_like` concept, meaning they are interoperable with
    proper `polyfloat` values. They also satisfy the `concepts::real` concept.
  - Almost all functions involving angles (within the parameters or the results) can receive an option (namely plf::radpi) such that
    every angle parameter or result will be expressed in \f$\pi\f$ multiples rather than in mere radians. (This use can be beneficial as some
    currently used angles values are small integer multiples of \f$\pi\f$. \f$\pi\f$ is not exactly represented by `polyfloat_like` values;
    contrarily to small integers)

Of course the algebra operation +, -, * and / are provided.

Constructors
------------

Proper `polyfloat` can be constructed using callables facilities `double_real_t` and `triple_real_t`.

Operators
---------

Operators (as said before) `+`, `-`, `*` and `/` can be used in infix form and can mix `polyfloat` values of
different dimensionalities. Of course the biggest dimensionlity is recovered in the output. Assigning operators
`+=`, `-=`, `*=` and `/=` are also available.

Prefix forms are also provided as `add`, `sub`, `mul`, and `div`. These version are multiparameters and can also use **KUMI** tuples.
Also `plus` and `minus` can be used for unary versions.

Functions
---------

**POLYFLOAT** callables are object functions following the **EVE** scheme. All of them accept at least the two (incompatible)
options `raw` and `pedantic`.

  - the `raw` option ensures that the speediest computation implemented will be used, perhaps at the price of accuracy or corner
    cases values conformity to the standards

  - The `pedantic` option ensures that the most accurate and standard conforming computation implemented will be used.
    In particular conforming to IEEE754 corner cases if any defined.

Often, these two options do nothing more than the regular (no options) call and their effects are explained in the individual
documentations only if it is not the case.

Most **POLYFLOAT** callables are usable with all [polyfloat_like](@ref kyosu::concepts::polyfloat_like) types.

  * Callables usable with all `polyfloat` types

    Most **EVE** arithmetic and math functions are (or will be eventually) provided for `polyfloat` datas.
    Up to now only analogs of **EVE** core functions are implemented.

    The following tables  stat which fonction are already available. Not available ones are
    followed by a `SNA`, meanning Still Non Available.

Core functions
==============

  These are the arithmetic functions that do not involve transcendantal computations, predicates,
  and the `sqrt` and `rsqrt` functions.

   |                                      |                                           |                                           |                                         |
   |--------------------------------------|-------------------------------------------|-------------------------------------------|-----------------------------------------|
   |[abs](@ref plf::abs)            |[absmax](@ref plf::absmax)           |[absmin](@ref plf::absmin)           |[add](@ref plf::add)               |
   |[agm](@ref plf::agm)|[average](@ref plf::average)|[ceil](@ref plf::ceil)|[chi](@ref plf::chi)|
   |[clamp](@ref plf::clamp)|[convert](@ref plf::convert)|[copysign](@ref plf::copysign)|[dec](@ref plf::dec)|
   ||[dist](@ref plf::dist)|[div](@ref plf::div)|[dot](@ref plf::dot)|
   |[epsilon](@ref plf::epsilon)|[exponent](@ref plf::exponent)|[floor](@ref plf::floor)|[fma](@ref plf::fma)|
   |[fnma](@ref plf::fnma)|[fmod](@ref plf::fmod)|[frac](@ref plf::frac)|[frexp](@ref plf::frexp)|
   |[heaviside](@ref plf::heaviside)|[horner](@ref plf::horner)|[if_else](@ref plf::if_else)|[inc](@ref plf::inc)|
   |[is_denormal](@ref plf::is_denormal)|[is_equal](@ref plf::is_equal)|[is_eqz](@ref plf::is_eqz)|[is_eqmz](@ref plf::is_eqmz)|
   |[is_eqpz](@ref plf::is_eqpz)|[is_even](@ref plf::is_even)|[is_finite](@ref plf::is_finite)|[is_flint](@ref plf::is_flint)|
   |[is_greater](@ref plf::is_greater)|[is_greater_equal](@ref plf::is_greater_equal)|[is_gtz](@ref plf::is_gtz)|[is_infinite](@ref plf::is_infinite)|
   |[is_less](@ref plf::is_less)|[is_less_equal](@ref plf::is_less_equal)|[is_lessgreater](@ref plf::is_lessgreater)|[is_lez](@ref plf::is_lez)|
   |[is_ltz](@ref plf::is_ltz)|[is_minf](@ref plf::is_minf)|[is_nan](@ref plf::is_nan)|[is_negative](@ref plf::is_negative)|
   |[is_nemz](@ref plf::is_nemz)|[is_nepz](@ref plf::is_nepz)|[is_nez](@ref plf::is_nez)|[is_ngez](@ref plf::is_ngez)|
   |[is_ngtz](@ref plf::is_ngtz)|[is_nlez](@ref plf::is_nlez)|[is_nltz](@ref plf::is_nltz)|[is_not_denormal](@ref plf::is_not_denormal)|
   |[is_not_equal](@ref plf::is_not_equal)|[is_not_finite](@ref plf::is_not_finite)|[is_not_flint](@ref plf::is_not_flint)|[is_not_greater](@ref plf::is_not_greater)|
   |[is_not_greater_equal](@ref plf::is_not_greater_equal)|[is_not_infinite](@ref plf::is_not_infinite)|[is_not_less](@ref plf::is_not_less)|[is_not_less_equal](@ref plf::is_not_less_equal)|
   |[is_not_nan](@ref plf::is_not_nan)|[is_odd](@ref plf::is_odd)|[is_ordered](@ref plf::is_ordered)|[is_pinf](@ref plf::is_pinf)|
   |[is_positive](@ref plf::is_positive)|[is_pow2](@ref plf::is_pow2)|[is_unit](@ref plf::is_unit)|[is_unordered](@ref plf::is_unordered)|
   |[ldexp](@ref plf::ldexp)|[lerp](@ref plf::lerp)|[mantissa](@ref plf::mantissa)|[max](@ref plf::max)|
   |[min](@ref plf::min)|[minus](@ref plf::minus)|[modf](@ref plf::modf)|[mul](@ref plf::mul)|
   |[nearest](@ref plf::nearest)|[negate](@ref plf::negate)|[negatenz](@ref plf::negatenz)|[next](@ref plf::next)|
   |[parts](@ref plf::parts)|[prev](@ref plf::prev)|[rec](@ref plf::rec)|[reldist](@ref plf::reldist)|
   |[reverse_horner](@ref plf::reverse_horner)|[rsqrt](@ref plf::rsqrt)|[sign](@ref plf::sign)|[signnz](@ref plf::signnz)|
   |[sqr](@ref plf::sqr)|[sqrt](@ref plf::sqrt)|[sub](@ref plf::sub)|[trunc](@ref plf::trunc)|

  @note All predicates comparing to `zero` and almost all one parameter predicates are a lot faster than two parameters ones
  for which testing the 'hi' part is not sufficient.

Core constants
==============


These are proper `polyfloat` constant values related to precision internal IEEE representation  or or simple arithmetic constants wrapped from **EVE** .

   |   Proper values                         |                                           |                                           |                                         |
   |-----------------------------------------|-------------------------------------------|-------------------------------------------|-----------------------------------------|
   |[effective_mantissa_bits](@ref plf::effective_mantissa_bits) |[eps](@ref plf::eps)   |[inveps](@ref plf::inveps) |[logeps](@ref plf::logeps) |
   |[maxflint](@ref plf::maxflint)           |[oneosqrteps](@ref plf::oneosqrteps)       |[sqrt_2](@ref plf::sqrt_2)                 |[sqrteps](@ref plf::sqrteps) |
   |[[sqrtvalmax](@ref plf::sqrtvalmax) |[valmax](@ref plf::valmax) |[valmin](@ref plf::valmin) | |


   |   wrapped from **EVE**                  |                                           |                                           |                                         |
   |-----------------------------------------|-------------------------------------------|-------------------------------------------|-----------------------------------------|
   |[half](@ref plf::half)                   |[inf](@ref plf::inf)                       |[mhalf](@ref plf::mhalf)                   |[mindenormal](@ref plf::mindenormal)     |
   |[minexponent](@ref plf::minexponent)     |[minf](@ref plf::minf)                     |[mone](@ref plf::mone)                     |[mzero](@ref plf::mzero)                |
   |[nan](@ref plf::nan)                     |[one](@ref plf::one)                       |                                           ||


Error free and accuracy augmented functions
==========================================

These functions are not of common use but are the inner bases with `fma` of the implementation of `polyfloat` numbers.
They generally follow the descrption given in many articles of the ARENAIRE INRIA team. They return pair of triple of
values the first being the operation result main approximation, the others correction that could be virtually added
in an infinite precision environnement to get an exact (or for the `approx` ones) at least a still more accurate result.

   |                                         |                                           |                                           |                                         |
   |-----------------------------------------|-------------------------------------------|-------------------------------------------|-----------------------------------------|
   |[dekker_prod](@ref plf::three_add) |[three_add](@ref plf::three_add)     |[three_fma](@ref plf::three_fma)     |[two_add](@ref plf::two_add)       |
   |[two_div_approx](@ref plf::two_div_approx)|[two_fma_approx](@ref plf::two_fma_approx)|[two_prod](@ref plf::two_prod)  |[two_split](@ref plf::two_split)   |

Math elementary functions
=========================

STILL NOT DONE

Math special functions
=========================

STILL NOT DONE

Testing rationale
-----------------

The behaviour of `polyfloat` is not the same as standard floating points numbers, for instance
for any `polyfloat` the difference between any finite T and the next representable element is
the minimum denormal value of the type T, meaning that the intervals are quite more populated.

However, the following table shows the number of bits of mantissa available for each scalar
 `polyfloat` element as well as an expected machine precision (eps) related to this mantissa bit size

   |  base  type |   dimension |   bits number  |   eps            |
   |-------------|-------------|----------------|------------------|
   | float       |   2         |   48           |   3.5527e-15     |
   | float       |   3         |   72           |   2.1176e-22     |
   | double      |   2         |   106          |   1.2326e-32     |
   | double      |   3         |   159          |   1.3685e-48     |

So if an `mpfr` implementation of a fonction is at hand, we generally choose to evaluate
the relative absolute error between our computation converted to `mpfr` value
of the same mantissa precision and the `mpfr` computation with the converted inputs
and be satisfied if it is less than a small mutiple of the corresponding `eps`.

The relative error formula between \f$a\f$ and \f$b\f$
is chosen to be \f$|a-b|/(\max(|a|,|b|,1)\f$.
