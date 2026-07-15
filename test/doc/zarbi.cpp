#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

auto pipo(auto z){return eve::is_ltz(plf::hi(z)); }
int main()
{
  using pv_t  = plf::polyfloat<double, 2>;
  pv_t z(-1.0, 0.005);
  std::cout << z << std::endl;
  std::cout << "plf::is_ltz(z)     " << plf::is_ltz(z) << std::endl;
  std::cout << "eve::is_ltz(hi(z)) " <<eve::is_ltz(plf::hi(z))<< std::endl;
 std::cout << "pipo(z))            " <<pipo(z)<< std::endl;

  return 0;
}
