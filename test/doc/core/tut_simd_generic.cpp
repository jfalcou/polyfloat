#include <iostream>
#include <polyfloat/polyfloat.hpp>

// One body for a scalar or a register, of any dimension.
auto energy(auto z)
{
  return plf::sqr(z) + plf::exp(z);
}

int main()
{
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;

  std::cout << "double            : " << energy(1.0) << "\n";
  std::cout << "d2_t              : " << energy(d2_t(1.0)) << "\n";
  std::cout << "d3_t              : " << energy(d3_t(1.0)) << "\n";

  eve::wide<double> w1 = [](auto i, auto) { return 1.0 + i; };
  eve::wide<d2_t> w2 = [](auto i, auto) { return d2_t(1.0 + i); };
  eve::wide<d3_t> w3 = [](auto i, auto) { return d3_t(1.0 + i); };

  std::cout << "wide<double>      : " << energy(w1) << "\n";
  std::cout << "wide<d2_t>        : " << energy(w2) << "\n";
  std::cout << "wide<d3_t>        : " << energy(w3) << "\n";
}
