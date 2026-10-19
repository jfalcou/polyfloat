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
  "Check asinh ", plf::scalar_real_types, tts::randoms(0, 1), tts::randoms(0.0, 1.e-20), tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::asin;
  auto masin = [](auto a) { return mpfr::asin(a); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(asin(pa), tts::mpfr_exec(masin, pa), 2 * tts::epsprec<pv_t>()) << "pa " << pa << "\n";
    pv_t o(T(0.625), T(0));
    TTS_RELATIVE_EQUAL(asin(o), tts::mpfr_exec(masin, o), tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    TTS_IEEE_EQUAL(plf::asin(z), z);

    for (pv_t i = 0; i < 1; i += pv_t(0.01))
    {
      TTS_RELATIVE_EQUAL(plf::asin(i), tts::mpfr_exec(masin, i), 8 * tts::epsprec<pv_t>()) << "i " << i << "\n";
    }
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(asin(pa), tts::mpfr_exec(masin, pa), tts::epsprec<pv_t>()) << "pa " << pa << "\n";
    pv_t o(T(0.625), T(0));
    TTS_RELATIVE_EQUAL(asin(o), tts::mpfr_exec(masin, o), tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    TTS_IEEE_EQUAL(plf::asin(z), z);

    for (pv_t i = 0; i < 1; i += pv_t(0.01))
    {
      TTS_RELATIVE_EQUAL(plf::asin(i), tts::mpfr_exec(masin, i), 8 * tts::epsprec<pv_t>()) << "i " << i << "\n";
    }
  }
};
