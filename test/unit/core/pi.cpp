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
  std::cout << plf::invlog_10(eve::as<plf::polyfloat<T, 2>>()) << std::endl;
  auto mpi = []<typename TT>(TT) { return 4 * atan(1); };
  {
    {
      std::cout << plf::pi(eve::as<T>()) << std::endl;
      TTS_RELATIVE_EQUAL(pi(eve::as<T>()), eve::pi(eve::as<T>()));
      std::cout << 0x1.921fb54442d18p+1 << std::endl;
    }
    {
      using pv_t = plf::polyfloat<T, 2>;
      std::cout << plf::pi(eve::as<pv_t>()) << std::endl;
      TTS_RELATIVE_EQUAL(pi(eve::as<pv_t>()), tts::mpfr_exec(mpi, pv_t()), tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      TTS_RELATIVE_EQUAL(pi(eve::as<pv_t>()), tts::mpfr_exec(mpi, pv_t()), tts::epsprec<pv_t>());
    }
  }
};
