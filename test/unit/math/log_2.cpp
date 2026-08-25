//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

auto reduction(auto x,  auto c1,  auto c2)
{std::cout << " reduction " << x << std::endl;
  auto z = plf::nearest(x/(c1+c2));
  std::cout << "zz " << z << std::endl;
  auto u = plf::fnma(z, c1, x);
  std::cout << "uz " << u << std::endl;

  auto v1 = plf::fnma(z, c2, u);
  auto [p1, p2] = plf::two_prod(z, c2);
  auto [t1, t2] = plf::two_add(u, -p1);
  return ((t1-v1)+t2)-p2;
}

TTS_CASE_WITH("Check abs",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax)
             )
  <typename T>(T const& , T const& , T const& )
{
  using  mpfr::mpreal;
//   using plf::abs;
//   auto mlog_2 = [](){return mpfr::log(2); };
  {
//    auto tn = tts::typename_<T>;
     mpfr::mpreal::set_default_prec(256);
   auto C = 1/mpfr::log(2);
//    std::cout << "Cmpfr " << " " << std::setprecision(100) << C << std::endl;
    using pfl2_t = plf::double_real_t<T>;
//    std::cout << "bit prec double_real < " << tn<< "> " << tts::bitprec<pfl2_t>() << " eps " << std::defaultfloat << std::setprecision(5) << plf::hi(plf::eps(eve::as<pfl2_t>())) << std::endl;
    auto r = tts::to_polyfloat(C, eve::as(pfl2_t()));
//     std::cout << "r " << std::hexfloat << r << std::endl;
//     std::cout << "diff " << std::setprecision(5) << C - tts::to_mpreal(plf::hi(r))- tts::to_mpreal(plf::lo(r)) << std::endl;
    auto nbm2 = eve::nbmantissabits(eve::as(plf::hi(r)))-2;
    auto r10 = plf::ldexp(r, nbm2);
    auto r11 = plf::nearest(r10);
    auto r1  = plf::ldexp(r11, -nbm2);
//     std::cout << std::hexfloat << "r10 " << r10 << std::endl;
//     std::cout << std::hexfloat << "r11 " << r11 << std::endl;
    std::cout << std::hexfloat << "r1 " << r1 << std::endl;
    auto r2 = r-r1;
    std::cout << std::hexfloat << "r2 " << r2 << std::endl;
    std::cout << "new diff " << r-(r1+r2) << std::endl;

    pfl2_t z(T(0.123456), T(2.0e-10));
    std::cout << std::defaultfloat << "z " << z << std::endl;
    for(int i=1; i < 3; ++i)
    {
      auto x = z*tts::to_polyfloat(i*mpfr::log(2), eve::as(pfl2_t()));
      std::cout << "x " << x << std::endl;
      auto r = reduction(x, r1, r2);
      std::cout << "r " << r << std::endl;
      std::cout << "naive " << (x-plf::nearest(x/(r1+r2))*x)<< std::endl;
    }
  }
};
