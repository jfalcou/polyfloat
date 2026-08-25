//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

auto reduction(auto x,  auto c1,  auto c2, auto c)
{
  std::cout << " reduction " << x << std::endl;
  std::cout << "c " << c << std::endl;
  auto z = plf::nearest(x*c);
  std::cout << "zz " << z << std::endl;
  auto u = plf::fma(-z, c1, x);
  std::cout << "u " << u << std::endl;
  auto v1 = plf::fma(-z, c2, u);
 std::cout << "u-v " << u-v1 << std::endl;

//    auto [p1, p2] = plf::dekker_prod(z, c2);
//    auto [t1, t2] = plf::two_add(u, -p1);
//   return ((t1-v1)+t2)-p2;
  return v1;
}

template < typename T> auto c1c2(auto l2, eve::as<T>){
  auto r =  tts::to_polyfloat(l2, eve::as<T>());
  auto nbm2 = eve::nbmantissabits(eve::as(plf::hi(r)))-2;
  auto r10 = plf::ldexp(r, nbm2);
  auto r11 = plf::nearest(r10);
  auto r1  = plf::ldexp(r11, -nbm2);
  auto r2 = r-r1;
  return eve::zip(r1, r2);
}


TTS_CASE_WITH("Check reduction",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax)
             )
  <typename T>(T const& , T const& , T const& )
{
  using pfl2_t = plf::triple_real_t<T>;
  using  mpfr::mpreal;

  mpfr::mpreal::set_default_prec(200);
  auto C = 1/mpfr::log(2);
  auto l2 =  mpfr::log(2);
  auto [c1, c2] = c1c2(l2,  eve::as<pfl2_t>());
  std::cout << std::hexfloat << "c1 "<< c1 << std::endl;
  std::cout << std::hexfloat << "c2 "<< c2 << std::endl;



//   auto invlog2 = tts::to_polyfloat(C,  eve::as<pfl2_t>());
//   std::cout << std::hexfloat << "invlog2 "<< invlog2 << std::endl;

//   pfl2_t z(T(0.123456), T(2.0e-10));
//   std::cout << std::defaultfloat << "z " << z << std::endl;
//   for(int i=1; i < 3; ++i)
//   {
//     auto x = z+tts::to_polyfloat(i*mpfr::log(2), eve::as(pfl2_t()));
//     auto log2 = tts::to_polyfloat(l2,  eve::as<pfl2_t>());
//     auto invlog2 = tts::to_polyfloat(C,  eve::as<pfl2_t>());
//     std::cout << std::hexfloat << "invlog2 "<< invlog2 << std::endl;

// //    std::cout << "x " << x << std::endl;
// //    auto r = reduction(x, c1, c2, invlog2);
// //    std::cout << "r " << r << std::endl;
// //    TTS_RELATIVE_EQUAL(r, z,  tts::epsprec<pfl2_t>());
// //    std::cout << "naive " << (x-plf::nearest(x/log2)*log2)<< std::endl;
//   }
};
