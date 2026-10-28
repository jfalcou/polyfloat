//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check inc",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using plf::inc;
  {
    {
      using pv_t = plf::polyfloat<T, 2>;
      pv_t pa(a0, a1);
      TTS_EQUAL(inc(pa), pa + 1);
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      TTS_EQUAL(inc(pa), pa + 1);
    }
  }
};

//==================================================================================================
//==  inc modular tests
//==================================================================================================
TTS_CASE_WITH("Check behavior of inc mod on wide", plf::scalar_real_types, tts::randoms(0, 96))
<typename T>(T const& ra0)
{
  using eve::mod;
  using plf::inc;
  {
    using pv_t = T;
    pv_t a0 = plf::floor(ra0);
    using e_t = eve::element_type_t<T>;
    e_t p = 97;
    std::cout << "a0 " << a0 << std::endl;
    std::cout << "p  " << p << std::endl;
    TTS_EQUAL(inc[mod = p](a0), plf::if_else(a0 == 0, p - 1, a0 + 1));
  }
  {
    using pv_t = plf::double_real_t<T>;
    pv_t a0 = plf::floor(ra0);
    using e_t = eve::element_type_t<T>;
    e_t p = 97;
    TTS_EQUAL(inc[mod = p](a0), plf::if_else(a0 == 0, p - 1, a0 + 1));
  }
};
