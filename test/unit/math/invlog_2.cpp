//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check invlog_2", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using mpfr::mpreal;
  using plf::invlog_2;
  auto minvlog_2 = []<typename TT>(TT) { return 1 / mpfr::const_log2(); };
  {
    {
      TTS_EQUAL(invlog_2(eve::as<T>()), eve::invlog_2(eve::as<T>()));
    }
    {
      using pv_t = plf::polyfloat<T, 2>;
      TTS_RELATIVE_EQUAL(invlog_2(eve::as<pv_t>()), tts::mpfr_exec(minvlog_2, pv_t()), tts::epsprec<pv_t>());
      TTS_EQUAL(plf::hi(invlog_2(eve::as<pv_t>())), invlog_2(eve::as<T>()));
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      TTS_RELATIVE_EQUAL(invlog_2(eve::as<pv_t>()), tts::mpfr_exec(minvlog_2, pv_t()), tts::epsprec<pv_t>());
      TTS_EQUAL(plf::hi(invlog_2(eve::as<pv_t>())), invlog_2(eve::as<T>()));
    }
  }
};
