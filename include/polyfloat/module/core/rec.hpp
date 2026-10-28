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

  template<typename Options>
  struct rec_t : eve::elementwise_callable<rec_t, Options, raw_option, pedantic_option, eve::mod_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI Z operator()(Z z) const noexcept { return POLYFLOAT_CALL(z); }

    POLYFLOAT_CALLABLE_OBJECT(rec_t, rec_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var rec
  //!   @brief return the ratio of the values.
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
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto rec(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the ratio of the arguments.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/rec.cpp}
  //======================================================================================================================

  inline constexpr auto rec = eve::functor<rec_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O> constexpr auto rec_(POLYFLOAT_DELAY(), O const&, Z const& z) noexcept
  {
    if constexpr (dimension_v<Z> == 1) return eve::rec[eve::pedantic](z);
    else return _::rec(z);
  }

  template<typename T, eve::callable_options O>
  constexpr auto rec_(POLYFLOAT_DELAY(), O const& o, T a) noexcept
  requires(O::contains(eve::mod))
  {
    auto p = o[eve::mod].value(as(a));
    auto base(a);
    auto expo(p - 2);

    auto result = plf::one(eve::as<T>());
    while (eve::any(plf::is_nez(expo)))
    {
      result = plf::mul[eve::mod = p](result, plf::if_else(plf::is_odd(expo), base, plf::one(eve::as(expo))));
      expo = plf::floor(expo / 2);
      base = plf::mul[eve::mod = p](base, base);
    }
    return result;
  }
}
