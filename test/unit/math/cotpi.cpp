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
  "Check cot[pirad] ", double, tts::randoms(50.0, 100.0), tts::randoms(0.0, 1.e-20), tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  auto cotpi = plf::cot[eve::radpi];
  auto mcotpi = [](auto a) { return mpfr::cot(a * mpfr::const_pi()); };
  {
    using pv_t = float;
    pv_t pa(a0);
    TTS_RELATIVE_EQUAL(cotpi[eve::medium](pa), tts::mpfr_exec(mcotpi, pa), 256 * tts::epsprec<pv_t>());
    auto quarter = pv_t(0.25);
    for (pv_t i = 0; i < quarter; i += pv_t(0.51))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(cotpi[eve::medium](x), tts::mpfr_exec(mcotpi, x), 256 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0);
    TTS_BIT_EQUAL(cotpi[eve::medium](z), plf::inf(eve::as(z)));
    TTS_BIT_EQUAL(cotpi[eve::medium](-z), plf::minf(eve::as(z)));
  }
  {
    using pv_t = double;
    pv_t pa(a0);
    TTS_RELATIVE_EQUAL(cotpi[eve::medium](pa), tts::mpfr_exec(mcotpi, pa), 256 * tts::epsprec<pv_t>());
    auto quarter = pv_t(0.25);
    for (pv_t i = 0; i < quarter; i += pv_t(0.051))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(cotpi[eve::medium](x), tts::mpfr_exec(mcotpi, x), 2 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0);
    TTS_BIT_EQUAL(cotpi[eve::medium](z), plf::inf(eve::as(z)));
    TTS_BIT_EQUAL(cotpi[eve::medium](-z), plf::minf(eve::as(z)));
  }
  {
    using pv_t = plf::polyfloat<float, 2>;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(cotpi[eve::medium](pa), tts::mpfr_exec(mcotpi, pa), 256 * tts::epsprec<pv_t>());
    auto quarter = pv_t(0.25);
    for (pv_t i = pv_t(0.051); i < quarter; i += pv_t(0.051))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(cotpi[eve::medium](x), tts::mpfr_exec(mcotpi, x), 256 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0f, 0.0f);
    TTS_BIT_EQUAL(plf::hi(cotpi[eve::medium](z)), plf::inf(eve::as(plf::hi(z))));
    TTS_BIT_EQUAL(plf::hi(cotpi[eve::medium](-z)), plf::minf(eve::as(plf::hi(z))));
  }
  {
    using pv_t = plf::polyfloat<double, 2>;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(cotpi[eve::medium](pa), tts::mpfr_exec(mcotpi, pa), 256 * tts::epsprec<pv_t>());
    auto quarter = pv_t(0.25);
    for (pv_t i = pv_t(0.051); i < quarter; i += pv_t(0.051))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(cotpi[eve::medium](x), tts::mpfr_exec(mcotpi, x), 256 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0, 0.0);
    TTS_BIT_EQUAL(plf::hi(cotpi[eve::medium](z)), plf::inf(eve::as(plf::hi(z))));
    TTS_BIT_EQUAL(plf::hi(cotpi[eve::medium](-z)), plf::minf(eve::as(plf::hi(z))));
  }
  {
    using pv_t = plf::polyfloat<float, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(cotpi[eve::medium](pa), tts::mpfr_exec(mcotpi, pa), 256 * tts::epsprec<pv_t>());
    auto quarter = pv_t(0.25);
    for (pv_t i = pv_t(0.051); i < quarter; i += pv_t(0.051))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(cotpi[eve::medium](x), tts::mpfr_exec(mcotpi, x), 256 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0);
    TTS_BIT_EQUAL(plf::hi(cotpi[eve::medium](z)), plf::inf(eve::as(plf::hi(z))));
    TTS_BIT_EQUAL(plf::hi(cotpi[eve::medium](-z)), plf::minf(eve::as(plf::hi(z))));
  }
  {
    using pv_t = plf::polyfloat<double, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(cotpi[eve::medium](pa), tts::mpfr_exec(mcotpi, pa), 256 * tts::epsprec<pv_t>());
    auto quarter = pv_t(0.25);
    for (pv_t i = pv_t(0.051); i < quarter; i += pv_t(0.051))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(cotpi[eve::medium](x), tts::mpfr_exec(mcotpi, x), 256 * tts::epsprec<pv_t>())
        << "i " << i << "\n";
    }
    pv_t z(0.0);
    TTS_BIT_EQUAL(plf::hi(cotpi[eve::medium](z)), plf::inf(eve::as(plf::hi(z))));
    TTS_BIT_EQUAL(plf::hi(cotpi[eve::medium](-z)), plf::minf(eve::as(plf::hi(z))));
  }
};
