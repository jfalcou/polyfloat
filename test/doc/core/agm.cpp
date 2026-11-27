#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The value comes from mpmath at 600 bits, and each expected value rounds it to nearest part by part.
  std::cout << "1/agm(1, sqrt(2)) = 0.83462684167407318628142973279904680899399301349034700244982737010368199270952641"
            << std::endl;
  using plf::agm;
  using plf2 = plf::double_real_t<double>;
  using plf3 = plf::triple_real_t<double>;
  {
    plf2 o(1.0);
    plf2 sqt2 = plf::sqrt_2(eve::as(o));
    std::cout << std::setprecision(32);
    std::cout << "o    " << o << std::endl;
    std::cout << "sqt2 " << sqt2 << std::endl;
    std::cout << "1/agm(o, sqt2) " << 1.0f / agm(o, sqt2) << std::endl;
    std::cout << "expected       0.83462684167407318628142973279905" << std::endl;
  }
  {
    plf3 o(1.0);
    plf3 sqt2 = plf::sqrt_2(eve::as(o));
    std::cout << std::setprecision(48);
    std::cout << "o    " << o << std::endl;
    std::cout << "sqt2 " << sqt2 << std::endl;
    std::cout << "1/agm(o, sqt2) " << 1.0f / agm(o, sqt2) << std::endl;
    std::cout << "expected       0.83462684167407318628142973279904680899399301349" << std::endl;
  }
}
