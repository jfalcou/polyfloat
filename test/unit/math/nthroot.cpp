//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check nthroot ",
              plf::scalar_real_types,
              tts::randoms(0.0,1000.0),
              tts::randoms(0.0, 1.e-20),
              tts::randoms(0.0, 1.e-30)
             )
  <typename T>(T const& a0, T const& a1, T const& a2)
{
  using  mpfr::mpreal;
  using plf::nthroot;
  auto msqrt = [](auto a ){return mpfr::sqrt(a); };
  auto msqrt2 = [](auto a ){return mpfr::sqrt(mpfr::sqrt(a)); };
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(nthroot(pa, 2), tts::mpfr_exec(msqrt, pa), 128*tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    TTS_RELATIVE_EQUAL(nthroot(o, 2), tts::mpfr_exec(msqrt, o), 64*tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    TTS_EQUAL(plf::nthroot(z, 2), z);
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(plf::nthroot(inf, 2), inf);
    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(nthroot(nan, 2), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(nthroot(minf, 2), nan);
    TTS_IEEE_EQUAL(nthroot(minf, 3), minf);
    TTS_RELATIVE_EQUAL(nthroot(pa, 4), tts::mpfr_exec(msqrt2, pa), 128*tts::epsprec<pv_t>());
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(nthroot(pa, 2), tts::mpfr_exec(msqrt, pa), 128*tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    TTS_RELATIVE_EQUAL(nthroot(o, 2), tts::mpfr_exec(msqrt, o), 64*tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    TTS_EQUAL(plf::nthroot(z, 2), z);
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(plf::nthroot(inf, 2), inf);
    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(nthroot(nan, 2), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(nthroot(minf, 2), nan);
    TTS_RELATIVE_EQUAL(nthroot(pa, 4), tts::mpfr_exec(msqrt2, pa), 128*tts::epsprec<pv_t>());
  }
};
