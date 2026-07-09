//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <eve/eve.hpp>
#include <polyfloat/types/helpers.hpp>
//#include <polyfloat/details/decorators.hpp>
#include <eve/as.hpp>
#include <bit>

namespace plf
{
  template<eve::floating_scalar_value Type, unsigned int N>
  requires(N > 1 && N <= _::MAX_N)
  struct polyfloat;
}

namespace plf::_
{
  // Force a type to be looked at as a wide so we can apply wide-like type preserving semantic in type computations
  template<typename T> struct sema
  {
    using type = T;
  };
  template<typename T> struct sema<eve::logical<T>> : sema<T>
  {
  };
  template<typename T, typename N> struct sema<eve::wide<T, N>>
  {
    using type = eve::wide<eve::underlying_type_t<T>>;
  };
  template<concepts::polyfloat T> struct sema<T>
  {
    using type = eve::wide<eve::underlying_type_t<T>>;
  };

  template<typename T> using sema_t = typename sema<T>::type;

  // Convert a Base type to a potential wide if any appear in T...
  template<typename Base, typename... T>
  using widen = std::conditional_t<std::max({eve::cardinal_v<T>...}) != 1ULL,
                                   eve::as_wide_t<Base, eve::fixed<std::max({eve::cardinal_v<T>...})>>,
                                   eve::element_type_t<Base>>;
}

namespace plf
{
  //====================================================================================================================
  //! @addtogroup traits
  //! @{
  //====================================================================================================================

  //====================================================================================================================
  //! @brief Obtains the rank containing a given type
  //!
  //! If `T` satisfies plf::concepts::polyfloat, evaluates to the number of parts of
  //! poly-float.
  //!
  //! @tparam T Type to analyze.
  //====================================================================================================================

  template<concepts::polyfloat T>
  inline constexpr auto dimension_v = std::remove_cvref_t<T>::static_dimension;

}
