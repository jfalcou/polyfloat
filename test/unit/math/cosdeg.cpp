//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check cos[eve::deg] ",
              plf::scalar_real_types,
              tts::randoms(-100, 100),
              tts::randoms(0.0, 1.e-20),
              tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::cos;
  auto mcosdeg = [](auto a) { return mpfr::cos(a * mpfr::const_pi() / 180); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t nan(plf::nan(eve::as<pv_t>()));
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(cos[eve::deg][eve::medium](pa), tts::mpfr_exec(mcosdeg, pa), tts::epsprec<pv_t>());
    pv_t o(T(30), T(0));
    TTS_RELATIVE_EQUAL(cos[eve::deg][eve::medium](o), tts::mpfr_exec(mcosdeg, o), tts::epsprec<pv_t>());
    pv_t oe(T(60), T(0));
    TTS_RELATIVE_EQUAL(cos[eve::deg][eve::medium](oe), tts::mpfr_exec(mcosdeg, oe), tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    TTS_IEEE_EQUAL(plf::cos[eve::deg][eve::medium](z), plf::one(eve::as(z)));
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(cos[eve::deg][eve::medium](inf), nan);
    TTS_IEEE_EQUAL(cos[eve::deg][eve::medium](nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(cos[eve::deg][eve::medium](minf), nan);
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t nan(plf::nan(eve::as<pv_t>()));
    pv_t inf(plf::inf(eve::as<pv_t>()));
    pv_t minf(plf::minf(eve::as<pv_t>()));
    pv_t pa(a0, a1, a2);
    pv_t o(T(30), T(0));
    TTS_RELATIVE_EQUAL(cos[eve::deg][eve::medium](o), tts::mpfr_exec(mcosdeg, o), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(cos[eve::deg][eve::medium](pa), tts::mpfr_exec(mcosdeg, pa), tts::epsprec<pv_t>());
    pv_t oe(T(60), T(0), T(0));
    TTS_RELATIVE_EQUAL(cos[eve::deg][eve::medium](oe), tts::mpfr_exec(mcosdeg, oe), tts::epsprec<pv_t>());
    pv_t z(T(0), T(0), T(0));
    TTS_IEEE_EQUAL(plf::cos[eve::deg][eve::medium](z), plf::one(eve::as(z)));
    TTS_IEEE_EQUAL(cos[eve::deg][eve::medium](inf), nan);
    TTS_IEEE_EQUAL(cos[eve::deg][eve::medium](nan), nan);
    TTS_IEEE_EQUAL(cos[eve::deg][eve::medium](minf), nan);
  }
};
