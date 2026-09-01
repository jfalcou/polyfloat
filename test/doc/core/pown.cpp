#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::pown;
  auto f = -2.0;
  auto a = plf::polyfloat(-1.3);
  auto b = plf::polyfloat(2.0, -1.0e-55);
  auto c = plf::polyfloat(2.0, -1.0e-55, 0.0);
  auto n = 2.;
  std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "pown(f) " << pown(f, n) << std::endl;
  std::cout << "pown(a, n) " << pown(a, n) << std::endl;
  std::cout << "pown(b, n) " << pown(b, n) << std::endl;
  std::cout << "pown(c, n) " << pown(c, n) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb      " << wb << std::endl;
  std::cout << "wc      " << wc << std::endl;
  std::cout << "pown(wb) " << pown(wb, 2.0) << std::endl;
  std::cout << "pown(wc) " << pown(wc, 2.0) << std::endl;
  return 0;
}
