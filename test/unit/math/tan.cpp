//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check tan ", double, tts::randoms(50.0, 100.0), tts::randoms(0.0, 1.e-20), tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::tan;
  auto mtan = [](auto a) { return mpfr::tan(a); };
  {
    using pv_t = float;
    pv_t pa(a0);
    TTS_RELATIVE_EQUAL(tan[eve::medium](pa), tts::mpfr_exec(mtan, pa), 2 * tts::epsprec<pv_t>());
    auto pio4 = plf::pio_4(eve::as<pv_t>());
    for (pv_t i = 0; i < pio4; i += pv_t(0.05))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(tan[eve::medium](x), tts::mpfr_exec(mtan, x), tts::epsprec<pv_t>());
    }
  }
  {
    using pv_t = double;
    pv_t pa(a0);
    TTS_RELATIVE_EQUAL(tan[eve::medium](pa), tts::mpfr_exec(mtan, pa), 2 * tts::epsprec<pv_t>());
    auto pio4 = plf::pio_4(eve::as<pv_t>());
    for (pv_t i = 0; i < pio4; i += pv_t(0.05))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(tan[eve::medium](x), tts::mpfr_exec(mtan, x), tts::epsprec<pv_t>());
    }
  }
  {
    using pv_t = plf::polyfloat<float, 2>;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(tan[eve::medium](pa), tts::mpfr_exec(mtan, pa), 2 * tts::epsprec<pv_t>());
    auto pio4 = plf::pio_4(eve::as<pv_t>());
    for (pv_t i = 0; i < pio4; i += pv_t(0.05))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(tan[eve::medium](x), tts::mpfr_exec(mtan, x), 2 * tts::epsprec<pv_t>());
    }
  }
  {
    using pv_t = plf::polyfloat<double, 2>;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(tan[eve::medium](pa), tts::mpfr_exec(mtan, pa), 2 * tts::epsprec<pv_t>());
    auto pio4 = plf::pio_4(eve::as<pv_t>());
    for (pv_t i = 0; i < pio4; i += pv_t(0.05))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(tan[eve::medium](x), tts::mpfr_exec(mtan, x), 2 * tts::epsprec<pv_t>());
    }
    std::cout << std::setprecision(32) << tan[eve::medium](pv_t(0.744)) << std::endl;
  }
  {
    using pv_t = plf::polyfloat<float, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(tan[eve::medium](pa), tts::mpfr_exec(mtan, pa), 2 * tts::epsprec<pv_t>());
    auto pio4 = plf::pio_4(eve::as<pv_t>());
    for (pv_t i = 0; i < pio4; i += pv_t(0.0051))
    {
      pv_t x(i);
      TTS_RELATIVE_EQUAL(tan[eve::medium](x), tts::mpfr_exec(mtan, x), 2 * tts::epsprec<pv_t>());
    }
  }
  {
    using pv_t = plf::polyfloat<double, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(tan[eve::medium](pa), tts::mpfr_exec(mtan, pa), 2 * tts::epsprec<pv_t>());
    auto pio4 = plf::pio_4(eve::as<pv_t>());
    for (pv_t i = 0; i < pio4; i += pv_t(0.005))
    {
      pv_t x(i);
      std::cout << i << "-> " << tan[eve::medium](x) << " ==  " << tts::mpfr_exec(mtan, x) << std::endl;
      TTS_RELATIVE_EQUAL(tan[eve::medium](x), tts::mpfr_exec(mtan, x), 2 * tts::epsprec<pv_t>());
    }
  }
};
