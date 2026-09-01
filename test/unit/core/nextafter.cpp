//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check nextafter",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax))
<typename T>(T const& a0, T const& a1, T const& a2, T const& a3, T const& a4, T const& a5)
{
  using plf::nextafter;
  using plf::prev;
  {
    if constexpr (sizeof(T) == 8)
    {
      {
        using pv_t = plf::polyfloat<T, 2>;
        pv_t pa(a0, a1);
        pv_t pb(a3, a4);
        TTS_EQUAL(plf::nextafter(pa, pb), plf::if_else(pa < pb, plf::next(pa), plf::prev(pa)));
      }
      {
        using pv_t = plf::polyfloat<T, 3>;
        pv_t pa(a0, a1, a2);
        pv_t pb(a3, a4, a5);
        TTS_EQUAL(plf::nextafter(pa, pb), plf::if_else(pa < pb, plf::next(pa), plf::prev(pa)));
      }
    }
  }
};
