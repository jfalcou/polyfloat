//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace plf::_
{

  // pade approximation of tan

  template<typename T> auto tan_coefs()
  {
    if constexpr (std::is_same_v<T, float>)
    {
      auto P = kumi::tuple{};
      auto Q = kumi::tuple{};
      return kumi::tuple{P, Q};
    }
    else if constexpr (std::is_same_v<T, double>)
    {
      auto P = kumi::tuple{};
      auto Q = kumi::tuple{};
      return kumi::tuple{P, Q};
    }
    else if constexpr (std::same_as<T, double_real_t<float>>)
    {
      auto P = kumi::tuple{};
      auto Q = kumi::tuple{};
      return kumi::tuple{P, Q};
    }
    else if constexpr (std::same_as<T, triple_real_t<float>>)
    {
      auto P = kumi::tuple{};
      auto Q = kumi::tuple{};
      return kumi::tuple{P, Q};
    }
    else if constexpr (std::same_as<T, double_real_t<double>>)
    {
      using d2_t = plf::double_real_t<double>;
      auto P = kumi::tuple{d2_t(0x1p+0, +0x1.09d8792fb4c49p-111),
                           d2_t(-0x1.344d1344d1345p-3, +0x1.765d9765d9766p-58),
                           d2_t(0x1.7b12d9e624ca8p-8, +0x1.6706c6fdaa3adp-62),
                           d2_t(-0x1.6a0d12a87a1adp-14, +0x1.76e8f5e27c86ap-68),
                           d2_t(0x1.34f3431f20841p-21, +0x1.93b41648f5518p-75),
                           d2_t(-0x1.dd72444b8d55dp-30, +0x1.1c077d5711807p-88),
                           d2_t(0x1.2a7a12505d5b7p-39, +0x1.e2c5d3a2adfdap-93),
                           d2_t(-0x1.988aaf33dec89p-51, -0x1.b8ebe1f70878ap-111)};

      auto Q = kumi::tuple{d2_t(0x1p+0 + 0x1.09d8792fb4c49p-111),
                           d2_t(-0x1.ef7bdef7bdef8p-2, +0x1.0842108421084p-56),
                           d2_t(0x1.1468698d257e5p-5, +0x1.b074f118f6cafp-59),
                           d2_t(-0x1.49776a9431acep-14, +0x1.0d7cf43c2ec1ap-68),
                           d2_t(0x1.04ad40a2436f7p-17, +0x1.693fe59b23afbp-72),
                           d2_t(-0x1.2ce4030a47bccp-25, +0x1.176a83580d19bp-81),
                           d2_t(0x1.2f23fa999ed0ep-34, +0x1.5a50f8f62319ap-88),
                           d2_t(-0x1.aee244c8b4f79p-45, +0x1.ffd97a8783345p-99),
                           d2_t(0x1.808286c768445p-58, -0x1.6e0a64bb0d912p-112)};
      return kumi::tuple{P, Q};
    }
    else if constexpr (std::same_as<T, triple_real_t<double>>)
    {
      auto P = kumi::tuple{};
      auto Q = kumi::tuple{};
      return kumi::tuple{P, Q};
    }
  }
}
