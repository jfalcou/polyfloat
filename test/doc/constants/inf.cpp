#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using dd_t =  plf::double_real_t<double>;
  using td_t =  plf::triple_real_t<double>;
  std::cout << plf::inf(eve::as<dd_t>()) << std::endl;
  std::cout << plf::inf(eve::as<td_t>()) << std::endl;

  using wdd_t =  plf::double_real_t<eve::wide<double>>;
  using wtd_t =  plf::triple_real_t<eve::wide<double>>;
  std::cout << plf::inf(eve::as<wdd_t>()) << std::endl;
  std::cout << plf::inf(eve::as<wtd_t>()) << std::endl;

  return 0;
}
