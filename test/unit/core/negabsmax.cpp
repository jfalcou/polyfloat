//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check negabsmax two params",
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
  using plf::abs;
  using plf::negabsmax;
  auto mnegabsmax = [](auto a, auto b) { return -mpfr::abs(mpfr::max(a, b)); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_EQUAL(negabsmax(pa, pb), tts::mpfr_exec(mnegabsmax, pa, pb));
    TTS_EQUAL(negabsmax(pa, pb), -plf::if_else(pa < pb, abs(pb), abs(pa)));
    TTS_EQUAL(negabsmax(a0, pa), negabsmax(pv_t(a0), pa));
    TTS_EQUAL(negabsmax(pa, a0), negabsmax(pa, pv_t(a0)));
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_EQUAL(negabsmax(pa, pb), tts::mpfr_exec(mnegabsmax, pa, pb));
    TTS_EQUAL(negabsmax(pa, pb), -plf::if_else(pa < pb, abs(pb), abs(pa)));
    TTS_EQUAL(negabsmax(a0, pa), negabsmax(pv_t(a0), pa));
    TTS_EQUAL(negabsmax(pa, a0), negabsmax(pa, pv_t(a0)));
  }
};
