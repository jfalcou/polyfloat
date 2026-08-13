//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check three_add params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1e-30, 1e-30),
              tts::randoms(-1e-35, 1e-35)
              )
  <typename T>(T const& a0, T const& a1, T const& a2)
{
  using  mpfr::mpreal;
  using plf::three_add;
  {
    auto [s, e0, e1] = plf::three_add(a0, a1, a2);
    std::cout << a0<< ",    " << a1 << ",    " << a2 << std::endl;
    std::cout << s << ",    " << e0 << ",    " << e1 << std::endl;

    auto z0 = tts::to_mpreal(a0)+tts::to_mpreal(a1)+tts::to_mpreal(a2);
    auto z1 = tts::to_mpreal(s)+tts::to_mpreal(e0)+tts::to_mpreal(e1);
    std::cout << z0-z1 << std::endl;
    TTS_EQUAL(z0, z1);
  }
  {
    auto [s, e0, e1] = plf::three_add(a0, a2, a1);
    std::cout << a0<< ",    " << a2 << ",    " << a1 << std::endl;
    std::cout << s << ",    " << e0 << ",    " << e1 << std::endl;

    auto z0 = tts::to_mpreal(a0)+tts::to_mpreal(a1)+tts::to_mpreal(a2);
    auto z1 = tts::to_mpreal(s)+tts::to_mpreal(e0)+tts::to_mpreal(e1);
    std::cout << z0-z1 << std::endl;
    TTS_EQUAL(z0, z1);
  }
  {
    auto [s, e0, e1] = plf::three_add(a1, a0, a2);
    std::cout << a1<< ",    " << a0 << ",    " << a2 << std::endl;
    std::cout << s << ",    " << e0 << ",    " << e1 << std::endl;

    auto z0 = tts::to_mpreal(a0)+tts::to_mpreal(a1)+tts::to_mpreal(a2);
    auto z1 = tts::to_mpreal(s)+tts::to_mpreal(e0)+tts::to_mpreal(e1);
    std::cout << z0-z1 << std::endl;
    TTS_EQUAL(z0, z1);
  }

  {
    auto [s, e0, e1] = plf::three_add(a1, a2, a0);
    std::cout << a1<< ",    " << a2 << ",    " << a0 << std::endl;
    std::cout << s << ",    " << e0 << ",    " << e1 << std::endl;

    auto z0 = tts::to_mpreal(a0)+tts::to_mpreal(a1)+tts::to_mpreal(a2);
    auto z1 = tts::to_mpreal(s)+tts::to_mpreal(e0)+tts::to_mpreal(e1);
    std::cout << z0-z1 << std::endl;
    TTS_EQUAL(z0, z1);
  }
  {
    auto [s, e0, e1] = plf::three_add(a2, a0, a1);
    std::cout << a2<< ",    " << a0 << ",    " << a1 << std::endl;
    std::cout << s << ",    " << e0 << ",    " << e1 << std::endl;

    auto z0 = tts::to_mpreal(a0)+tts::to_mpreal(a1)+tts::to_mpreal(a2);
    auto z1 = tts::to_mpreal(s)+tts::to_mpreal(e0)+tts::to_mpreal(e1);
    std::cout << z0-z1 << std::endl;
    TTS_EQUAL(z0, z1);
  }

  {
    auto [s, e0, e1] = plf::three_add(a2, a1, a0);
    std::cout << a2<< ",    " << a1 << ",    " << a0 << std::endl;
    std::cout << s << ",    " << e0 << ",    " << e1 << std::endl;

    auto z0 = tts::to_mpreal(a0)+tts::to_mpreal(a1)+tts::to_mpreal(a2);
    auto z1 = tts::to_mpreal(s)+tts::to_mpreal(e0)+tts::to_mpreal(e1);
    std::cout << z0-z1 << std::endl;
    TTS_EQUAL(z0, z1);
  }
};

// TTS_CASE_WITH("Check three_add two params",
//               plf::scalar_real_types,
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1e-30, 1e-30),
//               tts::randoms(-1e-35, 1e-35),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1e-30, 1e-30),
//               tts::randoms(-1e-35, 1e-35)

//              )
//   <typename T>(T const& a0, T const& a1, T const& a2,
//                T const& a3, T const& a4, T const& a5,
//               )
// {
//   using  mpfr::mpreal;
//   using plf::three_add;
//   {
//     using pv_t  = plf::polyfloat<T, 2>;
//     pv_t pa(a0, a1);
//     pv_t pb(a3, a4);
//     auto [s, e] = plf::three_add(pa, pb);
//     std::cout << s << ",    " << e << std::endl;
//     auto z0 = tts::to_mpreal(pa)+tts::to_mpreal(pb);
//     auto z1 = tts::to_mpreal(s)+tts::to_mpreal(e);
//     TTS_EQUAL(z0, z1);
//   }
//   {
//     using pv_t  = plf::polyfloat<T, 3>;
//     pv_t pa(a0, a1, a2);
//     pv_t pb(a3, a4, a5);
//     auto [s, e] = plf::three_add(pa, pb);
//     std::cout << s << " ,   " << e << std::endl;
//     auto z0 = tts::to_mpreal(pa)+tts::to_mpreal(pb);
//     auto z1 = tts::to_mpreal(s)+tts::to_mpreal(e);
//     TTS_EQUAL(z0, z1);
//   }
// };
