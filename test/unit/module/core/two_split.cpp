//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check two_split params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1e-30, 1e-30),
              tts::randoms(-1e-35, 1e-35)
             )
  <typename T>(T const& a0, T const& a1, T const& a2)
{
  using  mpfr::mpreal;
  {
    auto pa = a0;
    auto [s, e] = plf::two_split(pa);
    std::cout << s << ",    " << e << std::endl;
    auto z0 = tts::to_mpreal(pa);
    auto z1 = tts::to_mpreal(s)+tts::to_mpreal(e);
    TTS_EQUAL(z0, z1);
  }
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);

    auto [s, e] = plf::two_split(pa);
    std::cout << s << ",    " << e << std::endl;
    auto z0 = tts::to_mpreal(pa);
    auto z1 = tts::to_mpreal(s)+tts::to_mpreal(e);
    TTS_EQUAL(z0, z1);
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    auto [s, e] = plf::two_split(pa);
    std::cout << s << " ,   " << e << std::endl;
    auto z0 = tts::to_mpreal(pa);
    auto z1 = tts::to_mpreal(s)+tts::to_mpreal(e);
    TTS_EQUAL(z0, z1);
  }
};
