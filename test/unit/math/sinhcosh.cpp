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
  "Check sinh ", plf::scalar_real_types, tts::randoms(0.0, 88.0), tts::randoms(0.0, 1.e-20), tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::sinhcosh;
  auto msinh = [](auto a) { return (mpfr::exp(a) - mpfr::exp(-a)) / 2; };
  auto mcosh = [](auto a) { return (mpfr::exp(a) + mpfr::exp(-a)) / 2; };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    auto [spa, cpa] = sinhcosh(pa);
    TTS_RELATIVE_EQUAL(spa, tts::mpfr_exec(msinh, pa), 12800 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(cpa, tts::mpfr_exec(mcosh, pa), 12800 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    auto [spo, cpo] = sinhcosh(o);
    TTS_RELATIVE_EQUAL(spo, tts::mpfr_exec(msinh, o), 12800 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(cpo, tts::mpfr_exec(mcosh, o), 12800 * tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    auto [spz, cpz] = sinhcosh(z);
    TTS_RELATIVE_EQUAL(spz, tts::mpfr_exec(msinh, z), 12800 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(cpz, tts::mpfr_exec(mcosh, z), 12800 * tts::epsprec<pv_t>());
    pv_t inf(plf::inf(eve::as<pv_t>()));
    auto [spinf, cpinf] = sinhcosh(inf);
    TTS_EQUAL(spinf, inf);
    TTS_EQUAL(cpinf, inf);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    auto [spminf, cpminf] = sinhcosh(minf);
    TTS_EQUAL(spminf, minf);
    TTS_EQUAL(cpminf, inf);
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    auto [spa, cpa] = sinhcosh(pa);
    TTS_RELATIVE_EQUAL(spa, tts::mpfr_exec(msinh, pa), 42800 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(cpa, tts::mpfr_exec(mcosh, pa), 42800 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    auto [spo, cpo] = sinhcosh(o);
    TTS_RELATIVE_EQUAL(spo, tts::mpfr_exec(msinh, o), 12800 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(cpo, tts::mpfr_exec(mcosh, o), 12800 * tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    auto [spz, cpz] = sinhcosh(z);
    TTS_RELATIVE_EQUAL(spz, tts::mpfr_exec(msinh, z), 12800 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(cpz, tts::mpfr_exec(mcosh, z), 12800 * tts::epsprec<pv_t>());
    pv_t inf(plf::inf(eve::as<pv_t>()));
    auto [spinf, cpinf] = sinhcosh(inf);
    TTS_EQUAL(spinf, inf);
    TTS_EQUAL(cpinf, inf);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    auto [spminf, cpminf] = sinhcosh(minf);
    TTS_EQUAL(spminf, minf);
    TTS_EQUAL(cpminf, inf);
  }
};
