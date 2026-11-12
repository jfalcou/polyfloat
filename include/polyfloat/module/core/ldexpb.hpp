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
#include <polyfloat/module/core/three_add.hpp>
#include <polyfloat/details/inner_graillat.hpp>
// namespace toto
// {
//   template<typename T> struct typename_impl
//   {
//     static auto value() noexcept
//     {
// #if defined(_MSC_VER)
//       std::string_view data(__FUNCSIG__);
//       auto i = data.find('<') + 1, j = data.find(">::value");
//       auto name = data.substr(i, j - i);
// #else
//       std::string_view data(__PRETTY_FUNCTION__);
//       auto i = data.find('=') + 2, j = data.find_last_of(']');
//       auto name = data.substr(i, j - i);
// #endif
//       return std::string(name.data(), name.size());
//     }
//   };

//   template<typename T> inline auto const typename_ = typename_impl<T>::value();
//   template<typename T> constexpr auto name(T const&)
//   {
//     return typename_<T>;
//   }
// }

namespace plf
{

  template<typename Options>
  struct ldexpb_t : plf::callable<ldexpb_t, eve::ldexp_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z, eve::integral_scalar_value N>
    POLYFLOAT_ABI constexpr Z operator()(Z z, N n) const noexcept
    {
      return POLYFLOAT_CALL(z, n);
    }

    template<concepts::polyfloat_like Z, eve::integral_simd_value N>
    POLYFLOAT_ABI constexpr eve::as_wide_as_t<Z, N> operator()(Z z, N n) const noexcept
    {
      return POLYFLOAT_CALL(z, n);
    }

    template<concepts::polyfloat_like Z, concepts::polyfloat_like Z1>
    POLYFLOAT_ABI constexpr plf::as_polyfloat_t<Z, Z1> operator()(Z z, Z1 n) const noexcept
    requires(!eve::integral_value<Z1>)
    {
      return POLYFLOAT_CALL(z, n);
    }

    POLYFLOAT_CALLABLE_OBJECT(ldexpb_t, ldexpb_);
  };

  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var ldexpb
  //!   @brief computes \f$\textstyle x 2^n\f$.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <eve/module/module/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace eve
  //!   {
  //!      // Regular overload
  //!      constexpr auto ldexpb(polyfloat_like auto x, value N)                           noexcept; // 1
  //!
  //!      // Lanes masking
  //!      constexpr auto ldexpb[conditional_expr auto c](polyfloat_like auto x), value N) noexcept; // 2
  //!      constexpr auto ldexpb[logical_value auto m](polyfloat_like auto x, value N)     noexcept; // 2
  //!
  //!      // Semantic options
  //!      constexpr auto ldexpb[pedantic](floating_value auto x, integral_value N)        noexcept; // 3
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `x`: [value](@ref eve::value).
  //!     * `c`: [Conditional expression](@ref eve::conditional_expr) masking the operation.
  //!     * `n`: [integral or flint value argument](@ref eve::integral_value).
  //!     * `m`: [Logical value](@ref eve::logical_value) masking the operation.
  //!
  //!    **Return value**
  //!
  //!     1. The value of \f$\textstyle x 2^n\f$ is returned.
  //!     2. [The operation is performed conditionnaly](@ref conditional).
  //!     3. Takes extra care to handling limit values.
  //!         * If `x` is \f$\pm0\f$, it is returned, unmodified.
  //!         * If `x` is \f$\pm\infty\f$, it is returned, unmodified.
  //!         * If `n` is 0, then `x` is returned, unmodified.
  //!         * If `x` is NaN, NaN is returned.
  //!
  //!  @groupheader{External references}
  //!   *  [C++ standard reference](https://en.cppreference.com/w/cpp/numeric/math/ldexpb)
  //!
  //!  @groupheader{Example}
  //!  @godbolt_todo{doc/core/ldexpb.cpp}
  //================================================================================================
  inline constexpr auto ldexpb = eve::functor<ldexpb_t>;
  //================================================================================================
  //! @}
  //================================================================================================
}

namespace plf::_
{
  template<typename Z, typename N, eve::callable_options O>
  constexpr auto ldexpb_(POLYFLOAT_DELAY(), O const&, Z const& z, N const& n) noexcept
  {
    if constexpr (eve::scalar_value<N>) return z * plf::hi(exp2n(n, eve::as(z)));
    else if constexpr (eve::scalar_value<Z>)
    {
      auto wz = eve::as_wide_as_t<N, Z>(z);
      return wz * plf::hi(exp2n(n, eve::as(wz)));
    }
    else
    {
      return z * plf::hi(exp2n(n, eve::as(z)));
    }
  }
}
