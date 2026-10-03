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

}
