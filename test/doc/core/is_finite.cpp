#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The infinities and NaN are tested beside finite values.
  using plf::is_finite;
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
  auto i = plf::inf(eve::as<d2_t>());
  std::cout << "i  " << i << std::endl;
  auto mi = plf::minf(eve::as<d2_t>());
  std::cout << "mi  " << mi << std::endl;
  auto n = plf::nan(eve::as<d2_t>());
  std::cout << "n  " << n << std::endl;
  std::cout << "is_finite(f) = " << is_finite(f) << std::endl;
  std::cout << "is_finite(a) = " << is_finite(a) << std::endl;
  std::cout << "is_finite(b) = " << is_finite(b) << std::endl;
  std::cout << "is_finite(c) = " << is_finite(c) << std::endl;
  std::cout << "is_finite(i) = " << is_finite(i) << std::endl;
  std::cout << "is_finite(mi) = " << is_finite(mi) << std::endl;
  std::cout << "is_finite(n) = " << is_finite(n) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_finite(wb) = " << is_finite(wb) << std::endl;
  std::cout << "is_finite(wc) = " << is_finite(wc) << std::endl;
}
