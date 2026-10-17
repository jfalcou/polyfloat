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
  "Check atan ", plf::scalar_real_types, tts::randoms(0, 0.4), tts::randoms(0.0, 1.e-20), tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::atan;
  auto matan = [](auto a) { return mpfr::atan(a); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(atan(pa), tts::mpfr_exec(matan, pa), 2 * tts::epsprec<pv_t>()) << "pa " << pa << "\n";
    pv_t z(T(0), T(0));
    TTS_IEEE_EQUAL(plf::atan(z), plf::zero(eve::as(z)));
    pv_t o(T(1), T(0));
    TTS_IEEE_EQUAL(plf::atan(o), plf::pio_4(eve::as(z)));

    for (pv_t i = 1; i < 2.0; i += pv_t(0.01))
    {
      TTS_RELATIVE_EQUAL(plf::atan(i), tts::mpfr_exec(matan, i), 2 * tts::epsprec<pv_t>()) << "i " << i << "\n";
    }
    auto inf = plf::inf(eve::as<pv_t>());
    auto pio2 = plf::pio_2(eve::as<pv_t>());
    TTS_EQUAL(plf::atan(inf), pio2);
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(atan(pa), tts::mpfr_exec(matan, pa), 2 * tts::epsprec<pv_t>()) << "pa " << pa << "\n";
    pv_t z(T(0), T(0));
    TTS_IEEE_EQUAL(plf::atan(z), plf::zero(eve::as(z)));
    pv_t o(T(1), T(0));
    TTS_IEEE_EQUAL(plf::atan(o), plf::pio_4(eve::as(z)));

    for (pv_t i = 1; i < 2.0; i += pv_t(0.01))
    {
      TTS_RELATIVE_EQUAL(plf::atan(i), tts::mpfr_exec(matan, i), 2 * tts::epsprec<pv_t>()) << "i " << i << "\n";
    }
  }
};
