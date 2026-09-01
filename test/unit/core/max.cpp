//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check max two params",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax))
<typename T>(T const& a0, T const& a1, T const& a2, T const& a3, T const& a4, T const& a5)
{
  using mpfr::mpreal;
  using plf::max;
  auto mmax = [](auto a, auto b) { return mpfr::max(a, b); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_EQUAL(max(pa, pb), tts::mpfr_exec(mmax, pa, pb));
    TTS_EQUAL(max(pa, pb), plf::if_else(pa < pb, pb, pa));
    TTS_EQUAL(max(a0, pa), max(pv_t(a0), pa));
    TTS_EQUAL(max(pa, a0), max(pa, pv_t(a0)));
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_EQUAL(max(pa, pb), tts::mpfr_exec(mmax, pa, pb));
    TTS_EQUAL(max(pa, pb), plf::if_else(pa < pb, pb, pa));
    TTS_EQUAL(max(a0, pa), max(pv_t(a0), pa));
    TTS_EQUAL(max(pa, a0), max(pa, pv_t(a0)));
  }
};
