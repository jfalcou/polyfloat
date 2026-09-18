//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check kolmmean",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(1, 1.0e-20),
              tts::randoms(1, 1.0e-30),
              tts::randoms(-1000, 1000),
              tts::randoms(0, 1.0e-20),
              tts::randoms(0, 1.0e-30),
              tts::randoms(-1000, 1000),
              tts::randoms(0, 1.0e-20),
              tts::randoms(0, 1.0e-30))
<typename T>(
  T const& a0, T const& a1, T const& a2, T const& a3, T const& a4, T const& a5, T const& a6, T const& a7, T const& a8)
{
  using mpfr::mpreal;
  using plf::kolmmean;
  auto f0 = plf::abs;
  auto am = []<typename... Ts>(Ts... e) { return (abs(e) + ...) / (sizeof...(Ts)); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t pc(a6, a7);
    TTS_RELATIVE_EQUAL(kolmmean(f0, f0, pa, pb), tts::mpfr_exec(am, pa, pb), 2 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(kolmmean(f0, f0, pa, pb, pc), tts::mpfr_exec(am, pa, pb, pc), 1 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(kolmmean(f0, f0, a0, pa, pc), kolmmean(f0, f0, pv_t(a0), pa, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(kolmmean(f0, f0, pa, a0, pc), kolmmean(f0, f0, pa, pv_t(a0), pc), tts::epsprec<pv_t>());
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t pc(a6, a7, a8);
    TTS_RELATIVE_EQUAL(kolmmean(f0, f0, pa, pb), tts::mpfr_exec(am, pa, pb), 2 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(kolmmean(f0, f0, pa, pb, pc), tts::mpfr_exec(am, pa, pb, pc), 1 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(kolmmean(f0, f0, a0, pa, pc), kolmmean(f0, f0, pv_t(a0), pa, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(kolmmean(f0, f0, pa, a0, pc), kolmmean(f0, f0, pa, pv_t(a0), pc), tts::epsprec<pv_t>());
  }
};
