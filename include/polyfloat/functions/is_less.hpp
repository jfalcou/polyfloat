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
#include <polyfloat/functions/abs.hpp>

namespace plf
{

  template<typename Options> struct is_less_t : eve::strict_tuple_callable<is_less_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1,  concepts::polyfloat_like Z2>
      POLYFLOAT_FORCEINLINE constexpr  eve::as_logical_t<as_polyfloat_like_t<Z1, Z2>>
    operator()(Z1 z1, Z2 z2) const noexcept
    {
     return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_less_t, is_less_);
  };
  //======================================================================================================================
  //! @addtogroup functions
  //! @{
  //!   @var is_less
  //!   @brief return the is_lessance value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <kyosu/functions.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace kyosu
  //!   {
  //!      template<kyosu::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto is_less(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the is_lessolute value of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/is_less.cpp}
  //======================================================================================================================

  inline constexpr auto is_less = eve::functor<is_less_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z1, typename Z2, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_less_(POLYFLOAT_DELAY(), O const& , Z1 const& z1, Z2 const& z2) noexcept
  {
    using plf_t = as_polyfloat_t<Z1, Z2>;
    using u_t = eve::element_type_t<plf_t>;
    auto cvt = [](auto a){ return plf::convert(a, as<u_t>());};
    return cvt(z1) < cvt(z2);
  }
}
