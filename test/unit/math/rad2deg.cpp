//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check rad2deg", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using mpfr::mpreal;
  using plf::rad2deg;
  auto mrad2deg = []<typename TT>(TT) { return 180 / mpfr::const_pi(); };
  {
    {
      TTS_RELATIVE_EQUAL(rad2deg(eve::as<T>()), 180 / eve::pi(eve::as(T())), tts::epsprec<T>());
    }
    {
      using pv_t = plf::polyfloat<T, 2>;
      TTS_RELATIVE_EQUAL(rad2deg(eve::as<pv_t>()), tts::mpfr_exec(mrad2deg, pv_t()), tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      TTS_RELATIVE_EQUAL(rad2deg(eve::as<pv_t>()), tts::mpfr_exec(mrad2deg, pv_t()), tts::epsprec<pv_t>());
    }
  }
};
