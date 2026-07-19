//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check add two params",
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
  using plf::add;
  auto madd = [](auto a,  auto b){return a+b; };
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_ULP_EQUAL(add(pa, pb), tts::mpfr_exec(madd, pa, pb), 0.5);
    TTS_ULP_EQUAL(add(a0, pa), add(pv_t(a0), pa), 0.5);
    TTS_ULP_EQUAL(add(pa, a0), add(pa, pv_t(a0)), 0.5);
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_ULP_EQUAL(add(pa, pa), tts::mpfr_exec(madd, pa, pb), 0.5);
    TTS_ULP_EQUAL(add(a0, pa), add(pv_t(a0), pa), 0.5);
    TTS_ULP_EQUAL(add(pa, a0), add(pa, pv_t(a0)), 0.5);
  }
};
