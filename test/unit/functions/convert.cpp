//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

  template<typename X, eve::product_type Tuple>
  POLYFLOAT_FORCEINLINE constexpr auto
  h(X x, eve::coefficients<Tuple> const& tup) noexcept
  {
    if constexpr(Tuple::size() == 0)
      return eve::zero(as(x));
    else
    {
      using r_t = plf::as_polyfloat_t<X, eve::coefficients<Tuple>>;
      return kumi::apply( [&](auto... m) { return plf::horner(x, plf::convert(m, eve::as_element<r_t>())...); }, tup);
    }
  }


//==================================================================================================
// Types tests
//==================================================================================================
TTS_CASE_TPL( "Check convert", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
//   using pv_t2  = plf::polyfloat<T, 2>;
//   using pv_t3  = plf::polyfloat<T, 3>;
//   using wpv_t2 = eve::wide<pv_t2, eve::fixed<2>>;
//   using wpv_t3 = eve::wide<pv_t3, eve::fixed<2>>;

//   pv_t2 pva2(1.0, 1.0e-300);
//   pv_t3 pva3(1.0, 1.0e-300, 0.0);
//   wpv_t2 wpva2(pva2);
//   wpv_t3 wpva3(pva3);
//   TTS_EQUAL(pva3, plf::convert(pva2, eve::as<pv_t3>()));
//   TTS_EQUAL(wpva3, plf::convert(wpva2, eve::as<pv_t3>()));


//   std::cout <<  std::setprecision(15);
//   using plf::convert;
//   using d1_t = double;
//   using d2_t = plf::double_real_t<double>;
//   using d3_t = plf::triple_real_t<double>;
//   using w1_t = eve::wide<double>;
//   using w2_t = eve::wide<d2_t>;
// //  using w3_t = eve::wide<d3_t>;
//   double a1(1.0);
//   d2_t a2(a1);
//   std::cout << plf::convert(a1, eve::as<d2_t>()) << std::endl;
//   std::cout << plf::convert(a2, eve::as<d3_t>()) << std::endl;

//   std::cout << plf::convert(w1_t(a1), eve::as<d2_t>()) << std::endl;
//   std::cout << plf::convert(w2_t(a2), eve::as<d3_t>()) << std::endl;

//   using r_t = plf::as_polyfloat_like_t<w2_t, d1_t>;
//   using p_t = r_t::value_type;
//   using u_t = plf::as_component_type_t<r_t>;
//   std::cout << "u_t " << tts::typename_<u_t> << std::endl;
//   std::cout << "r_t " << tts::typename_<r_t> << std::endl;
//   std::cout << "d2_t " <<tts::typename_<d2_t> << std::endl;
//   std::cout << "p_t " <<tts::typename_<p_t> << std::endl;
// //  std::cout << plf::convert(w2_t(a2), eve::as<u_t>()) << std::endl;
// //  std::cout << plf::convert(w2_t(a2), eve::as<d2_t>()) << std::endl;

  kumi::tuple a{1.5, 2.0, 4.0};
  using Tuple = decltype(a);
  using X = plf::triple_real_t<double>;
  X x(1, 2e-60, 3);
  using r_t = plf::as_polyfloat_t<X, eve::coefficients<Tuple>>;
  std::cout << tts::typename_<r_t> << std::endl;
  auto z = kumi::apply([&](auto... m) { return plf::horner(x, plf::convert(m, eve::as_element<r_t>())...); }, a);
  std::cout << z << std::endl;
  std::cout << h(x, eve::coefficients(a)) << std::endl;
  std::cout << plf::horner(x, eve::coefficients(a)) << std::endl;   ;
};
