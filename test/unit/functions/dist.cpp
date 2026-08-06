//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check dist two params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000)
             )
  <typename T>(T const& a0, T const& a1, T const& a2,
               T const& a3, T const& a4, T const& a5)
{
  using  mpfr::mpreal;
  using plf::dist;
  auto mdist = [](auto a,  auto b){return mpfr::abs(a-b); };

  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_RELATIVE_EQUAL(dist(pa, pb), tts::mpfr_exec(mdist, pa, pb), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(dist(a0, pa), dist(pv_t(a0), pa), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(dist(pa, a0), dist(pa, pv_t(a0)), tts::epsprec<pv_t>());
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a5);
    pv_t pb(a3, a4, a2);
    TTS_RELATIVE_EQUAL(dist(pa, pb), tts::mpfr_exec(mdist, pa, pb), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(dist(a0, pa), dist(pv_t(a0), pa), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(dist(pa, a0), dist(pa, pv_t(a0)), tts::epsprec<pv_t>());
  }
};
