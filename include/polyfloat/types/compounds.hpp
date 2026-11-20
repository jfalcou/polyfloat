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
        using u_t = eve::element_type_t<T>;
        constexpr u_t t(2);

        if constexpr (dimension_v<T> == 2)
        {
          auto a0 = plf::hi(a);
          auto x0 = eve::rec[pedantic](a0);
          auto x1 = x0 * (t - a * x0);
          return correct(x1);
        }
        else if constexpr (dimension_v<T> == 3)
        {
          auto a0 = plf::_::from_pair(plf::hi(a), plf::md(a));
          auto x0 = plf::_::rec(a0);
          auto x1 = x0 * (t - a * x0);
          return correct(x1);
        }
      }
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
