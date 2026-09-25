//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check cos_1", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using mpfr::mpreal;
  using plf::cos_1;
  auto mcos_1 = []<typename TT>(TT) { return mpfr::cos(1); };
  {
    {
      TTS_EQUAL(cos_1(eve::as<T>()), eve::cos_1(eve::as<T>()));
    }
    {
      using pv_t = plf::polyfloat<T, 2>;
      TTS_RELATIVE_EQUAL(cos_1(eve::as<pv_t>()), tts::mpfr_exec(mcos_1, pv_t()), tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      TTS_RELATIVE_EQUAL(cos_1(eve::as<pv_t>()), tts::mpfr_exec(mcos_1, pv_t()), tts::epsprec<pv_t>());
    }
  }
};
