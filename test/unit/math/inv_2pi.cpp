//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check inv_2pi", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using mpfr::mpreal;
  using plf::inv_2pi;
  auto minv_2pi = []<typename TT>(TT) { return mpfr::mpreal(1 / (mpfr::const_pi() * 2)); };
  {
    {
      TTS_EQUAL(inv_2pi(eve::as<T>()), eve::inv_2pi(eve::as<T>()));
    }
    {
      using pv_t = plf::polyfloat<T, 2>;
      TTS_RELATIVE_EQUAL(inv_2pi(eve::as<pv_t>()), tts::mpfr_exec(minv_2pi, pv_t()), tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      TTS_RELATIVE_EQUAL(inv_2pi(eve::as<pv_t>()), tts::mpfr_exec(minv_2pi, pv_t()), tts::epsprec<pv_t>());
    }
  }
};
