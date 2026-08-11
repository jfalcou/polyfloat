//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check three_fma params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000)
              )
  <typename T>(T const& a0, T const& a1, T const& a2)
{
  using  mpfr::mpreal;
  using plf::three_fma;
  {
    auto [s, e0, e1] = plf::three_fma(a0, a1, a2);
    std::cout << a0<< ",    " << a1 << ",    " << a2 << std::endl;
    std::cout << s << ",    " << e0 << ",    " << e1 << std::endl;

    auto z0 = tts::to_mpreal(a0)*tts::to_mpreal(a1)+tts::to_mpreal(a2);
    auto z1 = tts::to_mpreal(s)+tts::to_mpreal(e0)+tts::to_mpreal(e1);
    std::cout << z0-z1 << std::endl;
    TTS_EQUAL(z0, z1);
  }
};
