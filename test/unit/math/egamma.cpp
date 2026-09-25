//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check egamma", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using mpfr::mpreal;
  using plf::egamma;
  auto megamma = []<typename TT>(TT) {
    return mpfr::mpreal(
      "0.5772156649015328606065120900824024310421593359399235988057672348848677267776646709369470632917467495");
  };
  {
    {
      TTS_EQUAL(egamma(eve::as<T>()), eve::egamma(eve::as<T>()));
    }
    {
      using pv_t = plf::polyfloat<T, 2>;
      TTS_RELATIVE_EQUAL(egamma(eve::as<pv_t>()), tts::mpfr_exec(megamma, pv_t()), tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      TTS_RELATIVE_EQUAL(egamma(eve::as<pv_t>()), tts::mpfr_exec(megamma, pv_t()), tts::epsprec<pv_t>());
    }
  }
};
