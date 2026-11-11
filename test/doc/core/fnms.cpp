#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The three arguments mix the dimensions 1, 2, and 3.
  using plf::fnms;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "fnms(f, f, f) = " << fnms(f, f, f) << std::endl;
  std::cout << "fnms(a, b, c) = " << fnms(a, b, c) << std::endl;
  std::cout << "fnms(c, b, a) = " << fnms(c, b, a) << std::endl;
  std::cout << "fnms(f, a, b) = " << fnms(f, a, b) << std::endl;
  std::cout << "fnms(b, c, f) = " << fnms(b, c, f) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "fnms(wb, wc, wb) = " << fnms(wb, wc, wb) << std::endl;
  std::cout << "fnms(wc, wb, f) = " << fnms(wc, wb, f) << std::endl;
}
