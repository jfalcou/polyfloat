//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check ulpdist two params",
              plf::scalar_real_types,
//               tts::randoms(eve::valmin, eve::valulpdist), //TODO
//               tts::randoms(eve::valmin, eve::valulpdist),
//               tts::randoms(eve::valmin, eve::valulpdist),
//               tts::randoms(eve::valmin, eve::valulpdist),
//               tts::randoms(eve::valmin, eve::valulpdist),
//               tts::randoms(eve::valmin, eve::valulpdist)
              tts::randoms(-1.e-37, 1.e-37),
              tts::randoms(-1.e-37, 1.e-37),
              tts::randoms(-1.e-37, 1.e-37),
              tts::randoms(-1.e-37, 1.e-37),
              tts::randoms(-1.e-37, 1.e-37),
              tts::randoms(-1.e-37, 1.e-37)
            )
<typename T>(T const& a0, T const& a1 , T const& ,
             T const& a3, T const& a4, T const& )
{
  {
    using pv_t  = T;
    pv_t pa(a0);
    pv_t pb(a3);
    std::cout << "pa "<<  pa << std::endl;
    std::cout << "pb "<<  pb << std::endl;
    std::cout << "eve::dist(pa, pb) "<<  eve::dist(pa, pb) << std::endl;
    std::cout << "eve::plf(pa, pb) "<<  plf::dist(pa, pb) << std::endl;
    TTS_EQUAL(plf::ulpdist(pa, pb), eve::ulpdist(pa, pb));
    TTS_EQUAL(plf::ulpdist(1.0, eve::next(1.0)), eve::ulpdist(1.0, eve::next(1.0)));
    TTS_EQUAL(plf::ulpdist(1.0, 2.0),            eve::ulpdist(1.0, 2.0));
  }
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_EQUAL(plf::ulpdist(pa, pb), plf::if_else(plf::is_less(pa, pb), pb, pa));
  }
//   {
//     using pv_t  = plf::polyfloat<T, 3>;
//     pv_t pa(a0, a1, a2);
//     pv_t pb(a3, a4, a5);
//     TTS_EQUAL(plf::ulpdist(pa, pb), plf::if_else(plf::is_less(pa, pb), pb, pa));
//   }
};
