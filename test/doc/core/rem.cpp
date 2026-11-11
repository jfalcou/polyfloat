#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The divisor is smaller than the dividend, of the same or of a lower dimension.
  using plf::rem;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "rem(a, f) = " << rem(a, f) << std::endl;
  std::cout << "rem(c, b) = " << rem(c, b) << std::endl;
  std::cout << "rem(plf::polyfloat(7.5), f) = " << rem(plf::polyfloat(7.5), f) << std::endl;
  std::cout << "rem(-a, b) = " << rem(-a, b) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "rem(wb, wb) = " << rem(wb, wb) << std::endl;
  std::cout << "rem(wc, wc) = " << rem(wc, wc) << std::endl;
  std::cout << "rem(wc, wb) = " << rem(wc, wb) << std::endl;
}
