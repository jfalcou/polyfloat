#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // NaN and an infinity are tested beside finite values.
  using plf::is_not_nan;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  using d2_t = plf::polyfloat<double, 2>;
  auto n = plf::nan(eve::as<d2_t>());
  std::cout << "n  " << n << std::endl;
  auto i = plf::inf(eve::as<d2_t>());
  std::cout << "i  " << i << std::endl;
  std::cout << "is_not_nan(f) = " << is_not_nan(f) << std::endl;
  std::cout << "is_not_nan(a) = " << is_not_nan(a) << std::endl;
  std::cout << "is_not_nan(b) = " << is_not_nan(b) << std::endl;
  std::cout << "is_not_nan(c) = " << is_not_nan(c) << std::endl;
  std::cout << "is_not_nan(n) = " << is_not_nan(n) << std::endl;
  std::cout << "is_not_nan(i) = " << is_not_nan(i) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_not_nan(wb) = " << is_not_nan(wb) << std::endl;
  std::cout << "is_not_nan(wc) = " << is_not_nan(wc) << std::endl;
}
