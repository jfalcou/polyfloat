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
  struct invcbrt_pi_t : plf::constant_callable<invcbrt_pi_t, eve::invcbrt_pi_t, Options, lower_option, upper_option>
  {
    template<typename T> POLYFLOAT_ABI static constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_pair<u_t>(0x1.5d95e00000000p-1, -0x1.285aa20000000p-26);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<u_t>(0x1.5d95df6bd2aeep-1, -0x1.9749756e80c72p-55);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.5d95e00000000p-1, -0x1.285aa20000000p-26, -0x1.32e92e0000000p-52);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<u_t>(0x1.5d95df6bd2aeep-1, -0x1.9749756e80c72p-55, -0x1.279bb37a6148fp-109);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_ABI constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(invcbrt_pi_t, invcbrt_pi_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var invcbrt_pi
  //!   @brief return \f$1/\sqrt[3]\pi\f$.
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
  //!      template<concepts::polyfloat_like T> constexpr auto invcbrt_pi(eve::as<T> z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: [Type wrapper](@ref eve::as) of the type of the constant.
  //!
  //!   **Return value**
  //!
  //!     Returns the invcbrt_pi value as T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/math/invcbrt_pi.cpp}
  //======================================================================================================================

  inline constexpr auto invcbrt_pi = eve::functor<invcbrt_pi_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
