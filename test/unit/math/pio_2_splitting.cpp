//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>
#include <polyfloat/module/math/details/pio_2_splitting.hpp>
#include <eve/traits/helpers.hpp>
#include <polyfloat/module/math/details/cody_waite_reduce.hpp>

//   using plf::_::from_pair;
//   using plf::_::from_triple;

namespace plf
{
  template<typename X, typename C, eve::product_type Tuple>
  POLYFLOAT_FORCEINLINE constexpr auto cody_wait(X x, C invc, eve::coefficients<Tuple> const& tup) noexcept
  {
    //    return kumi::apply([&](auto... m) { return cody_wait(x, invc, m...); }, tup);
    constexpr auto lst = kumi::size_v<Tuple> - 1;
    auto butlast = kumi::extract(tup, kumi::index<0>, kumi::index<kumi::size_v<Tuple> - 1>);
    std::cout << "tup " << tup << std::endl;
    std::cout << "butlast " << butlast << std::endl;
    std::cout << "kumi::get<lst>(tup)" << kumi::get<lst>(tup) << std::endl;
    return kumi::apply([&](auto... m) { return cody_wait(x, invc, kumi::get<lst>(tup), m...); },
                       butlast); //kumi::extract(tup, kumi::index<1>));
  }

  template<typename X, typename C, typename C0, typename Cn, typename... Cs>
  POLYFLOAT_FORCEINLINE constexpr auto cody_wait(X x, C invc, Cn lastc, C0 c0, Cs... cs) noexcept
  {
    using r_t = as_polyfloat_like_t<X, C, Cn, C0, Cs...>;
    auto xn = -plf::nearest(x * invc);
    r_t that = plf::fma(c0, xn, x);
    ((that = plf::fma(cs, xn, that)), ...);
    //    std::cout << "lastc "<< lastc << std::endl;
    //     auto [da, err] = plf::two_prod(xn, lastc);
    //     that -= da;
    auto da = xn * lastc;
    auto a = that + da;
    da = (that - a) + da;
    auto n = plf::quadrant(-xn);
    return eve::zip(n, a, da);
  }
}

TTS_CASE_TPL("Check pio_2 _splitting", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using mpfr::mpreal;
  using plf::_::from_pair;

  //   auto ad = [](auto t){
  //     mpfr::mpreal::set_default_prec(300);
  //     return tts::to_mpreal(get<0>(t))+tts::to_mpreal(get<1>(t))+tts::to_mpreal(get<2>(t));
  //   };

  mpfr::mpreal::set_default_prec(300);
  using plf::_::pio_2_splitting;
  //  using pl2_t = plf::double_real_t<T>;
  using pl3_t = plf::triple_real_t<T>;
  //    auto spl1 = pio_2_splitting(eve::as<T>());
  //    std::cout << spl1 << std::endl;
  //    auto spl2 = pio_2_splitting(eve::as<pl2_t>());
  //    std::cout << spl2 << std::endl;
  auto spl3 = pio_2_splitting(eve::as<pl3_t>());
  //    std::cout << spl3 << std::endl;
  //    std::cout << ad(spl1)-mpfr::const_pi()/2<< std::endl;
  //    std::cout << ad(spl2)-mpfr::const_pi()/2<< std::endl;
  //    std::cout << ad(spl3)-mpfr::const_pi()/2<< std::endl;

  // auto z =  kumi::tuple{
  //           from_pair<float>(0x1.9210000000000p+0, 0x0.0p+0),
  //             from_pair<float>(0x1.f6a0000000000p-13, 0x0.0p+0),
  //             from_pair<float>(0x1.110b460000000p-26, 0x1.1a62640000000p-54)
  //             };
  //   std::cout << z << std::endl;
  //   mpfr::mpreal::set_default_prec(300);
  //   std::cout << ad(z)-mpfr::const_pi()/2<< std::endl;

  auto z = plf::_::cody_waite_reduce(plf::pio_6(eve::as<pl3_t>()) + 100 * plf::pi(eve::as<pl3_t>()),
                                     2 * plf::inv_pi(eve::as<pl3_t>()), eve::coefficients(spl3));
  std::cout << z << std::endl;
  std::cout << plf::pio_6(eve::as<pl3_t>()) << std::endl;
};
