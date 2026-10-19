//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check three_pio_4", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using mpfr::mpreal;
  using plf::three_pio_4;
  auto mthree_pio_4 = []<typename TT>(TT) { return mpfr::mpreal(atan(1) * 3); };
  {
    {
      TTS_EQUAL(three_pio_4(eve::as<T>()), eve::three_pio_4(eve::as<T>()));
    }
    {
      using pv_t = plf::polyfloat<T, 2>;
      TTS_RELATIVE_EQUAL(three_pio_4(eve::as<pv_t>()), tts::mpfr_exec(mthree_pio_4, pv_t()), tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      TTS_RELATIVE_EQUAL(three_pio_4(eve::as<pv_t>()), tts::mpfr_exec(mthree_pio_4, pv_t()), tts::epsprec<pv_t>());
    }
  }
};
