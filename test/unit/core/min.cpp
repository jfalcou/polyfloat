//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check min two params",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax)
             )
  <typename T>(T const& a0, T const& a1, T const& a2,
               T const& a3, T const& a4, T const& a5)
{
  using  mpfr::mpreal;
  using plf::min;
  auto mmin = [](auto a,  auto b){ return mpfr::min(a, b); };
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_EQUAL(min(pa, pb), tts::mpfr_exec(mmin, pa, pb));
    TTS_EQUAL(min(pa, pb), plf::if_else(pa < pb, pa, pb));
    TTS_EQUAL(min(a0, pa), min(pv_t(a0), pa));
    TTS_EQUAL(min(pa, a0), min(pa, pv_t(a0)));
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_EQUAL(min(pa, pb), tts::mpfr_exec(mmin, pa, pb));
    TTS_EQUAL(min(pa, pb), plf::if_else(pa < pb, pa, pb));
    TTS_EQUAL(min(a0, pa), min(pv_t(a0), pa));
    TTS_EQUAL(min(pa, a0), min(pa, pv_t(a0)));
  }
};
