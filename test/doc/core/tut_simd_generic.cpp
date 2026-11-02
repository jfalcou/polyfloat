#include <iostream>
#include <polyfloat/polyfloat.hpp>

// One body, whatever the caller hands over.
auto energy(auto z)
{
  return plf::sqr(z) + plf::exp(z);
}

int main()
{
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  std::cout << "scalar d1_t : " << energy(d1_t(1.0)) << "\n";
  std::cout << "scalar d2_t : " << energy(d2_t(1.0)) << "\n";
  std::cout << "scalar d3_t : " << energy(d3_t(1.0)) << "\n";

  eve::wide<d1_t> re1 = [](auto i, auto) { return d1_t(1.0 + i); };
  eve::wide<d2_t> re2 = [](auto i, auto) { return d1_t(1.0 + i); };
  eve::wide<d3_t> re3 = [](auto i, auto) { return d1_t(1.0 + i); };
  std::cout << "re1                     " << re1 << "\n";
  std::cout << "re2                     " << re2 << "\n";
  std::cout << "re3                     " << re3 << "\n";
  std::cout << "wide energy 1           " << energy(re1) << "\n";
  std::cout << "wide energy 2           " << energy(re2) << "\n";
  std::cout << "wide energy 3           " << energy(re3) << "\n";
}
