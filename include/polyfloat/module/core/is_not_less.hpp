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

  template<typename Options> struct is_not_less_t : eve::strict_tuple_callable<is_not_less_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1,  concepts::polyfloat_like Z2>
      POLYFLOAT_FORCEINLINE constexpr  eve::as_logical_t<as_polyfloat_like_t<Z1, Z2>>
    operator()(Z1 z1, Z2 z2) const noexcept
    {
     return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_not_less_t, is_not_less_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var is_not_less
  //!   @brief return true iff !(z1 < z2)
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
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto is_not_less(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns true iff !(z1 < z2).
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/is_not_less.cpp}
  //======================================================================================================================

  inline constexpr auto is_not_less = eve::functor<is_not_less_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z1, typename Z2, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_not_less_(POLYFLOAT_DELAY(), O const& , Z1 const& z1, Z2 const& z2) noexcept
  {
    using plf_t = as_polyfloat_t<Z1, Z2>;
    using u_t = eve::element_type_t<plf_t>;
    auto cvt = [](auto a){ return plf::convert(a, as<u_t>());};
    return !(cvt(z1) < cvt(z2));
  }
}
