//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check sinh ",
              plf::scalar_real_types,
              tts::randoms(-3.14 / 4, 3.14 / 4),
              tts::randoms(0.0, 1.e-20),
              tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::sin;
  auto msin = [](auto a) { return mpfr::sin(a); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    //   pv_t nan(plf::nan(eve::as<pv_t>()));
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(sin[eve::quarter_circle](pa), tts::mpfr_exec(msin, pa), tts::epsprec<pv_t>());
    pv_t o(T(1.0) / 3, T(0));
    TTS_RELATIVE_EQUAL(sin[eve::quarter_circle](o), tts::mpfr_exec(msin, o), tts::epsprec<pv_t>());
    //     pv_t oe = plf::inc(plf::eps(eve::as(o)));
    //     std::cout << std::setprecision(30) << sin[eve::quarter_circle](oe) << std::endl;
    //     TTS_RELATIVE_EQUAL(sin[eve::quarter_circle](oe), tts::mpfr_exec(msin, oe), tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    //     TTS_IEEE_EQUAL(plf::sin[eve::quarter_circle](z), nan);
    //     pv_t inf(plf::inf(eve::as<pv_t>()));
    //     TTS_EQUAL(sin[eve::quarter_circle](inf), inf);
    //     TTS_IEEE_EQUAL(sin[eve::quarter_circle](nan), nan);
    //     pv_t minf(plf::minf(eve::as<pv_t>()));
    //     TTS_IEEE_EQUAL(sin[eve::quarter_circle](minf), nan);
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    //    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_RELATIVE_EQUAL(sin[eve::quarter_circle](pa), tts::mpfr_exec(msin, pa), tts::epsprec<pv_t>());
    pv_t o(T(1.0) / 3, T(0), T(0));
    TTS_RELATIVE_EQUAL(sin[eve::quarter_circle](o), tts::mpfr_exec(msin, o), tts::epsprec<pv_t>());
    pv_t z(T(0), T(0), T(0));
    //    TTS_IEEE_EQUAL(sin[eve::quarter_circle](z), nan);
    //     pv_t inf(plf::inf(eve::as<pv_t>()));
    //     TTS_EQUAL(sin[eve::quarter_circle](inf), inf);
    //     TTS_IEEE_EQUAL(sin[eve::quarter_circle](nan), nan);
    //     pv_t minf(plf::minf(eve::as<pv_t>()));
    //     TTS_IEEE_EQUAL(sin[eve::quarter_circle](minf), nan);
  }
};
