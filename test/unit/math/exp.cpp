//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>



TTS_CASE_WITH("Check exp ",
              plf::scalar_real_types,
              tts::randoms(0.0,0.3),
              tts::randoms(0.0,0.3e-20),
              tts::randoms(0.0,0.3e-50)
             )
  <typename T>(T const& , T const& , T const& )
{
  using  mpfr::mpreal;
  using plf::exp;
  auto mexp = [](auto a){return mpfr::exp(a); };
//   {
//     using pv_t  = plf::polyfloat<T, 2>;
//     pv_t pa(a0, a1);
//     TTS_RELATIVE_EQUAL(exp(pa), tts::mpfr_exec(mexp, pa), tts::epsprec<pv_t>());
//     pv_t o(T(1), T(0));
//     TTS_RELATIVE_EQUAL(exp(o), tts::mpfr_exec(mexp, o), tts::epsprec<pv_t>());
//     pv_t z(T(0), T(0));
//     TTS_RELATIVE_EQUAL(exp(z), o, tts::epsprec<pv_t>());
//   }
  {
    using pv_t  = plf::polyfloat<T, 3>;
//     pv_t pa(a0, a1, a2);
//     TTS_RELATIVE_EQUAL(exp(pa), tts::mpfr_exec(mexp, pa), tts::epsprec<pv_t>());
    pv_t o(T(1), T(0), T(0));
    pv_t a = plf::exp(o);
    TTS_RELATIVE_EQUAL(exp(o), tts::mpfr_exec(mexp, o), tts::epsprec<pv_t>());
    std::cout << "mpreal " << std::setprecision(50) << mpfr::exp(1) << std::endl;
    std::cout << "plf " << tts::to_mpreal(plf::hi(a))+tts::to_mpreal(plf::md(a))+tts::to_mpreal(plf::lo(a)) << std::endl;
    pv_t e = plf::euler(eve::as<eve::element_type_t<pv_t>>());
    std::cout << "plf " << tts::to_mpreal(plf::hi(e))+tts::to_mpreal(plf::md(e))+tts::to_mpreal(plf::lo(e)) << std::endl;

//     TTS_RELATIVE_EQUAL(exp(o), tts::to_polyfloat(mpfr::exp(1), eve::as(o)), tts::epsprec<pv_t>());
//     pv_t z(T(0), T(0), T(0));
//     TTS_RELATIVE_EQUAL(exp(z), o, tts::epsprec<pv_t>());

  }
};
