//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check four_pio_3", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using mpfr::mpreal;
  using plf::four_pio_3;
  auto mfour_pio_3 = []<typename TT>(TT) { return mpfr::mpreal(4 * mpfr::const_pi() / 3); };
  {
    {
      TTS_EQUAL(four_pio_3(eve::as<T>()), eve::four_pio_3(eve::as<T>()));
    }
    {
      using pv_t = plf::polyfloat<T, 2>;
      TTS_RELATIVE_EQUAL(four_pio_3(eve::as<pv_t>()), tts::mpfr_exec(mfour_pio_3, pv_t()), tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      TTS_RELATIVE_EQUAL(four_pio_3(eve::as<pv_t>()), tts::mpfr_exec(mfour_pio_3, pv_t()), tts::epsprec<pv_t>());
    }
  }
};
