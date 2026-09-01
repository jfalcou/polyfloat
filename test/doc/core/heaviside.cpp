#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::heaviside;
  auto f = -1.0;
  auto a = plf::polyfloat(-1.3);
  auto b = plf::polyfloat(1.0, -1.0e-300);
  auto c = plf::polyfloat(-1.0, 1.0e-10, -1.0e-300);
  std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "heaviside(f) " << heaviside(f) << std::endl;
  std::cout << "heaviside(a) " << heaviside(a) << std::endl;
  std::cout << "heaviside(b) " << heaviside(b) << std::endl;
  std::cout << "heaviside(c) " << heaviside(c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb      " << wb << std::endl;
  std::cout << "wc      " << wc << std::endl;
  std::cout << "heaviside(wb) " << heaviside(wb) << std::endl;
  std::cout << "heaviside(wc) " << heaviside(wc) << std::endl;
  std::cout << "heaviside(wb, wc) " << heaviside(wb, wc) << std::endl;
  std::cout << "heaviside(wc, wb) " << heaviside(wc, wb) << std::endl;

  return 0;
}
