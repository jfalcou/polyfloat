//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check minmag two params",
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
  using plf::minmag;
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_EQUAL(minmag(pa, pb), plf::if_else(plf::abs(pb) < plf::abs(pa), pb, pa));
    TTS_EQUAL(minmag(a0, pa), minmag(pv_t(a0), pa));
    TTS_EQUAL(minmag(pa, a0), minmag(pa, pv_t(a0)));
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_EQUAL(minmag(pa, pb), plf::if_else(plf::abs(pb) < plf::abs(pa), pb, pa));
    TTS_EQUAL(minmag(a0, pa), minmag(pv_t(a0), pa));
    TTS_EQUAL(minmag(pa, a0), minmag(pa, pv_t(a0)));
  }
};
