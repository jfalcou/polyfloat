//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once
#include <polyfloat/details/abi.hpp>
#include <polyfloat/types/traits.hpp>
#include <eve/traits/overload.hpp>

namespace plf::_
{
  EVE_CALLABLE_NAMESPACE();
}

//  EVE-related macro that use polyfloat::_ as the deferred namespace
#define POLYFLOAT_CALLABLE_OBJECT(TYPE, NAME) EVE_CALLABLE_OBJECT_FROM(plf::_, TYPE, NAME)
#define POLYFLOAT_CALL(...) EVE_DISPATCH_CALL(__VA_ARGS__)
#define POLYFLOAT_DELAY() EVE_REQUIRES(eve::cpu_)

namespace plf
{
  namespace _
  {
    // behavior() is the entry point eve dispatches every call through
    template<template<typename> class Eve, typename Base> struct deferring_callable : Base
    {
      template<eve::callable_options O, typename... Ts>
      POLYFLOAT_FORCEINLINE constexpr auto behavior(auto arch, O const& opts, Ts... xs) const
      {
        if constexpr (((dimension_v<Ts> == 1) && ...)) return eve::functor<Eve>[opts](xs...);
        else return Base::behavior(arch, opts, xs...);
      }
    };

    template<template<typename> class Eve, typename Base> struct deferring_constant : Base
    {
      template<typename O, typename T>
      POLYFLOAT_FORCEINLINE constexpr auto behavior(auto arch, O const& opts, eve::as<T> target) const
      {
        if constexpr (dimension_v<T> == 1) return eve::functor<Eve>[opts](target);
        else return Base::behavior(arch, opts, target);
      }
    };
  }

  //====================================================================================================================
  //! @addtogroup traits
  //! @{
  //====================================================================================================================

  //====================================================================================================================
  //! @struct elementwise_callable
  //! @brief [polyfloat](@ref plf) counterpart of eve::elementwise_callable.
  //!
  //! Behaves as eve::elementwise_callable except when all its parameters have a dimension_v equal to 1, in which case
  //! it forwards to [EVE](https://jfalcou.github.io/eve/) directly.
  //!
  //! @tparam Func          The callable being defined
  //! @tparam Eve           The [EVE](https://jfalcou.github.io/eve/) callable to forward to
  //! @tparam OptionsValues Type of the stored options
  //! @tparam Options       List of supported option specifications
  //====================================================================================================================
  template<template<typename> class Func, template<typename> class Eve, typename OptionsValues, typename... Options>
  struct elementwise_callable : _::deferring_callable<Eve, eve::elementwise_callable<Func, OptionsValues, Options...>>
  {
  };

  //====================================================================================================================
  //! @struct strict_tuple_callable
  //! @brief [polyfloat](@ref plf) counterpart of eve::strict_tuple_callable.
  //!
  //! Behaves as eve::strict_tuple_callable except when all its parameters have a dimension_v equal to 1, in which case
  //! it forwards to [EVE](https://jfalcou.github.io/eve/) directly.
  //!
  //! @tparam Func          The callable being defined
  //! @tparam Eve           The [EVE](https://jfalcou.github.io/eve/) callable to forward to
  //! @tparam OptionsValues Type of the stored options
  //! @tparam Options       List of supported option specifications
  //====================================================================================================================
  template<template<typename> class Func, template<typename> class Eve, typename OptionsValues, typename... Options>
  struct strict_tuple_callable : _::deferring_callable<Eve, eve::strict_tuple_callable<Func, OptionsValues, Options...>>
  {
  };

  //====================================================================================================================
  //! @struct callable
  //! @brief [polyfloat](@ref plf) counterpart of eve::callable.
  //!
  //! Behaves as eve::callable except when all its parameters have a dimension_v equal to 1, in which case it forwards
  //! to [EVE](https://jfalcou.github.io/eve/) directly.
  //!
  //! @tparam Func          The callable being defined
  //! @tparam Eve           The [EVE](https://jfalcou.github.io/eve/) callable to forward to
  //! @tparam OptionsValues Type of the stored options
  //! @tparam Options       List of supported option specifications
  //====================================================================================================================
  template<template<typename> class Func, template<typename> class Eve, typename OptionsValues, typename... Options>
  struct callable : _::deferring_callable<Eve, eve::callable<Func, OptionsValues, Options...>>
  {
  };

  //====================================================================================================================
  //! @struct constant_callable
  //! @brief [polyfloat](@ref plf) counterpart of eve::constant_callable.
  //!
  //! Behaves as eve::constant_callable except when its target type has a dimension_v equal to 1, in which case it
  //! forwards to [EVE](https://jfalcou.github.io/eve/) directly.
  //!
  //! @tparam Func          The constant being defined
  //! @tparam Eve           The [EVE](https://jfalcou.github.io/eve/) constant to forward to
  //! @tparam OptionsValues Type of the stored options
  //! @tparam Options       List of supported option specifications
  //====================================================================================================================
  template<template<typename> class Func, template<typename> class Eve, typename OptionsValues, typename... Options>
  struct constant_callable : _::deferring_constant<Eve, eve::constant_callable<Func, OptionsValues, Options...>>
  {
  };

  //====================================================================================================================
  //! @}
  //====================================================================================================================
}
