#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::ldexp;
  auto f = -1.0;
  auto a = plf::polyfloat(-1.3);
  auto b = plf::polyfloat(1.0, -1.0e-300);
  auto c = plf::polyfloat(-1.0, 1.0e-10, -1.0e-300);
  std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "ldexp(f, 2) " << ldexp(f, 2) << std::endl;
  std::cout << "ldexp(a, 2) " << ldexp(a, 2) << std::endl;
  std::cout << "ldexp(b, 2) " << ldexp(b, 2) << std::endl;
  std::cout << "ldexp(c, 2) " << ldexp(c, 2) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb      " << wb << std::endl;
  std::cout << "wc      " << wc << std::endl;
  std::cout << "ldexp(wb) " << ldexp(wb, 2) << std::endl;
  std::cout << "ldexp(wc) " << ldexp(wc, 2) << std::endl;

  return 0;
}
