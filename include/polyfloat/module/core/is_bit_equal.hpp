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

  template<typename Options>
  struct is_bit_equal_t : eve::callable<is_bit_equal_t, Options, raw_option, pedantic_option, numeric_option>
  {
    //     template <typename T, typename U > using  b_t = bit_value_t<T, U>;
    //     template <typename T, typename U > using  ui_t = as_integer_t<b_t<T, U>, unsigned>;

    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr auto operator()(Z z1, Z z2) const noexcept
      -> decltype(eve::is_bit_equal(hi(z1), hi(z2)))
    {
      return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_bit_equal_t, is_bit_equal_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var is_bit_equal
  //!   @brief returns a logical true  if and only if the element bits are all equal.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto is_bit_equal(T z1, T z2)  noexcept
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2` : Values to process.
  //!
  //!   **Return value**
  //!
  //!     Returns true  the element bits of `z1` and `z2`are all equal.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/is_bit_equal.cpp}
  //======================================================================================================================

  inline constexpr auto is_bit_equal = eve::functor<is_bit_equal_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_bit_equal_(POLYFLOAT_DELAY(), O const&, Z const& z1, Z const& z2) noexcept
  {
    if constexpr (dimension_v<Z> == 1) return eve::is_bit_equal(z1, z2);
    else if constexpr (dimension_v<Z> == 2)
      return eve::is_bit_equal(lo(z1), lo(z2)) && eve::is_bit_equal(hi(z1), hi(z2));
    else if constexpr (dimension_v<Z> == 3)
      return eve::is_bit_equal(lo(z1), lo(z2)) && eve::is_bit_equal(md(z1), md(z2)) &&
             eve::is_bit_equal(hi(z1), hi(z2));
  }
}
