#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);
  using plf::ulpdist;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "ulpdist(f, f) " << ulpdist(f, f+f) << std::endl;
  std::cout << "ulpdist(a, a) " << ulpdist(a, a+a) << std::endl;
  std::cout << "ulpdist(b, b) " << ulpdist(b, b+b) << std::endl;
  std::cout << "ulpdist(c, c) "<<  ulpdist(c, c+c) << std::endl;
  std::cout << "ulpdist(a, f) " << ulpdist(a, f) << std::endl;
  std::cout << "ulpdist(b, a) " << ulpdist(b, a) << std::endl;
  std::cout << "ulpdist(c, b) "<<  ulpdist(c, b) << std::endl;
  std::cout << "ulpdist(f, a) " << ulpdist(f, a) << std::endl;
  std::cout << "ulpdist(a, b) " << ulpdist(a, b) << std::endl;
  std::cout << "ulpdist(b, c) "<<  ulpdist(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "ulpdist(wb, wb) "<< ulpdist(wb, wb) << std::endl;
  std::cout << "ulpdist(wc, wc) "<< ulpdist(wc, wc) << std::endl;
  // std::cout << "ulpdist(wc, wb) "<< ulpdist(wc, wb) << std::endl;

  return 0;
}
