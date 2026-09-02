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
      else return as_component_type_t<std::remove_cvref_t<Z>>{0};
    }

    template<concepts::real V> POLYFLOAT_FORCEINLINE constexpr decltype(auto) operator()(V&& v) const noexcept
    {
      using type = std::remove_cvref_t<V>;
      if constexpr (Index == 0) return POLYFLOAT_FWD(v);
      else return type{0};
    }
  };

  //====================================================================================================================
  //! @addtogroup core
  //! @{
  //====================================================================================================================

  //====================================================================================================================
  //!   @var hi
  //!   @brief Extracts the hi part of a value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <plf/module/core.hpp>
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
  //!  @godbolt_todo{doc/core/hi.cpp}
  //====================================================================================================================
  inline constexpr auto hi = extractor<0>{};

  //====================================================================================================================
  //!   @var md
  //!   @brief Extracts the md part of a value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <plf/module/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace plf
  //!   {
  //!     constexpr decltype(auto) md(concepts::polyfloat auto&& v)  noexcept; // 1
  //!     constexpr decltype(auto) md(concepts::real auto&& v)       noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!   * `v`: Value to process.
  //!
  //!   **Return value**
  //!
  //!   1. Returns a properly const-qualified reference to the md part of `v`.
  //!   2. Returns a properly const-qualified reference to `v`.
  //!
  //!  @note the md part of a floating point value is always 0, for polyfloat the md part
  //!    always refers to the second component.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/md.cpp}
  //====================================================================================================================
  inline constexpr auto md = extractor<1>{};

  //====================================================================================================================
  //!   @var lo
  //!   @brief Extracts the lo part of a value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <plf/module/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace plf
  //!   {
  //!     constexpr decltype(auto) lo(concepts::polyfloat auto&& v)  noexcept; // 1
  //!     constexpr decltype(auto) lo(concepts::real auto&& v)       noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!   * `v`: Value to process.
  //!
  //!   **Return value**
  //!
  //!   1. Returns a properly const-qualified reference to the lo part of `v`.
  //!   2. Returns a properly const-qualified reference to `v`.
  //!
  //!  @note the lo part of a floating point value is always 0, for polyfloat the lo part
  //!    always refers to the last component.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/lo.cpp}
  //====================================================================================================================

  // TODO
  template<typename Options> struct lo_t : eve::elementwise_callable<lo_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr decltype(auto) operator()(Z&& z) const noexcept
    {
      if constexpr (dimension_v<Z> == 1) return extractor<1>{}(z);
      else return extractor<dimension_v<Z> - 1>{}(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(lo_t, lo_);
  };
  inline constexpr auto lo = eve::functor<lo_t>;

}
