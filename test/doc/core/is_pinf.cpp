#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Both infinities are tested beside finite values.
  using plf::is_pinf;
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
  std::cout << "is_pinf(f) = " << is_pinf(f) << std::endl;
  std::cout << "is_pinf(a) = " << is_pinf(a) << std::endl;
  std::cout << "is_pinf(b) = " << is_pinf(b) << std::endl;
  std::cout << "is_pinf(c) = " << is_pinf(c) << std::endl;
  std::cout << "is_pinf(i) = " << is_pinf(i) << std::endl;
  std::cout << "is_pinf(mi) = " << is_pinf(mi) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_pinf(wb) = " << is_pinf(wb) << std::endl;
  std::cout << "is_pinf(wc) = " << is_pinf(wc) << std::endl;
}
