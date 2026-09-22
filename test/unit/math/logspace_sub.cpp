//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check logspace_sub",
              plf::scalar_real_types,
              tts::randoms(10, 100),
              tts::randoms(1, 1.0e-20),
              tts::randoms(1, 1.0e-30),
              tts::randoms(1, 10),
              tts::randoms(1, 1.0e-20),
              tts::randoms(1, 1.0e-30),
              tts::randoms(1, 1),
              tts::randoms(1, 1.0e-20),
              tts::randoms(1, 1.0e-30))
<typename T>(
  T const& a0, T const& a1, T const& a2, T const& a3, T const& a4, T const& a5, T const& a6, T const& a7, T const& a8)
{
  using mpfr::mpreal;
  using plf::logspace_sub;
  auto hm2 = [](auto e, auto f) { return log(exp(e) - exp(f)); };
  auto hm3 = [](auto e, auto f, auto g) { return log(exp(e) - exp(f) - exp(g)); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t pc(a6, a7);
    TTS_RELATIVE_EQUAL(logspace_sub(pa, pb), tts::mpfr_exec(hm2, pa, pb), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(logspace_sub(pa, pb, pc), tts::mpfr_exec(hm3, pa, pb, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(logspace_sub(a0, pb, pc), logspace_sub(pv_t(a0), pb, pc), tts::epsprec<pv_t>());
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t pc(a6, a7, a8);
    TTS_RELATIVE_EQUAL(logspace_sub(pa, pb), tts::mpfr_exec(hm2, pa, pb), 5120 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(logspace_sub(pa, pb, pc), tts::mpfr_exec(hm3, pa, pb, pc), 20000 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(logspace_sub(a0, pb, pc), logspace_sub(pv_t(a0), pb, pc), tts::epsprec<pv_t>());
  }
};
