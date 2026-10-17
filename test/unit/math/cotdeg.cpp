//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH(
  "Check cot[deg] ", double, tts::randoms(50.0, 100.0), tts::randoms(0.0, 1.e-20), tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  auto cotd = plf::cot[eve::deg];
  auto mcotd = [](auto a) { return mpfr::cot(a * mpfr::const_pi() / 180); };
  {
    using pv_t = float;
    pv_t pa(a0);
    TTS_RELATIVE_EQUAL(cotd[eve::medium](pa), tts::mpfr_exec(mcotd, pa), 256 * tts::epsprec<pv_t>());
    auto quarter = pv_t(45);
    for (pv_t i = pv_t(0.51); i < quarter; i += pv_t(0.51))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(cotd[eve::medium](x), tts::mpfr_exec(mcotd, x), 256 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0);
    TTS_BIT_EQUAL(cotd[eve::medium](z), plf::inf(eve::as<pv_t>()));
    TTS_BIT_EQUAL(cotd[eve::medium](-z), plf::minf(eve::as<pv_t>()));
  }
  {
    using pv_t = double;
    pv_t pa(a0);
    TTS_RELATIVE_EQUAL(cotd[eve::medium](pa), tts::mpfr_exec(mcotd, pa), 256 * tts::epsprec<pv_t>());
    auto quarter = pv_t(45);
    for (pv_t i = pv_t(0.51); i < quarter; i += pv_t(0.51))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(cotd[eve::medium](x), tts::mpfr_exec(mcotd, x), 4 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0);
    TTS_BIT_EQUAL(cotd[eve::medium](z), plf::inf(eve::as<pv_t>()));
    TTS_BIT_EQUAL(cotd[eve::medium](-z), plf::minf(eve::as<pv_t>()));
  }
  {
    using pv_t = plf::polyfloat<float, 2>;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(cotd[eve::medium](pa), tts::mpfr_exec(mcotd, pa), 256 * tts::epsprec<pv_t>());
    auto quarter = pv_t(45);
    for (pv_t i = pv_t(0.51); i < quarter; i += pv_t(0.51))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(cotd[eve::medium](x), tts::mpfr_exec(mcotd, x), 512 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0f, 0.0f);
    TTS_BIT_EQUAL(plf::hi(cotd[eve::medium](z)), plf::hi(plf::inf(eve::as<pv_t>())));
    TTS_BIT_EQUAL(plf::hi(cotd[eve::medium](-z)), plf::hi(plf::minf(eve::as<pv_t>())));
  }
  {
    using pv_t = plf::polyfloat<double, 2>;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(cotd[eve::medium](pa), tts::mpfr_exec(mcotd, pa), 256 * tts::epsprec<pv_t>());
    auto quarter = pv_t(45);
    for (pv_t i = pv_t(0.51); i < quarter; i += pv_t(0.51))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(cotd[eve::medium](x), tts::mpfr_exec(mcotd, x), 256 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0, 0.0);
    TTS_BIT_EQUAL(plf::hi(cotd[eve::medium](z)), plf::hi(plf::inf(eve::as<pv_t>())));
    TTS_BIT_EQUAL(plf::hi(cotd[eve::medium](-z)), plf::hi(plf::minf(eve::as<pv_t>())));
  }
  {
    using pv_t = plf::polyfloat<float, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(cotd[eve::medium](pa), tts::mpfr_exec(mcotd, pa), 256 * tts::epsprec<pv_t>());
    auto quarter = pv_t(45);
    for (pv_t i = pv_t(0.51); i < quarter; i += pv_t(0.51))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(cotd[eve::medium](x), tts::mpfr_exec(mcotd, x), 256 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0);
    TTS_BIT_EQUAL(plf::hi(cotd[eve::medium](z)), plf::hi(plf::inf(eve::as<pv_t>())));
    TTS_BIT_EQUAL(plf::hi(cotd[eve::medium](-z)), plf::hi(plf::minf(eve::as<pv_t>())));
  }
  {
    using pv_t = plf::polyfloat<double, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(cotd[eve::medium](pa), tts::mpfr_exec(mcotd, pa), 256 * tts::epsprec<pv_t>());
    auto quarter = pv_t(45);
    for (pv_t i = pv_t(0.51); i < quarter; i += pv_t(0.51))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(cotd[eve::medium](x), tts::mpfr_exec(mcotd, x), 256 * tts::epsprec<pv_t>())
        << "i " << i << "\n";
    }
    pv_t z(0.0);
    TTS_BIT_EQUAL(plf::hi(cotd[eve::medium](z)), plf::hi(plf::inf(eve::as<pv_t>())));
    TTS_BIT_EQUAL(plf::hi(cotd[eve::medium](-z)), plf::hi(plf::minf(eve::as<pv_t>())));
  }
};
