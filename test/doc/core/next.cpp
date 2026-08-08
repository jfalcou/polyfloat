#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(17);
  using plf::next;
  auto f = -1.0;
  auto a = plf::polyfloat(-1.3);
  auto b = plf::polyfloat(1.0, -1.0e-300);
  auto c = plf::polyfloat(-1.0, 1.0e-10, -1.0e-300);
  std::setprecision(17);
  std::cout << "f       "<< f << std::endl;
  std::cout << "a       "<< a << std::endl;
  std::cout << "b       "<< b << std::endl;
  std::cout << "c       "<< c << std::endl;
  std::cout << "next(f) " << next(f) << std::endl;
  std::cout << "next(a) " << next(a) << std::endl;
  std::cout << "next(b) " << next(b) << std::endl;
  std::cout << "next(c) "<<  next(c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb       "<< wb << std::endl;
  std::cout << "wc       "<< wc << std::endl;
  std::cout << "next(wb) "<< next(wb) << std::endl;
  std::cout << "next(wc) "<< next(wc) << std::endl;

  return 0;
}
