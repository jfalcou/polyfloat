Precision {#implementation_precisions}
=========

# Representation

A floating-point expansion of dimension \f$N\f$ represents a real number as the unevaluated sum
\f$x_0 + x_1 + \cdots + x_{N-1}\f$ of floating-point numbers of one type `T`, of decreasing
magnitude, which do not overlap: two successive parts satisfy \f$x_k + x_{k+1} = x_k\f$ in `T`,
rounded to nearest, which implies \f$|x_{k+1}| \le \mathrm{ulp}(x_k)/2\f$. plf::is_normalized
tests this condition, which is stricter by a factor of 2 than the ulp-nonoverlapping expansions
of Joldes, Marty, Muller, and Popescu, \f$|x_{k+1}| \le \mathrm{ulp}(x_k)\f$.

The expansions of the literature have two, three, four, or more parts, and **POLYFLOAT**
implements those of two and three parts, plf::double_real_t and plf::triple_real_t, over `float`
and `double`. The arithmetic on the parts uses the hardware floating-point operations and the
error-free transformations of @ref biblio "Joldes, Marty, Muller, and Popescu".

# Precision

An expansion of dimension \f$N\f$ over `T` has \f$N\f$ times the mantissa bits of `T`, which
plf::effective_mantissa_bits returns. The exponent range is the one of `T`. These figures
describe the representation, and do not bound the error of an operation.

| Base type | Dimension | Mantissa bits | \f$2^{-\text{bits}}\f$ | plf::eps        |
|-----------|-----------|---------------|------------------------|-----------------|
| `float`   | 2         | 48            | \f$3.5527 \cdot 10^{-15}\f$ | \f$2^{-48}\f$  |
| `float`   | 3         | 72            | \f$2.1176 \cdot 10^{-22}\f$ | \f$2^{-72}\f$  |
| `double`  | 2         | 106           | \f$1.2326 \cdot 10^{-32}\f$ | \f$2^{-104}\f$ |
| `double`  | 3         | 159           | \f$1.3685 \cdot 10^{-48}\f$ | \f$2^{-156}\f$ |

Over `float`, an expansion of dimension 3 exceeds the 53 bits of `double`, while one of
dimension 2 falls short of them, and both keep the exponent range of `float`. They extend the
precision on a target without `double`, or estimate the rounding error of a computation in
`float`. Over `double`, both dimensions exceed the 64 bits of the x87
extended format, while the 113 bits of IEEE binary128, the `long double` of some targets, exceed
the 106 bits of dimension 2. An expansion also applies to SIMD registers, which `long double`
does not.

# Limits

- Overflow and underflow occur where they occur in `T`.
- The low part becomes denormal when the high part falls below about \f$2^{-969}\f$ for a
  `plf::double_real_t<double>`, and \f$2^{-916}\f$ for a `plf::triple_real_t<double>`, and the
  precision decreases from there. Below the smallest positive normal value of `T`, the high part
  is itself denormal and has fewer bits than `T`.
- The infinities and the quiet NaN are represented in the high part, the other parts being zero.
- The distance from a finite value to the next representable one can be as small as the smallest
  denormal of `T`, so the representable values are not evenly spaced as in `T`.

# Testing

A function is tested against its implementation in [MPFR](https://www.mpfr.org/), when one
exists. MPFR evaluates it with ten times the mantissa bits of the tested type, 1060 bits for
`plf::double_real_t<double>`. Its result is converted to that type part by part: the high part is
the result rounded to `T`, and each following part the remainder rounded to `T`. The reference
carries a rounding error of its own, of the order of \f$2^{-\text{bits}}\f$. The test passes when
the distance between the two results is under a multiple of the \f$2^{-\text{bits}}\f$ of the type,
set by each test. The distance between \f$a\f$ and \f$b\f$, which plf::reldist computes, is

\f[ \frac{|a - b|}{\max(|a|, |b|, 1)}, \f]

the relative error when \f$\max(|a|, |b|)\f$ exceeds 1, and the absolute error below. A result
of magnitude below 1 is therefore tested against an absolute bound, and a result below that
bound passes whatever its value.
