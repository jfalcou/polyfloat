#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using plf::is_eqpz;
  auto f = 1.0;
  auto a = plf::polyfloat(0.0);
  auto b = plf::polyfloat(0.0, 1.0e-300);
  auto c = plf::polyfloat(0.0, 0.0, 0.0);
  auto d = plf::polyfloat(-0.0, 0.0, 0.0);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "d  " << d << std::endl;
  std::cout << "is_eqpz(f) " << is_eqpz(f) << std::endl;
  std::cout << "is_eqpz(a) " << is_eqpz(a) << std::endl;
  std::cout << "is_eqpz(b) " << is_eqpz(b) << std::endl;
  std::cout << "is_eqpz(c) " << is_eqpz(c) << std::endl;
  std::cout << "is_eqpz(d) " << is_eqpz(d) << std::endl;
  using pf3_t = eve::wide<plf::polyfloat<double, 3>, eve::fixed<2>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>, eve::fixed<2>>;
  pf2_t wb(b, 0.0);
  pf3_t wc(c, 0.0);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_eqpz(wb) " << is_eqpz(wb) << std::endl;
  std::cout << "is_eqpz(wc) " << is_eqpz(wc) << std::endl;

  return 0;
}
