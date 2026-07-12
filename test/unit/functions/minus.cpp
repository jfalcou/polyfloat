//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

//==================================================================================================
// Types tests
//==================================================================================================
TTS_CASE_TPL( "Check minus", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv_t  = plf::polyfloat<T, 2>;
  using wpv_t = eve::wide<pv_t, eve::fixed<2>>;
//   using wT    = eve::wide<T>;

  pv_t pva(1.0, 1.0e-300);
  pv_t pvb(-1.0, -1.0e-300);
  TTS_EQUAL(plf::minus(pvb), pva);
  TTS_EQUAL(plf::minus(pva), pvb);
  wpv_t ab(pva, pvb);
  std::cout << plf::minus(ab) << std::endl;
  std::cout << plf::is_ltz(ab) <<  std::endl;
  std::cout << plf::minus[plf::is_ltz(ab)](ab) << std::endl;


};


TTS_CASE_WITH("Check minus",
              plf::scalar_real_types,
//               tts::randoms(eve::valmin, eve::valmax), //TODO
//               tts::randoms(eve::valmin, eve::valmax),
//               tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(-1.e-37, 1.e-37),
              tts::randoms(-1.e-37, 1.e-37),
              tts::randoms(-1.e-37, 1.e-37)
            )
<typename T>(T const& a0, T const& a1, T const& a2)
{
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    TTS_EQUAL(plf::minus(pa), -pa);
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    TTS_EQUAL(plf::minus(pa), -pa);
  }
};
