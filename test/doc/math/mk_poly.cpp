//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("mk poly ", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  if (constexpr(std::same_as<T, float>))
  {
    std::array<char*> t{'1',
                        '-0.4999999999999928945726423989981412888',
                        '4.166666666646534622486797161400318146e-2',
                        '-1.388888886916100906532278713712003082e-3',
                        '2.480157823443436895805014330562698888e-5',
                        '-2.755518625956602835232189807612712684e-7',
                        '2.062775680653932568376805398169260286e-9'};
    using mpfr::mpreal;
    using plf::acosh;

    for (int i = 0; i < t.size(); ++i)
    {
      std::cout << tts::to_polyfloat<float>(mpfr::mpreal(t[i])) << std::endl;
    }
  }
};
