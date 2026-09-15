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
  "Check exp10 ", plf::scalar_real_types, tts::randoms(-37, 37.0), tts::randoms(0.0, 1.e-20), tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::exp10;
  auto mexp10 = [](auto a) { return mpfr::exp(mpfr::log(10) * a); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    std::cout << plf::exp(plf::log_10(eve::as<pv_t>())) << std::endl;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(exp10(pa), tts::mpfr_exec(mexp10, pa), 128 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    TTS_RELATIVE_EQUAL(exp10(o), tts::mpfr_exec(mexp10, o), 128 * tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    auto ez = plf::exp10(z);
    TTS_EQUAL(plf::hi(ez), T(1));
    TTS_EQUAL(plf::lo(ez), T(0));
    TTS_EQUAL(plf::exp10(z), o);
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(exp10(inf), inf);
    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(exp10(nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_EQUAL(exp10(minf), z);
    pv_t maxlogp1(plf::maxlog(eve::as<pv_t>()) + 1);
    TTS_EQUAL(exp10(maxlogp1), inf);
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    std::cout << plf::exp(plf::log_10(eve::as<pv_t>())) << std::endl;
    TTS_RELATIVE_EQUAL(exp10(pa), tts::mpfr_exec(mexp10, pa), 80000 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0), T(0));
    TTS_RELATIVE_EQUAL(exp10(o), tts::mpfr_exec(mexp10, o), 8 * tts::epsprec<pv_t>());
    pv_t z(T(0), T(0), T(0));
    TTS_RELATIVE_EQUAL(exp10(z), o, tts::epsprec<pv_t>());
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(exp10(inf), inf);
    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(exp10(nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_EQUAL(exp10(minf), z);
    pv_t maxlogp1(plf::maxlog(eve::as<pv_t>()) + 1);
    TTS_EQUAL(exp10(maxlogp1), inf);
  }
};
