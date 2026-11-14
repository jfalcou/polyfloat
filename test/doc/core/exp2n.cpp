#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::exp2n;
  auto a = -2.0;
  auto b = plf::polyfloat(-2.0, 0.0);
  auto c = plf::polyfloat(-2.0, 0.0, 0.0);
  std::setprecision(15);
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "exp2n(a) " << exp2n(a) << std::endl;
  std::cout << "exp2n(b) " << exp2n(b) << std::endl;
  std::cout << "exp2n(c) " << exp2n(c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>, 2>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>, 2>;
  using pf1_t = eve::wide<double, 2>;
  pf1_t wa(a, -2 * a);
  pf2_t wb(b, -2 * b);
  pf3_t wc(c, -2 * c);
  std::cout << "wa      " << wa << std::endl;
  std::cout << "wb      " << wb << std::endl;
  std::cout << "wc      " << wc << std::endl;
  std::cout << "exp2n(wa) " << exp2n(wa) << std::endl;
  std::cout << "exp2n(wb) " << exp2n(wb) << std::endl;
  std::cout << "exp2n(wc) " << exp2n(wc) << std::endl;

  auto maxe = pf2_t(eve::maxexponent(eve::as<double>()));
  std::cout << "exp2n(maxe) " << exp2n(maxe) << std::endl;
  std::cout << "exp2n[eve::raw](maxe) " << exp2n[eve::raw](maxe) << std::endl;
  auto mine = pf2_t(eve::minexponent(eve::as<double>()));
  std::cout << "exp2n(mine) " << exp2n(mine) << std::endl;
  std::cout << "exp2n(mine) " << exp2n[eve::raw](mine) << std::endl;
  auto nan = pf2_t(eve::nan(eve::as<double>()));
  std::cout << "exp2n(nan) " << exp2n(nan) << std::endl;
  auto inf = pf2_t(eve::inf(eve::as<double>()));
  std::cout << "exp2n(inf) " << exp2n(inf) << std::endl;
  auto minf = pf2_t(eve::minf(eve::as<double>()));
  std::cout << "exp2n(minf) " << exp2n(minf) << std::endl;
}
