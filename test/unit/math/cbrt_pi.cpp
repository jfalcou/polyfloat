//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check cbrt_pi", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using mpfr::mpreal;
  using plf::cbrt_pi;
  auto mcbrt_pi = []<typename TT>(TT) { return pow(mpfr::const_pi(), mpfr::mpreal(1) / 3); };
  {
    {
      TTS_EQUAL(cbrt_pi(eve::as<T>()), eve::cbrt_pi(eve::as<T>()));
    }
    {
      using pv_t = plf::polyfloat<T, 2>;
      TTS_RELATIVE_EQUAL(cbrt_pi(eve::as<pv_t>()), tts::mpfr_exec(mcbrt_pi, pv_t()), tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      TTS_RELATIVE_EQUAL(cbrt_pi(eve::as<pv_t>()), tts::mpfr_exec(mcbrt_pi, pv_t()), tts::epsprec<pv_t>());
    }
  }
};
