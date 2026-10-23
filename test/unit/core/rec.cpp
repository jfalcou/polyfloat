//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check rec",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::rec;
  auto mrec = [](auto b) { return 1 / b; };
  {
    {
      using pv_t = plf::polyfloat<T, 2>;
      pv_t pa(a0, a1);
      pv_t rpa = plf::rec(pa);
      TTS_RELATIVE_EQUAL(rpa, tts::mpfr_exec(mrec, pa), tts::epsprec<pv_t>());
      pv_t inf(plf::inf(eve::as(pa)));
      TTS_EQUAL(plf::rec(inf), pv_t(0));
      TTS_EQUAL(plf::rec(plf::zero(eve::as(pa))), inf);
      TTS_EQUAL(plf::rec(plf::mzero(eve::as(pa))), -inf);
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      pv_t rpa = plf::rec(pa);
      TTS_RELATIVE_EQUAL(rpa, tts::mpfr_exec(mrec, pa), tts::epsprec<pv_t>());
      pv_t inf(plf::inf(eve::as(pa)));
      TTS_EQUAL(plf::rec(inf), pv_t(0));
      TTS_EQUAL(plf::rec(plf::zero(eve::as(pa))), inf);
      TTS_EQUAL(plf::rec(plf::mzero(eve::as(pa))), -inf);
    }

    using pv_t = plf::polyfloat<float, 3>;
    pv_t f = plf::_::from_triple(-0x1.38ab52p-1f, + 0x1.2a9844p-69f, 0x1.53ed1ap-102f);
    std::cout << " f " << f << std::endl;
    std::cout << " rec(f) " << plf::rec(f) << std::endl;
    std::cout << " pv_t(1)/f    " << pv_t(1)/f << std::endl;
    std::cout << " 1.0f/f       "  << 1.0f/f    << std::endl;
    std::cout << " cos(f)    "  << plf::acos( 1.0f/f)   << std::endl;
    std::cout << " acsec(f)     "  << plf::asec(f)   << std::endl;
//tts::mpfr_exec(msec, pa) but 1.20155 - 5.2741e-08 + 1.13269e-15 == 1.22062 + 4.86012e-08 - 9.13215e-16 within 0.015625 rel
//    when  2.1175824e-22 rel were expected.
  auto mcos = [](auto a) { return mpfr::cos(a); };
  auto msec = [](auto a) { return mpfr::mpreal("1")/mpfr::cos(a);};
  auto msec2= [](auto a) { return                   mpfr::sec(a);};
  std::cout << plf::cos[eve::medium](f) << std::endl;
  std::cout << tts::mpfr_exec(mcos, f)<< std::endl;
  std::cout << plf::rec(plf::cos[eve::medium](f)) << std::endl;
  std::cout << pv_t(1)/plf::cos[eve::medium](f)   << std::endl;
  std::cout << tts::mpfr_exec(msec, f)<< std::endl;
  std::cout << tts::mpfr_exec(msec2, f)<< std::endl;

  }

};
