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
#include <eve/module/math/constant/invlog_10.hpp>

namespace plf
{

  template<typename Options>
  struct invlog_10_t : plf::constant_callable<invlog_10_t, eve::invlog_10_t, Options, lower_option, upper_option>
  {
    template<typename T> POLYFLOAT_ABI static constexpr T value(eve::as<T> const&, auto const&)
    {
      using u_t = plf::as_component_type_t<T>;
      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>) return plf::_::from_pair<float>(0x1.bcb7b2p-2, -0x1.5b235ep-27);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<double>(0x1.bcb7b1526e50ep-2, 0x1.95355baaafad3p-57);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<float>(0x1.bcb7b2p-2, -0x1.5b235ep-27, -0x1.cd5954p-54);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<double>(0x1.bcb7b1526e50ep-2, 0x1.95355baaafad3p-57, 0x1.ee191f71a3012p-112);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_ABI constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(invlog_10_t, invlog_10_);
  };
  //======================================================================================================================
  //! @defgroup plf_invlog_10 plf::invlog_10
  //! @ingroup constants
  //! @brief return the inverse of \f$\log 10\f$.
  //! @{
  //!   @var invlog_10
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
  //!   namespace kyosu
  //!   {
  //!      template<plf::concepts::polyfloat_like T> constexpr auto invlog_10(eve::as<T> z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!
  //!   **Return value**
  //!
  //!     Returns \f$1/\log 10\f$.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/math/invlog_10.cpp}
  //======================================================================================================================

  inline constexpr auto invlog_10 = eve::functor<invlog_10_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
