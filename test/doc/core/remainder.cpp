#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The divisor is smaller than the dividend, of the same or of a lower dimension.
  using plf::remainder;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "remainder(a, f) = " << remainder(a, f) << std::endl;
  std::cout << "remainder(c, b) = " << remainder(c, b) << std::endl;
  std::cout << "remainder(plf::polyfloat(7.5), f) = " << remainder(plf::polyfloat(7.5), f) << std::endl;
  std::cout << "remainder(-a, b) = " << remainder(-a, b) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "remainder(wb, wb) = " << remainder(wb, wb) << std::endl;
  std::cout << "remainder(wc, wc) = " << remainder(wc, wc) << std::endl;
  std::cout << "remainder(wc, wb) = " << remainder(wc, wb) << std::endl;
}
