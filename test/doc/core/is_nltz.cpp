#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // A negative value, both zeros, and NaN are tested beside positive values.
  using plf::is_nltz;
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
  std::cout << "is_nltz(f) = " << is_nltz(f) << std::endl;
  std::cout << "is_nltz(a) = " << is_nltz(a) << std::endl;
  std::cout << "is_nltz(b) = " << is_nltz(b) << std::endl;
  std::cout << "is_nltz(c) = " << is_nltz(c) << std::endl;
  std::cout << "is_nltz(m) = " << is_nltz(m) << std::endl;
  std::cout << "is_nltz(z) = " << is_nltz(z) << std::endl;
  std::cout << "is_nltz(mz) = " << is_nltz(mz) << std::endl;
  std::cout << "is_nltz(n) = " << is_nltz(n) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_nltz(wb) = " << is_nltz(wb) << std::endl;
  std::cout << "is_nltz(wc) = " << is_nltz(wc) << std::endl;
}
