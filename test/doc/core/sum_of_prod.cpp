#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The four arguments mix the dimensions 1, 2, and 3.
  using plf::sum_of_prod;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "sum_of_prod(f, f, f, f) = " << sum_of_prod(f, f, f, f) << std::endl;
  std::cout << "sum_of_prod(a, b, c, f) = " << sum_of_prod(a, b, c, f) << std::endl;
  std::cout << "sum_of_prod(c, b, a, -f) = " << sum_of_prod(c, b, a, -f) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "sum_of_prod(wb, wc, wb, wc) = " << sum_of_prod(wb, wc, wb, wc) << std::endl;
}
