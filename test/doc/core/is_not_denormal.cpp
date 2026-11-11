#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The smallest denormal is tested beside normal values.
  using plf::is_not_denormal;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  using d2_t = plf::polyfloat<double, 2>;
  auto dn = plf::mindenormal(eve::as<d2_t>());
  std::cout << "dn  " << dn << std::endl;
  auto z = plf::zero(eve::as<d2_t>());
  std::cout << "z  " << z << std::endl;
  std::cout << "is_not_denormal(f) = " << is_not_denormal(f) << std::endl;
  std::cout << "is_not_denormal(a) = " << is_not_denormal(a) << std::endl;
  std::cout << "is_not_denormal(b) = " << is_not_denormal(b) << std::endl;
  std::cout << "is_not_denormal(c) = " << is_not_denormal(c) << std::endl;
  std::cout << "is_not_denormal(dn) = " << is_not_denormal(dn) << std::endl;
  std::cout << "is_not_denormal(z) = " << is_not_denormal(z) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_not_denormal(wb) = " << is_not_denormal(wb) << std::endl;
  std::cout << "is_not_denormal(wc) = " << is_not_denormal(wc) << std::endl;
}
