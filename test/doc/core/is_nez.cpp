#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Both zeros are tested beside non-zero values.
  using plf::is_nez;
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
  auto z = plf::zero(eve::as<d2_t>());
  std::cout << "z  " << z << std::endl;
  auto mz = plf::mzero(eve::as<d2_t>());
  std::cout << "mz  " << mz << std::endl;
  std::cout << "is_nez(f) = " << is_nez(f) << std::endl;
  std::cout << "is_nez(a) = " << is_nez(a) << std::endl;
  std::cout << "is_nez(b) = " << is_nez(b) << std::endl;
  std::cout << "is_nez(c) = " << is_nez(c) << std::endl;
  std::cout << "is_nez(z) = " << is_nez(z) << std::endl;
  std::cout << "is_nez(mz) = " << is_nez(mz) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_nez(wb) = " << is_nez(wb) << std::endl;
  std::cout << "is_nez(wc) = " << is_nez(wc) << std::endl;
}
