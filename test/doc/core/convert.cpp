#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::convert;
  //  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using w1_t = eve::wide<double>;
  using w2_t = eve::wide<d2_t>;
  //  using w3_t = eve::wide<d3_t>;
  double a1(1.0);
  d2_t a2(a1);
  std::cout << plf::convert(a1, eve::as<d2_t>()) << std::endl;
  std::cout << plf::convert(a2, eve::as<d3_t>()) << std::endl;

  std::cout << plf::convert(w1_t(a1), eve::as<d2_t>()) << std::endl;
  std::cout << plf::convert(w2_t(a2), eve::as<d3_t>()) << std::endl;

  //  using r_t = plf::as_polyfloat_like_t<d2_t, d1_t>;
  //  using u_t = plf::as_component_type_t<r_t>;
  //  std::cout << plf::convert(w2_t(a2), eve::as<u_t>()) << std::endl;
  std::cout << plf::convert(w2_t(a2), eve::as<d2_t>()) << std::endl;

  return 0;
}
