#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::mul;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "mul(f, f) " << mul(f, f) << std::endl;
  std::cout << "mul(a, a) " << mul(a, a) << std::endl;
  std::cout << "mul(b, b) " << mul(b, b) << std::endl;
  std::cout << "mul(c, c) " << mul(c, c) << std::endl;
  std::cout << "mul(a, f) " << mul(a, f) << std::endl;
  std::cout << "mul(b, a) " << mul(b, a) << std::endl;
  std::cout << "mul(c, b) " << mul(c, b) << std::endl;
  std::cout << "mul(f, a) " << mul(f, a) << std::endl;
  std::cout << "mul(a, b) " << mul(a, b) << std::endl;
  std::cout << "mul(b, c) " << mul(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "mul(wb, wb) " << mul(wb, wb) << std::endl;
  std::cout << "mul(wc, wc) " << mul(wc, wc) << std::endl;
  std::cout << "mul(wc, wb) " << mul(wc, wb) << std::endl;

  return 0;
}
