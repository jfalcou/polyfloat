//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check is_less",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax), //TODO
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax)
            )
<typename T>(T const& a0, T const& a1, T const& a2,
             T const& a3, T const& a4, T const& a5)
{
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_EQUAL(plf::is_less(pa, pb), plf::is_ltz(pa-pb));
    auto t =  eve::as_logical_t<T>(true);
    pv_t z(-1.0, 0.005);
    std::cout << "plf::is_ltz(z) " << plf::is_ltz(z) << std::endl;
    std::cout << "eve::is_ltz(hi(z)) " <<eve::is_ltz(plf::hi(z))<< std::endl;
    TTS_EQUAL(plf::is_less(pa, pb), t);
    std::cout << plf::is_ltz(pa-pb) << std::endl;
    std::cout << plf::is_ltz(pb-pa) << std::endl;
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_EQUAL(plf::is_less(pa, pb), plf::is_ltz(pa-pb));
  }
};
