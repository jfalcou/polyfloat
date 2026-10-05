//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check inv_e", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using mpfr::mpreal;
  using plf::inv_e;
  auto minv_e = []<typename TT>(TT) { return exp(mpfr::mpreal(-1)); };
  {
    {
      TTS_EQUAL(inv_e(eve::as<T>()), eve::inv_e(eve::as<T>()));
    }
    {
      using pv_t = plf::polyfloat<T, 2>;
      TTS_RELATIVE_EQUAL(inv_e(eve::as<pv_t>()), tts::mpfr_exec(minv_e, pv_t()), tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      TTS_RELATIVE_EQUAL(inv_e(eve::as<pv_t>()), tts::mpfr_exec(minv_e, pv_t()), tts::epsprec<pv_t>());
    }
  }
};
