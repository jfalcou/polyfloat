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
  struct pio_6_t : plf::constant_callable<pio_6_t, eve::pio_6_t, Options, lower_option, upper_option>
  {
    template<typename T> POLYFLOAT_ABI static constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_pair<u_t>(0x1.0c15240000000p-1, -0x1.f4a3260000000p-27);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<u_t>(0x1.0c152382d7366p-1, -0x1.ee6913347c2a6p-55);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.0c15240000000p-1, -0x1.f4a3260000000p-27, -0x1.3dcd220000000p-52);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<u_t>(0x1.0c152382d7366p-1, -0x1.ee6913347c2a6p-55, -0x1.4bba47a9e5fd2p-111);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_ABI constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(pio_6_t, pio_6_);
  };
  //======================================================================================================================
  //! @defgroup plf_pio_6 plf::pio_6
  //! @ingroup constants
  //! @brief return \f$\pi/6\f$.
  //! @{
  //!   @var pio_6
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
  //!      template<concepts::polyfloat_like T> constexpr auto pio_6(eve::as<T> z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: [Type wrapper](@ref eve::as) of the type of the constant.
  //!
  //!   **Return value**
  //!
  //!     Returns the pio_6 value as T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/math/pio_6.cpp}
  //======================================================================================================================

  inline constexpr auto pio_6 = eve::functor<pio_6_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
