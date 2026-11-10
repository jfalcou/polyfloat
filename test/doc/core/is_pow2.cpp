#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // A power of two and an odd integer are tested beside the other values.
  using plf::is_pow2;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  auto p = plf::polyfloat(8.0);
  std::cout << "p  " << p << std::endl;
  auto q = plf::polyfloat(7.0);
  std::cout << "q  " << q << std::endl;
  std::cout << "is_pow2(f) = " << is_pow2(f) << std::endl;
  std::cout << "is_pow2(a) = " << is_pow2(a) << std::endl;
  std::cout << "is_pow2(b) = " << is_pow2(b) << std::endl;
  std::cout << "is_pow2(c) = " << is_pow2(c) << std::endl;
  std::cout << "is_pow2(p) = " << is_pow2(p) << std::endl;
  std::cout << "is_pow2(q) = " << is_pow2(q) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_pow2(wb) = " << is_pow2(wb) << std::endl;
  std::cout << "is_pow2(wc) = " << is_pow2(wc) << std::endl;
}
