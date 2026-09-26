//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check pio_6", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using mpfr::mpreal;
  using plf::pio_6;
  auto mpio_6 = []<typename TT>(TT) { return mpfr::const_pi() / 6; };
  {
    {
      TTS_EQUAL(pio_6(eve::as<T>()), eve::pio_6(eve::as<T>()));
    }
    {
      using pv_t = plf::polyfloat<T, 2>;
      TTS_RELATIVE_EQUAL(pio_6(eve::as<pv_t>()), tts::mpfr_exec(mpio_6, pv_t()), tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      TTS_RELATIVE_EQUAL(pio_6(eve::as<pv_t>()), tts::mpfr_exec(mpio_6, pv_t()), tts::epsprec<pv_t>());
    }
  }
};
