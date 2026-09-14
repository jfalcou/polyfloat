//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check asech ",
              plf::scalar_real_types,
              tts::randoms(0.2, 1.0),
              tts::randoms(-1.e-20, 0.0),
              tts::randoms(-1.e-30, 0.0))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::asech;
  auto masech = [](auto b) {
    auto a = 1 / b;
    return mpfr::log(a + mpfr::sqrt(a * a - 1));
  };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t nan(plf::nan(eve::as<pv_t>()));
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(asech(pa), tts::mpfr_exec(masech, pa), 128 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    pv_t z(T(0), T(0));
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(asech(o), z);
    TTS_IEEE_EQUAL(plf::asech(z), inf);
    TTS_IEEE_EQUAL(asech(inf), nan);
    TTS_IEEE_EQUAL(asech(nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(asech(minf), nan);
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_RELATIVE_EQUAL(asech(pa), tts::mpfr_exec(masech, pa), 200000 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    pv_t z(T(0), T(0));
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(asech(o), z);
    TTS_IEEE_EQUAL(plf::asech(z), inf);
    TTS_IEEE_EQUAL(asech(inf), nan);
    TTS_IEEE_EQUAL(asech(nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(asech(minf), nan);
  }
};
