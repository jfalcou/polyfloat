//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <polyfloat/details/callable.hpp>
#include <polyfloat/types/concepts.hpp>
#include <polyfloat/types/traits.hpp>
#include <type_traits>

namespace plf
{

  template<typename Options> struct fma_t : eve::strict_tuple_callable<fma_t, Options, raw_option, pedantic_option>
  {
    template<typename... Ts> struct result : as_polyfloat_like<Ts...>
    {
    };

    template<concepts::polyfloat_like Z0, concepts::polyfloat_like Z1, concepts::polyfloat_like Z2>
    EVE_FORCEINLINE typename result<Z0, Z1, Z2>::type constexpr operator()(Z0 z0, Z1 z1, Z2 z2) const noexcept
    {
      return POLYFLOAT_CALL(z0, z1, z2);
    }


    POLYFLOAT_CALLABLE_OBJECT(fma_t, fma_);
  };
  //======================================================================================================================
  //! @fmatogroup core
  //! @{
  //!   @var fma
  //!   @brief return the fused multiply add of the parameters.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <kyosu/module/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace kyosu
  //!   {
  //!      template<kyosu::concepts::polyfloat_like Z1, polyfloat_like Z2, polyfloat_like Z3> constexpr auto fma(Z1 z1, Z2 z2, Z3 z3) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2`, `z3`: Values to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the fused multiply add of the arguments.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/fma.cpp}
  //======================================================================================================================

  inline constexpr auto fma = eve::functor<fma_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z1, typename Z2, typename Z3, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto fma_(POLYFLOAT_DELAY(), O const& , Z1 const& x, Z2 const& y, Z3 const& z) noexcept
  {
    using r_t = as_polyfloat_t<Z1, Z2, Z3>;
    if constexpr((dimension_v<Z1> > 2) && (dimension_v<Z2> > 2) &&(dimension_v<Z3> > 2))
    {
      return x*y+z; //TODO
    }
    if constexpr((dimension_v<Z1> == 2) && (dimension_v<Z2> == 2) &&(dimension_v<Z3> == 2))
    {
      auto [xhi, xlo] = x;
      auto [yhi, ylo] = y;
      auto [zhi, zlo] = z;
      auto [chi, c1] = eve::two_prod(xhi, yhi);
      auto t0 = xlo * ylo;
      auto t1 = eve::fma(xhi, ylo, t0);
      auto c2 = eve::fma(xlo, yhi, t1);
      auto c3 = c1 + c2;
      auto [dhi, dlo] = eve::two_add[eve::raw](chi, c3);

      auto [shi, slo] = eve::two_add(zhi, dhi);
      auto [thi, tlo] = eve::two_add(zlo, dlo);
      auto c = slo + thi;
      auto [vhi, vlo] = eve::two_add[eve::raw](shi, c);
      auto w = tlo + vlo;
      auto [hi, lo] = eve::two_add[eve::raw](vhi, w);
      return r_t(hi, lo);
    }
    else  if constexpr ((dimension_v<Z1> == 1) && (dimension_v<Z2> == 1))
    {
      if constexpr(dimension_v<Z3> == 1)
        return eve::fma(x, y, z);
      else if constexpr(dimension_v<Z3> == 2)
      {
        auto [zhi, zlo] = z;
        auto [chi, c1] = eve::two_prod(x, y);
        auto [shi, slo] = eve::two_add(zhi, chi);
        auto [thi, tlo] = eve::two_add(zlo, c1);
        auto c = slo + thi;
        auto [vhi, vlo] = eve::two_add[eve::raw](shi, c);
        auto w = tlo + vlo;
        auto [hi, lo] = eve::two_add[eve::raw](vhi, w);
        return r_t(hi, lo);
      }
    }
    else
    {
      using r_t = as_polyfloat_t<Z1, Z2, Z3>;
      auto cvt =  [](auto a){return plf::convert(a, eve::as<eve::element_type_t<r_t>>());};
      return fma(cvt(x), cvt(y), cvt(z));
    }
  }
}
