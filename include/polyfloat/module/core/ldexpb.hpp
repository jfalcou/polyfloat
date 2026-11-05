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
    template<concepts::polyfloat_like Z1, eve::integral_value N>
    POLYFLOAT_ABI constexpr eve::as_wide_as_t<Z1, N> operator()(Z1 z1, N n) const noexcept
    {
      using r_t = eve::element_type_t<decltype(hi(Z1()))>;
      //      auto r =
      return POLYFLOAT_CALL(z1, eve::convert(n, eve::as<r_t>()));
      //      std::cout << toto::typename_<decltype(r) > << "\n";
      //      return r;
    }

    template<concepts::polyfloat_like Z, typename N>
    POLYFLOAT_ABI constexpr eve::as_wide_as_t<Z, N> operator()(Z z, N n) const noexcept
    {
      using r_t = eve::element_type_t<as_component_type_t<Z>>;
      //      auto r =
      return POLYFLOAT_CALL(z, plf::convert(n, eve::as<r_t>()));
      //      std::cout << toto::typename_<decltype(r) > << "\n";
      //      return r;
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

// namespace plf::_
// {
//   template<typename Z, typename N, eve::callable_options O>
//   constexpr auto ldexpb_(POLYFLOAT_DELAY(), O const&, Z const& z, N const& n) noexcept
//   {
//     if constexpr (dimension_v<Z> == 2)
//     {
//       auto [zh, zl] = z;
//       auto h = eve::ldexp(zh, n);
//       auto l = eve::ldexpb(zl, n);
//       return Z(h, l);
//     }
//     else if constexpr (dimension_v<Z> == 3)
//     {
//       auto [zh, zm, zl] = z;
//       auto h = eve::ldexpb(zh, n);
//       auto m = eve::ldexpb(zm, n);
//       auto l = eve::ldexpb(zl, n);
// //       Z z(h);
// //       md(z) = m;
// //       lo(z) = l;
//        EVE_ASSERT(eve::all(plf::is_normalized(Z(h, m, l))), "output of ldexpb is not normalized");
// //       return z;
//          return Z(h, m, l);
//     }
//   }

// };

// template<typename Z>
// auto my_is_normalized(Z const& z) noexcept
// {
//   auto eqnum = eve::is_equal[eve::numeric];
//   if constexpr (plf::dimension_v<Z> == 1)
//   {
//     return eve::true_(eve::as(z));
//   }
//   else if constexpr (plf::dimension_v<Z> == 2)
//   {
//     auto [h, l] = z;
//     return eqnum(h + l, h);
//   }
//   else if constexpr (plf::dimension_v<Z> == 3)
//   {
//     auto [h, m, l] = z;
//     return eqnum(h + m, h) && eqnum(m + l, m);
//   }
// }

namespace plf::_
{
  template<typename Z, typename N, eve::callable_options O>
  constexpr auto ldexpb_(POLYFLOAT_DELAY(), O const&, Z const& zz, N const& n) noexcept
  {
    using r_t = eve::as_wide_as_t<Z, N>;
    auto z = r_t(zz);
    if constexpr (dimension_v<Z> == 2)
    {
      auto [zh, zl] = z;
      auto h = eve::ldexp(zh, n);
      auto l = eve::ldexp(zl, n);
      r_t r(h, l);
      EVE_ASSERT(eve::all(inner_is_normalized(r)), "output of ldexpb is not normalized");
      return r;
    }
    else if constexpr (dimension_v<Z> == 3)
    {
      auto [zh, zm, zl] = z;
      auto h = eve::ldexp(zh, n);
      auto m = eve::ldexp(zm, n);
      auto l = eve::ldexp(zl, n);
      auto r = plf::three_add(h, m, l);
      EVE_ASSERT(eve::all(inner_is_normalized(r)), "output of ldexpb is not normalized");
      return r;
    }
  }
}
