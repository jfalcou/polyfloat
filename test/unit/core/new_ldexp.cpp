//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>
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

template<eve::integral_value N, typename Z> constexpr auto my_exp2n(N const& n, eve::as<Z>) noexcept
{
  if constexpr (eve::scalar_value<N>)
  {
    using c_t = plf::as_component_type_t<Z>;
    using e_t = eve::element_type_t<Z>;
    using u_t = eve::underlying_type_t<e_t>;
    using i_t = eve::as_wide_as_t<N, Z>;
    std::cout << "i_t " << toto::typename_<i_t> << std::endl;
    std::cout << "Z   " << toto::typename_<Z> << std::endl;
    auto wn = i_t(n);
    std::cout << "wn " << wn << std::endl;
    auto bits = (wn + eve::maxexponent(eve::as<u_t>())) << eve::nbmantissabits(eve::as<u_t>());
    auto r = eve::bit_cast(bits, eve::as(Z()));
    return r;
    //     auto bits = (wn + eve::maxexponent(eve::as<u_t>())) << eve::nbmantissabits(eve::as<u_t>());
    //     std::cout << std::endl << " bits "<< bits << std::endl;
    //     auto r = eve::bit_cast(bits, eve::as<Z>());
    //     std::cout << "r " << r << std::endl;
  }
  else
  {
    //  using c_t = plf::as_component_type_t<Z>;
    using e_t = eve::element_type_t<Z>;
    using u_t = eve::underlying_type_t<e_t>;
    // using wu_t = eve::as_wide_as_t< u_t, Z>;
    auto bits = (n + eve::maxexponent(eve::as<u_t>())) << eve::nbmantissabits(eve::as<u_t>());
    auto wbits = eve::as_wide_as_t<N, Z>(bits);
    std::cout << std::endl << " bits " << bits << std::endl;
    std::cout << std::endl << "wbits " << wbits << std::endl;
  }
  //  auto r0 = eve::bit_cast(wbits, eve::as(c_t()));
  //  std::cout << "r0 " << r0 << std::endl;

  //   std::cout << bits << std::endl;
  //   std::cout << sizeof(bits) << std::endl;
  //   std::cout << sizeof(c_t) << std::endl;
  //   return Z();
}

auto new_ldexp(auto a, auto n)
{
  return a * plf::exp2n(n, eve::as(a));
};

TTS_CASE_WITH("Check ldexp",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::ldexp;
  {
    using pv_t = plf::polyfloat<T, 2>;
    using wpv_t = eve::wide<pv_t, 2>;
    pv_t pa(a0, a1);
    int n(2);
    //    std::cout << "ldexp(n)    "<<plf::exp2(pv_t(n)) << std::endl;
    //     std::cout << "my_ldexp(n) "<< my_exp2n(n, eve::as(pa)) << std::endl;
    //    std::cout << "n " << n << std::endl;
    std::cout << "my_ldexp(n) " << my_exp2n(n, eve::as<wpv_t>()) << std::endl;
    //    auto nn = eve::as_wide_as_t<int, wpv_t>(n);
    //     wpv_t wpa(pa, pa);
    //     std::cout << "nn " << nn << std::endl;
    //     std::cout << "wpa " << wpa << std::endl;
    //     std::cout << "my_ldexp(n) "<< my_exp2n(nn, eve::as(wpa)) << std::endl;
    //     TTS_EQUAL(ldexp(pa, n), pa * 4);
    //     TTS_EQUAL(ldexp(pa, n), new_ldexp(pa, n));
    //     using wpv_t = eve::wide<pv_t, 2>;
    //     wpv_t wpab(pa, pa);
    //     std::cout << ldexp(wpab, n) << std::endl;
    //     TTS_RELATIVE_EQUAL(ldexp(wpab, n), wpab * 4, tts::epsprec<T>());
    //     TTS_EQUAL(ldexp(wpab, n), new_ldexp(wpab, n));
    //     auto e = plf::exponent(wpab);
    //     std::cout << tts::typename_<decltype(e)> << std::endl;
    //     std::cout << tts::typename_<decltype(wpab)> << std::endl;
    //     std::cout << ldexp(wpab, -e) << std::endl;
    //     std::cout << new_ldexp(wpab, -e) << std::endl;
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    auto n = 2;
    TTS_EQUAL(ldexp(pa, n), pa * 4);
  }
};
