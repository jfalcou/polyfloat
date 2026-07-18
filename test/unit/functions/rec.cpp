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

template < typename T> auto mpfr_rec(T a)
{
  return tts::to_polyfloat(1/tts::to_mpreal(a), eve::as<T>());
}

// template<auto N, typename T>
// void perform_test(T pa,  T rpa)
// {
//   std::cout << " ------------------------------------------- " << std::endl;
//   using  mpfr::mpreal;
//   mpreal::set_default_prec(N);
//   constexpr auto prec = plf::dimension_v<T>*sizeof(decltype(plf::hi(T())));
//   auto mpa = tts::to_mpreal(pa);
//   auto mrpa= tts::to_mpreal(rpa);
//   std::cout << std::setprecision(32) << (mpa)    << " -- " << std::setprecision(prec) <<(pa)                       << std::endl;
//   std::cout << std::setprecision(32) << (mrpa)   << " -- " << std::setprecision(prec) <<(rpa)                      << std::endl;
//   std::cout << tts::typename_<decltype(pa)> << std::endl;
//   std::cout << "N " << N                  << std::endl;
//   std::cout << "epsi " << tts::epsprec<T>() << std::endl;
//   std::cout << "dim " << plf::dimension_v<T> << std::endl;
//   std::cout << "d " << (1/mpa - mrpa) << std::endl;
//   std::cout << "r " << mpfr::abs (1/mpa - mrpa)/mpfr::max(mpfr::abs(mrpa), 1)<< std::endl;
//   std::cout << "d1 " << plf::abs(tts::to_polyfloat(1/mpa, eve::as<T>())-rpa) << std::endl;
//   std::cout << "u " << plf::ulpdist(pa, tts::to_polyfloat(mrpa, eve::as<T>())) << std::endl;
//   TTS_EXPECT( plf::hi(plf::ulpdist(rpa, tts::to_polyfloat(mrpa, eve::as<T>()))) <= 0.5);
// //  TTS_EXPECT( mpfr::abs(1/mpa - mrpa) < tts::epsprec<T>()*mpfr::max(mpfr::abs(mpa), 1));
//  std::cout << " ============================================ " << std::endl;
// }


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
//      constexpr auto N = tts::bitprec<pv_t>();
      pv_t pa(a0, a1);
      pv_t rpa = plf::rec(pa);
     TTS_ULP_EQUAL(rpa, mpfr_rec(pa), 0.5);
//      perform_test<N>(pa, rpa);
    }
    {
      using pv_t  = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      pv_t rpa = plf::rec(pa);
//       constexpr auto N = tts::bitprec<pv_t>();
//       perform_test<N>(pa, rpa);
     TTS_ULP_EQUAL(rpa, mpfr_rec(pa), 0.5);
    }
  }
};
