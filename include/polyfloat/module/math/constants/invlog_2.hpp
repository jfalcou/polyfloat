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

  template<typename Options> struct invlog_2_t : eve::constant_callable<invlog_2_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr T value(eve::as<T> const&, auto const&)
    {
      using u_t = plf::as_component_type_t<T>;
      if constexpr (plf::dimension_v<T> == 1)
      {
        if constexpr (std::same_as<u_t, float>) return float(0x1.62e43p-1);
        else if constexpr (std::same_as<u_t, double>) return double(0x1.62e42fefa39efp-1);
      }
      else if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>) return plf::_::from_pair<float>(0x1.715476p+0, 0x1.4ae0cp-26);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<double>(0x1.71547652b82fep+0, 0x1.777d0ffda0d24p-56);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<float>(0x1.715476p+0, 0x1.4ae0cp-26, -0x1.e8883p-52);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<double>(0x1.71547652b82fep+0, 0x1.777d0ffda0d24p-56, -0x1.60bb8a5442ab9p-110);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(invlog_2_t, invlog_2_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var invlog_2
  //!   @brief return the log(2) inverse value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/math.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace polyfloat
  //!   {
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto invlog_2(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!
  //!   **Return value**
  //!
  //!     Returns the inverse of log(2).
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/invlog_2.cpp}
  //======================================================================================================================

  inline constexpr auto invlog_2 = eve::functor<invlog_2_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
