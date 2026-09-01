//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check covariance three params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000))
<typename T>(T const& a0,
             T const& a1,
             T const& a2,
             T const& a3,
             T const& a4,
             T const& a5,
             T const& a6,
             T const& a7,
             T const& a8,
             T const& a9,
             T const& a10,
             T const& a11)
{
  using mpfr::mpreal;
  auto mcovariance = [](auto a, auto b, auto c, auto d) {
    auto m1 = (a + b) / 2;
    auto m2 = (c + d) / 2;
    a = a - m1;
    b = b - m1;
    c = c - m2;
    d = d - m2;
    return (a * c + b * d) / 2;
  };
  using plf::covariance;
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t pc(a6, a7);
    pv_t pd(a9, a10);
    TTS_RELATIVE_EQUAL(covariance(pa, pb, pc, pd), tts::mpfr_exec(mcovariance, pa, pb, pc, pd), tts::epsprec<T>());
    TTS_RELATIVE_EQUAL(covariance(kumi::make_tuple(pa, pb), kumi::make_tuple(pc, pd)),
                       tts::mpfr_exec(mcovariance, pa, pb, pc, pd), tts::epsprec<T>());
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t pc(a6, a7, a8);
    pv_t pd(a9, a10, a11);
    TTS_RELATIVE_EQUAL(covariance(pa, pb, pc, pd), tts::mpfr_exec(mcovariance, pa, pb, pc, pd), tts::epsprec<T>());
  }
};
