//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check rec",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::rec;
  auto mrec = [](auto b) { return 1 / b; };
  {
    {
      using pv_t = plf::polyfloat<T, 2>;
      pv_t pa(a0, a1);
      pv_t rpa = plf::rec(pa);
      TTS_RELATIVE_EQUAL(rpa, tts::mpfr_exec(mrec, pa), tts::epsprec<pv_t>());
      pv_t inf(plf::inf(eve::as(pa)));
      TTS_EQUAL(plf::rec(inf), pv_t(0));
      TTS_EQUAL(plf::rec(plf::zero(eve::as(pa))), inf);
      TTS_EQUAL(plf::rec(plf::mzero(eve::as(pa))), -inf);
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      pv_t rpa = plf::rec(pa);
      TTS_RELATIVE_EQUAL(rpa, tts::mpfr_exec(mrec, pa), tts::epsprec<pv_t>());
      pv_t inf(plf::inf(eve::as(pa)));
      TTS_EQUAL(plf::rec(inf), pv_t(0));
      TTS_EQUAL(plf::rec(plf::zero(eve::as(pa))), inf);
      TTS_EQUAL(plf::rec(plf::mzero(eve::as(pa))), -inf);
    }
  }
};
