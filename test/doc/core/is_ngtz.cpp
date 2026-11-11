#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // A negative value, both zeros, and NaN are tested beside positive values.
  using plf::is_ngtz;
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
  auto n = plf::nan(eve::as<d2_t>());
  std::cout << "n  " << n << std::endl;
  std::cout << "is_ngtz(f) = " << is_ngtz(f) << std::endl;
  std::cout << "is_ngtz(a) = " << is_ngtz(a) << std::endl;
  std::cout << "is_ngtz(b) = " << is_ngtz(b) << std::endl;
  std::cout << "is_ngtz(c) = " << is_ngtz(c) << std::endl;
  std::cout << "is_ngtz(m) = " << is_ngtz(m) << std::endl;
  std::cout << "is_ngtz(z) = " << is_ngtz(z) << std::endl;
  std::cout << "is_ngtz(mz) = " << is_ngtz(mz) << std::endl;
  std::cout << "is_ngtz(n) = " << is_ngtz(n) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_ngtz(wb) = " << is_ngtz(wb) << std::endl;
  std::cout << "is_ngtz(wc) = " << is_ngtz(wc) << std::endl;
}
