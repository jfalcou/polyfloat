//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check sigmoid",
              plf::scalar_real_types,
              tts::randoms(-10.0, 10.0),
              tts::randoms(0.0, 1.e-20),
              tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::sigmoid;
  auto msigmoid = [](auto b) { return 1 / (1 + mpfr::exp(-b)); };
  {
    {
      using pv_t = plf::polyfloat<T, 2>;
      pv_t pa(a0, a1);
      TTS_RELATIVE_EQUAL(sigmoid(pa), tts::mpfr_exec(msigmoid, pa), 10000 * tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      TTS_RELATIVE_EQUAL(sigmoid(pa), tts::mpfr_exec(msigmoid, pa), 10000 * tts::epsprec<pv_t>());
    }
  }
};
