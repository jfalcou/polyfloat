//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <array>
#include <cmath>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include <string_view>

namespace
{
  template<typename V, typename... M> std::string text(V const& v, M... m)
  {
    std::ostringstream os;
    (os << ... << m) << v;
    return os.str();
  }

  struct comma : std::numpunct<char>
  {
    char do_decimal_point() const override { return ','; }
    char do_thousands_sep() const override { return '.'; }
    std::string do_grouping() const override { return "\3"; }
  };

  template<typename V> std::string localized(V const& v, std::ios_base::fmtflags flags)
  {
    std::ostringstream os;
    os.imbue(std::locale(std::locale::classic(), new comma));
    os.flags(flags);
    os << v;
    return os.str();
  }

  struct wide_comma : std::numpunct<wchar_t>
  {
    wchar_t do_decimal_point() const override { return L','; }
    wchar_t do_thousands_sep() const override { return L'.'; }
    std::string do_grouping() const override { return "\3"; }
  };

  template<typename V> std::wstring wide_localized(V const& v, std::ios_base::fmtflags flags)
  {
    std::wostringstream os;
    os.imbue(std::locale(std::locale::classic(), new wide_comma));
    os.flags(flags);
    os << std::setw(30) << v;
    return os.str();
  }

  std::string lanes(std::string const& v, std::ptrdiff_t n)
  {
    std::string s = "(" + v;
    for (std::ptrdiff_t i = 1; i < n; ++i) s += ", " + v;
    return s + ")";
  }

  constexpr auto half_min_double =
    "2."
    "470328229206232720882843964341106861825299013071623822127928412503377536351043759326499181808179961898982823477228"
    "588654633283551779698981993873980053909390631503565951557022639229085839244910518443593180284993653615250031937045"
    "767824921936562366986365848075700158576926990370631192827955855133292783433840935197801553124659726357957462276646"
    "527282722005637400648549997709659947045402082816622623785739345073633900796776193057750674017632467360096895134053"
    "553745851666113422376667860416215968046191446729184030053005753084904876539171138659164623952491262365388187963623"
    "937328042389101867234849766823508986338858792562830275599565752445550725518931369083625477918694866799496832404970"
    "5821028513185451396213837722826145437693412532098591327667236328125e-324";
  constexpr auto half_min_float =
    "7.00649232162408535461864791644958065640130970938257885878534141944895541342930300743319094181060791015625e-46";

  constexpr auto sqrt2_digits =
    "1.4142135623730950488016887242096980785696718753769480731766797379907324784621070388503875343276415727";
}

TTS_CASE_TPL("Check from_string", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv2 = plf::polyfloat<T, 2>;
  using pv3 = plf::polyfloat<T, 3>;

  auto r2 = plf::from_string(eve::as<pv2>(), sqrt2_digits);
  auto e2 = plf::sqrt_2(eve::as<pv2>());
  TTS_EQUAL(plf::hi(r2), plf::hi(e2));
  TTS_EQUAL(plf::lo(r2), plf::lo(e2));

  auto r3 = plf::from_string(eve::as<pv3>(), sqrt2_digits);
  auto e3 = plf::sqrt_2(eve::as<pv3>());
  TTS_EQUAL(plf::hi(r3), plf::hi(e3));
  TTS_EQUAL(plf::md(r3), plf::md(e3));
  TTS_EQUAL(plf::lo(r3), plf::lo(e3));

  auto tenth = plf::from_string(eve::as<pv2>(), "0.1");
  if constexpr (std::same_as<T, double>)
  {
    TTS_EQUAL(plf::hi(tenth), 0x1.999999999999ap-4);
    TTS_EQUAL(plf::lo(tenth), -0x1.999999999999ap-58);
  }
  else
  {
    TTS_EQUAL(plf::hi(tenth), 0x1.99999ap-4f);
    TTS_EQUAL(plf::lo(tenth), -0x1.99999ap-30f);
  }

  TTS_EQUAL(plf::hi(plf::from_string(eve::as<pv2>(), "0X1.8P+1")), T(3));
  TTS_EQUAL(plf::lo(plf::from_string(eve::as<pv2>(), "0x1.8p1")), T(0));
  TTS_EQUAL(plf::hi(plf::from_string(eve::as<pv2>(), "-0")), T(0));
  TTS_EXPECT(std::signbit(plf::hi(plf::from_string(eve::as<pv2>(), "-0"))));
  TTS_EQUAL(plf::hi(plf::from_string(eve::as<pv2>(), "-Infinity")), eve::minf(eve::as<T>()));
  TTS_EQUAL(plf::hi(plf::from_string(eve::as<pv2>(), "1e400")), eve::inf(eve::as<T>()));
  TTS_EQUAL(plf::hi(plf::from_string(eve::as<pv2>(), "1e-400")), T(0));
  TTS_EXPECT(eve::is_nan(plf::hi(plf::from_string(eve::as<pv2>(), "NaN"))));
  TTS_EXPECT(std::signbit(plf::hi(plf::from_string(eve::as<pv2>(), "-nan"))));
  for (auto s : {"", "-", "1.2.3", "0x", "0x.p1", "1e", "1e+", " 1", "1 ", "abc", "1.5x", "--1", "infinit"})
  {
    TTS_EXPECT(!plf::from_string[plf::pedantic](eve::as<pv2>(), s).has_value());
    TTS_EXPECT(eve::is_nan(plf::hi(plf::from_string(eve::as<pv2>(), s))));
  }
};

TTS_CASE_TPL("Check from_string for a real, a register, and under pedantic", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv2 = plf::polyfloat<T, 2>;
  TTS_EQUAL(plf::from_string(eve::as<T>(), "0.1"), T(0.1));
  TTS_EXPECT(eve::all(plf::from_string(eve::as<eve::wide<T>>(), "0x1.8p1") == T(3)));

  auto w = plf::from_string(eve::as<eve::wide<pv2>>(), "0.1");
  auto x = plf::from_string(eve::as<pv2>(), "0.1");
  TTS_EXPECT(eve::all(plf::hi(w) == plf::hi(x)) && eve::all(plf::lo(w) == plf::lo(x)));

  auto checked = plf::from_string[plf::pedantic](eve::as<pv2>(), "0.1");
  TTS_EXPECT(checked.has_value());
  TTS_EQUAL(plf::hi(*checked), plf::hi(x));
  TTS_EXPECT(plf::from_string[plf::pedantic](eve::as<pv2>(), "nan").has_value());
};

TTS_CASE_TPL("Check from_string of one string per lane", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv2 = plf::polyfloat<T, 2>;
  using wpv2 = eve::wide<pv2, 4>;
  using wT = eve::wide<T, 4>;

  char const* pointer = "3'125'569.000'1";
  std::string string = "-0x1.8p1";
  std::string_view view = "1e-5";
  std::array expected{plf::from_string(eve::as<pv2>(), "0.1"), plf::from_string(eve::as<pv2>(), pointer),
                      plf::from_string(eve::as<pv2>(), string), plf::from_string(eve::as<pv2>(), view)};

  auto w = plf::from_string(eve::as<wpv2>(), "0.1", pointer, string, view);
  auto checked = plf::from_string[plf::pedantic](eve::as<wpv2>(), "0.1", pointer, string, view);
  auto bad = plf::from_string(eve::as<wpv2>(), "0.1", pointer, "1.5x", view);
  TTS_EXPECT(checked.has_value(), REQUIRED);
  for (std::ptrdiff_t i = 0; i < 4; ++i)
  {
    TTS_IEEE_EQUAL(plf::hi(w.get(i)), plf::hi(expected[i]));
    TTS_IEEE_EQUAL(plf::lo(w.get(i)), plf::lo(expected[i]));
    TTS_IEEE_EQUAL(plf::hi(checked->get(i)), plf::hi(expected[i]));
    TTS_IEEE_EQUAL(plf::lo(checked->get(i)), plf::lo(expected[i]));
    if (i != 2) TTS_IEEE_EQUAL(plf::hi(bad.get(i)), plf::hi(expected[i]));
  }
  TTS_EXPECT(plf::is_nan(bad.get(2)));
  TTS_EXPECT(!plf::from_string[plf::pedantic](eve::as<wpv2>(), "0.1", pointer, "1.5x", view).has_value());

  auto spaced =
    plf::from_string[plf::pedantic][plf::separator = ' '](eve::as<wpv2>(), "0.1", "3 125 569.000 1", string, view);
  TTS_EXPECT(spaced.has_value(), REQUIRED);
  for (std::ptrdiff_t i = 0; i < 4; ++i)
  {
    TTS_IEEE_EQUAL(plf::hi(spaced->get(i)), plf::hi(expected[i]));
    TTS_IEEE_EQUAL(plf::lo(spaced->get(i)), plf::lo(expected[i]));
  }

  auto pair = plf::from_string(eve::as<eve::wide<pv2, 2>>(), "0.1", pointer);
  for (std::ptrdiff_t i = 0; i < 2; ++i)
  {
    TTS_IEEE_EQUAL(plf::hi(pair.get(i)), plf::hi(expected[i]));
    TTS_IEEE_EQUAL(plf::lo(pair.get(i)), plf::lo(expected[i]));
  }

  TTS_IEEE_EQUAL(plf::from_string(eve::as<wT>(), "1", "2.5", "-0x1.8p1", "inf"),
                 wT(T(1), T(2.5), T(-3), eve::inf(eve::as<T>())));
  TTS_IEEE_EQUAL(plf::from_string[plf::separator = ' '](eve::as<wT>(), "1 000", "2 000", "3 000", "4 000"),
                 wT(T(1000), T(2000), T(3000), T(4000)));
  TTS_EXPECT(eve::all(eve::is_nan(plf::from_string[plf::separator = '\0'](eve::as<wT>(), "1'0", "2'0", "3'0", "4'0"))));

  TTS_EXPECT_NOT_COMPILES(view, { plf::from_string(eve::as<wT>(), view, view, view); });
  TTS_EXPECT_NOT_COMPILES(view, { plf::from_string(eve::as<T>(), view, view); });
  TTS_EXPECT_NOT_COMPILES(view, { plf::from_string(eve::as<eve::wide<T, 2>>(), ' ', view); });
  TTS_EXPECT_NOT_COMPILES(view, { plf::from_string[plf::separator = view](eve::as<T>(), view); });
  int none = 0;
  TTS_EXPECT_NOT_COMPILES(view, none, { plf::from_string[plf::separator = none](eve::as<T>(), view); });
};

TTS_CASE_TPL("Check from_string with a separator", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv2 = plf::polyfloat<T, 2>;
  auto same = [](pv2 a, pv2 b) { return plf::hi(a) == plf::hi(b) && plf::lo(a) == plf::lo(b); };
  auto plain = plf::from_string(eve::as<pv2>(), "3.14566599923332566");

  TTS_EXPECT(same(plf::from_string(eve::as<pv2>(), "3.1456'65999'2333'2566"), plain));
  TTS_EXPECT(same(plf::from_string(eve::as<pv2>(), "3'125'569"), pv2(T(3125569))));
  TTS_EXPECT(same(plf::from_string[plf::separator = ' '](eve::as<pv2>(), "3.1456 65999 2333 2566"), plain));
  TTS_EXPECT(same(plf::from_string[plf::separator = '_'](eve::as<pv2>(), "3.1456_65999_2333_2566"), plain));
  TTS_EXPECT(same(plf::from_string[plf::separator = ','](eve::as<pv2>(), "3,125,569"), pv2(T(3125569))));
  TTS_EXPECT(!plf::from_string[plf::pedantic][plf::separator = ' '](eve::as<pv2>(), "1'2").has_value());
  auto checked = plf::from_string[plf::separator = ' '][plf::pedantic](eve::as<pv2>(), "3 125 569");
  TTS_EXPECT(checked.has_value(), REQUIRED);
  TTS_EXPECT(same(*checked, pv2(T(3125569))));
  TTS_EXPECT(same(plf::from_string[plf::separator = '\''](eve::as<pv2>(), "-1'234.5e-3"),
                  plf::from_string(eve::as<pv2>(), "-1.2345")));
  TTS_EXPECT(same(plf::from_string[plf::separator = '\''](eve::as<pv2>(), "0x1'8p1"), pv2(T(48))));
  TTS_EXPECT(same(plf::from_string(eve::as<pv2>(), "1e1'0"), pv2(T(1e10))));
  TTS_EXPECT(same(plf::from_string(eve::as<pv2>(), "0x1p1'0"), pv2(T(1024))));
  for (auto s : {"'1", "1'", "1''2", "1'.5", "1.'5", "1'e5", "1e'10", "1e+'1", "1e1'", "0x'1", "'"})
    TTS_EXPECT(!plf::from_string[plf::pedantic](eve::as<pv2>(), s).has_value());
  TTS_EXPECT(!plf::from_string[plf::pedantic][plf::separator = '\0'](eve::as<pv2>(), "1'2").has_value());
  TTS_EXPECT(!plf::from_string[plf::pedantic](eve::as<pv2>(), "1 2").has_value());
  TTS_EXPECT(!plf::from_string[plf::pedantic][plf::separator = '.'](eve::as<pv2>(), "1.5").has_value());
  TTS_EXPECT(!plf::from_string[plf::pedantic][plf::separator = '5'](eve::as<pv2>(), "15").has_value());
};

TTS_CASE_TPL("Check the rounding of from_string at its boundaries", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv2 = plf::polyfloat<T, 2>;
  auto eps = eve::eps(eve::as<T>());

  std::string tie =
    std::same_as<T, double> ? "1.00000000000000011102230246251565404236316680908203125" : "1.000000059604644775390625";
  auto at = plf::from_string(eve::as<pv2>(), tie);
  TTS_EQUAL(plf::hi(at), T(1));
  TTS_EQUAL(plf::lo(at), eps / 2);
  for (std::size_t zeros : {10u, 5000u, 100000u})
  {
    auto above = plf::from_string(eve::as<pv2>(), tie + std::string(zeros, '0') + "1");
    TTS_EQUAL(plf::hi(above), T(1));
    TTS_EQUAL(plf::lo(above), eps / 2);
  }

  std::string lo_tie = std::same_as<T, double>
                         ? "1.0000000000000000008673617379884036435024594600577460219395221292463659"
                           "2690508241076940976199693977832794189453125"
                         : "1.000000000931322630126629746882827021181583404541015625";
  auto lo_even = std::same_as<T, double> ? T(0x1p-60) : T(0x1p-30);
  auto lo_odd = lo_even + (std::same_as<T, double> ? T(0x1p-112) : T(0x1p-53));
  TTS_EQUAL(plf::lo(plf::from_string(eve::as<pv2>(), lo_tie)), lo_even);
  for (std::size_t zeros : {10u, 5000u, 100000u})
  {
    auto above = plf::from_string(eve::as<pv2>(), lo_tie + std::string(zeros, '0') + "1");
    TTS_EQUAL(plf::hi(above), T(1));
    TTS_EQUAL(plf::lo(above), lo_odd);
  }

  auto e = std::ilogb(eve::mindenormal(eve::as<T>()));
  TTS_EQUAL(plf::hi(plf::from_string(eve::as<pv2>(), "0x1p" + std::to_string(e - 1))), T(0));
  TTS_EQUAL(plf::hi(plf::from_string(eve::as<pv2>(), "0x1.8p" + std::to_string(e - 1))),
            eve::mindenormal(eve::as<T>()));

  std::string half = std::same_as<T, double> ? half_min_double : half_min_float;
  TTS_EQUAL(plf::hi(plf::from_string(eve::as<pv2>(), half)), T(0));
  auto e10 = half.find('e');
  TTS_EQUAL(plf::hi(plf::from_string(eve::as<pv2>(), half.substr(0, e10) + "1" + half.substr(e10))),
            eve::mindenormal(eve::as<T>()));

  if constexpr (std::same_as<T, double>)
  {
    TTS_EQUAL(plf::hi(plf::from_string(eve::as<pv2>(), "1e305")), 1e305);
    TTS_EQUAL(plf::hi(plf::from_string(eve::as<pv2>(), "1e-305")), 1e-305);
  }
  else
  {
    TTS_EQUAL(plf::hi(plf::from_string(eve::as<pv2>(), "1e38")), 1e38f);
    TTS_EQUAL(plf::hi(plf::from_string(eve::as<pv2>(), "1e-38")), 1e-38f);
  }

  auto top = std::same_as<T, double> ? std::string("0x1.fffffffffffff8p1023") : std::string("0x1.ffffffp127");
  auto below = std::same_as<T, double> ? std::string("0x1.fffffffffffff7ffp1023") : std::string("0x1.fffffefp127");
  TTS_EQUAL(plf::hi(plf::from_string(eve::as<pv2>(), top)), eve::inf(eve::as<T>()));
  TTS_EQUAL(plf::hi(plf::from_string(eve::as<pv2>(), below)), eve::valmax(eve::as<T>()));

  auto odd =
    std::same_as<T, double> ? std::string("0x1.00000000000017fffffffffffffp0") : std::string("0x1.000002ffffffcp0");
  auto normalized = plf::from_string(eve::as<pv2>(), odd);
  TTS_EQUAL(plf::hi(normalized), T(1) + 2 * eps);
  TTS_EQUAL(plf::lo(normalized), -eps / 2);
};

TTS_CASE_WITH("Check that a printed value reads back",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using pv3 = plf::polyfloat<T, 3>;
  pv3 x(a0, a1, a2);

  auto exact = text(x, std::hexfloat);
  TTS_EQUAL(text(plf::from_string(eve::as<pv3>(), exact), std::hexfloat), exact);
  TTS_EQUAL(text(plf::from_string(eve::as<pv3>(), text(x, std::setprecision(1200))), std::hexfloat), exact);
};

TTS_CASE_TPL("Check that a value a double holds prints as the double", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv2 = plf::polyfloat<T, 2>;
  using f = std::ios_base;
  double const nan = std::numeric_limits<double>::quiet_NaN();
  double const inf = std::numeric_limits<double>::infinity();

  for (double v : {1.25, -1234567.25, 0.0, -0.0, 1048576.0, 0x1p-15, 9.5, 99.5, inf, -inf, nan, -nan})
  {
    pv2 x(static_cast<T>(v));
    for (f::fmtflags flags : {f::fmtflags{}, f::showpoint, f::showpos, f::uppercase | f::showpos, f::fixed,
                              f::fixed | f::showpoint, f::scientific, f::scientific | f::uppercase | f::showpoint,
                              f::fixed | f::scientific, f::fixed | f::scientific | f::showpoint | f::uppercase})
    {
      for (int p : {-1, 0, 1, 6, 17})
        TTS_EQUAL(text(x, std::setiosflags(flags), std::setprecision(p)),
                  text(v, std::setiosflags(flags), std::setprecision(p)));
      for (auto adjust : {f::left, f::right, f::internal})
        TTS_EQUAL(text(x, std::setiosflags(flags | adjust), std::setw(24), std::setfill('*')),
                  text(v, std::setiosflags(flags | adjust), std::setw(24), std::setfill('*')));
      TTS_EQUAL(localized(x, flags), localized(v, flags));
      TTS_EXPECT(wide_localized(x, flags) == wide_localized(v, flags));
    }
  }
};

TTS_CASE_TPL("Check stream output", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv2 = plf::polyfloat<T, 2>;
  using pv3 = plf::polyfloat<T, 3>;
  auto r2 = plf::sqrt_2(eve::as<pv2>());
  auto r3 = plf::sqrt_2(eve::as<pv3>());

  if constexpr (std::same_as<T, double>)
  {
    TTS_EQUAL(text(r2, std::setprecision(32)), std::string("1.4142135623730950488016887242097"));
    TTS_EQUAL(text(r3, std::setprecision(48)), std::string("1.41421356237309504880168872420969807856967187538"));
    TTS_EQUAL(text(r2, std::hexfloat), std::string("0x1.6a09e667f3bcc908b2fb1366ea8p+0"));
    TTS_EQUAL(text(r3, std::hexfloat), std::string("0x1.6a09e667f3bcc908b2fb1366ea957d3e3adec175p+0"));
    TTS_EQUAL(text(r2, plf::showparts), std::string("1.41421 - 9.66729e-17"));
    TTS_EQUAL(text(r2, std::showpos, plf::showparts), std::string("+1.41421 - 9.66729e-17"));
    TTS_EQUAL(text(r2, std::fixed, std::setprecision(20)), std::string("1.41421356237309504880"));
    TTS_EQUAL(text(r2, std::scientific, std::setprecision(25)), std::string("1.4142135623730950488016887e+00"));
  }
  else
  {
    TTS_EQUAL(text(r2, std::setprecision(32)), std::string("1.4142135623730958116084366338328"));
    TTS_EQUAL(text(r3, std::setprecision(48)), std::string("1.41421356237309504880169279742146287714987806794"));
    TTS_EQUAL(text(r2, std::hexfloat), std::string("0x1.6a09e667f3bdp+0"));
    TTS_EQUAL(text(r3, std::hexfloat), std::string("0x1.6a09e667f3bcc908b3p+0"));
    TTS_EQUAL(text(r2, plf::showparts), std::string("1.41421 + 2.42032e-08"));
    TTS_EQUAL(text(r2, std::showpos, plf::showparts), std::string("+1.41421 + 2.42032e-08"));
    TTS_EQUAL(text(r2, std::fixed, std::setprecision(20)), std::string("1.41421356237309581161"));
    TTS_EQUAL(text(r2, std::scientific, std::setprecision(25)), std::string("1.4142135623730958116084366e+00"));
  }

  auto eps = eve::eps(eve::as<T>());
  pv2 below_one(T(1), -eps * eps);
  TTS_EQUAL(text(below_one, std::fixed, std::setprecision(3)), std::string("1.000"));
  TTS_EQUAL(text(below_one, std::scientific, std::setprecision(2)), std::string("1.00e+00"));
  TTS_EQUAL(text(below_one, std::setprecision(3)), std::string("1"));
  pv2 above_one(T(1), eps * eps);
  TTS_EQUAL(text(above_one), std::string("1"));
  TTS_EQUAL(text(above_one, std::showpoint), std::string("1.00000"));
  TTS_EQUAL(text(r2, std::scientific, std::showpoint, std::setprecision(0)), std::string("1.e+00"));

  auto grouped = [](auto x, std::string g, std::ios_base::fmtflags flags) {
    struct dot : std::numpunct<char>
    {
      std::string g;
      dot(std::string s) : g(s) {}
      char do_decimal_point() const override { return ','; }
      char do_thousands_sep() const override { return '.'; }
      std::string do_grouping() const override { return g; }
    };
    std::ostringstream os;
    os.imbue(std::locale(std::locale::classic(), new dot(g)));
    os.flags(flags);
    os.precision(2);
    os << x;
    return os.str();
  };
  TTS_EQUAL(grouped(pv2(T(1073741824)), std::string("\4\0", 2), std::ios_base::fixed), std::string("10.7374.1824,00"));
  TTS_EQUAL(grouped(pv2(T(1073741824)), std::string("\3\0\2", 3), std::ios_base::fixed),
            std::string("1.073.741.824,00"));
  TTS_EQUAL(grouped(pv2(T(1.5)), std::string("\1"), std::ios_base::fixed | std::ios_base::scientific),
            std::string("0.x.1,8p+0"));

  TTS_EQUAL(text(r2), std::string("1.41421"));
  TTS_EQUAL(text(r2, plf::showparts, plf::noshowparts), std::string("1.41421"));

  auto parts = text(r2, plf::showparts);
  TTS_EQUAL(text(r2, plf::showparts, std::setw(30), std::setfill('*')), std::string(30 - parts.size(), '*') + parts);

  std::wostringstream ws;
  ws << plf::from_string(eve::as<pv2>(), "0.1");
  TTS_EXPECT(ws.str() == L"0.1");
};

TTS_CASE("Check half precision")
{
  using pv2 = plf::polyfloat<eve::float16_t, 2>;
  auto x = plf::from_string(eve::as<pv2>(), "0.1");
  TTS_EQUAL(static_cast<double>(plf::hi(x)), 0x1.998p-4);
  TTS_EQUAL(static_cast<double>(plf::lo(x)), 0x1.9ap-16);
  TTS_EQUAL(text(x), std::string("0.1"));
  TTS_EQUAL(text(x, std::hexfloat), std::string("0x1.9999ap-4"));
  TTS_EQUAL(text(x, plf::showparts), std::string("0.0999756 + 2.44379e-05"));

  auto hi = [](char const* s) { return static_cast<double>(plf::hi(plf::from_string(eve::as<pv2>(), s))); };
  TTS_EQUAL(hi("0x1p-25"), 0.0);
  TTS_EQUAL(hi("0x1.8p-25"), 0x1p-24);
  TTS_EXPECT(std::isinf(hi("0x1.ffep15")));
  TTS_EQUAL(hi("65519"), 65504.0);
  TTS_EQUAL(static_cast<double>(plf::lo(plf::from_string(eve::as<pv2>(), "65519"))), 15.0);
};

TTS_CASE_TPL("Check stream output of a register", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv2 = plf::polyfloat<T, 2>;
  eve::wide<pv2> w(pv2(T(1)));
  TTS_EQUAL(text(w), lanes("1", w.size()));
  TTS_EQUAL(text(w, plf::showparts), lanes("1 + 0", w.size()));
};
