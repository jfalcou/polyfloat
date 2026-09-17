//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check harmean",
              plf::scalar_real_types,
              tts::randoms(1, 1000),
              tts::randoms(1, 1000),
              tts::randoms(1, 1000),
              tts::randoms(1, 1000),
              tts::randoms(1, 1000),
              tts::randoms(1, 1000),
              tts::randoms(1, 1000),
              tts::randoms(1, 1000),
              tts::randoms(1, 1000))
<typename T>(
  T const& a0, T const& a1, T const& a2, T const& a3, T const& a4, T const& a5, T const& a6, T const& a7, T const& a8)
{
  using mpfr::mpreal;
  using plf::harmmean;
  auto hm2 = [](auto e, auto f) { return 1 / ((1 / e + 1 / f) / 2); };
  auto hm3 = [](auto e, auto f, auto g) { return 1 / ((1 / e + 1 / f + 1 / g) / 3); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t pc(a6, a7);
    TTS_RELATIVE_EQUAL(harmmean(pa, pb), tts::mpfr_exec(hm2, pa, pb), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(harmmean(pa, pb, pc), tts::mpfr_exec(hm3, pa, pb, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(harmmean(a0, pa, pc), harmmean(pv_t(a0), pa, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(harmmean(pa, a0, pc), harmmean(pa, pv_t(a0), pc), tts::epsprec<pv_t>());
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t pc(a6, a7, a8);
    TTS_RELATIVE_EQUAL(harmmean(pa, pb), tts::mpfr_exec(hm2, pa, pb), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(harmmean(pa, pb, pc), tts::mpfr_exec(hm3, pa, pb, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(harmmean(a0, pa, pc), harmmean(pv_t(a0), pa, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(harmmean(pa, a0, pc), harmmean(pa, pv_t(a0), pc), tts::epsprec<pv_t>());
  }
};
