//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check cosh_1", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using mpfr::mpreal;
  using plf::cosh_1;
  auto mcosh_1 = []<typename TT>(TT) { return mpfr::cosh(1); };
  {
    {
      TTS_EQUAL(cosh_1(eve::as<T>()), eve::cosh_1(eve::as<T>()));
    }
    {
      using pv_t = plf::polyfloat<T, 2>;
      TTS_RELATIVE_EQUAL(cosh_1(eve::as<pv_t>()), tts::mpfr_exec(mcosh_1, pv_t()), tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      TTS_RELATIVE_EQUAL(cosh_1(eve::as<pv_t>()), tts::mpfr_exec(mcosh_1, pv_t()), tts::epsprec<pv_t>());
    }
  }
};
