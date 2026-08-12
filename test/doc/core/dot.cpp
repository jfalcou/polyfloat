#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);
  using plf::dot;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "dot(f, f) " << dot(f, f) << std::endl;
  std::cout << "dot(a, a) " << dot(a, a) << std::endl;
  std::cout << "dot(b, b) " << dot(b, b) << std::endl;
  std::cout << "dot(c, c) "<<  dot(c, c) << std::endl;
  std::cout << "dot(a, f) " << dot(a, f) << std::endl;
  std::cout << "dot(b, a) " << dot(b, a) << std::endl;
  std::cout << "dot(c, b) "<<  dot(c, b) << std::endl;
  std::cout << "dot(f, a) " << dot(f, a) << std::endl;
  std::cout << "dot(a, b) " << dot(a, b) << std::endl;
  std::cout << "dot(b, c) "<<  dot(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "dot(wb, wb, wb, wb) "<< dot(wb, wb, wb, wb) << std::endl;
  std::cout << "dot(wc, wc) "<< dot(wc, wc, wc, wc) << std::endl;
  std::cout << "dot(wc, wb) "<< dot(wc, wb, wc, wc) << std::endl;
//  std::cout << "dot(wc, wb, b, c) "<< dot(wb, wb, b, c) << std::endl;

  auto t = eve::zip(wb, wb);
  std::cout << t << std::endl;
//   using r_t =  plf::as_polyfloat_like_t<pf2_t, pf3_t, double>;
//   using u_t = eve::element_type_t<r_t>;
//   // auto cvt = [](auto a){return plf::convert(a,  as<u_t>());};

//   std::cout << r_t() << std::endl;
//   std::cout << u_t() << std::endl;
  return 0;
}
