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
  "Check expm1 ", plf::scalar_real_types, tts::randoms(0.0, 88.0), tts::randoms(0.0, 1.e-20), tts::randoms(0.0, 1.e-30))
<typename T>(T const&, T const&, T const&)
{
  using mpfr::mpreal;
  using plf::expm1;
  // auto mexpm1 = [](auto a){return mpfr::exp(a)-1; };
  {
    using pv_t = plf::polyfloat<T, 2>;
    //      pv_t pa(a0, a1);
    //      TTS_RELATIVE_EQUAL(expm1(pa), tts::mpfr_exec(mexpm1, pa), 128*tts::epsprec<pv_t>());
    //      pv_t pb(T(0.1));
    //      TTS_RELATIVE_EQUAL(expm1(pb), tts::mpfr_exec(mexpm1, pb), 128*tts::epsprec<pv_t>());
    //      pv_t o(T(1), T(-1));
    //      TTS_RELATIVE_EQUAL(expm1(o), tts::mpfr_exec(mexpm1, o), 64*tts::epsprec<pv_t>());
    //      pv_t z(T(0), T(0));
    //      TTS_EQUAL(plf::expm1(z), z);
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(expm1(inf), inf);
    //      pv_t nan(plf::nan(eve::as<pv_t>()));
    //      TTS_IEEE_EQUAL(expm1(nan), nan);
    //      pv_t minf(plf::minf(eve::as<pv_t>()));
    //      TTS_EQUAL(expm1(minf), -o);
  }
  //   {
  //     using pv_t  = plf::polyfloat<T, 3>;
  //     pv_t pa(a0, a1, a2);
  //     TTS_RELATIVE_EQUAL(expm1(pa), tts::mpfr_exec(mexpm1, pa), 128*tts::epsprec<pv_t>());
  //     pv_t o(T(1), T(0));
  //     TTS_RELATIVE_EQUAL(expm1(o), tts::mpfr_exec(mexpm1, o), 64*tts::epsprec<pv_t>());
  //     pv_t z(T(0), T(0));
  //     TTS_EQUAL(plf::expm1(z), z);
  //     pv_t inf(plf::inf(eve::as<pv_t>()));
  //     TTS_EQUAL(expm1(inf), inf);
  //     pv_t nan(plf::nan(eve::as<pv_t>()));
  //     TTS_IEEE_EQUAL(expm1(nan), nan);
  //     pv_t minf(plf::minf(eve::as<pv_t>()));
  //     TTS_EQUAL(expm1(minf), -o);
  //   }
};
