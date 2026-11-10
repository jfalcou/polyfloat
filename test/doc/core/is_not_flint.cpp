#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // An integer and a non-integer value are tested beside the other values.
  using plf::is_not_flint;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  auto k = plf::polyfloat(4.0);
  std::cout << "k  " << k << std::endl;
  auto h = plf::polyfloat(4.5);
  std::cout << "h  " << h << std::endl;
  std::cout << "is_not_flint(f) = " << is_not_flint(f) << std::endl;
  std::cout << "is_not_flint(a) = " << is_not_flint(a) << std::endl;
  std::cout << "is_not_flint(b) = " << is_not_flint(b) << std::endl;
  std::cout << "is_not_flint(c) = " << is_not_flint(c) << std::endl;
  std::cout << "is_not_flint(k) = " << is_not_flint(k) << std::endl;
  std::cout << "is_not_flint(h) = " << is_not_flint(h) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_not_flint(wb) = " << is_not_flint(wb) << std::endl;
  std::cout << "is_not_flint(wc) = " << is_not_flint(wc) << std::endl;
}
