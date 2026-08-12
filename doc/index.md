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
two, three, or four machine-precision numbers, extending the effective precision to double,
triple, or quadruple the native machine precision.

Up to now, we limit the implementation to 3 machine-precision numbers.

Starting from the real numbers (supported by type `T`: `float` or `double`) we define:

  - `double_real_t<T>`      (dimension 2) as a pair   of `T`, alias of `polyfloat<T,2>`
  - `triple_real_t<T>`      (dimension 3) as a triple of `T`, alias of `polyfloat<T,3>`

**SIMD** analog can be used simlessly

  - `double_real_t<eve::wide<T>>`      (dimension 2), alias of  `eve::wide<polyfloat<T,2>>`
  - `triple_real_t<eve::wide<T>>`      (dimension 3), alias of  `eve::wide<polyfloat<T,3>>`

@note Please observe the crucial reordering of `wide` in the above description : NEVER USE `polyfloat<eve:wide<T>,N>`


These datas with different dimensions but same  standard floating-point underlying type can be freely mixed
with the obvious semantic that if `N < M` an element of `polyfloat<N,T>` will be considered as having its components
from `N` to `M-1` null, as an element of `polyfloat<M,T>`

All these types do not extend the exponent range of their undelying type, but their number of mantissa bits.
  * `double_real_t<float>` have 46 bits of mantissa
  * `triple_real_t<float>` have 59 bits of mantissa
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

Being intended that a `polyfloat`_like is a `polyfloat` or a standard floating-point number,
all operators and functions (with a few exceptions restricted to some dimensionnalities constraints)
implemented can receive a mix of scalar or  simd of `polyfloat`_like of various dimensionnality
(but same underlying type) and are defined in the namespace `plf`.

  - Proper `polyfloat` values are those for which dimensionality is greater or equal to 2 : they satisfy the
    `concepts::polyfloat` concept. They don't satisfy the  `concepts::real` concept;
  - scalar and simd floating types only satisfy  the `concepts::polyfloat_like` concept, meaning they are interoperable with
    proper `polyfloat` values. They also satisfy the `concepts::real` concept.
  - Almost all functions involving angles (within the parameters or the results) can receive an option (namely plf::radpi) such that
    every angle parameter or result will be expressed in \f$\pi\f$ multiples rather than in mere radians. (This use can be beneficial as some
    currently used angles values are small integer multiples of \f$\pi\f$. \f$\pi\f$ is not exactly represented by `polyfloat`_like values;
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

    The following table is mainly a todo list : `sna` meanning stil non available.

   |                                                           |                                                           |                                                           |                                                           |
   |-----------------------------------------------------------|-----------------------------------------------------------|-----------------------------------------------------------|-----------------------------------------------------------|
   |[abs    ](@ref `polyfloat`::abs)                             |[acos `sna`](@ref `polyfloat`::acos)                           |[acosh `sna`](@ref `polyfloat`::acosh)                         |[acot `sna`](@ref `polyfloat`::acot)                           |
   |[acoth `sna`](@ref `polyfloat`::acoth)                         |[acsc `sna`](@ref `polyfloat`::acsc)                           |[acsch `sna`](@ref `polyfloat`::acsch)                         |[add    ](@ref `polyfloat`::add)                             |
   |[agd    ](@ref `polyfloat`::agd)                             |[airy `sna`](@ref `polyfloat`::airy)                           |[airy_ai `sna`](@ref `polyfloat`::airy_ai)                     |[airy_bi `sna`](@ref `polyfloat`::airy_bi)                     |
   |[am `sna`](@ref `polyfloat`::am)                               |[arg `sna`](@ref `polyfloat`::arg)                             |[asec `sna`](@ref `polyfloat`::asec)                           |[asech `sna`](@ref `polyfloat`::asech)                         |
   |[asin `sna`](@ref `polyfloat`::asin)                           |[asinh `sna`](@ref `polyfloat`::asinh)                         |[associator `sna`](@ref `polyfloat`::associator)               |[atan `sna`](@ref `polyfloat`::atan)                           |
   |[atanh `sna`](@ref `polyfloat`::atanh)                         |[average    ](@ref `polyfloat`::average)                     |[bessel_h `sna`](@ref `polyfloat`::bessel_h)                   |[bessel_i `sna`](@ref `polyfloat`::bessel_i)                   |
   |[bessel_j `sna`](@ref `polyfloat`::bessel_j)                   |[bessel_k `sna`](@ref `polyfloat`::bessel_k)                   |[bessel_y `sna`](@ref `polyfloat`::bessel_y)                   |[beta `sna`](@ref `polyfloat`::beta)                           |
   |[ceil    ](@ref `polyfloat`::ceil)                           |[cbrt `sna`](@ref `polyfloat`::cbrt)                           |[chi    ](@ref `polyfloat`::chi)                             |[commutator `sna`](@ref `polyfloat`::commutator)               |
   |[conj `sna`](@ref `polyfloat`::conj)                           |[convert    ](@ref `polyfloat`::convert)                     |[cos `sna`](@ref `polyfloat`::cos)                             |[cosh `sna`](@ref `polyfloat`::cosh)                           |
   |[cot `sna`](@ref `polyfloat`::cot)                             |[coth `sna`](@ref `polyfloat`::coth)                           |[csc `sna`](@ref `polyfloat`::csc)                             |[csch `sna`](@ref `polyfloat`::csch)                           |
   |                                                           |[dec    ](@ref `polyfloat`::dec)                             |[deta `sna`](@ref `polyfloat`::deta)                           |[digamma `sna`](@ref `polyfloat`::digamma)                     |
   |[dist    ](@ref `polyfloat`::dist)                           |[div    ](@ref `polyfloat`::div)                             |[dot `sna`](@ref `polyfloat`::dot)                             |[ellint_fe `sna`](@ref `polyfloat`::ellint_fe)                 |
   |[ellint_rc `sna`](@ref `polyfloat`::ellint_rc)                 |[ellint_rd `sna`](@ref `polyfloat`::ellint_rd)                 |[ellint_rf `sna`](@ref `polyfloat`::ellint_rf)                 |[ellint_rg `sna`](@ref `polyfloat`::ellint_rg)                 |
   |[ellint_rj `sna`](@ref `polyfloat`::ellint_rj)                 |[erf `sna`](@ref `polyfloat`::erf)                             |[erfcx `sna`](@ref `polyfloat`::erfcx)                         |[erfi `sna`](@ref `polyfloat`::erfi)                           |
   |[eta `sna`](@ref `polyfloat`::eta)                             |[exp `sna`](@ref `polyfloat`::exp)                             |[exp10 `sna`](@ref `polyfloat`::exp10)                         |[exp2 `sna`](@ref `polyfloat`::exp2)                           |
   |                                                           |[expm1 `sna`](@ref `polyfloat`::expm1)                         |[expmx2 `sna`](@ref `polyfloat`::expmx2)                       |                                                           |
   |[expx2 `sna`](@ref `polyfloat`::expx2)                         |[faddeeva `sna`](@ref `polyfloat`::faddeeva)                   |[fam `sna`](@ref `polyfloat`::fam)                             |[floor    ](@ref `polyfloat`::floor)                         |
   |[fma    ](@ref `polyfloat`::fma)                             |[fms `sna`](@ref `polyfloat`::fms)                             |[fnma    ](@ref `polyfloat`::fnma)                           |[fnms `sna`](@ref `polyfloat`::fnms)                           |
   |[frac `sna`](@ref `polyfloat`::frac)                           |                                                           |[fsm `sna`](@ref `polyfloat`::fsm)                             |[gd `sna`](@ref `polyfloat`::gd)                               |
   |[gegenbauer `sna`](@ref `polyfloat`::gegenbauer)               |[horner    ](@ref `polyfloat`::horner)                       |[hypergeometric `sna`](@ref `polyfloat`::hypergeometric)       |[hypot `sna`](@ref `polyfloat`::hypot)                         |
   |[if_else   ](@ref `polyfloat`::if_else)                      |[inc    ](@ref `polyfloat`::inc)                             |                                                           |[is_denormal    ](@ref `polyfloat`::is_denormal)             |
   |[is_equal    ](@ref `polyfloat`::is_equal)                   |[is_eqz    ](@ref `polyfloat`::is_eqz)                       |[is_finite    ](@ref `polyfloat`::is_finite)                 |[is_flint    ](@ref `polyfloat`::is_flint)                   |
   |                                                           |                                                           |[is_infinite    ](@ref `polyfloat`::is_infinite)             |[is_nan    ](@ref `polyfloat`::is_nan)                       |
   |[is_nez    ](@ref `polyfloat`::is_nez)                       |                                                           |[is_not_denormal    ](@ref `polyfloat`::is_not_denormal)     |[is_not_equal    ](@ref `polyfloat`::is_not_equal)           |
   |[is_not_finite    ](@ref `polyfloat`::is_not_finite)         |[is_not_flint    ](@ref `polyfloat`::is_not_flint)           |                                                           |[is_not_infinite    ](@ref `polyfloat`::is_not_infinite)     |
   |[is_not_nan    ](@ref `polyfloat`::is_not_nan)               |[is_not_real     ](@ref `polyfloat`::is_not_real)            |                                                           |[is_real `sna`](@ref `polyfloat`::is_real)                     |
   |[is_unitary    ](@ref `polyfloat`::is_unitary)               |[jacobi_elliptic `sna`](@ref `polyfloat`::jacobi_elliptic)     |[kolmmean `sna`](@ref `polyfloat`::kolmmean)                   |[kronecker `sna`](@ref `polyfloat`::kronecker)                 |
   |[kummer `sna`](@ref `polyfloat`::kummer)                       |[lambda `sna`](@ref `polyfloat`::lambda)                       |[lbeta `sna`](@ref `polyfloat`::lbeta)                         |[ldiv `sna`](@ref `polyfloat`::ldiv)                           |
   |[legendre `sna`](@ref `polyfloat`::legendre)                   |[lerp    ](@ref `polyfloat`::lerp)                           |[log `sna`](@ref `polyfloat`::log)                             |[log10 `sna`](@ref `polyfloat`::log10)                         |
   |[log1p `sna`](@ref `polyfloat`::log1p)                         |[log2 `sna`](@ref `polyfloat`::log2)                           |[log_abs `sna`](@ref `polyfloat`::log_abs)                     |[log_abs_gamma `sna`](@ref `polyfloat`::log_abs_gamma)         |
   |[log_gamma `sna`](@ref `polyfloat`::log_gamma)                 |[lpnorm `sna`](@ref `polyfloat`::lpnorm)                       |[lrising_factorial `sna`](@ref `polyfloat`::lrising_factorial) |                                                           |
   |[manhattan `sna`](@ref `polyfloat`::manhattan)                 |[maxabs `sna`](@ref `polyfloat`::maxabs)                       |[maxmag `sna`](@ref `polyfloat`::maxmag)                       |                                                           |
   |[minabs `sna`](@ref `polyfloat`::minabs)                       |[minmag `sna`](@ref `polyfloat`::minmag)                       |[minus    ](@ref `polyfloat`::minus)                         |[mul    ](@ref `polyfloat`::mul)                             |
   |                                                           |                                                           |[nearest    ](@ref `polyfloat`::nearest)                     |[negmaxabs `sna`](@ref `polyfloat`::negmaxabs)                 |
   |[negminabs `sna`](@ref `polyfloat`::negminabs)                 |[nthroot `sna`](@ref `polyfloat`::nthroot)                     |[oneminus   ](@ref `polyfloat`::oneminus)                    |[pow `sna`](@ref `polyfloat`::pow)                             |
   |[pow1p `sna`](@ref `polyfloat`::pow1p)                         |[pow_abs `sna`](@ref `polyfloat`::pow_abs)                     |[powm1 `sna`](@ref `polyfloat`::powm1)                         |[proj `sna`](@ref `polyfloat`::proj)                           |
   |                                                           |[radinpi `sna`](@ref `polyfloat`::radinpi)                     |[rec    ](@ref `polyfloat`::rec)                             |[reldist `sna`](@ref `polyfloat`::reldist)                     |
   |[reverse_horner    ](@ref `polyfloat`::reverse_horner)       |[rising_factorial `sna`](@ref `polyfloat`::rising_factorial)   |[rsqrt  ](@ref `polyfloat`::rsqrt)                           |[sec `sna`](@ref `polyfloat`::sec)                             |
   |[sech `sna`](@ref `polyfloat`::sech)                           |[sign    ](@ref `polyfloat`::sign)                           |                                                           |                                                           |
   |[signz    ](@ref `polyfloat`::signz)                         |[sin `sna`](@ref `polyfloat`::sin)                             |[sinc `sna`](@ref `polyfloat`::sinc)                           |[sincos `sna`](@ref `polyfloat`::sincos)                       |
   |[sinh `sna`](@ref `polyfloat`::sinh)                           |[sinhc `sna`](@ref `polyfloat`::sinhc)                         |[sinhcosh `sna`](@ref `polyfloat`::sinhcosh)                   |                                                           |
   |[sqr    ](@ref `polyfloat`::sqr)                             |                                                           |[sqrt    ](@ref `polyfloat`::sqrt)                           |[sub    ](@ref `polyfloat`::sub)                             |
   |[tan `sna`](@ref `polyfloat`::tan)                             |[tanh `sna`](@ref `polyfloat`::tanh)                           |[tchebytchev `sna`](@ref `polyfloat`::tchebytchev)             |[tgamma `sna`](@ref `polyfloat`::tgamma)                       |
   |[tgamma_inv `sna`](@ref `polyfloat`::tgamma_inv)               |                                                           |[to_polar `sna`](@ref `polyfloat`::to_polar)                   |[tricomi `sna`](@ref `polyfloat`::tricomi)                     |
   |[trunc    ](@ref `polyfloat`::trunc)                         |[zeta `sna`](@ref `polyfloat`::zeta)                           |                                                   |                                                   |



Remark on predicates
--------------------

All predicates comparing to `zero` and almost all one parameter predicates are a lot faster than two parameters ones
for which testing the 'hi' part is not sufficient.


Testing rationale
-----------------

The behaviour of `polyfloat` is not the same as standard floating points numbers, for instance
for any `polyfloat` the difference between any finite T and the next representable element is
the minimum denormal value of the type T, meaning that the intervals are quite more populated.

However, the following table shows the number of bits of mantissa available for each scalar
 `polyfloat` element as well as an expected machine precision (eps) related to this mantissa bit size

   |  base  type |   dimension |   bits number  |   eps            |
   |-------------|-------------|----------------|------------------|
   | float       |   2         |   46           |   1.4211e-14     |
   | float       |   3         |   69           |   1.6941e-21     |
   | double      |   2         |   106          |   1.2326e-32     |
   | double      |   3         |   159          |   1.3685e-48     |

So if an `mpfr` implementation of a fonction is at hand, we generally choose to evaluate
the relative absolute error between our computation converted to `mpfr` value
of the same mantissa precision and the `mpfr` computation with the converted inputs
and be satisfied if it is less than a small mutiple of the corresponding `eps`.

The relative error formula between \f$a\f$ and \f$b\f$
is chosen to be \f$|a-b|/(\max(|a|,|b|,1)\f$.
