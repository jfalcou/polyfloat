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
  "Check agd ", plf::scalar_real_types, tts::randoms(0, 1), tts::randoms(0.0, 1.e-20), tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::agd;
  auto magd = [](auto a) { return 2 * mpfr::atanh(mpfr::tan(a / 2)); };
  {
    auto fac = 8.0e3;
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(agd(pa), tts::mpfr_exec(magd, pa), fac * tts::epsprec<pv_t>()) << "pa " << pa << "\n";
    pv_t o(T(0.625), T(0));
    TTS_RELATIVE_EQUAL(agd(o), tts::mpfr_exec(magd, o), fac * tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    TTS_IEEE_EQUAL(plf::agd(z), z);

    for (pv_t i = 0; i < 1; i += pv_t(0.01))
    {
      TTS_RELATIVE_EQUAL(plf::agd(i), tts::mpfr_exec(magd, i), fac * tts::epsprec<pv_t>()) << "i " << i << "\n";
    }
  }
  {
    auto fac = 5.0e5;
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(agd(pa), tts::mpfr_exec(magd, pa), fac * tts::epsprec<pv_t>()) << "pa " << pa << "\n";
    pv_t o(T(0.625), T(0));
    TTS_RELATIVE_EQUAL(agd(o), tts::mpfr_exec(magd, o), fac * tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    TTS_IEEE_EQUAL(plf::agd(z), z);

    for (pv_t i = 0; i < 1; i += pv_t(0.01))
    {
      TTS_RELATIVE_EQUAL(plf::agd(i), tts::mpfr_exec(magd, i), fac * tts::epsprec<pv_t>()) << "i " << i << "\n";
    }
  }
};
