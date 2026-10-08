//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check cos[eve::radpi] ",
              plf::scalar_real_types,
              tts::randoms(-100, 100),
              tts::randoms(0.0, 1.e-20),
              tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::cos;
  auto mcospi = [](auto a) { return mpfr::cos(a * mpfr::const_pi()); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t nan(plf::nan(eve::as<pv_t>()));
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(cos[eve::radpi][eve::medium](pa), tts::mpfr_exec(mcospi, pa), tts::epsprec<pv_t>());
    pv_t o(T(1.0) / 3, T(0));
    TTS_RELATIVE_EQUAL(cos[eve::radpi][eve::medium](o), tts::mpfr_exec(mcospi, o), tts::epsprec<pv_t>());
    pv_t oe = plf::inc(plf::eps(eve::as(o)));
    TTS_RELATIVE_EQUAL(cos[eve::radpi][eve::medium](oe), tts::mpfr_exec(mcospi, oe), tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    TTS_IEEE_EQUAL(plf::cos[eve::radpi][eve::medium](z), plf::one(eve::as(z)));
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(cos[eve::radpi][eve::medium](inf), nan);
    TTS_IEEE_EQUAL(cos[eve::radpi][eve::medium](nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(cos[eve::radpi][eve::medium](minf), nan);
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t nan(plf::nan(eve::as<pv_t>()));
    pv_t inf(plf::inf(eve::as<pv_t>()));
    pv_t minf(plf::minf(eve::as<pv_t>()));
    pv_t pa(a0, a1, a2);
    //    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_RELATIVE_EQUAL(cos[eve::radpi][eve::medium](pa), tts::mpfr_exec(mcospi, pa), tts::epsprec<pv_t>());
    pv_t o(T(1.0) / 3, T(0), T(0));
    TTS_RELATIVE_EQUAL(cos[eve::radpi][eve::medium](o), tts::mpfr_exec(mcospi, o), tts::epsprec<pv_t>());
    pv_t z(T(0), T(0), T(0));
    TTS_IEEE_EQUAL(plf::cos[eve::radpi][eve::medium](z), plf::one(eve::as(z)));
    TTS_IEEE_EQUAL(cos[eve::radpi][eve::medium](inf), nan);
    TTS_IEEE_EQUAL(cos[eve::radpi][eve::medium](nan), nan);
    TTS_IEEE_EQUAL(cos[eve::radpi][eve::medium](minf), nan);
  }
};
