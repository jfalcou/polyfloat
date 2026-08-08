#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
//   plf::double_real_t<double> xs(1.0f, 1.0e-30f);
//   double a = 1.0;

//   using r_t   =  plf::as_polyfloat_t<plf::double_real_t<double>, double>;
//   using u_t = plf::as_component_type_t<r_t>;
//   auto cvt = [](auto a){return plf::convert(a,  eve::as<u_t>());};

//   std::cout << xs << "  " << plf::double_real_t<double>(xs) << std::endl;
//   std::cout << a << "  " << plf::double_real_t<double>(a)  << std::endl;
//   std::cout << a << "  " << cvt(a) << std::endl;
// //  std::cout << xs<< "  " << cvt(xs)<< std::endl;

//   using type = eve::as_wide_as_t<decltype(a), u_t>;
//   using u_t = plf::as_component_type_t<plf::double_real_t<double>>;
//   std::cout << kumi::apply([](auto const&... e) { return type{plf::convert(e, eve::as<u_t>{})...}; }, xs) << std::endl;;

  return 0;
}
