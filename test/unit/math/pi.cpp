//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check pi", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using mpfr::mpreal;
  using plf::pi;
  auto mpi = []<typename TT>(TT) { return mpfr::const_pi(); };
  {
    {
      TTS_EQUAL(pi(eve::as<T>()), eve::pi(eve::as<T>()));
    }
    {
      using pv_t = plf::polyfloat<T, 2>;
      TTS_RELATIVE_EQUAL(pi(eve::as<pv_t>()), tts::mpfr_exec(mpi, pv_t()), tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      TTS_RELATIVE_EQUAL(pi(eve::as<pv_t>()), tts::mpfr_exec(mpi, pv_t()), tts::epsprec<pv_t>());
    }
  }
};
