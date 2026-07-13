//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>
#include <mpreal.h>
#include <iostream>


template<auto N, typename T>
void perform_test(T pa,  T pb,  T pab)
{
  using  mpfr::mpreal;
  mpreal::set_default_prec(N);
  auto mpa = tts::to_mpreal(pa);
  auto mpb = tts::to_mpreal(pb);
  auto mpab= tts::to_mpreal(pab);
//   std::cout << (mpa)    << " -- " << (pa)                       << std::endl;
//   std::cout << (mpb)    << " -- " << (pb)                       << std::endl;
//   std::cout << (mpab)   << " -- " << (pab)                      << std::endl;
//   std::cout << tts::typename_<decltype(pa)> << std::endl;
//   std::cout << "N " << N                  << std::endl;
//   std::cout << "dim " << plf::dimension_v<T> << std::endl;
//   std::cout << "d " << (mpa + mpb - mpab) << std::endl;
//   std::cout << "r " << mpfr::abs (mpa + mpb - mpab)/mpfr::max(mpfr::max(mpfr::abs(mpa), mpfr::abs(mpb)), 1)<< std::endl;
  TTS_EXPECT(mpa+mpb == mpab);
//   std::cout << " ============================================ " << std::endl;
}

TTS_CASE_WITH("Check add two params",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax)
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
      pv_t pab = plf::add(pa, pb);
      perform_test<N>(pa, pb, pab);
    }
    {
      using pv_t  = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      pv_t pb(a3, a4, a5);
      pv_t pab = plf::add(pa, pb);
      constexpr auto N = tts::bitprec<pv_t>();
      perform_test<N>(pa, pb, pab);
    }
  }
};
