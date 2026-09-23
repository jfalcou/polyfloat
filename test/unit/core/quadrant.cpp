//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check quadrant", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using plf::quadrant;
  using pv2_t = plf::double_real_t<T>;
  using pv3_t = plf::triple_real_t<T>;
  for (int i = -10; i < 11; ++i)
  {
    TTS_EQUAL(pv2_t(plf::quadrant(i)), plf::quadrant(pv2_t(i)));
    TTS_EQUAL(pv3_t(plf::quadrant(i)), plf::quadrant(pv3_t(i)));
  }
};
