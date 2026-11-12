//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0ld
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check ldexpb",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::ldexp;
  using plf::ldexpb;
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    auto n = 2;
    TTS_EQUAL(ldexpb(pa, n), pa * 4);
    using wpv_t = eve::wide<pv_t, 2>;
    wpv_t wpab(pa, pa);
    TTS_RELATIVE_EQUAL(ldexpb(wpab, n), wpab * 4, tts::epsprec<T>());
    TTS_EQUAL(ldexpb(wpab, n), ldexp(wpab, n));
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    auto n = 2;
    TTS_EQUAL(ldexpb(pa, n), pa * 4);
    using wpv_t = eve::wide<pv_t, 2>;
    wpv_t wpab(pa, pa);
    TTS_RELATIVE_EQUAL(ldexpb(wpab, n), wpab * 4, tts::epsprec<T>());
    TTS_EQUAL(ldexpb(wpab, n), ldexp(wpab, n));
  }
};
