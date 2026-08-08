//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check is_even",
              plf::scalar_real_types,
              tts::randoms(0, 1.0e30),
              tts::randoms(0, 1.0e15),
              tts::randoms(0, 19)
             )
  <typename T>(T const& a0, T const& a1, T const& a2)
{

  auto f = []<typename Z>(Z z){
    using plf::hi;
    using plf::lo;
    using plf::md;
    auto t = plf::is_flint(z);
    auto hieven = eve::is_even(hi(z));
    auto loeven = eve::is_even(lo(z));
    auto loeqz = eve::is_eqz(lo(z));

    if constexpr(plf::dimension_v<Z> == 2)
    {
      return t && ((hieven && loeqz) || (loeven && !loeqz));
    }
    else if constexpr(plf::dimension_v<Z> == 3)
    {
      auto mdeqz = eve::is_eqz(md(z));
      auto mdeven = eve::is_even(md(z));
      auto t1 = loeqz && mdeqz;
      return t && ((t1 && hieven) ||
                   (!mdeqz  && mdeven) ||
                   (!loeqz  && loeven));
    }
  };

  using plf::is_even;
  using eve::trunc;
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(trunc(a0), trunc(a1));
    TTS_EQUAL(is_even(pa), f(pa));
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(trunc(a0), trunc(a1), trunc(a2));
    TTS_EQUAL(is_even(pa), f(pa));
  }
};
