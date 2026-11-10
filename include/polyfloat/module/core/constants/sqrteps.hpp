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

namespace plf
{
  template<typename Options>
  struct sqrteps_t : plf::constant_callable<sqrteps_t, eve::sqrteps_t, Options, lower_option, upper_option>
  {
    template<typename T> POLYFLOAT_ABI static constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, eve::float16_t>) return T(0x1p-10);
        else if constexpr (std::same_as<u_t, float>) return T(0x1p-23);
        else if constexpr (std::same_as<u_t, double>) return T(0x1p-52);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, eve::float16_t>) return T(0x1p-15);
        else if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.6a09e6p-35, 0x1.9fcef4p-61, -0x1.b7ba68p-86);
        else if constexpr (std::same_as<u_t, double>) return T(0x1p-78);
      }
      else
      {
        return eve::sqrteps(eve::as<u_t>());
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_ABI constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(sqrteps_t, sqrteps_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var sqrteps
  //!   @brief the square root of plf::eps.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/polyfloat.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace plf
  //!   {
  //!      template<concepts::polyfloat_like T> constexpr auto sqrteps(eve::as<T> z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: [Type wrapper](@ref eve::as) of the type of the constant.
  //!
  //!   **Return value**
  //!
  //!     Returns the square root of plf::eps of the type of the constant.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/sqrteps.cpp}
  //======================================================================================================================

  inline constexpr auto sqrteps = eve::functor<sqrteps_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
