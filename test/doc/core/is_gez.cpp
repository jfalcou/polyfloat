#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // A negative value and both zeros are tested beside positive values.
  using plf::is_gez;
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
  auto m = -b;
  std::cout << "m  " << m << std::endl;
  auto z = plf::zero(eve::as<d2_t>());
  std::cout << "z  " << z << std::endl;
  auto mz = plf::mzero(eve::as<d2_t>());
  std::cout << "mz  " << mz << std::endl;
  std::cout << "is_gez(f) = " << is_gez(f) << std::endl;
  std::cout << "is_gez(a) = " << is_gez(a) << std::endl;
  std::cout << "is_gez(b) = " << is_gez(b) << std::endl;
  std::cout << "is_gez(c) = " << is_gez(c) << std::endl;
  std::cout << "is_gez(m) = " << is_gez(m) << std::endl;
  std::cout << "is_gez(z) = " << is_gez(z) << std::endl;
  std::cout << "is_gez(mz) = " << is_gez(mz) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_gez(wb) = " << is_gez(wb) << std::endl;
  std::cout << "is_gez(wc) = " << is_gez(wc) << std::endl;
}
