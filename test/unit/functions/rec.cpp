//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

// auto mini = tts::constant([]<typename T>(eve::as<T> const&)
//                           { return  -eve::sqrtvalmax(eve::as<T>()); };

TTS_CASE_WITH("Check rec",
              plf::scalar_real_types,
              tts::randoms(eve::zero, eve::sqrtvalmax),
              tts::randoms(eve::zero, eve::sqrtvalmax),
              tts::randoms(eve::zero, eve::sqrtvalmax)
            )
<typename T>(T const& a0, T const& a1, T const& a2)
{
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pr = plf::rec(pa);
    auto cvtd = [](auto a){ return eve::convert(a, eve::as<double>());};
    auto cvtld= [](auto a){ return (long double)(a); };
    if constexpr(std::same_as<T, float>)
    {
      auto dpa  = cvtd(plf::hi(pa))+cvtd(plf::md(pa))+cvtd(plf::lo(pa));
      auto dpr  = cvtd(plf::hi(pr))+cvtd(plf::md(pr))+cvtd(plf::lo(pr));
      TTS_RELATIVE_EQUAL( dpr, eve::rec(dpa), 1.0e-5);
    }
    else if constexpr(std::same_as<T, double>)
    {
      auto dpa  = cvtld(plf::hi(pa))+cvtld(plf::md(pa))+cvtld(plf::lo(pa));
      auto dpr  = cvtld(plf::hi(pr))+cvtld(plf::md(pr))+cvtld(plf::lo(pr));
      TTS_RELATIVE_EQUAL( dpr, (long double)(1)/(dpa), 1.0e-14);
    }
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pr = plf::rec(pa);
    auto cvtd = [](auto a){ return eve::convert(a, eve::as<double>());};
    auto cvtld= [](auto a){ return (long double)(a); };
    if constexpr(std::same_as<T, float>)
    {
      auto dpa  = cvtd(plf::hi(pa))+cvtd(plf::md(pa))+cvtd(plf::lo(pa));
      auto dpr  = cvtd(plf::hi(pr))+cvtd(plf::md(pr))+cvtd(plf::lo(pr));
      TTS_RELATIVE_EQUAL( eve::rec(dpa), dpr, 1.0e-12);
    }
    else if constexpr(std::same_as<T, double>)
    {
      auto dpa  = cvtld(plf::hi(pa))+cvtld(plf::md(pa))+cvtld(plf::lo(pa));
      auto dpr  = cvtld(plf::hi(pr))+cvtld(plf::md(pr))+cvtld(plf::lo(pr));
      TTS_RELATIVE_EQUAL(dpr, (long double)(1)/(dpa), 1.0e-16);
    }
  }
};


template<auto N, typename T>
void perform_test(T pa,  T rpa)
{
  using  mpfr::mpreal;
  mpreal::set_default_prec(N);
  auto mpa = tts::to_mpreal(pa);
  auto mrpa= tts::to_mpreal(rpa);
  std::cout << (mpa)    << " -- " << (pa)                       << std::endl;
  std::cout << (mrpa)   << " -- " << (rpa)                      << std::endl;
  std::cout << tts::typename_<decltype(pa)> << std::endl;
  std::cout << "N " << N                  << std::endl;
  std::cout << "dim " << plf::dimension_v<T> << std::endl;
  std::cout << "d " << (1/mpa - mrpa) << std::endl;
  std::cout << "r " << mpfr::abs (1/mpa - mrpa)/mpfr::max(mpfr::abs(mpa), 1)<< std::endl;
  TTS_EXPECT( mpfr::abs(1/mpa - mrpa) < tts::epsprec<T>()*mpfr::max(mpfr::abs(mpa), 1));
 std::cout << " ============================================ " << std::endl;
}


TTS_CASE_WITH("Check rec",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax)
             )
  <typename T>(T const& a0, T const& a1, T const& a2)
{
  using  mpfr::mpreal;
  {
    {
      using pv_t  = plf::polyfloat<T, 2>;
      constexpr auto N = tts::bitprec<pv_t>();
      pv_t pa(a0);
      pv_t rpa = plf::rec(pa);
      perform_test<N>(pa, rpa);
    }
    {
      using pv_t  = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      pv_t rpa = plf::rec(pa);
      constexpr auto N = tts::bitprec<pv_t>();
      perform_test<N>(pa, rpa);
    }
  }
};
