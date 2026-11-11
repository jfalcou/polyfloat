#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Values built by a constructor are normalized, whatever the order of their arguments.
  using plf::is_normalized;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  auto r = plf::double_real_t<double>(1.0e-10, 1.0);
  std::cout << "r  " << r << std::endl;
  std::cout << "is_normalized(f) = " << is_normalized(f) << std::endl;
  std::cout << "is_normalized(a) = " << is_normalized(a) << std::endl;
  std::cout << "is_normalized(b) = " << is_normalized(b) << std::endl;
  std::cout << "is_normalized(c) = " << is_normalized(c) << std::endl;
  std::cout << "is_normalized(r) = " << is_normalized(r) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_normalized(wb) = " << is_normalized(wb) << std::endl;
  std::cout << "is_normalized(wc) = " << is_normalized(wc) << std::endl;
}
