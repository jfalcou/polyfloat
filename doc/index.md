Polyfloat
=========

**POLYFLOAT** is an implementation of extended precision floating points numbers
using a sequence of (currently) 2 or 3 standard floating points
numbers of sam type (`float` or `double`)

Most standard library fonctions  in **scalar** and **SIMD** form mimicking **EVE** calls
are implemented or will be.

The main references we use to perform these representations are:

  * [D. Bailey](https://www.davidhbailey.com/dhbpapers/qd.pdf)
  * [D. K. Zhang](https://dl.acm.org/doi/10.1145/3712285.3759876)

Polyfloat numbers
=================

As explained in the above articles,
Polyfloat are floating-point expansions that represent high-precision numbers as sequences of
two, three, or four machine-precision numbers, extending the effective precision to double,
triple, or quadruple the native machine precision.

Up to now, we limit the implementation to 3 machine-precision numbers.

Starting from the real numbers (supported by type `T`: `float` or `double`) we define:

  - two_real        (dimension 2) as a pair   of `T`, alias of polyfloat<T,2>
  - three_real      (dimension 3) as a triple of `T`, alias of polyfloat<T,3>

**SIMD** analog can be used simlessly

  - two_real        (dimension 2)  wide<polyfloat<T,2>>
  - three_real      (dimension 3)  wide<polyfloat<T,3>>


These datas with different dimensions but same  standard floating-point underlying type can be freely mixed
with the obvious semantic that if `N < M` an element of `polyfloat<N,T>` will be considered as having its components
from `N` to `M-1` null, as an element of `polyfloat<M,T>`

All these types do not extend the exponent range of their undelying type, but their number of mantissa bits.
  * `polyfloat<2,float>` have 46 bits of mantissa
  * `polyfloat<3,float>` have 59 bits of mantissa
  * `polyfloat<2,double>` have 106 bits of mantissa
  * `polyfloat<3,double>` have 159 bits of mantissa

This means that for  `T` `float`, these types can only be useful to obtain `double>` precision equivalent
on system where the hardware does not support them.

Contrarily, for  `T` `double`, they can be used to obtain greater precision, especially if standard
`long double` has only 64 or 80 bits of storage.


What does this implementation provide
======================================

Being intended that a polyfloat_like is a polyfloat or a standard floating-point number,
all operators and functions (with a few exceptions restricted to some dimensionnalities constraints)
implemented can receive a mix of scalar or  simd of polyfloat_like of various dimensionnality
(but same underlying type) and are defined in the namespace `plf`.

  - Proper polyfloat values are those of dimensionality is greater or equal to 2 and satisfy the
    `concepts::polyfloat` concept. They don't satisfy the  `concepts::real` concept;
  - scalar and simd floating types only satisfy  the `concepts::polyfloat_like` concept, meaning they are interoperable with
    proper polyfloat values. They satisfy the `concepts::real` concept.
  - Almost all functions involving angles (within the parameters or the results) can receive an option (namely plf::radpi) such that
    every angle parameter or result will be expressed in \f$\pi\f$ multiples rather than in mere radians. (This use can be beneficial as some
    currently used angles values are small integer multiples of \f$\pi\f$. \f$\pi\f$ is not exactly represented by polyfloat_like values;
    but small integers are...)

Of course the algebra operation +, -, * and / are provided.

Constructors
------------

two_real and three_real can be constructed using callables facilities `two_real` and `three_real`.

Operators
---------

Operators (as said before) `+`, `-`, `*` and `/` can be used in infix form and can mix polyfloat values of
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

  * Callables usable with all polyfloat types

    Most **EVE** arithmetic and math functions are (or will be eventually) provided for polyfloat datas.

   |                                                       |                                                       |                                                       |                                                       |
   |-------------------------------------------------------|-------------------------------------------------------|-------------------------------------------------------|-------------------------------------------------------|
   |[abs](@ref polyfloat::abs)                             |[acos](@ref polyfloat::acos)                           |[acosh](@ref polyfloat::acosh)                         |[acot](@ref polyfloat::acot)                           |
   |[acoth](@ref polyfloat::acoth)                         |[acsc](@ref polyfloat::acsc)                           |[acsch](@ref polyfloat::acsch)                         |[add](@ref polyfloat::add)                             |
   |[agd](@ref polyfloat::agd)                             |[airy](@ref polyfloat::airy)                           |[airy_ai](@ref polyfloat::airy_ai)                     |[airy_bi](@ref polyfloat::airy_bi)                     |
   |[am](@ref polyfloat::am)                               |[arg](@ref polyfloat::arg)                             |[asec](@ref polyfloat::asec)                           |[asech](@ref polyfloat::asech)                         |
   |[asin](@ref polyfloat::asin)                           |[asinh](@ref polyfloat::asinh)                         |[associator](@ref polyfloat::associator)               |[atan](@ref polyfloat::atan)                           |
   |[atanh](@ref polyfloat::atanh)                         |[average](@ref polyfloat::average)                     |[bessel_h](@ref polyfloat::bessel_h)                   |[bessel_i](@ref polyfloat::bessel_i)                   |
   |[bessel_j](@ref polyfloat::bessel_j)                   |[bessel_k](@ref polyfloat::bessel_k)                   |[bessel_y](@ref polyfloat::bessel_y)                   |[beta](@ref polyfloat::beta)                           |
   |[ceil](@ref polyfloat::ceil)                           |[cbrt](@ref polyfloat::cbrt)                           |[chi](@ref polyfloat::chi)                             |[commutator](@ref polyfloat::commutator)               |
   |[conj](@ref polyfloat::conj)                           |[convert](@ref polyfloat::convert)                     |[cos](@ref polyfloat::cos)                             |[cosh](@ref polyfloat::cosh)                           |
   |[cot](@ref polyfloat::cot)                             |[coth](@ref polyfloat::coth)                           |[csc](@ref polyfloat::csc)                             |[csch](@ref polyfloat::csch)                           |
   |                                                       |[dec](@ref polyfloat::dec)                             |[deta](@ref polyfloat::deta)                           |[digamma](@ref polyfloat::digamma)                     |
   |[dist](@ref polyfloat::dist)                           |[div](@ref polyfloat::div)                             |[dot](@ref polyfloat::dot)                             |[ellint_fe](@ref polyfloat::ellint_fe)                 |
   |[ellint_rc](@ref polyfloat::ellint_rc)                 |[ellint_rd](@ref polyfloat::ellint_rd)                 |[ellint_rf](@ref polyfloat::ellint_rf)                 |[ellint_rg](@ref polyfloat::ellint_rg)                 |
   |[ellint_rj](@ref polyfloat::ellint_rj)                 |[erf](@ref polyfloat::erf)                             |[erfcx](@ref polyfloat::erfcx)                         |[erfi](@ref polyfloat::erfi)                           |
   |[eta](@ref polyfloat::eta)                             |[exp](@ref polyfloat::exp)                             |[exp10](@ref polyfloat::exp10)                         |[exp2](@ref polyfloat::exp2)                           |
   |[exp_i](@ref polyfloat::exp_i)                         |[expm1](@ref polyfloat::expm1)                         |[expmx2](@ref polyfloat::expmx2)                       |                                                       |
   |[expx2](@ref polyfloat::expx2)                         |[faddeeva](@ref polyfloat::faddeeva)                   |[fam](@ref polyfloat::fam)                             |[floor](@ref polyfloat::floor)                         |
   |[fma](@ref polyfloat::fma)                             |[fms](@ref polyfloat::fms)                             |[fnma](@ref polyfloat::fnma)                           |[fnms](@ref polyfloat::fnms)                           |
   |[frac](@ref polyfloat::frac)                           |[from_polar](@ref polyfloat::from_polar)               |[fsm](@ref polyfloat::fsm)                             |[gd](@ref polyfloat::gd)                               |
   |[gegenbauer](@ref polyfloat::gegenbauer)               |[horner](@ref polyfloat::horner)                       |[hypergeometric](@ref polyfloat::hypergeometric)       |[hypot](@ref polyfloat::hypot)                         |
   |[if_else](@ref polyfloat::if_else)                     |[inc](@ref polyfloat::inc)                             |[is_cinf](@ref polyfloat::is_cinf)                     |[is_denormal](@ref polyfloat::is_denormal)             |
   |[is_equal](@ref polyfloat::is_equal)                   |[is_eqz](@ref polyfloat::is_eqz)                       |[is_finite](@ref polyfloat::is_finite)                 |[is_flint](@ref polyfloat::is_flint)                   |
   |[is_fnan](@ref polyfloat::is_fnan)                     |[is_imag](@ref polyfloat::is_imag)                     |[is_infinite](@ref polyfloat::is_infinite)             |[is_nan](@ref polyfloat::is_nan)                       |
   |[is_nez](@ref polyfloat::is_nez)                       |[is_not_cinf](@ref polyfloat::is_not_cinf)             |[is_not_denormal](@ref polyfloat::is_not_denormal)     |[is_not_equal](@ref polyfloat::is_not_equal)           |
   |[is_not_finite](@ref polyfloat::is_not_finite)         |[is_not_flint](@ref polyfloat::is_not_flint)           |[is_not_fnan](@ref polyfloat::is_not_fnan)             |[is_not_infinite](@ref polyfloat::is_not_infinite)     |
   |[is_not_nan](@ref polyfloat::is_not_nan)               |[is_not_real](@ref polyfloat::is_not_real)             |[is_pure](@ref polyfloat::is_pure)                     |[is_real](@ref polyfloat::is_real)                     |
   |[is_unitary](@ref polyfloat::is_unitary)               |[jacobi_elliptic](@ref polyfloat::jacobi_elliptic)     |[kolmmean](@ref polyfloat::kolmmean)                   |[kronecker](@ref polyfloat::kronecker)                 |
   |[kummer](@ref polyfloat::kummer)                       |[lambda](@ref polyfloat::lambda)                       |[lbeta](@ref polyfloat::lbeta)                         |[ldiv](@ref polyfloat::ldiv)                           |
   |[legendre](@ref polyfloat::legendre)                   |[lerp](@ref polyfloat::lerp)                           |[log](@ref polyfloat::log)                             |[log10](@ref polyfloat::log10)                         |
   |[log1p](@ref polyfloat::log1p)                         |[log2](@ref polyfloat::log2)                           |[log_abs](@ref polyfloat::log_abs)                     |[log_abs_gamma](@ref polyfloat::log_abs_gamma)         |
   |[log_gamma](@ref polyfloat::log_gamma)                 |[lpnorm](@ref polyfloat::lpnorm)                       |[lrising_factorial](@ref polyfloat::lrising_factorial) |                                                   |
   |[manhattan](@ref polyfloat::manhattan)                 |[maxabs](@ref polyfloat::maxabs)                       |[maxmag](@ref polyfloat::maxmag)                       |                                                   |
   |[minabs](@ref polyfloat::minabs)                       |[minmag](@ref polyfloat::minmag)                       |[minus](@ref polyfloat::minus)                         |[mul](@ref polyfloat::mul)                             |
   |[muli](@ref polyfloat::muli)                           |[mulmi](@ref polyfloat::mulmi)                         |[nearest](@ref polyfloat::nearest)                     |[negmaxabs](@ref polyfloat::negmaxabs)                 |
   |[negminabs](@ref polyfloat::negminabs)                 |[nthroot](@ref polyfloat::nthroot)                     |[oneminus](@ref polyfloat::oneminus)                   |[pow](@ref polyfloat::pow)                             |
   |[pow1p](@ref polyfloat::pow1p)                         |[pow_abs](@ref polyfloat::pow_abs)                     |[powm1](@ref polyfloat::powm1)                         |[proj](@ref polyfloat::proj)                           |
   |[pure](@ref polyfloat::pure)                           |[radinpi](@ref polyfloat::radinpi)                     |[rec](@ref polyfloat::rec)                             |[reldist](@ref polyfloat::reldist)                     |
   |[reverse_horner](@ref polyfloat::reverse_horner)       |[rising_factorial](@ref polyfloat::rising_factorial)   |[sec](@ref polyfloat::sec)                             |[sech](@ref polyfloat::sech)                           |
   |[sign](@ref polyfloat::sign)                           |[sin](@ref polyfloat::sin)                             |[sinc](@ref polyfloat::sinc)                           |[sincos](@ref polyfloat::sincos)                       |
   |[sinh](@ref polyfloat::sinh)                           |[sinhc](@ref polyfloat::sinhc)                         |[sinhcosh](@ref polyfloat::sinhcosh)                   |[slerp](@ref polyfloat::slerp)                         |
   |[sqr](@ref polyfloat::sqr)                             |[sqr_abs](@ref polyfloat::sqr_abs)                     |[sqrt](@ref polyfloat::sqrt)                           |[sub](@ref polyfloat::sub)                             |
   |[tan](@ref polyfloat::tan)                             |[tanh](@ref polyfloat::tanh)                           |[tchebytchev](@ref polyfloat::tchebytchev)             |[tgamma](@ref polyfloat::tgamma)                       |
   |[tgamma_inv](@ref polyfloat::tgamma_inv)               |[to_cylindrical](@ref polyfloat::to_cylindrical)       |[to_polar](@ref polyfloat::to_polar)                   |[tricomi](@ref polyfloat::tricomi)                     |
   |[trunc](@ref polyfloat::trunc)                         |[zeta](@ref polyfloat::zeta)                           |                                                   |                                                   |
