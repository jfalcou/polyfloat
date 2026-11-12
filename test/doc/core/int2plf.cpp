#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::convert;
  using d1_t = double;
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  {
    std::int32_t n = 2;
    auto d1n = convert(n, eve::as<d1_t>());
    std::cout << "d1n " << d1n << std::endl;
    auto d2n = convert(n, eve::as<d2_t>());
    std::cout << "d2n " << d2n << std::endl;
    auto d3n = convert(n, eve::as<d3_t>());
    std::cout << "d3n " << d3n << std::endl;
  }
  {

    std::int64_t n = 2;
    auto d1n = convert(n, eve::as<d1_t>());
    std::cout << "d1n " << d1n << std::endl;
    auto d2n = convert(n, eve::as<d2_t>());
    std::cout << "d2n " << d2n << std::endl;
    auto d3n = convert(n, eve::as<d3_t>());
    std::cout << "d3n " << d3n << std::endl;
  }

  //   using wd1_t = eve::wide<d1_t, 2>;
  //   using wd2_t = eve::wide<d2_t, 2>;
  //   using wd3_t = eve::wide<d3_t, 2>;

  {
    eve::wide<std::int32_t, 2> wn(2);
    std::int32_t n = 2;
    auto d1n = convert(n, eve::as<d1_t>());
    std::cout << "d1n " << d1n << std::endl;
    auto d2n = convert(n, eve::as<d2_t>());
    std::cout << "d2n " << d2n << std::endl;
    auto d3n = convert(n, eve::as<d3_t>());
    std::cout << "d3n " << d3n << std::endl;
  }
  {
    eve::wide<std::int64_t, 2> wn(2);
    std::int64_t n = 2;
    auto d1n = eve::convert(n, eve::as<double>());
    auto wd1n = eve::convert(wn, eve::as<double>());
    std::cout << "d1n " << d1n << std::endl;
    std::cout << "wd1n " << wd1n << std::endl;
    auto d2n = convert(n, eve::as<d2_t>());
    auto wd2n = convert(wn, eve::as<d2_t>());
    std::cout << "d2n " << d2n << std::endl;
    std::cout << "wd2n " << wd2n << std::endl;
    auto d3n = convert(n, eve::as<d3_t>());
    auto wd3n = convert(wn, eve::as<d3_t>());
    std::cout << "d3n " << d3n << std::endl;
    std::cout << "wd3n " << wd3n << std::endl;
  }
  return 0;
}
