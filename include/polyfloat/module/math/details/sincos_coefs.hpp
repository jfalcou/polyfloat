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

  template<typename T> auto cos_coefs()
  {
    if constexpr (std::same_as<T, double_real_t<float>>)
    {
      //using r_t = double_real_t<float>
      return kumi::tuple{plf::_::from_pair<float>(0x1p+0, +0x0p+0),
                         plf::_::from_pair<float>(-0x1p-1, +0x1.8p-48),
                         plf::_::from_pair<float>(0x1.555556p-5, -0x1.55614p-30),
                         plf::_::from_pair<float>(-0x1.6c16c2p-10, +0x1.376484p-35),
                         plf::_::from_pair<float>(0x1.a019f8p-16, +0x1.33c19p-42),
                         plf::_::from_pair<float>(-0x1.27df56p-22, -0x1.fe7cbp-49),
                         plf::_::from_pair<float>(0x1.1b8fbcp-29, -0x1.3ccf8p-58)};
    }
    else if constexpr (std::same_as<T, triple_real_t<float>>)
    {
      //using r_t = double_real_t<float>;
      return kumi::tuple{
        plf::_::from_triple<float>(0x1p+0, +0x0p+0, +0x0p+0),
        plf::_::from_triple<float>(-0x1p-1, +0x1p-68, +0x0p+0),
        plf::_::from_triple<float>(0x1.555556p-5, -0x1.555556p-30, +0x1.53c8cp-55),
        plf::_::from_triple<float>(-0x1.6c16c2p-10, +0x1.27d27ep-35, +0x1.a71a8p-60),
        plf::_::from_triple<float>(0x1.a01a02p-16, -0x1.7f9f04p-42, -0x1.36ep-72),
        plf::_::from_triple<float>(-0x1.27e4fcp-22, +0x1.150d44p-47, +0x1.b0d88p-72),
        plf::_::from_triple<float>(0x1.1eed8cp-29, +0x1.4dd5p-56, +0x1.19bbp-81),
        plf::_::from_triple<float>(-0x1.9392c2p-37, -0x1.8aab28p-63, -0x1.7c58p-89),
        plf::_::from_triple<float>(0x1.aa972ep-45, -0x1.9e9332p-70, -0x1.74e9p-95),
      };
    }
    else if constexpr (std::same_as<T, double_real_t<double>>)
    {
      //using r_t = double_real_t<double>;
      return kumi::tuple{
        plf::_::from_pair<double>(0x1p+0, +0x0p+0),
        plf::_::from_pair<double>(-0x1p-1, +0x1.18p-102),
        plf::_::from_pair<double>(0x1.5555555555555p-5, +0x1.5555555548eb4p-59),
        plf::_::from_pair<double>(-0x1.6c16c16c16c17p-10, +0x1.f49f4a5768168p-65),
        plf::_::from_pair<double>(0x1.a01a01a01a01ap-16, +0x1.9fe8c4b57e18p-76),
        plf::_::from_pair<double>(-0x1.27e4fb7789f5cp-22, -0x1.c9f238e0a982dp-76),
        plf::_::from_pair<double>(0x1.1eed8eff8d896p-29, +0x1.978ac9749f96fp-83),
        plf::_::from_pair<double>(-0x1.93974a8c07793p-37, +0x1.82ee317825dbp-94),
        plf::_::from_pair<double>(0x1.ae7f3e726ce4fp-45, -0x1.6d4bb0e413fafp-99),
        plf::_::from_pair<double>(-0x1.682784de2f11p-53, -0x1.7124a4345b29ep-108),
        plf::_::from_pair<double>(0x1.e53fccfb5614cp-62, -0x1.daedc787b65f8p-117),
        plf::_::from_pair<double>(-0x1.0b15f05d82628p-70, +0x1.b38f07d777c42p-125),
      };
    }
    else if constexpr (std::same_as<T, triple_real_t<double>>)
    {
      //using r_t = triple_real_t<double>;
      return kumi::tuple{
        plf::_::from_triple<double>(0x1p+0, +0x0p+0, +0x0p+0),
        plf::_::from_triple<double>(-0x1p-1, +0x0p+0, +0x0p+0),
        plf::_::from_triple<double>(0x1.5555555555555p-5, +0x1.5555555555555p-59, +0x1.5555555555474p-113),
        plf::_::from_triple<double>(-0x1.6c16c16c16c17p-10, +0x1.f49f49f49f49fp-65, +0x1.27d27d29369cep-119),
        plf::_::from_triple<double>(0x1.a01a01a01a01ap-16, +0x1.a01a01a01a01ap-76, +0x1.9fa8bd5859p-136),
        plf::_::from_triple<double>(-0x1.27e4fb7789f5cp-22, -0x1.cbbc05b4fa99ap-76, +0x1.c7712d610a62p-132),
        plf::_::from_triple<double>(0x1.1eed8eff8d898p-29, -0x1.2aec959e14c06p-83, -0x1.97e00071ede88p-138),
        plf::_::from_triple<double>(-0x1.93974a8c07c9dp-37, -0x1.05d6f8a2ef7e7p-92, +0x1.d326c1a15e4eep-146),
        plf::_::from_triple<double>(0x1.ae7f3e733b81fp-45, +0x1.1d8656ac84d0dp-101, +0x1.1fd2c1d0996f4p-155),
        plf::_::from_triple<double>(-0x1.6827863b97d97p-53, -0x1.eec00cb429655p-107, -0x1.4ee20fb1234p-167),
        plf::_::from_triple<double>(0x1.e542ba4020225p-62, +0x1.e7fb335aedc9bp-120, -0x1.fffab29cc914p-174),
        plf::_::from_triple<double>(-0x1.0ce396db7f852p-70, -0x1.e690437d35839p-124, +0x1.5c76a791a5431p-178),
        plf::_::from_triple<double>(0x1.f2cf01972f4a2p-80, +0x1.4ea269f34fe63p-138, -0x1.750170debd68p-192),
        plf::_::from_triple<double>(-0x1.88e85fc67dc3cp-89, -0x1.17e7f4e4b8ed6p-143, +0x1.486eb1e708244p-199),
        plf::_::from_triple<double>(0x1.0a18a211f01bdp-98, +0x1.206dbe6558fcp-153, -0x1.4057cbbd0b374p-207),
        plf::_::from_triple<double>(-0x1.3931e172b6931p-108, -0x1.ae8922f8ac0fp-163, -0x1.6b9f3d518571ap-217),
        plf::_::from_triple<double>(0x1.41cd7944e8bc1p-118, -0x1.c71cf34af3e2p-177, +0x1.eda8cfeb4e1p-234)};
    }
  }

  template<typename T> auto sino_x_coefs()
  {
    if constexpr (std::same_as<T, double_real_t<float>>)
    {
      //using r_t = double_real_t<float>
      return kumi::tuple{plf::_::from_pair<float>(0x1p+0, +0x0p+0),
                         plf::_::from_pair<float>(-0x1.555556p-3, +0x1.555558p-28),
                         plf::_::from_pair<float>(0x1.111112p-7, -0x1.dde238p-32),
                         plf::_::from_pair<float>(-0x1.a01a02p-13, +0x1.93dd88p-39),
                         plf::_::from_pair<float>(0x1.71de34p-19, +0x1.692c54p-44),
                         plf::_::from_pair<float>(-0x1.ae5dep-26, -0x1.d8e3cp-52),
                         plf::_::from_pair<float>(0x1.5d7052p-33, +0x1.74a7ep-61)};
    }
    else if constexpr (std::same_as<T, triple_real_t<float>>)
    {
      //using r_t = double_real_t<float>;
      return kumi::tuple{plf::_::from_triple<float>(0x1p+0, +0x0p+0, +0x0p+0),
                         plf::_::from_triple<float>(-0x1.555556p-3, +0x1.555556p-28, -0x1.555558p-53),
                         plf::_::from_triple<float>(0x1.111112p-7, -0x1.dddddep-32, +0x1.112cp-59),
                         plf::_::from_triple<float>(-0x1.a01a02p-13, +0x1.7f97fap-39, -0x1.334fep-64),
                         plf::_::from_triple<float>(0x1.71de3ap-19, +0x1.55b1fcp-45, +0x1.ac39p-70),
                         plf::_::from_triple<float>(-0x1.ae6456p-26, -0x1.fdb8d4p-52, +0x1.28c7p-78),
                         plf::_::from_triple<float>(0x1.612462p-33, -0x1.489358p-58, +0x1.0ae3p-85),
                         plf::_::from_triple<float>(-0x1.ae7f7p-41, -0x1.abd16ep-68, -0x1.415fcp-94),
                         plf::_::from_triple<float>(0x1.95546cp-49, -0x1.a12e54p-74, +0x1.1da4p-103),
                         plf::_::from_triple<float>(-0x1.3beacep-57, +0x1.2c0736p-82, +0x1.d2aea8p-107)};
    }
    else if constexpr (std::same_as<T, double_real_t<double>>)
    {
      return kumi::tuple{plf::_::from_pair<double>(0x1p+0, +0x0p+0),
                         plf::_::from_pair<double>(-0x1.5555555555555p-3, -0x1.5555555555555p-57),
                         plf::_::from_pair<double>(0x1.1111111111111p-7, +0x1.1111111110b28p-63),
                         plf::_::from_pair<double>(-0x1.a01a01a01a01ap-13, -0x1.a01a017855fcp-73),
                         plf::_::from_pair<double>(0x1.71de3a556c734p-19, -0x1.c154fb0f012e5p-73),
                         plf::_::from_pair<double>(-0x1.ae64567f544e4p-26, +0x1.c06c29a3555bcp-80),
                         plf::_::from_pair<double>(0x1.6124613a86d09p-33, +0x1.d93f6f54fe66cp-87),
                         plf::_::from_pair<double>(-0x1.ae7f3e733b808p-41, -0x1.4c0dfcb7beee8p-97),
                         plf::_::from_pair<double>(0x1.952c7703074efp-49, +0x1.800a8d6fc3118p-105),
                         plf::_::from_pair<double>(-0x1.2f49b4624f386p-57, +0x1.107bdd978ff7cp-113),
                         plf::_::from_pair<double>(0x1.71b8e345c53b4p-66, -0x1.62182f0e94a3p-123),
                         plf::_::from_pair<double>(-0x1.760c2a005ccbep-75, +0x1.f000c1aff4a2ep-129),
                         plf::_::from_pair<double>(0x1.365f1b4976ce5p-84, -0x1.0292b83c87daep-138)};
    }
    else if constexpr (std::same_as<T, triple_real_t<double>>)
    {
      //using r_t = double_real_t<double>;
      return kumi::tuple{
        plf::_::from_triple<double>(0x1p+0, +0x0p+0, +0x0p+0),
        plf::_::from_triple<double>(-0x1.5555555555555p-3, -0x1.5555555555555p-57, -0x1.5555555555555p-111),
        plf::_::from_triple<double>(0x1.1111111111111p-7, +0x1.1111111111111p-63, +0x1.111111110e62p-119),
        plf::_::from_triple<double>(-0x1.a01a01a01a01ap-13, -0x1.a01a01a01a01ap-73, -0x1.a019e05fd4p-133),
        plf::_::from_triple<double>(0x1.71de3a556c734p-19, -0x1.c154f8ddc6cp-73, +0x1.71de2c8b111d6p-127),
        plf::_::from_triple<double>(-0x1.ae64567f544e4p-26, +0x1.c062e06d1f209p-80, -0x1.c5c35ae4e386cp-136),
        plf::_::from_triple<double>(0x1.6124613a86d09p-33, +0x1.f28e0cc748ebdp-87, +0x1.698c02ecfb12p-145),
        plf::_::from_triple<double>(-0x1.ae7f3e733b81fp-41, -0x1.1d8656b0ed5fap-97, +0x1.332f46ff869ep-152),
        plf::_::from_triple<double>(0x1.952c77030ad4ap-49, +0x1.ac9814643646cp-103, -0x1.672ff9149e1e4p-157),
        plf::_::from_triple<double>(-0x1.2f49b46814157p-57, -0x1.2650e850a9639p-112, -0x1.87d4dcc7949f8p-167),
        plf::_::from_triple<double>(0x1.71b8ef6dcf572p-66, -0x1.d06ed193305d2p-120, +0x1.c8a6569527851p-174),
        plf::_::from_triple<double>(-0x1.761b41316381ap-75, +0x1.64ae3e5cd8493p-129, -0x1.e07ede3a3bb48p-184),
        plf::_::from_triple<double>(0x1.3f3ccdd165ef7p-84, +0x1.8e705b5f4306bp-140, -0x1.6170961bf218p-198),
        plf::_::from_triple<double>(-0x1.d1ab1c2d9396ap-94, +0x1.0fb92a3020019p-149, +0x1.79c7336af0a5ap-203),
        plf::_::from_triple<double>(0x1.259f984ab1657p-103, +0x1.115b541983fe8p-157, -0x1.b6ec9fca0d8bap-211),
        plf::_::from_triple<double>(-0x1.434c28656c9d2p-113, +0x1.04f1739868a88p-170, +0x1.70d3ba901a7ep-224),
        plf::_::from_triple<double>(0x1.37f7bad17451dp-123, +0x1.682a8cc6ac10dp-177, -0x1.6fe5ff9fe424ep-232)};
    }
  }
}
