//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check rat",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::rat;
  auto mdiv = [](auto a, auto b) { return a / b; };
  {
    {
      using pv_t = plf::polyfloat<T, 2>;
      pv_t pa(a0, a1);
      auto [npa, dpa] = rat(pa);
      TTS_RELATIVE_EQUAL(pa, tts::mpfr_exec(mdiv, npa, dpa), tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      auto [npa, dpa] = rat(pa);
      TTS_RELATIVE_EQUAL(pa, tts::mpfr_exec(mdiv, npa, dpa), tts::epsprec<pv_t>());
    }
  }
};
