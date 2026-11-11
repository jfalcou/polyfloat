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
  struct cos_1_t : plf::constant_callable<cos_1_t, eve::cos_1_t, Options, lower_option, upper_option>
  {
    template<typename T> POLYFLOAT_ABI static constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_pair<u_t>(0x1.14a2800000000p-1, 0x1.f6a0d20000000p-26);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<u_t>(0x1.14a280fb5068cp-1, -0x1.b71edcc9344bcp-55);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.14a2800000000p-1, 0x1.f6a0d20000000p-26, -0x1.1b71ee0000000p-51);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<u_t>(0x1.14a280fb5068cp-1, -0x1.b71edcc9344bcp-55, -0x1.c85acbb918aedp-109);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_ABI constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(cos_1_t, cos_1_);
  };
  //======================================================================================================================
  //! @defgroup plf_cos_1 plf::cos_1
  //! @ingroup constants
  //! @brief return \f$\cos 1\f$.
  //! @{
  //!   @var cos_1
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
  //!      template<concepts::polyfloat_like T> constexpr auto cos_1(eve::as<T> z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: [Type wrapper](@ref eve::as) of the type of the constant.
  //!
  //!   **Return value**
  //!
  //!     Returns the cos_1 value as T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/math/cos_1.cpp}
  //======================================================================================================================

  inline constexpr auto cos_1 = eve::functor<cos_1_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
