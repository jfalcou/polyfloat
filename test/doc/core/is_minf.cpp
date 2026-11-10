#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Both infinities are tested beside finite values.
  using plf::is_minf;
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
  std::cout << "is_minf(f) = " << is_minf(f) << std::endl;
  std::cout << "is_minf(a) = " << is_minf(a) << std::endl;
  std::cout << "is_minf(b) = " << is_minf(b) << std::endl;
  std::cout << "is_minf(c) = " << is_minf(c) << std::endl;
  std::cout << "is_minf(i) = " << is_minf(i) << std::endl;
  std::cout << "is_minf(mi) = " << is_minf(mi) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_minf(wb) = " << is_minf(wb) << std::endl;
  std::cout << "is_minf(wc) = " << is_minf(wc) << std::endl;
}
