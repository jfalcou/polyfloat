//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check four_minus_pi", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using mpfr::mpreal;
  using plf::four_minus_pi;
  auto mfour_minus_pi = []<typename TT>(TT) { return mpfr::mpreal(4 - mpfr::const_pi()); };
  {
    {
      TTS_EQUAL(four_minus_pi(eve::as<T>()), eve::four_minus_pi(eve::as<T>()));
    }
    {
      using pv_t = plf::polyfloat<T, 2>;
      TTS_RELATIVE_EQUAL(four_minus_pi(eve::as<pv_t>()), tts::mpfr_exec(mfour_minus_pi, pv_t()), tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      TTS_RELATIVE_EQUAL(four_minus_pi(eve::as<pv_t>()), tts::mpfr_exec(mfour_minus_pi, pv_t()), tts::epsprec<pv_t>());
    }
  }
};
