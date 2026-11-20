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
#include <limits>
#include <optional>
#include <string_view>

namespace plf
{
  template<typename Options> struct from_string_t : eve::callable<from_string_t, Options, pedantic_option>
  {
    // Do not route this call through POLYFLOAT_CALL: EVE's dispatch ends in a noexcept call, and reading allocates,
    // so a std::bad_alloc would end the program.
    template<typename T>
    requires(concepts::polyfloat<T> || eve::floating_value<T>)
    auto operator()(std::string_view s, eve::as<T>, char separator = '\'') const
    {
      using element_t = eve::element_type_t<T>;
      using base_t = as_component_type_t<element_t>;
      constexpr std::size_t n = dimension_v<element_t>;

      auto make = [](std::array<double, n> const& parts) {
        element_t v{};
        if constexpr (n == 1) v = static_cast<element_t>(parts[0]);
        else kumi::for_each_index([&](auto i, auto& part) { part = static_cast<base_t>(parts[i]); }, v.contents);
        return T(v);
      };

      auto parts = _::decimal::parse_parts<base_t, n>(s, separator);
      if constexpr (Options::contains(pedantic)) return parts ? std::optional<T>(make(*parts)) : std::optional<T>{};
      else return make(parts.value_or(std::array<double, n>{std::numeric_limits<double>::quiet_NaN()}));
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
  //!   - a decimal number, with an optional exponent `e`.
  //!   - a hexadecimal number after `0x`, with an optional binary exponent `p`. `0x1.8` reads as 1.5, as `strtod`
  //!     reads it, where a C++ literal requires the exponent.
  //!   - `inf`, `infinity`, or `nan`.
  //!
  //!   The separator may stand between two digits, the exponent included, as the digit separator `'` of C++ does.
  //!   It is `'` by default, and 0 allows none. Any other character makes the string malformed. A separator that is
  //!   a digit, a letter, the point, or a sign also does.
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
  //!      template<typename T> T from_string(std::string_view s, eve::as<T> target, char separator = '\'');
  //!   }
  //!   @endcode
  //!
  //!   With the option plf::pedantic, `plf::from_string[plf::pedantic](s, target, separator)` returns a
  //!   `std::optional<T>`.
  //!
  //!   **Parameters**
  //!
  //!     * `s`: the string to read.
  //!     * `target`: the type of the result, a polyfloat or a real, scalar or SIMD.
  //!     * `separator`: the character that may separate two digits, or 0 for none.
  //!
  //!   **Return value**
  //!
  //!     The value `s` denotes: the high part is that value rounded to nearest, ties to even, and each next part
  //!     rounds the exact rest that the previous parts leave. A register holds this value in every lane. A malformed
  //!     string gives a NaN, and under plf::pedantic a [`std::optional`](https://en.cppreference.com/w/cpp/utility/optional)
  //!     that holds no value, so that a malformed string differs from `nan`.
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
