//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <polyfloat/details/callable.hpp>
#include <polyfloat/types/concepts.hpp>
#include <polyfloat/types/traits.hpp>
#include <type_traits>

namespace plf
{
  template<std::ptrdiff_t Index> struct extractor
  {
    template<concepts::polyfloat Z> POLYFLOAT_FORCEINLINE constexpr decltype(auto) operator()(Z&& z) const noexcept
    {
      using type = eve::element_type_t<std::remove_cvref_t<Z>>;
      if constexpr (Index < type::static_dimension) return get<Index>(POLYFLOAT_FWD(z));
      else return as_real_type_t<std::remove_cvref_t<Z>>{0};
    }

    template<concepts::real V> POLYFLOAT_FORCEINLINE constexpr decltype(auto) operator()(V&& v) const noexcept
    {
      using type = std::remove_cvref_t<V>;
      if constexpr (Index == 0) return POLYFLOAT_FWD(v);
      else return type{0};
    }
  };

  //====================================================================================================================
  //! @addtogroup functions
  //! @{
  //====================================================================================================================

  //====================================================================================================================
  //!   @var real
  //!   @brief Extracts the hi part of a value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <plf/functions.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace plf
  //!   {
  //!     constexpr decltype(auto) hi(concepts::polyfloat auto&& v)  noexcept; // 1
  //!     constexpr decltype(auto) hi(concepts::real auto&& v)       noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!   * `v`: Value to process.
  //!
  //!   **Return value**
  //!
  //!   1. Returns a properly const-qualified reference to the hi part of `v`.
  //!   2. Returns a properly const-qualified reference to `v`.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/hi.cpp}
  //====================================================================================================================
  inline constexpr auto hi = extractor<0>{};

}
