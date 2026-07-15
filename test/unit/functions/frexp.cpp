//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>
#include <iostream>
#include <iomanip>

TTS_CASE_WITH("Check frexp",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000)
             )
  <typename T>(T const& a0, T const& a1, T const& a2)
{
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    auto [m, n] = plf::frexp(pa);
    std::cout << std::setprecision(15)<< m << "  " << n << std::endl;
    std::cout << tts::typename_<decltype(n)>  << std::endl;
    TTS_EQUAL(pa, plf::ldexp(m, n));
  }

  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    auto [m, n] = plf::frexp(pa);
    std::cout << std::setprecision(15)<< m << "  " << n << std::endl;
    std::cout << tts::typename_<decltype(n)>  << std::endl;
    TTS_EQUAL(pa, plf::ldexp(m, n));
  }
};
