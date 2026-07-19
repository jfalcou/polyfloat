#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using pv_t  = plf::polyfloat<double, 2>;
  using eve::as;
  std::cout << plf::eps(as<pv_t>()) << std::endl;
  return 0;
}
