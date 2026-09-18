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
#include <polyfloat/module/math/nthroot.hpp>
#include <iostream>

namespace plf
{

  template<typename Options>
  struct geommean_t : eve::strict_tuple_callable<geommean_t, Options, raw_option, pedantic_option>
  {
    template<typename... Ts> struct result : as_polyfloat_like<Ts...>
    {
    };

    template<concepts::polyfloat_like Z1, concepts::polyfloat_like... Zs>
    POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Zs...> operator()(Z1 z1, Zs... zs) const noexcept
    {
      return POLYFLOAT_CALL(z1, zs...);
    }

    template<eve::non_empty_product_type Tup>
    POLYFLOAT_FORCEINLINE constexpr kumi::apply_traits_t<result, Tup> operator()(Tup tup) const noexcept
    requires(eve::same_lanes_or_scalar_tuple<Tup> && kumi::size_v<Tup> >= 1)
    {
      return POLYFLOAT_CALL(tup);
    }

    POLYFLOAT_CALLABLE_OBJECT(geommean_t, geommean_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var geommean
  //!   @brief  Callable object computing the geometric mean of the inputs \f$\left(\prod_{i = 1}^n\f$.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace polyfloat
  //!   {
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto geommean(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z, zs...`: Values to process.
  //!
  //!   **Return value**
  //!
  //!      Returns the geommean of the parameters.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/geommean.cpp}
  //======================================================================================================================

  inline constexpr auto geommean = eve::functor<geommean_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T1, typename... Ts, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto geommean_(POLYFLOAT_DELAY(), O const& o, T1 a0, Ts... args) noexcept
  {
    using r_t = as_polyfloat_like_t<T1, Ts...>;
    using e_t = eve::element_type_t<r_t>;
    auto cvt = [](auto a) { return plf::convert(a, as<e_t>()); };
    constexpr auto sz = sizeof...(Ts);
    if constexpr (sz == 0) return a0;
    else
    {
      auto e = -eve::maxmag(exponent(cvt(a0)), exponent(cvt(args))...);
      //       if constexpr (eve::scalar_value<r_t> && (sizeof...(Ts) + 1 >= eve::expected_cardinal_v<e_t>))
      //       {
      //         auto head = eve::as_wides(plf::one(as<r_t>()), cvt(ldexp[o](a0, e)), cvt(ldexp[o](args, e))...);
      //         auto s = eve::mul[o](head);
      //         auto p = eve::_::butterfly_reduction(s, plf::mul[o]).get(0);
      //         auto sgn = sign(p);
      //         p = plf::nthroot(p, sz + 1);
      //         p = plf::ldexp[eve::pedantic](p, -e);
      //         return plf::if_else(plf::is_even(sz) && plf::is_ltz(sgn), eve::allbits, sgn * p);
      //       }
      //       else
      //      {
      auto p = plf::mul[o](cvt(ldexp[o](a0, e)), cvt(ldexp[o](args, e))...);
      auto sgn = plf::sign(p);
      p = plf::nthroot(p, sz + 1);
      p = ldexp[pedantic](p, -e);
      return if_else(plf::is_even(sz) && plf::is_ltz(sgn), eve::allbits, sgn * p);
    }
    //    }
  }
}
