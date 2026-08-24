//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check rem two params",
              plf::scalar_real_types,
              tts::randoms(-1000,1000),
              tts::randoms(-1000,1000),
              tts::randoms(-1000,1000),
              tts::randoms(1, 1000),
              tts::randoms(1, 1000),
              tts::randoms(1, 1000)
             )
  <typename T>(T const& a0, T const& a1, T const& a2,
               T const& a3, T const& a4, T const& a5)
{
  using  mpfr::mpreal;
  using plf::rem;
  auto mrem = [](auto a,  auto b){return a- trunc(a/b)*b; };
 {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_RELATIVE_EQUAL(rem(pa, pb), tts::mpfr_exec(mrem, pa, pb), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(rem(a0, pa), rem(pv_t(a0), pa), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(rem(pa, a3), rem(pa, pv_t(a3)), tts::epsprec<pv_t>());
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_RELATIVE_EQUAL(rem(pa, pb), tts::mpfr_exec(mrem, pa, pb), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(rem(a0, pa), rem(pv_t(a0), pa), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(rem(pa, a3), rem(pa, pv_t(a3)), tts::epsprec<pv_t>());
  }
};
