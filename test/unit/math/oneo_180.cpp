//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check oneo_180", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using mpfr::mpreal;
  using plf::oneo_180;
  auto moneo_180 = []<typename TT>(TT) { return 1 / mpfr::mpreal("180"); };
  {
    {
      TTS_EQUAL(oneo_180(eve::as<T>()), 1 / T(180));
    }
    {
      using pv_t = plf::polyfloat<T, 2>;
      TTS_RELATIVE_EQUAL(oneo_180(eve::as<pv_t>()), tts::mpfr_exec(moneo_180, pv_t()), tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      TTS_RELATIVE_EQUAL(oneo_180(eve::as<pv_t>()), tts::mpfr_exec(moneo_180, pv_t()), tts::epsprec<pv_t>());
    }
  }
};
