//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once
#include <eve/eve.hpp>
#include <polyfloat/polyfloat.hpp>
#include <polyfloat/module/core/convert.hpp>
#include <polyfloat/module/core/if_else.hpp>
#include <polyfloat/module/core/oneminus.hpp>
#include <polyfloat/module/core/is_normalized.hpp>
#include <polyfloat/types/triple_real.hpp>
#include <polyfloat/types/double_real.hpp>
#include <polyfloat/details/plus_equal.hpp>
#include <polyfloat/details/mul_equal.hpp>

namespace toto
{
  template<typename T> struct typename_impl
  {
    static auto value() noexcept
    {
#if defined(_MSC_VER)
      std::string_view data(__FUNCSIG__);
      auto i = data.find('<') + 1, j = data.find(">::value");
      auto name = data.substr(i, j - i);
#else
      std::string_view data(__PRETTY_FUNCTION__);
      auto i = data.find('=') + 2, j = data.find_last_of(']');
      auto name = data.substr(i, j - i);
#endif
      return std::string(name.data(), name.size());
    }
  };

  template<typename T> inline auto const typename_ = typename_impl<T>::value();
  template<typename T> constexpr auto name(T const&)
  {
    return typename_<T>;
  }
}

namespace plf
{
  using _::fasttwoadd;
  using _::twoadd;
  //====================================================================================================================
  //! @name Compound Assignment Operators
  //! @related polyfloat
  //! @{
  //====================================================================================================================

  /// Adds the polyfloat value `other` to `self` and returns the new value of `self`.
  template<concepts::polyfloat T1, concepts::polyfloat_like T2>
  constexpr auto& operator+=(T1& self, T2 other) noexcept
  requires(dimension_v<T1> >= dimension_v<T2>)
  {
    if constexpr (eve::integral_value<T2>) return self += eve::convert(other, eve::as(eve::underlying_type_t<T1>()));
    else
    {
      return _::plus_equal(self, other);
    }
  }

  /// Subtracts the polyfloat value `other` from `self` and returns the new value of `self`.
  template<concepts::polyfloat T1, concepts::polyfloat_like T2>
  constexpr auto& operator-=(T1& self, T2 other) noexcept
  requires(dimension_v<T1> >= dimension_v<T2>)
  {
    return _::plus_equal(self, -other); //self += -other;
  }

  /// Multiply the polyfloat value `other` to `self` and returns the new value of `self`.
  template<concepts::polyfloat T1, concepts::polyfloat_like T2>
  constexpr T1& operator*=(T1& self, T2 other) noexcept
  requires(dimension_v<T1> >= dimension_v<T2>)
  {
    if constexpr (eve::integral_value<T2>) return self *= eve::convert(other, eve::as(eve::underlying_type_t<T1>()));
    else
    {
      //     T1 oth{plf::convert(other, eve::as<eve::element_type_t<T1>>())};
      return _::mul_equal(self, other);
    }
  }
}

#include <polyfloat/types/ops1.hpp> //define +, -, *, / * is used by plf::rec and /=

namespace plf
{

  namespace _
  {
    template<concepts::polyfloat_like T> auto rec(T a) noexcept
    {
      if constexpr (dimension_v<T> == 1 && std::is_floating_point_v<T>) return eve::rec[pedantic](a);
      else
      {
        a = eve::if_else(eve::is_denormal(hi(a)), T(hi(a) * eve::zero(as(hi(a)))), a);
        auto correct = [&a](auto x) {
          auto a0 = plf::hi(a);
          x = plf::if_else(eve::is_infinite(a0), T(eve::copysign(eve::zero(eve::as(a0)), a0)), x);
          return plf::if_else(eve::is_eqz(a0), T(eve::copysign(eve::inf(eve::as(a0)), a0)), x);
        };
        if constexpr (dimension_v<T> == 2)
        {
          auto a0 = plf::hi(a);
          auto x0 = eve::rec[pedantic](a0);
          auto x1 = x0 + x0 * plf::oneminus(a * x0);
          return correct(x1);
        }
        else if constexpr (dimension_v<T> == 3)
        {
          auto a0 = plf::_::from_pair(plf::hi(a), plf::md(a));
          auto x0 = plf::_::rec(a0);
          auto x1 = x0 + x0 * plf::oneminus(a * x0);
          return correct(x1);
        }
      }
      // ok aussi mais est-ce plus rapide ?
      //         auto a0 = plf::hi(a);
      //         auto correct =  [&a0](auto x){
      //           x = plf::if_else(eve::is_infinite(a0), T(eve::copysign(eve::zero(eve::as(a0)), a0)), x);
      //           return plf::if_else(eve::is_eqz(a0), T(eve::copysign(eve::inf(eve::as(a0)), a0)), x);
      //         };
      //         auto x0 = eve::rec[pedantic](a0);
      //         auto x1 = x0 + x0* plf::oneminus(a*x0);
      //         if constexpr (dimension_v<T> == 2) return correct(x1);
      //         x1 = x1 + x1* plf::oneminus(a*x1);
      //         x1 = x1 + x1* plf::oneminus(a*x1);
      //         return correct(x1);
      //       }

      // original
      //      else if constexpr (dimension_v<T> == 2)
      //       {
      //         auto [a0, b0] = a;
      //         auto x0 = eve::rec[pedantic](a0);
      //         auto x1 = x0 + x0 * (T(1) - a * x0);
      //         x1 = plf::if_else(eve::is_infinite(hi(a)), T(eve::copysign(eve::zero(eve::as(hi(a))), plf::hi(a))), x1);
      //         return if_else(eve::is_eqz(hi(a)), T(eve::copysign(eve::inf(eve::as(hi(a))), plf::hi(a))), x1);
      //       }
      //       else if constexpr (dimension_v<T> == 3)
      //       {
      //         auto [a0, b0, c0] = a;
      //         auto x0 = eve::rec[pedantic](a0);
      //         auto x1 = x0 + x0 * (T(1) - a * x0);
      //         auto x2 = x1 + x1 * (T(1) - a * x1);
      //         auto x3 = x2 + x2 * (T(1) - a * x2);
      //         x3 = plf::if_else(eve::is_infinite(hi(a)), T(eve::copysign(eve::zero(eve::as(hi(a))), plf::hi(a))), x3);
      //         return if_else(eve::is_eqz(hi(a)), T(eve::copysign(eve::inf(eve::as(hi(a))), plf::hi(a))), x3);
      //       }
    }
  }

  /// Divide  `self` by the  value `other` and returns the new value of `self`.
  template<concepts::polyfloat T1, concepts::polyfloat_like T2> constexpr auto& operator/=(T1& self, T2 other) noexcept
  {
    T1 oth{plf::convert(other, eve::as<eve::element_type_t<T1>>())};
    auto deno = eve::is_denormal(hi(oth));
    if (eve::none(deno)) return self *= _::rec(oth);
    else
    {
      auto a = self * _::rec(oth);
      auto b = T1(hi(self) / hi(oth));
      auto test = deno && eve::is_infinite(hi(a));
      return self = plf::if_else(test, b, a);
    }
    EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of /= is not normalized");
    return self;
  }
}

#include <polyfloat/types/ops2.hpp>
