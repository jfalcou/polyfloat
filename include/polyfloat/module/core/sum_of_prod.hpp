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

namespace plf
{

  template<typename Options>
  struct sum_of_prod_t : eve::strict_tuple_callable<sum_of_prod_t, Options, raw_option, pedantic_option>
  {
    template<typename... Ts> struct result : as_polyfloat_like<Ts...>
    {
    };

    template<concepts::polyfloat_like T0,
             concepts::polyfloat_like T1,
             concepts::polyfloat_like T2,
             concepts::polyfloat_like T3>
    requires(eve::same_lanes_or_scalar<T0, T1, T2, T3>)
    EVE_FORCEINLINE typename result<T0, T1, T2, T3>::type constexpr operator()(T0 t0,
                                                                               T1 t1,
                                                                               T2 t2,
                                                                               T3 t3) const noexcept
    {
      return POLYFLOAT_CALL(t0, t1, t2, t3);
    }

    POLYFLOAT_CALLABLE_OBJECT(sum_of_prod_t, sum_of_prod_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var sum_of_prod
  //!   @brief returns `a*b+c*d`.
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
  //!     constexpr auto sum_of_prod(auto a,  auto,  auto c,  auto d) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `a`, `b`, `c`, `d`: Values to process.
  //!
  //!   **Return value**
  //!
  //!     Returns a*b+c*d.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/sum_of_prod.cpp}
  //======================================================================================================================

  inline constexpr auto sum_of_prod = eve::functor<sum_of_prod_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================

  using callable_sum_of_prod_ = eve::tag_t<sum_of_prod>;

}

namespace plf::_
{

  template<typename T1, typename T2, typename T3, typename T4, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto sum_of_prod_(
    POLYFLOAT_DELAY(), O const& o, T1 const& a, T2 const& b, T3 const& c, T4 const& d) noexcept
  {
    if constexpr (O::contains(raw)) return a * b + c * d;
    else
    {
      auto cd = mul[o](c, d);
      auto err = fms[o](c, d, cd);
      auto dop = fma[o](a, b, cd);
      return add[o][is_finite(err)](dop, err);
    }
  }

}
