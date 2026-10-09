//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check sincos ",
              plf::scalar_real_types,
              tts::randoms(-100, 100),
              tts::randoms(0.0, 1.e-20),
              tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::sincos;
  auto msin = [](auto a) { return mpfr::sin(a); };
  auto mcos = [](auto a) { return mpfr::cos(a); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    auto [spa, cpa] = sincos[eve::medium](pa);
    TTS_RELATIVE_EQUAL(spa, tts::mpfr_exec(msin, pa), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(cpa, tts::mpfr_exec(mcos, pa), tts::epsprec<pv_t>());
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    auto [spa, cpa] = sincos[eve::medium](pa);
    TTS_RELATIVE_EQUAL(spa, tts::mpfr_exec(msin, pa), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(cpa, tts::mpfr_exec(mcos, pa), tts::epsprec<pv_t>());
  }
};
