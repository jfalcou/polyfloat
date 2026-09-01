#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using plf::is_eqmz;
  auto f = 1.0;
  auto a = plf::polyfloat(-0.0);
  auto b = plf::polyfloat(0.0, 1.0e-300);
  auto c = plf::polyfloat(-0.0, 0.0, 0.0);
  auto d = plf::polyfloat(0.0, 0.0, 0.0);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "d  " << d << std::endl;
  std::cout << "is_eqmz(f) " << is_eqmz(f) << std::endl;
  std::cout << "is_eqmz(a) " << is_eqmz(a) << std::endl;
  std::cout << "is_eqmz(b) " << is_eqmz(b) << std::endl;
  std::cout << "is_eqmz(c) " << is_eqmz(c) << std::endl;
  std::cout << "is_eqmz(d) " << is_eqmz(d) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>, eve::fixed<2>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>, eve::fixed<2>>;
  pf2_t wb(b, 0.0);
  pf3_t wc(c, 0.0);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_eqmz(wb) " << is_eqmz(wb) << std::endl;
  std::cout << "is_eqmz(wc) " << is_eqmz(wc) << std::endl;

  return 0;
}
