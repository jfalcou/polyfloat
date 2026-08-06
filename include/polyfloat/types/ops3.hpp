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
    POLYFLOAT_FORCEINLINE eve::common_logical_t<as_component_type_t<T1>, as_component_type_t<T2>>
  operator <(T1 const& aa, T2 const& bb) noexcept
  {
    constexpr auto  N = dimension_v<as_polyfloat_t<T1, T2>>;
    using plf_t = as_polyfloat_t<T1, T2>;
    using u_t = eve::element_type_t<plf_t>;
    auto cvt = [](auto a){ return plf::convert(a, as<u_t>());};
    plf_t a(cvt(aa));
    plf_t b(cvt(bb));
    if constexpr(N == 2)
    {
      auto th0 = hi(a) <  hi(b);
      auto th1 = hi(a) == hi(b);
      auto tl0 = lo(a) <  lo(b);
      return  th0 || (th1 && tl0);
    }
    else if constexpr(N == 3)
    {
      auto th0 = hi(a) <  hi(b);
      auto th1 = hi(a) == hi(b);
      auto tm0 = md(a) <  md(b);
      auto tm1 = md(a) == md(b);
      auto tl0 = lo(a) <  lo(b);
      return  th0 || (th1 && tm0) || (th1 && tm1 && tl0);
    }
  }

  template<eve::value T1, eve::value T2>
  requires(concepts::polyfloat<T1> || concepts::polyfloat<T2>)
  POLYFLOAT_FORCEINLINE eve::common_logical_t<as_component_type_t<T1>, as_component_type_t<T2>>
  operator > (T1 const& aa, T2 const& bb) noexcept
  {
    constexpr auto  N = dimension_v<as_polyfloat_t<T1, T2>>;
    using plf_t = as_polyfloat_t<T1, T2>;
    using u_t = eve::element_type_t<plf_t>;
    auto cvt = [](auto a){ return plf::convert(a, as<u_t>());};
    plf_t a(cvt(aa));
    plf_t b(cvt(bb));
    if constexpr(N == 2)
    {
      auto th0 = hi(a) >  hi(b);
      auto th1 = hi(a) == hi(b);
      auto tl0 = lo(a) >  lo(b);
      return  th0 || (th1 && tl0);
    }
    else if constexpr(N == 3)
    {
      auto th0 = hi(a) >  hi(b);
      auto th1 = hi(a) == hi(b);
      auto tm0 = md(a) >  md(b);
      auto tm1 = md(a) == md(b);
      auto tl0 = lo(a) >  lo(b);
      return  th0 || (th1 && tm0) || (th1 && tm1 && tl0);
    }
  }

  template<eve::value T1, eve::value T2>
  requires(concepts::polyfloat<T1> || concepts::polyfloat<T2>)
  POLYFLOAT_FORCEINLINE eve::common_logical_t<as_component_type_t<T1>, as_component_type_t<T2>>
  operator <= (T1 const& aa, T2 const& bb) noexcept
  {
    constexpr auto  N = dimension_v<as_polyfloat_t<T1, T2>>;
    using plf_t = as_polyfloat_t<T1, T2>;
    using u_t = eve::element_type_t<plf_t>;
    auto cvt = [](auto a){ return plf::convert(a, as<u_t>());};
    plf_t a(cvt(aa));
    plf_t b(cvt(bb));
    if constexpr(N == 2)
    {
      auto th0 = hi(a) <= hi(b);
      auto th1 = hi(a) == hi(b);
      auto tl0 = lo(a) <= lo(b);
      return  th0 || (th1 && tl0);
    }
    else if constexpr(N == 3)
    {
      auto th0 = hi(a) <=  hi(b);
      auto th1 = hi(a) == hi(b);
      auto tm0 = md(a) <= md(b);
      auto tm1 = md(a) == md(b);
      auto tl0 = lo(a) <= lo(b);
      return  th0 || (th1 && tm0) || (th1 && tm1 && tl0);
    }
  }

  template<eve::value T1, eve::value T2>
  requires(concepts::polyfloat<T1> || concepts::polyfloat<T2>)
  POLYFLOAT_FORCEINLINE eve::common_logical_t<as_component_type_t<T1>, as_component_type_t<T2>>
  operator >= (T1 const& aa, T2 const& bb) noexcept
  {
    constexpr auto  N = dimension_v<as_polyfloat_t<T1, T2>>;
    using plf_t = as_polyfloat_t<T1, T2>;
    using u_t = eve::element_type_t<plf_t>;
    auto cvt = [](auto a){ return plf::convert(a, as<u_t>());};
    plf_t a(cvt(aa));
    plf_t b(cvt(bb));
    if constexpr(N == 2)
    {
      auto th0 = hi(a) >= hi(b);
      auto th1 = hi(a) == hi(b);
      auto tl0 = lo(a) >= lo(b);
      return  th0 || (th1 && tl0);
    }
    else if constexpr(N == 3)
    {
      auto th0 = hi(a) >=  hi(b);
      auto th1 = hi(a) == hi(b);
      auto tm0 = md(a) >= md(b);
      auto tm1 = md(a) == md(b);
      auto tl0 = lo(a) >= lo(b);
      return  th0 || (th1 && tm0) || (th1 && tm1 && tl0);
    }
  }

  //====================================================================================================================
  //! @}
  //====================================================================================================================
}
