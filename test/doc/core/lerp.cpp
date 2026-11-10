#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The third argument is the interpolation coefficient.
  using plf::lerp;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "lerp(f, f, f) = " << lerp(f, f, f) << std::endl;
  std::cout << "lerp(a, b, c) = " << lerp(a, b, c) << std::endl;
  std::cout << "lerp(c, b, a) = " << lerp(c, b, a) << std::endl;
  std::cout << "lerp(f, a, b) = " << lerp(f, a, b) << std::endl;
  std::cout << "lerp(b, c, f) = " << lerp(b, c, f) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "lerp(wb, wc, wb) = " << lerp(wb, wc, wb) << std::endl;
  std::cout << "lerp(wc, wb, f) = " << lerp(wc, wb, f) << std::endl;
}
