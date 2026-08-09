#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using plf::is_even;
  auto f = 1000.0;
  auto a = plf::polyfloat(13.0);
  auto b = plf::polyfloat(1.0e30, 2.0);
  auto c = plf::polyfloat(1.0e30, 1.0e15, 1.0);
  auto d = plf::polyfloat(100.0, 12.0, 1.0e-10);
  auto e = plf::polyfloat(100.0, 12.0);
  std::cout << std::setprecision(15); 
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "d  "<< c << std::endl;
  std::cout << "e  "<< d << std::endl;
  std::cout << "c  "<< e << std::endl;
  std::cout << "is_even(f) " << is_even(f) << std::endl;
  std::cout << "is_even(a) " << is_even(a) << std::endl;
  std::cout << "is_even(b) " << is_even(b) << std::endl;
  std::cout << "is_even(c) "<<  is_even(c) << std::endl;
  std::cout << "is_even(d) " << is_even(d) << std::endl;
  std::cout << "is_even(e) "<<  is_even(e) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>, eve::fixed<2>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>, eve::fixed<2>>;
  pf2_t wb(b, e );
  pf3_t wc(c, d );
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "is_even(wb) "<< is_even(wb) << std::endl;
  std::cout << "is_even(wc) "<< is_even(wc) << std::endl;

  return 0;
}
