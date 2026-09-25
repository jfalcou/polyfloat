//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check catalan", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using mpfr::mpreal;
  using plf::catalan;
  auto mcatalan = []<typename TT>(TT) {
    return mpfr::mpreal(
      "0.9159655941772190150546035149323841107741493742816721342664981196217630197762547694793565129261151062");
  };
  {
    {
      TTS_EQUAL(catalan(eve::as<T>()), eve::catalan(eve::as<T>()));
    }
    {
      using pv_t = plf::polyfloat<T, 2>;
      TTS_RELATIVE_EQUAL(catalan(eve::as<pv_t>()), tts::mpfr_exec(mcatalan, pv_t()), tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      TTS_RELATIVE_EQUAL(catalan(eve::as<pv_t>()), tts::mpfr_exec(mcatalan, pv_t()), tts::epsprec<pv_t>());
    }
  }
};
