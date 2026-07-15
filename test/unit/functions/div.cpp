//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>
#include <iomanip>

// template < typename T > T cvt(mpfr::mpreal mpa, eve::as<T> )
// {
//   using u_t = decltype(plf::hi(T()));
//   using mu_t = decltype(mpa);
//   auto h = u_t(mpa);
//   auto m = u_t(mpa-mu_t(h));
//   if constexpr(plf::dimension_v<T> == 2)
//   {
//     return T(h, m);
//   }
//   else if constexpr(plf::dimension_v<T> == 3)
//   {
//     auto l = u_t(mpa - (mu_t(h)+mu_t(m)));
//     return T(h, m, l);
//   }
// }

template<auto N, typename T>
void perform_test(T pa,  T pb,  T pab)
{
  std::cout << " ------------------------------------------- " << std::endl;
  using  mpfr::mpreal;
  mpreal::set_default_prec(N);
  constexpr auto prec = plf::dimension_v<T>*sizeof(decltype(plf::hi(T())));
  auto mpa = tts::to_mpreal(pa);
  auto mpb = tts::to_mpreal(pb);
  auto mpab= tts::to_mpreal(pab);
  std::cout << std::setprecision(32) << (mpa)    << " -- " << std::setprecision(prec) << (pa)                       << std::endl;
  std::cout << std::setprecision(32) << (mpb)    << " -- " << std::setprecision(prec) << (pb)                       << std::endl;
  std::cout << std::setprecision(32) << (mpab)   << " -- " << std::setprecision(prec) << (pab)                      << std::endl;
  std::cout << std::setprecision(32) << (mpa/mpb)<< " -- " << std::setprecision(prec) << (pab)                      << std::endl;
  std::cout << tts::typename_<decltype(pa)> << std::endl;
  std::cout << "N " << N                  << std::endl;
  std::cout << "epsi " << tts::epsprec<T>() << std::endl;
  std::cout << "dim " << plf::dimension_v<T> << std::endl;
  std::cout << "d " << (mpa/mpb - mpab) << std::endl;
  std::cout << "d1 " << plf::abs(tts::to_polyfloat(mpa/mpb, eve::as<T>())-pab) << std::endl;
  std::cout << "r " << mpfr::abs (mpa/mpb - mpab)/mpfr::max(mpfr::max(mpfr::abs(mpa), mpfr::abs(mpb)), 1)<< std::endl;
  std::cout << "u " << plf::ulpdist(pab, tts::to_polyfloat(mpab, eve::as<T>())) << std::endl;
//  TTS_EXPECT( mpfr::abs(mpa/mpb - mpab) < tts::epsprec<T>()*mpfr::max(mpfr::max(mpfr::abs(mpa), mpfr::abs(mpb)), 1));
  TTS_EXPECT( plf::hi(plf::ulpdist(pab, tts::to_polyfloat(mpa/mpb, eve::as<T>()))) <= 0.5);
  std::cout << " ============================================ " << std::endl;
}


TTS_CASE_WITH("Check add two params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000)
             )
  <typename T>(T const& a0, T const& a1, T const& a2,
               T const& a3, T const& a4, T const& a5)
{
  using  mpfr::mpreal;
  {
    {
      using pv_t  = plf::polyfloat<T, 2>;
      constexpr auto N = tts::bitprec<pv_t>();
      pv_t pa(a0, a1);
      pv_t pb(a3, a4);
      pv_t pab = plf::div(pa, pb);
      perform_test<N>(pa, pb, pab);
    }
    {
      using pv_t  = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      pv_t pb(a3, a4, a5);
      pv_t pab = plf::div(pa, pb);
      constexpr auto N = tts::bitprec<pv_t>();
      perform_test<N>(pa, pb, pab);


//       pv_t x(1.2, 0.12, 0.012);
//       pv_t y(1.2, 0.12, 0.012);
//       pv_t xoy = plf::div(x, y);
//       perform_test<N>(x, y, xoy);
    }
  }
};
