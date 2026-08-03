//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check rsqrt",
              plf::scalar_real_types,
              tts::randoms(eve::zero, eve::valmax),
              tts::randoms(eve::zero, eve::valmax),
              tts::randoms(eve::zero, eve::valmax)
             )
  <typename T>(T const& a0, T const& a1, T const& a2)
{
  using  mpfr::mpreal;
  using plf::rsqrt;
  auto mrsqrt = [](auto b){return 1/mpfr::sqrt(b); };
  {
    {
      using pv_t  = plf::polyfloat<T, 2>;
      pv_t pa(a0, a1);
      TTS_ABSOLUTE_EQUAL(rsqrt(pa), tts::mpfr_exec(mrsqrt, pa), tts::epsprec<decltype(pa)>());
    }
    {
      using pv_t  = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      TTS_ABSOLUTE_EQUAL(rsqrt(pa), tts::mpfr_exec(mrsqrt, pa), tts::epsprec<decltype(pa)>());
    }
  }
};

TTS_CASE_WITH("Check rsqrt",
              plf::scalar_real_types,
              tts::randoms(eve::zero, 1000),
              tts::randoms(eve::zero, 1000),
              tts::randoms(eve::zero, 1000)
             )
  <typename T>(T const& a0, T const& a1, T const& a2)
{
  using  mpfr::mpreal;
  using plf::rsqrt;
  auto mrsqrt = [](auto b){return 1/mpfr::sqrt(b); };
  {
    {
        using pv_t  = plf::polyfloat<T, 2>;
        pv_t pa(a0, a1);
        std::cout << "pa " << pa << std::endl;
      std::cout << tts::typename_<T> << std::endl;
      std::cout << tts::epsprec<decltype(pa)>() << std::endl;
        TTS_ABSOLUTE_EQUAL(rsqrt(pa), tts::mpfr_exec(mrsqrt, pa), tts::epsprec<decltype(pa)>());
    }
    {
      using pv_t  = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      std::cout << tts::typename_<T> << std::endl;
      std::cout << tts::epsprec<decltype(pa)>() << std::endl;
      TTS_ABSOLUTE_EQUAL(rsqrt(pa), tts::mpfr_exec(mrsqrt, pa), tts::epsprec<decltype(pa)>());
    }
  }
};
