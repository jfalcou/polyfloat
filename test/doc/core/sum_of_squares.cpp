#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);
  using plf::sum_of_squares;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "sum_of_squares(f, f) " << sum_of_squares(f, f) << std::endl;
  std::cout << "sum_of_squares(a, a) " << sum_of_squares(a, a) << std::endl;
  std::cout << "sum_of_squares(b, b) " << sum_of_squares(b, b) << std::endl;
  std::cout << "sum_of_squares(c, c) "<<  sum_of_squares(c, c) << std::endl;
  std::cout << "sum_of_squares(a, f) " << sum_of_squares(a, f) << std::endl;
  std::cout << "sum_of_squares(b, a) " << sum_of_squares(b, a) << std::endl;
  std::cout << "sum_of_squares(c, b) "<<  sum_of_squares(c, b) << std::endl;
  std::cout << "sum_of_squares(f, a) " << sum_of_squares(f, a) << std::endl;
  std::cout << "sum_of_squares(a, b) " << sum_of_squares(a, b) << std::endl;
  std::cout << "sum_of_squares(b, c) "<<  sum_of_squares(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "sum_of_squares(wb, wb) "<< sum_of_squares(wb, wb) << std::endl;
  std::cout << "sum_of_squares(wc, wc) "<< sum_of_squares(wc, wc) << std::endl;
  std::cout << "sum_of_squares(wc, wb) "<< sum_of_squares(wc, wb) << std::endl;
  std::cout << "sum_of_squares(wc, wb, b) "<< sum_of_squares(wb, wb, wb, b, c, 1) << std::endl;

  return 0;
}
