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
  "Check tan[pirad] ", double, tts::randoms(50.0, 100.0), tts::randoms(0.0, 1.e-20), tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  auto tanpi = plf::tan[eve::radpi];
  auto mtanpi = [](auto a) { return mpfr::tan(a * mpfr::const_pi()); };
  {
    using pv_t = float;
    pv_t pa(a0);
    TTS_RELATIVE_EQUAL(tanpi[eve::medium](pa), tts::mpfr_exec(mtanpi, pa), 256 * tts::epsprec<pv_t>());
    auto quarter = pv_t(0.25);
    for (pv_t i = 0; i < quarter; i += pv_t(0.51))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(tanpi[eve::medium](x), tts::mpfr_exec(mtanpi, x), 256 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0);
    TTS_BIT_EQUAL(tanpi[eve::medium](z), z);
    TTS_BIT_EQUAL(tanpi[eve::medium](-z), -z);
  }
  {
    using pv_t = double;
    pv_t pa(a0);
    TTS_RELATIVE_EQUAL(tanpi[eve::medium](pa), tts::mpfr_exec(mtanpi, pa), 256 * tts::epsprec<pv_t>());
    auto quarter = pv_t(0.25);
    for (pv_t i = 0; i < quarter; i += pv_t(0.051))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(tanpi[eve::medium](x), tts::mpfr_exec(mtanpi, x), 2 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0);
    TTS_BIT_EQUAL(tanpi[eve::medium](z), z);
    TTS_BIT_EQUAL(tanpi[eve::medium](-z), -z);
  }
  {
    using pv_t = plf::polyfloat<float, 2>;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(tanpi[eve::medium](pa), tts::mpfr_exec(mtanpi, pa), 256 * tts::epsprec<pv_t>());
    auto quarter = pv_t(0.25);
    for (pv_t i = 0; i < quarter; i += pv_t(0.051))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(tanpi[eve::medium](x), tts::mpfr_exec(mtanpi, x), 256 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0f, 0.0f);
    TTS_BIT_EQUAL(plf::hi(tanpi[eve::medium](z)), plf::hi(z));
    TTS_BIT_EQUAL(plf::hi(tanpi[eve::medium](-z)), plf::hi(-z));
  }
  {
    using pv_t = plf::polyfloat<double, 2>;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(tanpi[eve::medium](pa), tts::mpfr_exec(mtanpi, pa), 256 * tts::epsprec<pv_t>());
    auto quarter = pv_t(0.25);
    for (pv_t i = 0; i < quarter; i += pv_t(0.051))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(tanpi[eve::medium](x), tts::mpfr_exec(mtanpi, x), 256 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0, 0.0);
    TTS_BIT_EQUAL(plf::hi(tanpi[eve::medium](z)), plf::hi(z));
    TTS_BIT_EQUAL(plf::hi(tanpi[eve::medium](-z)), plf::hi(-z));
  }
  {
    using pv_t = plf::polyfloat<float, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(tanpi[eve::medium](pa), tts::mpfr_exec(mtanpi, pa), 256 * tts::epsprec<pv_t>());
    auto quarter = pv_t(0.25);
    for (pv_t i = 0; i < quarter; i += pv_t(0.051))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(tanpi[eve::medium](x), tts::mpfr_exec(mtanpi, x), 256 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0);
    TTS_BIT_EQUAL(plf::hi(tanpi[eve::medium](z)), plf::hi(z));
    TTS_BIT_EQUAL(plf::hi(tanpi[eve::medium](-z)), plf::hi(-z));
  }
  {
    using pv_t = plf::polyfloat<double, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(tanpi[eve::medium](pa), tts::mpfr_exec(mtanpi, pa), 256 * tts::epsprec<pv_t>());
    auto quarter = pv_t(0.25);
    for (pv_t i = 0; i < quarter; i += pv_t(0.051))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(tanpi[eve::medium](x), tts::mpfr_exec(mtanpi, x), 256 * tts::epsprec<pv_t>())
        << "i " << i << "\n";
    }
    pv_t z(0.0);
    TTS_BIT_EQUAL(plf::hi(tanpi[eve::medium](z)), plf::hi(z));
    TTS_BIT_EQUAL(plf::hi(tanpi[eve::medium](-z)), plf::hi(-z));
  }
};
