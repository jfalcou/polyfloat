//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check lpnorm",
              plf::scalar_real_types,
              tts::randoms(1, 100),
              tts::randoms(1, 1.0e-20),
              tts::randoms(1, 1.0e-30),
              tts::randoms(1, 100),
              tts::randoms(1, 1.0e-20),
              tts::randoms(1, 1.0e-30),
              tts::randoms(1, 100),
              tts::randoms(1, 1.0e-20),
              tts::randoms(1, 1.0e-30))
<typename T>(
  T const& a0, T const& a1, T const& a2, T const& a3, T const& a4, T const& a5, T const& a6, T const& a7, T const& a8)
{
  using mpfr::mpreal;
  using plf::lpnorm;
  auto lpn2 = [](auto e, auto f) { return pow(pow(e, 3) + pow(f, 3), mpreal(1) / 3); };
  auto lpn3 = [](auto e, auto f, auto g) { return pow(pow(e, 3) + pow(f, 3) + pow(g, 3), mpreal(1) / 3); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t pc(a6, a7);
    TTS_RELATIVE_EQUAL(lpnorm(3, pa, pb), tts::mpfr_exec(lpn2, pa, pb), 1000 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(lpnorm(3, pa, pb, pc), tts::mpfr_exec(lpn3, pa, pb, pc), 2000 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(lpnorm(3, a0, pa, pc), lpnorm(3, pv_t(a0), pa, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(lpnorm(3, pa, a0, pc), lpnorm(3, pa, pv_t(a0), pc), tts::epsprec<pv_t>());
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t pc(a6, a7, a8);
    TTS_RELATIVE_EQUAL(lpnorm(3, pa, pb), tts::mpfr_exec(lpn2, pa, pb), 4000000 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(lpnorm(3, pa, pb, pc), tts::mpfr_exec(lpn3, pa, pb, pc), 40000 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(lpnorm(3, a0, pa, pc), lpnorm(3, pv_t(a0), pa, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(lpnorm(3, pa, a0, pc), lpnorm(3, pa, pv_t(a0), pc), 10000 * tts::epsprec<pv_t>());
  }
};
