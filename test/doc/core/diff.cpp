#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using u_t2 = plf::double_real_t<double>;

  std::cout << std::setprecision(15);
  using plf::diff;
  auto a = 1.0;
  auto b = u_t2(1.0, 1.0e-300);

  std::cout << "a " << a << std::endl;
  std::cout << "diff(kumi::make_tuple(a, a+1, a+3)) " << diff(kumi::make_tuple(a, a + 1, a + 3)) << std::endl;
  std::cout << "diff(a, a+1, a+3)                   " << diff(a, a + 1, a + 3) << std::endl;
  std::cout << "b " << b << std::endl;
  std::cout << "diff(kumi::make_tuple(b, b+1, b+3)) " << diff(kumi::make_tuple(b, b + 1, b + 3)) << std::endl;
  {
    kumi::tuple tt{u_t2(1.5000e-5), 2.2500, 3.3750, 5.0625, 7.0, 11.0, 17.0, 25.0};
    std::cout << " < - tt                        = " << tt << std::endl;
    std::cout << " -> diff(index_t<0>, tt)       = " << plf::diff(kumi::index_t<0>{}, tt) << std::endl;
    std::cout << " -> diff(tt)                   = " << plf::diff(tt) << std::endl;
    std::cout << " -> diff(index_t<1>, tt)       = " << plf::diff(kumi::index_t<1>{}, tt) << std::endl;
    std::cout << " -> diff(index_t<2>, tt)       = " << plf::diff(kumi::index_t<2>{}, tt) << std::endl;
    std::cout << " -> diff(index_t<7>, tt)       = " << plf::diff(kumi::index_t<7>{}, tt) << std::endl;
    std::cout << " -> diff(index_t<8>, tt)       = " << plf::diff(kumi::index_t<8>{}, tt) << std::endl;
  }
  return 0;
}
