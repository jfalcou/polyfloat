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
#include <polyfloat/module/core/cumfun.hpp>

namespace plf
{

  template<typename Options>
  struct cumsum_t : eve::strict_tuple_callable<cumsum_t, Options, raw_option, pedantic_option>
  {
    template<typename T> using return_type = T;

    template<typename... Ts>
    using result = kumi::result::fill_t<sizeof...(Ts), return_type<plf::as_polyfloat_like_t<Ts...>>>;

    template<eve::product_type Tup>
    using tuple_result = kumi::result::fill_t<Tup::size(), return_type<kumi::apply_traits_t<as_polyfloat_like, Tup>>>;

    template<concepts::polyfloat_like... Zs>
    POLYFLOAT_FORCEINLINE result<Zs...> constexpr operator()(Zs const&... zs) const noexcept
    {
      return POLYFLOAT_CALL(zs...);
    }

    template<eve::non_empty_product_type PT>
    POLYFLOAT_FORCEINLINE constexpr tuple_result<PT> operator()(PT t) const noexcept
    {
      return POLYFLOAT_CALL(t);
    }

    POLYFLOAT_CALLABLE_OBJECT(cumsum_t, cumsum_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var cumsum
  //!   @brief convert a pack of values into
  //!     a tuple of the cumulative sum of its values
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/module/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!      // Regular overloads
  //!      constexpr auto cumsum(auto ... xs)                noexcept; // 1
  //!      constexpr auto cumsum(non_empty_product_type tup) noexcept; // 2
  //!
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `xs...`: [polyfloat like](@ref plf::polyfloat_like) arguments.
  //!     * `tup`: kumi tuple of values.
  //!
  //!    **Return value**
  //!
  //!     1. return a kumi tuple of the values of the cumulated sums of all `xs` converted to
  //!         the element type of the common polyfloat like value of the `xs`.
  //!     2. same as 1., using the tuple elements.
  //!
  //!  @note currently cumsum can only be applied with `f` being one of these POLYFLOAT sumctors :
  //!   `add`, `mul`, `min`, `max` that define abelian monoids and each possess
  //!   `a well defined neutral element.
  //!
  //!  @groupheader{Example}
  //!  @godbolt{doc/core/cumsum.cpp}
  //================================================================================================
  inline constexpr auto cumsum = eve::functor<cumsum_t>;
  //================================================================================================
  //! @}
  //================================================================================================
}

namespace plf::_
{
  template<eve::product_type PT, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto cumsum_(POLYFLOAT_DELAY(), O const& o, PT tup) noexcept
  {
    return plf::cumfun[o](plf::add, tup);
  }

  template<typename... Ts, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto cumsum_(POLYFLOAT_DELAY(), O const& o, Ts... ts) noexcept
  {
    return plf::cumfun[o](plf::add, kumi::make_tuple(ts...));
  }
}
