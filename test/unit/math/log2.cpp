//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check log2 ",
              plf::scalar_real_types,
              tts::randoms(0.0,1000.0),
              tts::randoms(0.0, 1.e-20),
              tts::randoms(0.0, 1.e-30)
             )
  <typename T>(T const& a0, T const& a1, T const& a2)
{
  using  mpfr::mpreal;
  using plf::log2;
  auto mlog2 = [](auto a){return mpfr::log(a)/mpfr::log(2); };
  {
     using pv_t  = plf::polyfloat<T, 2>;
     pv_t pa(a0, a1);
     TTS_RELATIVE_EQUAL(log2(pa), tts::mpfr_exec(mlog2, pa), 256*tts::epsprec<pv_t>());
     pv_t o(T(1), T(0));
     pv_t z(T(0), T(0));
     pv_t inf(plf::inf(eve::as<pv_t>()));
     pv_t minf(plf::minf(eve::as<pv_t>()));
     pv_t nan(plf::nan(eve::as<pv_t>()));
     TTS_EQUAL(log2(o), z);
     TTS_EQUAL(plf::log2(z), minf);
     TTS_EQUAL(log2(inf), inf);
     TTS_IEEE_EQUAL(log2(nan), nan);
     TTS_IEEE_EQUAL(log2(-o), nan);
  }
 {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(log2(pa), tts::mpfr_exec(mlog2, pa), 204804*tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    pv_t z(T(0), T(0));
    pv_t inf(plf::inf(eve::as<pv_t>()));
    pv_t minf(plf::minf(eve::as<pv_t>()));
    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_EQUAL(log2(o), z);
    TTS_EQUAL(plf::log2(z), minf);
    TTS_EQUAL(log2(inf), inf);
    TTS_IEEE_EQUAL(log2(nan), nan);
    TTS_IEEE_EQUAL(log2(-o), nan);
  }
};
