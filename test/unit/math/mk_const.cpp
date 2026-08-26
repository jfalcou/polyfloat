//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

template<typename aT> auto mk(auto mval, aT)
{
  mpfr::mpreal::set_default_prec(200);
  return tts::to_polyfloat(mval, aT());
} ;

TTS_CASE_WITH("mk_constp ",
              plf::scalar_real_types,
              tts::randoms(0.0,88.0))
  <typename T>(T const& )
{
  using  mpfr::mpreal;
  auto mlog = [](auto a){ return mpfr::log(a); };
  {
    std::cout << std::hexfloat;
    {
     using pv1_t  = T;
     pv1_t pa(plf::valmax(eve::as<pv1_t>()));
     std::cout << "pa " << pa << std::endl;
     std::cout << eve::log(pa) << std::endl;
    }
    {
     using pv2_t  = plf::polyfloat<T, 2>;
     pv2_t pa(plf::valmax(eve::as<pv2_t>()));
     std::cout << "pa " << pa << std::endl;
     std::cout << tts::mpfr_exec(mlog, pa) << std::endl;
    }
    {
     using pv3_t  = plf::polyfloat<T, 3>;
     pv3_t pa(plf::valmax(eve::as<pv3_t>()));
     std::cout << "pa " << pa << std::endl;
     std::cout << tts::mpfr_exec(mlog, pa) << std::endl;
    }

//     std::cout << std::setprecision(15) << mpfr::log(tts::to_mpreal(plf::valmax(eve::as<float>()))) << std::endl;
//     std::cout << std::setprecision(15) << mpfr::log(tts::to_mpreal(plf::valmax(eve::as<double>())))<< std::endl;
//     std::cout << std::setprecision(25) << mpfr::log(tts::to_mpreal(plf::valmax(eve::as<plf::double_real_t<float>>())))<< std::endl;
//     std::cout << std::setprecision(25) << mpfr::log(tts::to_mpreal(plf::valmax(eve::as<plf::double_real_t<double>>())))<< std::endl;
//     std::cout << std::setprecision(50) << mpfr::log(tts::to_mpreal(plf::valmax(eve::as<plf::triple_real_t<float>>())))<< std::endl;
//     std::cout << std::setprecision(50) << mpfr::log(tts::to_mpreal(plf::valmax(eve::as<plf::triple_real_t<double>>())))<< std::endl;

//     mpfr::mpreal a = mpfr::log(tts::to_mpreal(plf::valmax(eve::as<float>())) );
//     auto b = mpfr::log(tts::to_mpreal(plf::valmax(eve::as<double>())));
//     auto c = mpfr::log(tts::to_mpreal(plf::valmax(eve::as<plf::double_real_t<float>>())));
//     auto d = mpfr::log(tts::to_mpreal(plf::valmax(eve::as<plf::double_real_t<double>>())));
//     auto e = mpfr::log(tts::to_mpreal(plf::valmax(eve::as<plf::triple_real_t<float>>())));
//     auto f = mpfr::log(tts::to_mpreal(plf::valmax(eve::as<plf::triple_real_t<double>>())));

//  using u_t = decltype(plf::hi(float()));
//  std::cout << tts::typename_<u_t> << std::endl;
//    std::cout << std::hexfloat << tts::to_polyfloat(a, eve::as<float>()) << std::endl;
//     std::cout << std::setprecision(15) <<
//     std::cout << std::setprecision(25) <<
//     std::cout << std::setprecision(25) <<
//     std::cout << std::setprecision(50) <<
//     std::cout << std::setprecision(50) <<

//    std::cout << "T(" <<  std::hexfloat << mk(tts::mpfr_exec(mpfrlog, plf::valmax(eve::as<float>())),  eve::as<float>()) << "); " << std::endl;
//     std::cout << "T(" <<  std::hexfloat << mk(tts::mpfr_exec(mpfrlog, plf::valmax(eve::as<double>())), eve::as<double>()) << ")" << std::endl;
//     std::cout << "T(" <<  std::hexfloat << mk(tts::mpfr_exec(mpfrlog, plf::valmax(eve::as<plf::double_real_t<float>>())), eve::as<plf::double_real_t<float>>()) << "); " << std::endl;
//     std::cout << "T(" <<  std::hexfloat << mk(tts::mpfr_exec(mpfrlog, plf::valmax(eve::as<plf::double_real_t<double>>())), eve::as<plf::double_real_t<double>>()) << "); " << std::endl;
//     std::cout << "T(" <<  std::hexfloat << mk(tts::mpfr_exec(mpfrlog, plf::valmax(eve::as<plf::triple_real_t<double>>())), eve::as<plf::triple_real_t<float>>()) <<  "); " <<std::endl;
//     std::cout << "T(" <<  std::hexfloat << mk(tts::mpfr_exec(mpfrlog, plf::valmax(eve::as<plf::double_real_t<double>>())), eve::as<plf::triple_real_t<double>>()) <<  "); " <<std::endl;
  }
  return 0;
};
