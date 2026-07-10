#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using namespace plf;
  std::cout <<  std::setprecision(15);

  auto f = 1.0;
  auto a = polyfloat(1.0);
  auto b = polyfloat<double, 2>(1.0, 1.0e-300);
  auto c = polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  b *= a;
  std::cout << b << std::endl;
  b *= b;
  std::cout << b << std::endl;
  c*= a;
  std::cout << c << std::endl;
  c *= b;
  std::cout << c << std::endl;
  c *= c;
  std::cout << c << std::endl;
  b*= f;
  std::cout << b << std::endl;
  c*= f;
  std::cout << c << std::endl;

  {
    double sqt2 = eve::sqrt_2(eve::as<double>());
    double tsqt2 = 3*sqt2;
    polyfloat<float, 2> psqt2(sqt2);
    polyfloat<float, 2> ptsqt2(tsqt2);
    auto dd = sqt2*tsqt2;
    auto pdd = psqt2;
    pdd *= ptsqt2;
    std::cout << std::setprecision(15) << "dd  " << dd << std::endl;
    std::cout << std::setprecision(7)  << "pdd " << pdd << std::endl;
    auto rpdd = double(get<0>(pdd)) + double(get<1>(pdd));
    std::cout << rpdd-dd << std::endl;
  }
  {
    double sqt2 = eve::sqrt_2(eve::as<double>());
    double tsqt2 = 3*sqt2;
    polyfloat<float, 3> psqt2(sqt2);
    polyfloat<float, 3> ptsqt2(tsqt2);
    auto dd = sqt2*tsqt2;
    auto pdd = psqt2;
    pdd *= ptsqt2;
    std::cout << std::setprecision(15) << "dd  " << dd << std::endl;
    std::cout << std::setprecision(7)  << "pdd " << pdd << std::endl;
    auto rpdd = double(get<0>(pdd)) + double(get<1>(pdd)) + double(get<2>(pdd));
    std::cout << rpdd-dd << std::endl;
  }
  return 0;
}
