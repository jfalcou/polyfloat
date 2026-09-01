#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::inc;
  auto f = -1.0;
  auto a = plf::polyfloat(-1.3);
  auto b = plf::polyfloat(1.0, -1.0e-300);
  auto c = plf::polyfloat(-1.0, 1.0e-10, -1.0e-300);
  std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "inc(f) " << inc(f) << std::endl;
  std::cout << "inc(a) " << inc(a) << std::endl;
  std::cout << "inc(b) " << inc(b) << std::endl;
  std::cout << "inc(c) " << inc(c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb      " << wb << std::endl;
  std::cout << "wc      " << wc << std::endl;
  std::cout << "inc(wb) " << inc(wb) << std::endl;
  std::cout << "inc(wc) " << inc(wc) << std::endl;

  return 0;
}
