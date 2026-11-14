//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check mul two params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000))
<typename T>(T const& a0, T const& a1, T const& a2, T const& a3, T const& a4, T const& a5)
{
  using mpfr::mpreal;
  using plf::mul;
  auto mmul = [](auto a, auto b) { return a * b; };
  auto mmul3 = [](auto a, auto b, auto c) { return a * b * c; };
  {
    {
      using pv_t = plf::polyfloat<T, 2>;
      pv_t pa(a0, a1);
      pv_t pb(a3, a4);
      pa += T(1.0e-35);
      pb += T(1.0e-37);
      std::cout << pa << std::endl;
      std::cout << pb << std::endl;
      TTS_RELATIVE_EQUAL(plf::mul(pa, pb), tts::mpfr_exec(mmul, pa, pb), tts::epsprec<pv_t>());
      TTS_RELATIVE_EQUAL(plf::mul(pa, pb, pb), tts::mpfr_exec(mmul3, pa, pb, pb), tts::epsprec<pv_t>());
      TTS_EQUAL(mul(a0, pa), mul(pv_t(a0), pa));
      TTS_EQUAL(mul(pa, a0), mul(pa, pv_t(a0)));
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      pa += T(1.0e-35);
      pv_t pb(a3, a4, a5);
      pb += T(1.0e-37);
      ;
      std::cout << pa << std::endl;
      std::cout << pb << std::endl;
      TTS_RELATIVE_EQUAL(plf::mul(pa, pb), tts::mpfr_exec(mmul, pa, pb), tts::epsprec<pv_t>());
      TTS_EQUAL(mul(a0, pa), mul(pv_t(a0), pa));
      TTS_EQUAL(mul(pa, a0), mul(pa, pv_t(a0)));
      using pv2_t = plf::polyfloat<T, 2>;
      pv_t pb3(a3, a4, T(0));
      pv2_t pb2(a3, a4);
      TTS_EQUAL(mul(pa, pb2), mul(pa, pb3));
    }
  }
};
