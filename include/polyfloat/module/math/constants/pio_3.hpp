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
  struct pio_3_t : plf::constant_callable<pio_3_t, eve::pio_3_t, Options, lower_option, upper_option>
  {
    template<typename T> POLYFLOAT_ABI static constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_pair<u_t>(0x1.0c15240000000p+0, -0x1.f4a3260000000p-26);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<u_t>(0x1.0c152382d7366p+0, -0x1.ee6913347c2a6p-54);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.0c15240000000p+0, -0x1.f4a3260000000p-26, -0x1.3dcd220000000p-51);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<u_t>(0x1.0c152382d7366p+0, -0x1.ee6913347c2a6p-54, -0x1.4bba47a9e5fd2p-110);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_ABI constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(pio_3_t, pio_3_);
  };
  //======================================================================================================================
  //! @defgroup plf_pio_3 plf::pio_3
  //! @ingroup constants
  //! @brief return \f$\pi/3\f$.
  //! @{
  //!   @var pio_3
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
  //!      template<concepts::polyfloat_like T> constexpr auto pio_3(eve::as<T> z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: [Type wrapper](@ref eve::as) of the type of the constant.
  //!
  //!   **Return value**
  //!
  //!     Returns the pio_3 value as T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/math/pio_3.cpp}
  //======================================================================================================================

  inline constexpr auto pio_3 = eve::functor<pio_3_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
