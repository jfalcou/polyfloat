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
  "Check sinc ", plf::scalar_real_types, tts::randoms(-100, 100), tts::randoms(0.0, 1.e-20), tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::sinc;
  auto msinc = [](auto a) { return a == 0 ? 1 : mpfr::sin(a) / a; };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(sinc[eve::medium](pa), tts::mpfr_exec(msinc, pa), tts::epsprec<pv_t>());
    pv_t o(T(1.0) / 3, T(0));
    TTS_RELATIVE_EQUAL(sinc[eve::medium](o), tts::mpfr_exec(msinc, o), 10 * tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    TTS_IEEE_EQUAL(plf::sinc[eve::medium](z), plf::one(eve::as(z)));
    pv_t nan(plf::nan(eve::as<pv_t>()));
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(sinc[eve::medium](inf), z);
    TTS_IEEE_EQUAL(sinc[eve::medium](nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(sinc[eve::medium](minf), z);
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t nan(plf::nan(eve::as<pv_t>()));
    pv_t inf(plf::inf(eve::as<pv_t>()));
    pv_t minf(plf::minf(eve::as<pv_t>()));
    pv_t pa(a0, a1, a2);
    //    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_RELATIVE_EQUAL(sinc[eve::medium](pa), tts::mpfr_exec(msinc, pa), tts::epsprec<pv_t>());
    pv_t o(T(1.0) / 3, T(0), T(0));
    TTS_RELATIVE_EQUAL(sinc[eve::medium](o), tts::mpfr_exec(msinc, o), tts::epsprec<pv_t>());
    pv_t z(T(0), T(0), T(0));
    TTS_IEEE_EQUAL(plf::sinc[eve::medium](z), plf::one(eve::as(z)));
    TTS_IEEE_EQUAL(sinc[eve::medium](inf), z);
    TTS_IEEE_EQUAL(sinc[eve::medium](nan), nan);
    TTS_IEEE_EQUAL(sinc[eve::medium](minf), z);
  }
};
