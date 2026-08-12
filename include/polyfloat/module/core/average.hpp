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
#include <polyfloat/module/core/abs.hpp>
#include <polyfloat/module/core/parts.hpp>

namespace plf
{

  template<typename Options> struct average_t : eve::strict_tuple_callable<average_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1,  concepts::polyfloat_like ...Zs>
      POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Zs...> operator()(Z1 z1, Zs ...zs) const noexcept
    {
     return POLYFLOAT_CALL(z1, zs...);
    }

    POLYFLOAT_CALLABLE_OBJECT(average_t, average_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var average
  //!   @brief return the average value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/module/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace polyfloat
  //!   {
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto average(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z, zs...`: Values to process.
  //!
  //!   **Return value**
  //!
  //!      Returns the average of the parameters.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/average.cpp}
  //======================================================================================================================

  inline constexpr auto average = eve::functor<average_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T1, typename ... Ts, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto average_(POLYFLOAT_DELAY(), O const& o, T1 a0, Ts ...args) noexcept
  {
    using r_t =  as_polyfloat_like_t<T1, Ts...>;
    using e_t =  eve::element_type_t<r_t>;
    if constexpr(sizeof...(Ts) == 0)
      return a0;
    else
    {
      constexpr auto N = sizeof...(Ts)+1;
      const/*expr*/ e_t invn = 1/(e_t(N));
      if constexpr(O::contains(raw))
      {
        return eve::mul[o](add[o.drop(raw)](a0, args...), invn);
      }
      else
      {
        r_t that(a0*invn);
        auto  next = [invn](auto avg, auto x) { return x*invn+avg; }; //fma ?
        ((that = next(that, r_t(args))), ...);
        return that;
      }
    }
  }
}
