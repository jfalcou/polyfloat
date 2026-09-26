//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check radindeg",
              plf::scalar_real_types,
              tts::randoms(-10.0, 10.0),
              tts::randoms(0.0, 1.0e-20),
              tts::randoms(0.0, 1.0e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::radindeg;
  auto mradindeg = [](auto b) { return (180 / mpfr::const_pi()) * b; };
  {
    {
      using pv_t = plf::polyfloat<T, 2>;
      pv_t pa(a0, a1);
      TTS_RELATIVE_EQUAL(radindeg(pa), tts::mpfr_exec(mradindeg, pa), 128 * tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      TTS_RELATIVE_EQUAL(radindeg(pa), tts::mpfr_exec(mradindeg, pa), 128 * tts::epsprec<pv_t>());
    }
  }
};
