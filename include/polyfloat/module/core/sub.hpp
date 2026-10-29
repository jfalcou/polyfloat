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
#include <polyfloat/module/core/is_ltz.hpp>
#include <polyfloat/module/core/add.hpp>

namespace plf
{

  template<typename Options>
  struct sub_t : eve::strict_tuple_callable<sub_t, Options, raw_option, pedantic_option, eve::mod_option>
  {
    template<concepts::polyfloat_like Z1, concepts::polyfloat_like Z2>
    POLYFLOAT_ABI constexpr as_polyfloat_like_t<Z1, Z2> operator()(Z1 z1, Z2 z2) const noexcept
    {
      return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(sub_t, sub_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var sub
  //!   @brief return the difference of the values.
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
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto sub(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the difference of the arguments.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/sub.cpp}
  //======================================================================================================================

  inline constexpr auto sub = eve::functor<sub_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T1, typename T2, eve::callable_options O>
  constexpr auto sub_(POLYFLOAT_DELAY(), O const& o, T1 const& a, T2 const& b) noexcept
  {
    auto s = a - b;
    if constexpr (O::contains(eve::mod))
    {
      using r_t = plf::as_polyfloat_like_t<T1, T2>;
      using u_t = eve::element_type_t<r_t>;
      auto p = o[eve::mod].value(eve::as<u_t>());
      return plf::add[eve::is_ltz(s)](s, p);
    }
    else return s;
  }

  template<eve::callable_options O, concepts::polyfloat_like T0, concepts::polyfloat_like... Ts>
  constexpr auto add_(POLYFLOAT_DELAY(), O const& o, T0 const& t0, Ts const&... ts) noexcept
  {
    if constexpr (sizeof...(Ts) == 0) return t0;
    else
    {
      using r_t = as_polyfloat_t<T0, Ts...>;
      auto cvt = [](auto a) { return plf::convert(a, eve::as_element<r_t>{}); };
      return plf::sub[o](cvt(t0), plf::add(cvt(ts)...));
    }
  }
}
