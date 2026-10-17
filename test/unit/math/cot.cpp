//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check cot ", float, tts::randoms(50.0, 100.0), tts::randoms(0.0, 1.e-20), tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::cot;
  auto mcot = [](auto a) { return mpfr::cot(a); };
  {
    using pv_t = float;
    pv_t pa(a0);
    TTS_RELATIVE_EQUAL(cot[eve::medium](pa), tts::mpfr_exec(mcot, pa), 2 * tts::epsprec<pv_t>());
    auto pio4 = plf::pio_4(eve::as<pv_t>());
    for (pv_t i = 0; i < pio4; i += pv_t(0.05))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(cot[eve::medium](x), tts::mpfr_exec(mcot, x), 2 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0);
    TTS_EQUAL(cot[eve::medium](z), plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(cot[eve::medium](-z), plf::minf(eve::as<pv_t>()));
  }
  {
    using pv_t = double;
    pv_t pa(a0);
    TTS_RELATIVE_EQUAL(cot[eve::medium](pa), tts::mpfr_exec(mcot, pa), 4 * tts::epsprec<pv_t>());
    auto pio4 = plf::pio_4(eve::as<pv_t>());
    for (pv_t i = 0; i < pio4; i += pv_t(0.05))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(cot[eve::medium](x), tts::mpfr_exec(mcot, x), 2 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0);
    TTS_EQUAL(cot[eve::medium](z), plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(cot[eve::medium](-z), plf::minf(eve::as<pv_t>()));
  }
  {
    using pv_t = plf::polyfloat<float, 2>;
    pv_t pa(a0, a1);
    std::cout << pa << std::endl;
    TTS_RELATIVE_EQUAL(cot[eve::medium](pa), tts::mpfr_exec(mcot, pa), 2 * tts::epsprec<pv_t>());
    auto pio4 = plf::pio_4(eve::as<pv_t>());
    for (pv_t i = pv_t(0.05); i < pio4; i += pv_t(0.05))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(cot[eve::medium](x), tts::mpfr_exec(mcot, x), 8 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0);
    TTS_EQUAL(cot[eve::medium](z), plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(cot[eve::medium](-z), plf::minf(eve::as<pv_t>()));
  }
  {
    using pv_t = plf::polyfloat<double, 2>;
    pv_t pa(a0, a1);
    std::cout << pa << std::endl;
    TTS_RELATIVE_EQUAL(cot[eve::medium](pa), tts::mpfr_exec(mcot, pa), 2 * tts::epsprec<pv_t>());
    auto pio4 = plf::pio_4(eve::as<pv_t>());
    for (pv_t i = pv_t(0.05); i < pio4; i += pv_t(0.05))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(cot[eve::medium](x), tts::mpfr_exec(mcot, x), 4 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0);
    TTS_EQUAL(cot[eve::medium](z), plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(cot[eve::medium](-z), plf::minf(eve::as<pv_t>()));
  }
  {
    using pv_t = plf::polyfloat<float, 3>;
    pv_t pa(a0, a1, a2);
    std::cout << pa << std::endl;
    TTS_RELATIVE_EQUAL(cot[eve::medium](pa), tts::mpfr_exec(mcot, pa), 2 * tts::epsprec<pv_t>());
    auto pio4 = plf::pio_4(eve::as<pv_t>());
    for (pv_t i = pv_t(0.05); i < pio4; i += pv_t(0.0051))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(cot[eve::medium](x), tts::mpfr_exec(mcot, x), 2 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0);
    TTS_EQUAL(cot[eve::medium](z), plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(cot[eve::medium](-z), plf::minf(eve::as<pv_t>()));
  }
  {
    using pv_t = plf::polyfloat<double, 3>;
    pv_t pa(a0, a1, a2);
    std::cout << pa << std::endl;
    TTS_RELATIVE_EQUAL(cot[eve::medium](pa), tts::mpfr_exec(mcot, pa), 2 * tts::epsprec<pv_t>());
    auto pio4 = plf::pio_4(eve::as<pv_t>());
    for (pv_t i = pv_t(0.05); i < pio4; i += pv_t(0.005))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(cot[eve::medium](x), tts::mpfr_exec(mcot, x), 2 * tts::epsprec<pv_t>());
    }
    pv_t z(0.0);
    TTS_EQUAL(cot[eve::medium](z), plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(cot[eve::medium](-z), plf::minf(eve::as<pv_t>()));
  }
};
