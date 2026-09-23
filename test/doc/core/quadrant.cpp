#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

using pv_t = plf::triple_real_t<double>;
eve::wide<pv_t> wf([](auto i, auto c) -> float { return 2 * (i - c / 2); });
eve::wide<std::int32_t> wi([](auto i, auto c) -> std::int32_t { return i - c / 2; });
eve::wide<std::uint32_t> wu([](auto i, auto) -> std::uint32_t { return i; });

int main()
{
  std::cout << "<- wf = " << wf << "\n";
  std::cout << "<- wi = " << wi << "\n";
  std::cout << "<- wu = " << wu << "\n";

  std::cout << "-> quadrant(wf)= " << plf::quadrant(wf) << "\n";
  std::cout << "-> quadrant(wi)= " << plf::quadrant(wi) << "\n";
  std::cout << "-> quadrant(wu)= " << plf::quadrant(wu) << "\n";
}
