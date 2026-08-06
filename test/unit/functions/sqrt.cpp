//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check sqrt",
              plf::scalar_real_types,
              tts::randoms(eve::zero, eve::valmax),
              tts::randoms(eve::zero, eve::valmax),
              tts::randoms(eve::zero, eve::valmax)
             )
  <typename T>(T const& a0, T const& a1, T const& a2)
{
  using  mpfr::mpreal;
  using plf::sqrt;
  auto msqrt = [](auto b){return mpfr::sqrt(b); };
  {
    {
      using pv_t  = plf::polyfloat<T, 2>;
      pv_t pa(a0, a1);
      TTS_RELATIVE_EQUAL(sqrt[eve::pedantic](pa), tts::mpfr_exec(msqrt, pa), tts::epsprec<pv_t>());
    }
    {
      using pv_t  = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      TTS_RELATIVE_EQUAL(sqrt[eve::pedantic](pa), tts::mpfr_exec(msqrt, pa), tts::epsprec<pv_t>());
    }
  }
};

TTS_CASE_WITH("Check sqrt",
              plf::scalar_real_types,
              tts::randoms(eve::zero, 1000),
              tts::randoms(eve::zero, 1000),
              tts::randoms(eve::zero, 1000)
             )
  <typename T>(T const& a0, T const& a1, T const& a2)
{
  using  mpfr::mpreal;
  using plf::sqrt;
  auto msqrt = [](auto b){return mpfr::sqrt(b); };
  {
    {
      using pv_t  = plf::polyfloat<T, 2>;
      pv_t pa(a0, a1);
      TTS_RELATIVE_EQUAL(sqrt(pa), tts::mpfr_exec(msqrt, pa), tts::epsprec<pv_t>());
    }
   {
      using pv_t  = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      TTS_RELATIVE_EQUAL(sqrt(pa), tts::mpfr_exec(msqrt, pa), tts::epsprec<pv_t>());
    }
  }
};
