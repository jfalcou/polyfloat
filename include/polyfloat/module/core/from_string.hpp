//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <polyfloat/details/callable.hpp>
#include <polyfloat/details/decimal/read.hpp>
#include <polyfloat/types/concepts.hpp>
#include <polyfloat/types/traits.hpp>
#include <array>
#include <concepts>
#include <cstddef>
#include <limits>
#include <optional>
#include <string_view>
#include <utility>

namespace plf
{
  template<typename Options>
  struct from_string_t : eve::callable<from_string_t, Options, pedantic_option, separator_option>
  {
    // Do not route this call through POLYFLOAT_CALL: EVE's dispatch ends in a noexcept call, and reading allocates,
    // so a std::bad_alloc would end the program.
    template<typename T, std::convertible_to<std::string_view>... S>
    requires((concepts::polyfloat<T> || eve::floating_value<T>) &&
             (sizeof...(S) == 1 || sizeof...(S) == eve::width_v<T>))
    auto operator()(eve::as<T>, S const&... s) const
    {
      using element_t = eve::element_type_t<T>;
      using base_t = as_component_type_t<element_t>;
      constexpr std::size_t n = dimension_v<element_t>;

      char const between = this->options()[separator | '\''];
      auto read = [&](std::string_view text) { return _::decimal::parse_parts<base_t, n>(text, between); };
      auto make = [](std::array<double, n> const& parts) {
        if constexpr (n == 1) return static_cast<element_t>(parts[0]);
        else if (parts[1] == 0) return element_t(static_cast<base_t>(parts[0]));
        else
          return [&]<std::size_t... I>(std::index_sequence<I...>) {
            return element_t(static_cast<base_t>(parts[I])...);
          }(std::make_index_sequence<n>{});
      };

      if constexpr (Options::contains(pedantic))
        return [&](auto const&... parts) {
          return (parts && ...) ? std::optional<T>(T(make(*parts)...)) : std::optional<T>{};
        }(read(s)...);
      else return T(make(read(s).value_or(std::array<double, n>{std::numeric_limits<double>::quiet_NaN()}))...);
    }
  };

  //======================================================================================================================
  //! @defgroup plf_from_string plf::from_string
  //! @ingroup core
  //! @brief Converts a string to a polyfloat value or to a real, each part rounded to nearest in turn.
  //! @{
  //!   @var from_string
  //!
  //!   The string holds one of these forms, with an optional sign and letters in either case:
  //!
  //!   - a decimal number, `.5` and `5.` included, and an optional exponent with its sign, `e-5`.
  //!   - a hexadecimal number after `0x`, and an optional binary exponent with its sign, `p-4`. `0x1.8` reads as 1.5,
  //!     as `strtod` reads it, where a C++ literal requires the exponent.
  //!   - `"%inf"`, `"infinity"`, or `"%nan"`.
  //!
  //!   The separator may stand between two digits of the significand or of the exponent, as the digit separator
  //!   `'` of C++ does. It is `'` by default, the option plf::separator names another one, and `'\0'` allows none.
  //!   A separator anywhere else, two in a row included, and every other character make the string malformed. A
  //!   separator that is a digit, a letter, the point, or a sign makes every string malformed.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/polyfloat.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace plf
  //!   {
  //!      template<typename T, std::convertible_to<std::string_view>... S>
  //!      T from_string(eve::as<T> target, S const&... s);
  //!   }
  //!   @endcode
  //!
  //!   Each option is given in its own brackets, and the two combine in either order,
  //!   `plf::from_string[plf::separator = ' '][plf::pedantic](target, s...)`:
  //!
  //!   - `plf::from_string[plf::separator = c](target, s...)` reads the strings with the character `c` as their
  //!     separator.
  //!   - `plf::from_string[plf::pedantic](target, s...)` returns a `std::optional<T>`.
  //!
  //!   **Parameters**
  //!
  //!     * `target`: `eve::as<T>()` for a result of type `T`, which is a scalar or SIMD polyfloat or real.
  //!     * `s`: the strings to read, of types convertible to `std::string_view`. Their count is 1 or the number of
  //!       lanes of `T`, N for `eve::wide<T, N>`, and another count does not compile.
  //!
  //!   **Return value**
  //!
  //!     The result is the value the string denotes. The high part is that value rounded to nearest, ties to even,
  //!     and each next part is the exact rest that the previous parts leave, rounded in the same way. The parts are
  //!     then normalized as by the constructor of plf::polyfloat, which changes them at a tie of a next part and
  //!     gives an infinity when their sum rounds past the largest finite value.
  //!
  //!     Infinities, zeros, and NaNs are read into the high part, with the sign of the string, and the next parts are
  //!     zero. An infinity and a zero also come from a value whose high part rounds past the largest finite value of
  //!     the base type or to zero: for `double`, `1e400` reads as an infinity and `-1e-400` as a negative zero.
  //!
  //!     A register holds the value of a single string in every lane, and the values of several strings in its
  //!     lanes, the first string in lane \f$0\f$.
  //!
  //!     A malformed string gives NaN, in its lane alone when several strings are read. Under plf::pedantic, the
  //!     [`std::optional`](https://en.cppreference.com/w/cpp/utility/optional) holds no value when a string of the
  //!     call is malformed, so that a malformed string differs from `"%nan"`.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/from_string.cpp}
  //======================================================================================================================

  inline constexpr auto from_string = eve::functor<from_string_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
