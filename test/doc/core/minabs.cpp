#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::minabs;
  auto f = -21.0;
  auto a = plf::polyfloat(1.3);
  auto b = -plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "minabs(f, f) " << minabs(f, f) << std::endl;
  std::cout << "minabs(a, a) " << minabs(a, a) << std::endl;
  std::cout << "minabs(b, b) " << minabs(b, b) << std::endl;
  std::cout << "minabs(c, c) " << minabs(c, c) << std::endl;
  std::cout << "minabs(a, f) " << minabs(a, f) << std::endl;
  std::cout << "minabs(b, a) " << minabs(b, a) << std::endl;
  std::cout << "minabs(c, b) " << minabs(c, b) << std::endl;
  std::cout << "minabs(f, a) " << minabs(f, a) << std::endl;
  std::cout << "minabs(a, b) " << minabs(a, b) << std::endl;
  std::cout << "minabs(b, c) " << minabs(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "minabs(wb, wb) " << minabs(wb, wb) << std::endl;
  std::cout << "minabs(wc, wc) " << minabs(wc, wc) << std::endl;
  std::cout << "minabs(wc, wb) " << minabs(wc, wb) << std::endl;

  return 0;
}
