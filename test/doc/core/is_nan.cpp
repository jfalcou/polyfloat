#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using plf::is_nan;
  auto f = eve::nan(eve::as<double>());
  auto a = plf::polyfloat(f);
  auto b = plf::polyfloat(0.0, f);
  auto c = plf::polyfloat(1.0, 0.0, 0.0);
  auto d = plf::polyfloat(f, f, f);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "d  " << d << std::endl;
  std::cout << "is_nan(f) " << is_nan(f) << std::endl;
  std::cout << "is_nan(a) " << is_nan(a) << std::endl;
  std::cout << "is_nan(b) " << is_nan(b) << std::endl;
  std::cout << "is_nan(c) " << is_nan(c) << std::endl;
  std::cout << "is_nan(d) " << is_nan(d) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>, eve::fixed<2>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>, eve::fixed<2>>;
  pf2_t wb(b, 0.0);
  pf3_t wc(c, 0.0);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_nan(wb) " << is_nan(wb) << std::endl;
  std::cout << "is_nan(wc) " << is_nan(wc) << std::endl;

  return 0;
}
