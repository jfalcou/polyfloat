#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The three arguments mix the dimensions 1, 2, and 3.
  using plf::fsm;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "fsm(f, f, f) = " << fsm(f, f, f) << std::endl;
  std::cout << "fsm(a, b, c) = " << fsm(a, b, c) << std::endl;
  std::cout << "fsm(c, b, a) = " << fsm(c, b, a) << std::endl;
  std::cout << "fsm(f, a, b) = " << fsm(f, a, b) << std::endl;
  std::cout << "fsm(b, c, f) = " << fsm(b, c, f) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "fsm(wb, wc, wb) = " << fsm(wb, wc, wb) << std::endl;
  std::cout << "fsm(wc, wb, f) = " << fsm(wc, wb, f) << std::endl;
}
