//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check geommean",
              plf::scalar_real_types,
              tts::randoms(1, 1000),
              tts::randoms(1, 1.0e-20),
              tts::randoms(1, 1.0e-30),
              tts::randoms(1, 1000),
              tts::randoms(0, 1.0e-20),
              tts::randoms(0, 1.0e-30),
              tts::randoms(1, 1000),
              tts::randoms(0, 1.0e-20),
              tts::randoms(0, 1.0e-30))
<typename T>(
  T const& a0, T const& a1, T const& a2, T const& a3, T const& a4, T const& a5, T const& a6, T const& a7, T const& a8)
{
  using mpfr::mpreal;
  using plf::geommean;
  auto gm2 = [](auto e, auto f) { return sqrt(e * f); };
  auto gm3 = [](auto e, auto f, auto g) { return pow(e * f * g, mpreal(1) / 3); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t pc(a6, a7);
    TTS_RELATIVE_EQUAL(geommean(pa, pb), tts::mpfr_exec(gm2, pa, pb), 2 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(geommean(pa, pb, pc), tts::mpfr_exec(gm3, pa, pb, pc), 1 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(geommean(a0, pa, pc), geommean(pv_t(a0), pa, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(geommean(pa, a0, pc), geommean(pa, pv_t(a0), pc), tts::epsprec<pv_t>());
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t pc(a6, a7, a8);
    TTS_RELATIVE_EQUAL(geommean(pa, pb), tts::mpfr_exec(gm2, pa, pb), 2 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(geommean(pa, pb, pc), tts::mpfr_exec(gm3, pa, pb, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(geommean(a0, pa, pc), geommean(pv_t(a0), pa, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(geommean(pa, a0, pc), geommean(pa, pv_t(a0), pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(geommean(pa, pb, pc, pa, pb, pc), tts::mpfr_exec(gm3, pa, pb, pc), 2 * tts::epsprec<pv_t>());
  }
};
