//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check modf",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax))
<typename T>(T const& a0, T const& a1, T const& a2){{using pv_t = plf::polyfloat<T, 2>;
pv_t pa(a0, a1);
TTS_EQUAL(plf::modf(pa), (kumi::tuple{plf::frac(pa), plf::trunc(pa)}));
}

{
  using pv_t = plf::polyfloat<T, 3>;
  pv_t pa(a0, a1, a2);
  TTS_EQUAL(plf::modf(pa), (kumi::tuple{plf::frac(pa), plf::trunc(pa)}));
}
}
;
