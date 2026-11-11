#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Parts of values of dimensions 2 and 3, and of registers of them.
  // Each argument is under half an ulp of the one before it, so the parts stay as written.
  using plf::hi;
  using plf::lo;
  using plf::md;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 0x1p-60);
  auto c = plf::polyfloat(1.0, 0x1p-60, 0x1p-120);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "hi(b) = " << hi(b) << std::endl;
  std::cout << "lo(b) = " << lo(b) << std::endl;
  std::cout << "hi(c) = " << hi(c) << std::endl;
  std::cout << "lo(c) = " << lo(c) << std::endl;
  std::cout << "md(c) = " << md(c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "hi(wc) = " << hi(wc) << std::endl;
  std::cout << "md(wc) = " << md(wc) << std::endl;
  std::cout << "lo(wc) = " << lo(wc) << std::endl;
}
