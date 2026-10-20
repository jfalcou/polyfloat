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
  "Check asech ", plf::scalar_real_types, tts::randoms(1, 1000), tts::randoms(0.0, 1.e-20), tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::asec;
  auto masec = [](auto a) { return mpfr::asec(a); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(asec(pa), tts::mpfr_exec(masec, pa), 2 * tts::epsprec<pv_t>()) << "pa " << pa << "\n";
    pv_t z(T(0), T(0));
    TTS_IEEE_EQUAL(plf::asec(z), plf::inf(eve::as(z)));
    TTS_IEEE_EQUAL(plf::asec(-z), plf::nan(eve::as(z)));

    for (pv_t i = 0; i < 1; i += pv_t(0.01))
    {
      auto ii = plf::rec(i);
      TTS_RELATIVE_EQUAL(plf::asec(ii), tts::mpfr_exec(masec, ii), 8 * tts::epsprec<pv_t>()) << "ii " << ii << "\n";
    }
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(asec(pa), tts::mpfr_exec(masec, pa), tts::epsprec<pv_t>()) << "pa " << pa << "\n";
    pv_t z(T(0), T(0));
    TTS_IEEE_EQUAL(plf::asec(z), plf::inf(eve::as(z)));
    TTS_IEEE_EQUAL(plf::asec(-z), plf::nan(eve::as(z)));

    for (pv_t i = 0; i < 1; i += pv_t(0.01))
    {
      auto ii = plf::rec(i);
      TTS_RELATIVE_EQUAL(plf::asec(ii), tts::mpfr_exec(masec, ii), 8 * tts::epsprec<pv_t>()) << "ii " << ii << "\n";
    }
  }
};
