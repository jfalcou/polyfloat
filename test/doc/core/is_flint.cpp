#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using plf::is_flint;
  auto f = 1000.0;
  auto a = plf::polyfloat(13.0);
  auto b = plf::polyfloat(13.0, 2.);
  auto c = plf::polyfloat(100.0, 12.0, 1.0);
  auto d = plf::polyfloat(100.0, 12.0, 1.0e-10);
  auto e = plf::polyfloat(100.0, 12.3);
  std::cout << std::setprecision(15) << std::hexfloat;
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "d  " << c << std::endl;
  std::cout << "e  " << d << std::endl;
  std::cout << "c  " << e << std::endl;
  std::cout << "is_flint(f) " << is_flint(f) << std::endl;
  std::cout << "is_flint(a) " << is_flint(a) << std::endl;
  std::cout << "is_flint(b) " << is_flint(b) << std::endl;
  std::cout << "is_flint(c) " << is_flint(c) << std::endl;
  std::cout << "is_flint(d) " << is_flint(d) << std::endl;
  std::cout << "is_flint(e) " << is_flint(e) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>, eve::fixed<2>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>, eve::fixed<2>>;
  pf2_t wb(b, e);
  pf3_t wc(c, d);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_flint(wb) " << is_flint(wb) << std::endl;
  std::cout << "is_flint(wc) " << is_flint(wc) << std::endl;

  return 0;
}
