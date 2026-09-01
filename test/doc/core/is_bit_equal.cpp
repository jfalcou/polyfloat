#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using plf::is_bit_equal;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-300, 0.0);
  std::cout << std::setprecision(15) << std::hexfloat;
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "is_bit_equal(f, f) " << is_bit_equal(f, f) << std::endl;
  std::cout << "is_bit_equal(a, a) " << is_bit_equal(a, a) << std::endl;
  std::cout << "is_bit_equal(b, b) " << is_bit_equal(b, b) << std::endl;
  std::cout << "is_bit_equal(c, c) " << is_bit_equal(c, c) << std::endl;
  std::cout << "is_bit_equal(b, a) " << is_bit_equal(b, a) << std::endl;
  std::cout << "is_bit_equal(a, b) " << is_bit_equal(a, b) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>, eve::fixed<4>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>, eve::fixed<4>>;
  pf2_t wb(b);
  pf2_t waabb(a, a, b, b);
  pf2_t wabab(a, b, a, b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_bit_equal(wb, wb) " << is_bit_equal(wb, wb) << std::endl;
  std::cout << "is_bit_equal(wc, wc) " << is_bit_equal(wc, wc) << std::endl;
  std::cout << "is_bit_equal(wabab, waabb) " << is_bit_equal(wabab, waabb) << std::endl;

  return 0;
}
