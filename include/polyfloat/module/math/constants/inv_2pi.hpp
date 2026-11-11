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
  struct inv_2pi_t : plf::constant_callable<inv_2pi_t, eve::inv_2pi_t, Options, lower_option, upper_option>
  {
    template<typename T> POLYFLOAT_ABI static constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_pair<u_t>(0x1.45f3060000000p-3, 0x1.b939100000000p-28);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<u_t>(0x1.45f306dc9c883p-3, -0x1.6b01ec5417056p-57);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.45f3060000000p-3, 0x1.b939100000000p-28, 0x1.529fc20000000p-54);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<u_t>(0x1.45f306dc9c883p-3, -0x1.6b01ec5417056p-57, -0x1.6447e493ad4cep-111);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_ABI constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(inv_2pi_t, inv_2pi_);
  };
  //======================================================================================================================
  //! @defgroup plf_inv_2pi plf::inv_2pi
  //! @ingroup constants
  //! @brief return \f$1/(2\pi)\f$.
  //! @{
  //!   @var inv_2pi
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
  //!      template<concepts::polyfloat_like T> constexpr auto inv_2pi(eve::as<T> z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: [Type wrapper](@ref eve::as) of the type of the constant.
  //!
  //!   **Return value**
  //!
  //!     Returns the inv_2pi value as T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/math/inv_2pi.cpp}
  //======================================================================================================================

  inline constexpr auto inv_2pi = eve::functor<inv_2pi_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
