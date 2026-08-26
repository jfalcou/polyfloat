//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <mpreal.h>
#include "../../mpfr_helpers.hpp"
#include <polyfloat/polyfloat.hpp>

  template < typename T > T to_polyfloat(mpfr::mpreal const & mpa, eve::as<T> )
  {
    using u_t = decltype(plf::hi(T()));
    using mu_t = decltype(mpa);
    auto h = u_t(mpa);
    auto m = u_t(mpa-mu_t(h));
    if constexpr(plf::dimension_v<T> == 1)
    {
      return h;
    }
    else     if constexpr(plf::dimension_v<T> == 2)
    {
      return plf::as_polyfloat_n_t<2, u_t>(h, m);
    }
    else if constexpr(plf::dimension_v<T> == 3)
    {
      auto l = u_t(mpa - (mu_t(h)+mu_t(m)));
      return plf::as_polyfloat_n_t<3, u_t>(h, m, l);
    }
  }

template<typename aT> auto mk(auto mval, aT)
{
  mpfr::mpreal::set_default_prec(200);
  return tts::to_polyfloat(mval, aT());
} ;

int main()
{
  using  mpfr::mpreal;

  {
//    auto mpfrlog = []<typename T>(T a){return tts::to_polyfloat(mpfr::log(tts::to_mpreal(a)), eve::as<T>()); };

    std::cout << std::setprecision(15) << mpfr::log(tts::to_mpreal(plf::valmax(eve::as<float>()))) << std::endl;
    std::cout << std::setprecision(15) << mpfr::log(tts::to_mpreal(plf::valmax(eve::as<double>())))<< std::endl;
    std::cout << std::setprecision(25) << mpfr::log(tts::to_mpreal(plf::valmax(eve::as<plf::double_real_t<float>>())))<< std::endl;
    std::cout << std::setprecision(25) << mpfr::log(tts::to_mpreal(plf::valmax(eve::as<plf::double_real_t<double>>())))<< std::endl;
    std::cout << std::setprecision(50) << mpfr::log(tts::to_mpreal(plf::valmax(eve::as<plf::triple_real_t<float>>())))<< std::endl;
    std::cout << std::setprecision(50) << mpfr::log(tts::to_mpreal(plf::valmax(eve::as<plf::triple_real_t<double>>())))<< std::endl;

    mpfr::mpreal a = mpfr::log(tts::to_mpreal(plf::valmax(eve::as<float>())) );
    auto b = mpfr::log(tts::to_mpreal(plf::valmax(eve::as<double>())));
    auto c = mpfr::log(tts::to_mpreal(plf::valmax(eve::as<plf::double_real_t<float>>())));
    auto d = mpfr::log(tts::to_mpreal(plf::valmax(eve::as<plf::double_real_t<double>>())));
    auto e = mpfr::log(tts::to_mpreal(plf::valmax(eve::as<plf::triple_real_t<float>>())));
    auto f = mpfr::log(tts::to_mpreal(plf::valmax(eve::as<plf::triple_real_t<double>>())));

 using u_t = decltype(plf::hi(float()));
 std::cout << tts::typename_<u_t> << std::endl;
 //std::cout << std::hexfloat << to_polyfloat(a, eve::as<float>()) << std::endl;
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
