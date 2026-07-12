//======================================================================================================================
/*
  POLYFLOAT - Extended precision floating points
  Copyright : POLYFLOAT Contributors & Maintainers
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once
#include <eve/eve.hpp>
#include <polyfloat/functions/parts.hpp>
namespace plf
{

  //====================================================================================================================
  //! @}
  //====================================================================================================================

  //====================================================================================================================
  //! @name Binary Operators  <  <=  >  >=
  //! @{
  //====================================================================================================================

  template<eve::value T1, eve::value T2>
  requires(concepts::polyfloat<T1> || concepts::polyfloat<T2>)
  POLYFLOAT_FORCEINLINE eve::common_logical_t<as_real_type_t<T1>, as_real_type_t<T2>>
  operator <(T1 const& a, T2 const& b) noexcept
  {
    // is it better to return is_ltz(a-b) ?
    constexpr auto N = dimension_v<eve::common_logical_t<as_real_type_t<T1>>>;
    auto r1 =  (hi(a) < hi(b));
    if constexpr(N == 1) return r1;
    else
    {
      auto r2 =  (hi(a) ==  hi(b)) && (md(a) <  md(b));
      if constexpr(N == 2) return r1 || r2;
      else
      {
        auto r3 = (hi(a) == hi(b)) && (md(a) == md(b)) && (lo(a) <  lo(b));
        return r1 || r2 || r3;
      };
    }
  }

  template<eve::value T1, eve::value T2>
  requires(concepts::polyfloat<T1> || concepts::polyfloat<T2>)
  POLYFLOAT_FORCEINLINE eve::common_logical_t<as_real_type_t<T1>, as_real_type_t<T2>>
  operator > (T1 const& a, T2 const& b) noexcept
  {
    return hi(a) >  hi(b);
  }

  template<eve::value T1, eve::value T2>
  requires(concepts::polyfloat<T1> || concepts::polyfloat<T2>)
  POLYFLOAT_FORCEINLINE eve::common_logical_t<as_real_type_t<T1>, as_real_type_t<T2>>
  operator <= (T1 const& a, T2 const& b) noexcept
  {
    return hi(a) <= hi(b);
  }

  template<eve::value T1, eve::value T2>
  requires(concepts::polyfloat<T1> || concepts::polyfloat<T2>)
  POLYFLOAT_FORCEINLINE eve::common_logical_t<as_real_type_t<T1>, as_real_type_t<T2>>
  operator >= (T1 const& a, T2 const& b) noexcept
  {
    return hi(a) >=  hi(b);
  }

  //====================================================================================================================
  //! @}
  //====================================================================================================================
}
