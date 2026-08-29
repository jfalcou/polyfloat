//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>


TTS_CASE_WITH("Check euler",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax)
             )
  <typename T>(T const&)
{
  using pfl3_t = plf::triple_real_t<T>;
  using pfl2_t = plf::double_real_t<T>;
  using pfl1_t = T;

  mpfr::mpreal::set_default_prec(200);
  auto e = mpfr::exp(1);
  TTS_RELATIVE_EQUAL(tts::to_polyfloat(e,  eve::as(pfl2_t())), plf::euler(eve::as<pfl1_t>()), tts::epsprec<pfl1_t>());
  TTS_RELATIVE_EQUAL(tts::to_polyfloat(e,  eve::as(pfl2_t())), plf::euler(eve::as<pfl2_t>()), tts::epsprec<pfl2_t>());
  TTS_RELATIVE_EQUAL(tts::to_polyfloat(e,  eve::as(pfl3_t())), plf::euler(eve::as<pfl3_t>()), tts::epsprec<pfl3_t>());

};
