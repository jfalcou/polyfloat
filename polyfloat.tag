<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile doxygen_version="1.16.1" doxygen_gitid="669aeeefca743c148e2d935b3d3c69535c7491e6">
  <compound kind="struct">
    <name>plf::as_component</name>
    <filename>structplf_1_1as__component.html</filename>
    <templarg>typename T</templarg>
    <base>eve::as&lt; typename T &gt;</base>
  </compound>
  <compound kind="struct">
    <name>plf::as_polyfloat_like</name>
    <filename>structplf_1_1as__polyfloat__like.html</filename>
    <templarg>typename... Ts</templarg>
  </compound>
  <compound kind="struct">
    <name>complexify</name>
    <filename>structcomplexify.html</filename>
  </compound>
  <compound kind="class">
    <name>plf::polyfloat</name>
    <filename>structplf_1_1polyfloat.html</filename>
    <templarg>eve::floating_scalar_value Type</templarg>
    <templarg>unsigned int N</templarg>
    <member kind="function">
      <type>POLYFLOAT_FORCEINLINE auto &amp;</type>
      <name>operator++</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>af55555f5460ba07834bc36ee420af703</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>POLYFLOAT_FORCEINLINE auto</type>
      <name>operator++</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a2c0f3d208e07f80944037205d8641287</anchor>
      <arglist>(int) noexcept</arglist>
    </member>
    <member kind="function">
      <type>POLYFLOAT_FORCEINLINE auto &amp;</type>
      <name>operator--</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a983c41907f96d5b39ba67d1bbd937dec</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>POLYFLOAT_FORCEINLINE auto</type>
      <name>operator--</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>aaae393ce36971865a3cfd8da9e5216cb</anchor>
      <arglist>(int) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr polyfloat &amp;</type>
      <name>operator=</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a4f0c0eccaaaa165c4d7e889912fe4214</anchor>
      <arglist>(T const &amp;a) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr</type>
      <name>polyfloat</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a5c166e3458fabf448a2b10c43725a3bb</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr</type>
      <name>polyfloat</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>aeb2f8de40a9c426bbf0b1427b6223821</anchor>
      <arglist>(eve::sized_product_type&lt; N &gt; auto const &amp;vs)</arglist>
    </member>
    <member kind="function">
      <type>constexpr</type>
      <name>polyfloat</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a1d09ab160ac18d2406ef85f99c06febf</anchor>
      <arglist>(polyfloat&lt; Type, M &gt; const &amp;a) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr</type>
      <name>polyfloat</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a6b08a160d470da14cb201f61404b0a9b</anchor>
      <arglist>(T v) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr</type>
      <name>polyfloat</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a93d98a333193dec59b5a3aaffa6dc4f6</anchor>
      <arglist>(T0 v0, T1 v1) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr</type>
      <name>polyfloat</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>af550d771b0aae725115d9d62841b41f1</anchor>
      <arglist>(T0 v0, T1 v1, T2 v2) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr</type>
      <name>polyfloat</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a9daf3b86eca68c8191af6022d577d99e</anchor>
      <arglist>(Type v) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto &amp;</type>
      <name>operator+=</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a17a30537c795078304e6f7510f0c4731</anchor>
      <arglist>(T1 &amp;self, T2 other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto &amp;</type>
      <name>operator-=</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>aef49920793b4da92e687b8d178be4835</anchor>
      <arglist>(T1 &amp;self, T2 other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto &amp;</type>
      <name>operator*=</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a58e25f46704ea034002c861386db069c</anchor>
      <arglist>(T1 &amp;self, T2 other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>auto &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a1d50add5f2f5370f64b20919751ccdcf</anchor>
      <arglist>(std::basic_ostream&lt; C, Ct &gt; &amp;os, CD const &amp;z)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator+</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a18cec006320794126c85b238a68fc91c</anchor>
      <arglist>(Z const &amp;z) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator-</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a3032325260646fe3f0832b076a2b146a</anchor>
      <arglist>(Z const &amp;z) noexcept</arglist>
    </member>
    <member kind="function">
      <type>as_polyfloat_t&lt; T1, T2 &gt;</type>
      <name>operator+</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a8dc21090f71e4797c23d3d4239557026</anchor>
      <arglist>(T1 const &amp;a, T2 const &amp;b) noexcept</arglist>
    </member>
    <member kind="function">
      <type>as_polyfloat_t&lt; T1, T2 &gt;</type>
      <name>operator-</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a665bbd4d727132496baa7e4a19e00ba5</anchor>
      <arglist>(T1 const &amp;a, T2 const &amp;b) noexcept</arglist>
    </member>
    <member kind="function">
      <type>as_polyfloat_t&lt; T1, T2 &gt;</type>
      <name>operator*</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>ac8720871310050866ed9dbef62bc4908</anchor>
      <arglist>(T1 const &amp;a, T2 const &amp;b) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator==</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a561363de989d2101775d8b85655ea08e</anchor>
      <arglist>(T1 const &amp;a, T2 b)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator!=</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>ac345e6a953c0ec69ee85d43be131c6c6</anchor>
      <arglist>(T1 const &amp;a, T2 b)</arglist>
    </member>
    <member kind="function">
      <type>as_polyfloat_t&lt; T1, T2 &gt;</type>
      <name>operator/</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a99e34a798da1443432b03f9e5e6f9b6e</anchor>
      <arglist>(T1 const &amp;a, T2 const &amp;b) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>polyfloat</name>
      <anchorfile>structplf_1_1polyfloat_a5bc8d3714e201b591e64a8901fdeb667.html</anchorfile>
      <anchor>a5bc8d3714e201b591e64a8901fdeb667</anchor>
      <arglist>(T0) -&gt; polyfloat&lt; T0, 2u &gt;</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>polyfloat</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>acb02165730e7ed765fdde7603c186597</anchor>
      <arglist>(T0, Ts...) -&gt; polyfloat&lt; T0, 1+sizeof...(Ts)&gt;</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto &amp;</type>
      <name>operator+=</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a17a30537c795078304e6f7510f0c4731</anchor>
      <arglist>(T1 &amp;self, T2 other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto &amp;</type>
      <name>operator-=</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>aef49920793b4da92e687b8d178be4835</anchor>
      <arglist>(T1 &amp;self, T2 other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto &amp;</type>
      <name>operator*=</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a58e25f46704ea034002c861386db069c</anchor>
      <arglist>(T1 &amp;self, T2 other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>auto &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a1d50add5f2f5370f64b20919751ccdcf</anchor>
      <arglist>(std::basic_ostream&lt; C, Ct &gt; &amp;os, CD const &amp;z)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator+</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a18cec006320794126c85b238a68fc91c</anchor>
      <arglist>(Z const &amp;z) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator-</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a3032325260646fe3f0832b076a2b146a</anchor>
      <arglist>(Z const &amp;z) noexcept</arglist>
    </member>
    <member kind="function">
      <type>as_polyfloat_t&lt; T1, T2 &gt;</type>
      <name>operator+</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a8dc21090f71e4797c23d3d4239557026</anchor>
      <arglist>(T1 const &amp;a, T2 const &amp;b) noexcept</arglist>
    </member>
    <member kind="function">
      <type>as_polyfloat_t&lt; T1, T2 &gt;</type>
      <name>operator-</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a665bbd4d727132496baa7e4a19e00ba5</anchor>
      <arglist>(T1 const &amp;a, T2 const &amp;b) noexcept</arglist>
    </member>
    <member kind="function">
      <type>as_polyfloat_t&lt; T1, T2 &gt;</type>
      <name>operator*</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>ac8720871310050866ed9dbef62bc4908</anchor>
      <arglist>(T1 const &amp;a, T2 const &amp;b) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator==</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a561363de989d2101775d8b85655ea08e</anchor>
      <arglist>(T1 const &amp;a, T2 b)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator!=</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>ac345e6a953c0ec69ee85d43be131c6c6</anchor>
      <arglist>(T1 const &amp;a, T2 b)</arglist>
    </member>
    <member kind="function">
      <type>as_polyfloat_t&lt; T1, T2 &gt;</type>
      <name>operator/</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a99e34a798da1443432b03f9e5e6f9b6e</anchor>
      <arglist>(T1 const &amp;a, T2 const &amp;b) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>polyfloat</name>
      <anchorfile>structplf_1_1polyfloat_a5bc8d3714e201b591e64a8901fdeb667.html</anchorfile>
      <anchor>a5bc8d3714e201b591e64a8901fdeb667</anchor>
      <arglist>(T0) -&gt; polyfloat&lt; T0, 2u &gt;</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>polyfloat</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>acb02165730e7ed765fdde7603c186597</anchor>
      <arglist>(T0, Ts...) -&gt; polyfloat&lt; T0, 1+sizeof...(Ts)&gt;</arglist>
    </member>
  </compound>
  <compound kind="concept">
    <name>plf::concepts::doublereal_like</name>
    <filename>conceptplf_1_1concepts_1_1doublereal__like.html</filename>
  </compound>
  <compound kind="concept">
    <name>plf::concepts::polyfloat</name>
    <filename>conceptplf_1_1concepts_1_1polyfloat.html</filename>
  </compound>
  <compound kind="concept">
    <name>plf::concepts::polyfloat_like</name>
    <filename>conceptplf_1_1concepts_1_1polyfloat__like.html</filename>
  </compound>
  <compound kind="concept">
    <name>plf::concepts::real</name>
    <filename>conceptplf_1_1concepts_1_1real.html</filename>
  </compound>
  <compound kind="concept">
    <name>plf::concepts::scalar_polyfloat</name>
    <filename>conceptplf_1_1concepts_1_1scalar__polyfloat.html</filename>
  </compound>
  <compound kind="concept">
    <name>plf::concepts::scalar_real</name>
    <filename>conceptplf_1_1concepts_1_1scalar__real.html</filename>
  </compound>
  <compound kind="concept">
    <name>plf::concepts::triplereal_like</name>
    <filename>conceptplf_1_1concepts_1_1triplereal__like.html</filename>
  </compound>
  <compound kind="namespace">
    <name>plf</name>
    <filename>namespaceplf.html</filename>
    <class kind="struct">plf::as_component</class>
    <class kind="struct">plf::as_polyfloat_like</class>
    <class kind="class">plf::polyfloat</class>
    <member kind="typedef">
      <type>typename as_component_type&lt; T &gt;::type</type>
      <name>as_component_type_t</name>
      <anchorfile>group__traits_gaa325dcaa3d30c3a89c5333b2800aac54.html</anchorfile>
      <anchor>gaa325dcaa3d30c3a89c5333b2800aac54</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename as_polyfloat_n&lt; Dim, Ts... &gt;::type</type>
      <name>as_polyfloat_n_t</name>
      <anchorfile>group__traits_gaa65fa3ada94ae1d661001889062623b4.html</anchorfile>
      <anchor>gaa65fa3ada94ae1d661001889062623b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename as_polyfloat&lt; Ts... &gt;::type</type>
      <name>as_polyfloat_t</name>
      <anchorfile>group__traits_gabb544245c689b7e0ea2f9f6e8feb8594.html</anchorfile>
      <anchor>gabb544245c689b7e0ea2f9f6e8feb8594</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>as_polyfloat_n_t&lt; 2, T &gt;</type>
      <name>double_real_t</name>
      <anchorfile>group__types_gad8203f72c65a6761f03db03f8ac55c61.html</anchorfile>
      <anchor>gad8203f72c65a6761f03db03f8ac55c61</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>as_polyfloat_n_t&lt; 3, T &gt;</type>
      <name>triple_real_t</name>
      <anchorfile>group__types_ga3150408863a87ad5a78978ea1eebf102.html</anchorfile>
      <anchor>ga3150408863a87ad5a78978ea1eebf102</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>constexpr auto &amp;</type>
      <name>operator/=</name>
      <anchorfile>namespaceplf.html</anchorfile>
      <anchor>a0d9579fedf83ffc6e9e39706329882dd</anchor>
      <arglist>(T1 &amp;self, T2 other) noexcept</arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>abs</name>
      <anchorfile>group__core_ga69b3078b6a64e0467e0595929ca947de.html</anchorfile>
      <anchor>ga69b3078b6a64e0467e0595929ca947de</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>absmax</name>
      <anchorfile>group__core_gadd0f5df2e8971e69dd54e2b9921d04a6.html</anchorfile>
      <anchor>gadd0f5df2e8971e69dd54e2b9921d04a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>absmin</name>
      <anchorfile>group__core_ga6b9323d57f26ce1cd555444d9b64c807.html</anchorfile>
      <anchor>ga6b9323d57f26ce1cd555444d9b64c807</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>add</name>
      <anchorfile>group__core_ga4d1ed930ff0fa7d990dddb01882515e6.html</anchorfile>
      <anchor>ga4d1ed930ff0fa7d990dddb01882515e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>agm</name>
      <anchorfile>group__core_gaaf79a031e1bb735e16389b0a19a2f3d7.html</anchorfile>
      <anchor>gaaf79a031e1bb735e16389b0a19a2f3d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>allbits</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>gabbd6cfcd83668ca5f081bcc515d75a59</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>average</name>
      <anchorfile>group__core_gad514388c4bd4fe58d50e53e426d62140.html</anchorfile>
      <anchor>gad514388c4bd4fe58d50e53e426d62140</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>bitincrement</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga8fa056d215485ffdb11c9e151f307df0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>cbrt</name>
      <anchorfile>group__core_gaa0cc19fbc27cb06fc0f81bb87148fd2b.html</anchorfile>
      <anchor>gaa0cc19fbc27cb06fc0f81bb87148fd2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>ceil</name>
      <anchorfile>group__core_gacf4cc27cc53a0faf471c2610eab95e8c.html</anchorfile>
      <anchor>gacf4cc27cc53a0faf471c2610eab95e8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>chi</name>
      <anchorfile>group__core_ga352e6ca52f4beeae5effd0cdf7325247.html</anchorfile>
      <anchor>ga352e6ca52f4beeae5effd0cdf7325247</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>clamp</name>
      <anchorfile>group__core_gaf3b6e14fd2890b610b24438a70b5ba87.html</anchorfile>
      <anchor>gaf3b6e14fd2890b610b24438a70b5ba87</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>convert</name>
      <anchorfile>group__core_ga3596810b24bfc8fb774e184cf3c2787e.html</anchorfile>
      <anchor>ga3596810b24bfc8fb774e184cf3c2787e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>copysign</name>
      <anchorfile>group__core_gae88e21eb3751b1d0fd7b71d288d9d1ee.html</anchorfile>
      <anchor>gae88e21eb3751b1d0fd7b71d288d9d1ee</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>cosh</name>
      <anchorfile>group__core_ga9c6115c7b57ba527694f481843d1edac.html</anchorfile>
      <anchor>ga9c6115c7b57ba527694f481843d1edac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>cosine_similarity</name>
      <anchorfile>group__core_gae9bf65899aaf52f81e706494a42c99d3.html</anchorfile>
      <anchor>gae9bf65899aaf52f81e706494a42c99d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>covariance</name>
      <anchorfile>group__core_ga849d694549afbbd8308f3509f7e2c780.html</anchorfile>
      <anchor>ga849d694549afbbd8308f3509f7e2c780</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>cumfun</name>
      <anchorfile>group__core_gad9ed275f6b6e77db5325c3893e933ef6.html</anchorfile>
      <anchor>gad9ed275f6b6e77db5325c3893e933ef6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>cumprod</name>
      <anchorfile>group__core_gaead0ce36438cf8108b2bf0997ff6e4f8.html</anchorfile>
      <anchor>gaead0ce36438cf8108b2bf0997ff6e4f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>cumsum</name>
      <anchorfile>group__core_ga431cf7d6555dc450704863dd522499b6.html</anchorfile>
      <anchor>ga431cf7d6555dc450704863dd522499b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>dec</name>
      <anchorfile>group__core_ga21dc299efb61f8ae4924e3fb0b953f7c.html</anchorfile>
      <anchor>ga21dc299efb61f8ae4924e3fb0b953f7c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>dekker_prod</name>
      <anchorfile>group__core__accuracy_ga1a41dc23e01e636ab69b39a3238a893f.html</anchorfile>
      <anchor>ga1a41dc23e01e636ab69b39a3238a893f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>diff</name>
      <anchorfile>group__core_ga197b906315ce84f0c78181a9314c0988.html</anchorfile>
      <anchor>ga197b906315ce84f0c78181a9314c0988</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr unsigned int</type>
      <name>dimension_v</name>
      <anchorfile>group__traits_ga846021636ff96cc73a58d2f664e7ce1f.html</anchorfile>
      <anchor>ga846021636ff96cc73a58d2f664e7ce1f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>dist</name>
      <anchorfile>group__core_ga31aaafd7f21c599693e7a2fd6533e315.html</anchorfile>
      <anchor>ga31aaafd7f21c599693e7a2fd6533e315</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>div</name>
      <anchorfile>group__core_gad96f947d70b23427a0305b9998aad337.html</anchorfile>
      <anchor>gad96f947d70b23427a0305b9998aad337</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>dot</name>
      <anchorfile>group__core_gaf5ce77de394a85c44e05c7f96215fc27.html</anchorfile>
      <anchor>gaf5ce77de394a85c44e05c7f96215fc27</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>effective_mantissa_bits</name>
      <anchorfile>group__constants_gac4277864eeceb38de7a3e18e4f329337.html</anchorfile>
      <anchor>gac4277864eeceb38de7a3e18e4f329337</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>eps</name>
      <anchorfile>group__constants_gacd69b768b1e3278712c5dd2b3cd7b58c.html</anchorfile>
      <anchor>gacd69b768b1e3278712c5dd2b3cd7b58c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>epsilon</name>
      <anchorfile>group__core_gac68d4fa443f186a4893bda40bdadcd39.html</anchorfile>
      <anchor>gac68d4fa443f186a4893bda40bdadcd39</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>euler</name>
      <anchorfile>group__constants_ga307c6361163f5ebe3b6a3c7ca0472da8.html</anchorfile>
      <anchor>ga307c6361163f5ebe3b6a3c7ca0472da8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>exp</name>
      <anchorfile>group__core_gab8e08b05daa3ee86e2ed652a07352d64.html</anchorfile>
      <anchor>gab8e08b05daa3ee86e2ed652a07352d64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>exp2</name>
      <anchorfile>group__core_gaec8099077dd346085e88919e08513d84.html</anchorfile>
      <anchor>gaec8099077dd346085e88919e08513d84</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>expm1</name>
      <anchorfile>group__core_ga6b355641ddbdb7ec0d1daa0bcf7be425.html</anchorfile>
      <anchor>ga6b355641ddbdb7ec0d1daa0bcf7be425</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>exponent</name>
      <anchorfile>group__core__internal_ga60713c93ccdf574a916e2c96eede7018.html</anchorfile>
      <anchor>ga60713c93ccdf574a916e2c96eede7018</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>fam</name>
      <anchorfile>group__core_ga901d4b061ed59463f25ab684e7707f35.html</anchorfile>
      <anchor>ga901d4b061ed59463f25ab684e7707f35</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>floor</name>
      <anchorfile>group__core_gabaa3043614b3644380404814e6718a87.html</anchorfile>
      <anchor>gabaa3043614b3644380404814e6718a87</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>fma</name>
      <anchorfile>group__core_gafe2539e930df632442830952eafe983f.html</anchorfile>
      <anchor>gafe2539e930df632442830952eafe983f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>fmod</name>
      <anchorfile>group__core_ga1e5b90cb087d254f8741482c0e894594.html</anchorfile>
      <anchor>ga1e5b90cb087d254f8741482c0e894594</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>fms</name>
      <anchorfile>group__core_ga528f7b968ee1663dd96dcbf976e96491.html</anchorfile>
      <anchor>ga528f7b968ee1663dd96dcbf976e96491</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>fnma</name>
      <anchorfile>group__core_ga5b4600c48a905e3808b32a9441a6d19d.html</anchorfile>
      <anchor>ga5b4600c48a905e3808b32a9441a6d19d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>fnms</name>
      <anchorfile>group__core_ga820c60b72b131ea41f424290e4777842.html</anchorfile>
      <anchor>ga820c60b72b131ea41f424290e4777842</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>frac</name>
      <anchorfile>group__core_ga6cbff9063806f25141fbe0f5863becae.html</anchorfile>
      <anchor>ga6cbff9063806f25141fbe0f5863becae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>frexp</name>
      <anchorfile>group__core_ga89334551f0d0c2f81bf852d2a0b9f502.html</anchorfile>
      <anchor>ga89334551f0d0c2f81bf852d2a0b9f502</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>fsm</name>
      <anchorfile>group__core_gab6ffa7b2b7b589bc9bbf790c8555e7f3.html</anchorfile>
      <anchor>gab6ffa7b2b7b589bc9bbf790c8555e7f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>half</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>gafdc7f58bede6debd2ef66a4b3521cb84</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>heaviside</name>
      <anchorfile>group__core_gaacc157e51d44695e50b1e1af7643abc0.html</anchorfile>
      <anchor>gaacc157e51d44695e50b1e1af7643abc0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>hi</name>
      <anchorfile>group__core_ga85fa850c93bf943fe9e434de3552293d.html</anchorfile>
      <anchor>ga85fa850c93bf943fe9e434de3552293d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>horner</name>
      <anchorfile>group__functions_gae998e94f32f326d4c67342e2ceb35982.html</anchorfile>
      <anchor>gae998e94f32f326d4c67342e2ceb35982</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>hypot</name>
      <anchorfile>group__core_gab1d383e91204c25060d9e6f3f68fac0b.html</anchorfile>
      <anchor>gab1d383e91204c25060d9e6f3f68fac0b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>if_else</name>
      <anchorfile>group__core_gafb741bdffc03f40d05b112ff6c893e7c.html</anchorfile>
      <anchor>gafb741bdffc03f40d05b112ff6c893e7c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>inc</name>
      <anchorfile>group__core_gad3d7ea17362a2244fb6ec0ca2d5a78e5.html</anchorfile>
      <anchor>gad3d7ea17362a2244fb6ec0ca2d5a78e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>inf</name>
      <anchorfile>group__constants_ga17a6561e33fcb9f3bf0be566ca5751f7.html</anchorfile>
      <anchor>ga17a6561e33fcb9f3bf0be566ca5751f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>inveps</name>
      <anchorfile>group__constants_gae1bef0c184e2dead4007764d4e821835.html</anchorfile>
      <anchor>gae1bef0c184e2dead4007764d4e821835</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>invlog_10</name>
      <anchorfile>group__constants_gae5ba2e8a8ea4d88c2799dcdf8424f574.html</anchorfile>
      <anchor>gae5ba2e8a8ea4d88c2799dcdf8424f574</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>invlog_2</name>
      <anchorfile>group__constants_ga558ed10477a5c340a720e2ea3866327c.html</anchorfile>
      <anchor>ga558ed10477a5c340a720e2ea3866327c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_bit_equal</name>
      <anchorfile>group__core_ga15e2026fc3252509ad69742f7daf0682.html</anchorfile>
      <anchor>ga15e2026fc3252509ad69742f7daf0682</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_denormal</name>
      <anchorfile>group__core_ga3b8438957e33ee0ee5b3ab2508aa72ac.html</anchorfile>
      <anchor>ga3b8438957e33ee0ee5b3ab2508aa72ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_eqmz</name>
      <anchorfile>group__core_ga1a258750e54fc736597fa9439bea340f.html</anchorfile>
      <anchor>ga1a258750e54fc736597fa9439bea340f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_eqpz</name>
      <anchorfile>group__core_ga1d3c7d7b9441ebc3115872893b1f35a7.html</anchorfile>
      <anchor>ga1d3c7d7b9441ebc3115872893b1f35a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_equal</name>
      <anchorfile>group__core_gaa3f884f1bd114c09949fb5d4e1af9876.html</anchorfile>
      <anchor>gaa3f884f1bd114c09949fb5d4e1af9876</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_eqz</name>
      <anchorfile>group__core_ga4d8c8308d3b4bba663bb237a195b27a6.html</anchorfile>
      <anchor>ga4d8c8308d3b4bba663bb237a195b27a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_even</name>
      <anchorfile>group__core_gabfa4b5248f0e3f16859f471e7445a0ec.html</anchorfile>
      <anchor>gabfa4b5248f0e3f16859f471e7445a0ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_finite</name>
      <anchorfile>group__core_ga51a63988bfb6162220cd95bcf37af748.html</anchorfile>
      <anchor>ga51a63988bfb6162220cd95bcf37af748</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_flint</name>
      <anchorfile>group__core_ga72a296047ea9f24dc1438e3a1161e58b.html</anchorfile>
      <anchor>ga72a296047ea9f24dc1438e3a1161e58b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_greater</name>
      <anchorfile>group__core_ga1a413faf72a8ca404c5445c18660b038.html</anchorfile>
      <anchor>ga1a413faf72a8ca404c5445c18660b038</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_greater_equal</name>
      <anchorfile>group__core_ga97645462f4430d66d0da2a93a1b2f37d.html</anchorfile>
      <anchor>ga97645462f4430d66d0da2a93a1b2f37d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_gtz</name>
      <anchorfile>group__core_gabd560b7b077896323ee38940ef5a3583.html</anchorfile>
      <anchor>gabd560b7b077896323ee38940ef5a3583</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_infinite</name>
      <anchorfile>group__core_gae4511a6a87e546c2fa45b2483a26cbd2.html</anchorfile>
      <anchor>gae4511a6a87e546c2fa45b2483a26cbd2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_less</name>
      <anchorfile>group__core_gaeb3a722d8086ab0090707c53e2058c3d.html</anchorfile>
      <anchor>gaeb3a722d8086ab0090707c53e2058c3d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_less_equal</name>
      <anchorfile>group__core_ga288303686db135dde311d78d6ebcc103.html</anchorfile>
      <anchor>ga288303686db135dde311d78d6ebcc103</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_lessgreater</name>
      <anchorfile>group__core_ga93c70fd4967b9569ea28724a993369be.html</anchorfile>
      <anchor>ga93c70fd4967b9569ea28724a993369be</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_lez</name>
      <anchorfile>group__core_gad212f44157bf7a494a02cdc8e2cb01b4.html</anchorfile>
      <anchor>gad212f44157bf7a494a02cdc8e2cb01b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_ltz</name>
      <anchorfile>group__core_ga62ddb7af573f49058eba0f222072310a.html</anchorfile>
      <anchor>ga62ddb7af573f49058eba0f222072310a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_minf</name>
      <anchorfile>group__core_gab77d212b376f19f9172c3741d6b2df35.html</anchorfile>
      <anchor>gab77d212b376f19f9172c3741d6b2df35</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_nan</name>
      <anchorfile>group__core_ga1db11a0b9a18822ffe41043c38cc80c3.html</anchorfile>
      <anchor>ga1db11a0b9a18822ffe41043c38cc80c3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_negative</name>
      <anchorfile>group__core_ga5b1a93ce270f1b01560e0007b998ea73.html</anchorfile>
      <anchor>ga5b1a93ce270f1b01560e0007b998ea73</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_nemz</name>
      <anchorfile>group__core_gab196817aaa41a88c58ed791c715b0350.html</anchorfile>
      <anchor>gab196817aaa41a88c58ed791c715b0350</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_nepz</name>
      <anchorfile>group__core_ga588f3519dcd992829d6060db0b2dd0b6.html</anchorfile>
      <anchor>ga588f3519dcd992829d6060db0b2dd0b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_nez</name>
      <anchorfile>group__core_ga1e4d7cd895471d034bfab1d93130be54.html</anchorfile>
      <anchor>ga1e4d7cd895471d034bfab1d93130be54</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_ngez</name>
      <anchorfile>group__core_ga4299f6d8bf5e48900d92af1371735d2f.html</anchorfile>
      <anchor>ga4299f6d8bf5e48900d92af1371735d2f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_ngtz</name>
      <anchorfile>group__core_ga1012d9d76ecb23bf85402fea5b7719ae.html</anchorfile>
      <anchor>ga1012d9d76ecb23bf85402fea5b7719ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_nlez</name>
      <anchorfile>group__core_ga78f7c97500b38f86a7a63242368aae2c.html</anchorfile>
      <anchor>ga78f7c97500b38f86a7a63242368aae2c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_nltz</name>
      <anchorfile>group__core_gae2a0761ccbc5a9fe472f2f5c14a8fcd9.html</anchorfile>
      <anchor>gae2a0761ccbc5a9fe472f2f5c14a8fcd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_denormal</name>
      <anchorfile>group__core_ga315ab6ec01496d96b325d266be09767f.html</anchorfile>
      <anchor>ga315ab6ec01496d96b325d266be09767f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_equal</name>
      <anchorfile>group__core_gaed9f3b4229041da1ac2a2070db903277.html</anchorfile>
      <anchor>gaed9f3b4229041da1ac2a2070db903277</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_finite</name>
      <anchorfile>group__core_ga63749142d53ad0d040659d8d4cffee74.html</anchorfile>
      <anchor>ga63749142d53ad0d040659d8d4cffee74</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_flint</name>
      <anchorfile>group__core_ga42ae7e20907bd55debe6262ff5ea78f9.html</anchorfile>
      <anchor>ga42ae7e20907bd55debe6262ff5ea78f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_greater</name>
      <anchorfile>group__core_ga2717687d1b7470024cd67a978c7b42b3.html</anchorfile>
      <anchor>ga2717687d1b7470024cd67a978c7b42b3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_greater_equal</name>
      <anchorfile>group__core_gabe0e10750aea5fdf460f4c56f46d84c9.html</anchorfile>
      <anchor>gabe0e10750aea5fdf460f4c56f46d84c9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_infinite</name>
      <anchorfile>group__core_gad3cf2c8f13b83ffed9f1b2924a8a8529.html</anchorfile>
      <anchor>gad3cf2c8f13b83ffed9f1b2924a8a8529</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_less</name>
      <anchorfile>group__core_gacad2e09ee75c713a87065f75a2a18c64.html</anchorfile>
      <anchor>gacad2e09ee75c713a87065f75a2a18c64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_less_equal</name>
      <anchorfile>group__core_gac10cc53f0009c90aa0a206f346e21cee.html</anchorfile>
      <anchor>gac10cc53f0009c90aa0a206f346e21cee</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_nan</name>
      <anchorfile>group__core_ga64a07f1dd60b6e1409442078cc039a42.html</anchorfile>
      <anchor>ga64a07f1dd60b6e1409442078cc039a42</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_odd</name>
      <anchorfile>group__core_ga455e06a0df2a0068637f251becfbb944.html</anchorfile>
      <anchor>ga455e06a0df2a0068637f251becfbb944</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_ordered</name>
      <anchorfile>group__core_ga7c90ae517c18bab6325f49cce61f4edf.html</anchorfile>
      <anchor>ga7c90ae517c18bab6325f49cce61f4edf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_pinf</name>
      <anchorfile>group__core_gaff62e2a7284c69e0b8c388e70ad2e066.html</anchorfile>
      <anchor>gaff62e2a7284c69e0b8c388e70ad2e066</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_positive</name>
      <anchorfile>group__core_ga382498c379928168e37005f38a9b8eaf.html</anchorfile>
      <anchor>ga382498c379928168e37005f38a9b8eaf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_pow2</name>
      <anchorfile>group__core_gaf77de37071bc9885bab1dc8d8bb235b0.html</anchorfile>
      <anchor>gaf77de37071bc9885bab1dc8d8bb235b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_unit</name>
      <anchorfile>group__core_gae00ac1ff95cdeca72e526d70cc419e51.html</anchorfile>
      <anchor>gae00ac1ff95cdeca72e526d70cc419e51</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_unordered</name>
      <anchorfile>group__core_ga46fff13f9c73cf8cdbe1ed78f4083f65.html</anchorfile>
      <anchor>ga46fff13f9c73cf8cdbe1ed78f4083f65</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>ldexp</name>
      <anchorfile>group__core_gaaafb5f51797ebd81c0fdc1011e0275a3.html</anchorfile>
      <anchor>gaaafb5f51797ebd81c0fdc1011e0275a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>lerp</name>
      <anchorfile>group__core_ga8875d0b61cf3fbeeaa6ed18b29e5ca9f.html</anchorfile>
      <anchor>ga8875d0b61cf3fbeeaa6ed18b29e5ca9f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>lo</name>
      <anchorfile>group__core_ga986719f5a39d352e01286ab52b9a54ff.html</anchorfile>
      <anchor>ga986719f5a39d352e01286ab52b9a54ff</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>log</name>
      <anchorfile>group__core_ga39d37d0f777a93ba32640c56565e2710.html</anchorfile>
      <anchor>ga39d37d0f777a93ba32640c56565e2710</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>log10</name>
      <anchorfile>group__core_gaae901ccc06c7a5efa0242e5fcd654bd4.html</anchorfile>
      <anchor>gaae901ccc06c7a5efa0242e5fcd654bd4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>log2</name>
      <anchorfile>group__core_ga74fe53ba9509c1894684a4fe92865d07.html</anchorfile>
      <anchor>ga74fe53ba9509c1894684a4fe92865d07</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>log_2</name>
      <anchorfile>group__constants_gab076b85673ceedd01180cae08b3b984e.html</anchorfile>
      <anchor>gab076b85673ceedd01180cae08b3b984e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>logeps</name>
      <anchorfile>group__constants_gad27792bcc40b8ac1693bacbd95570d68.html</anchorfile>
      <anchor>gad27792bcc40b8ac1693bacbd95570d68</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>mantissa</name>
      <anchorfile>group__core_ga592c5eb0fdeb82b41dd07a2ddc48dd6e.html</anchorfile>
      <anchor>ga592c5eb0fdeb82b41dd07a2ddc48dd6e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>max</name>
      <anchorfile>group__core_ga1d6b7e84a59f51f3fdeab89704ce3bb1.html</anchorfile>
      <anchor>ga1d6b7e84a59f51f3fdeab89704ce3bb1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>maxabs</name>
      <anchorfile>group__core_ga943ef8abb2c09066d89722a3ea69c78c.html</anchorfile>
      <anchor>ga943ef8abb2c09066d89722a3ea69c78c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>maxflint</name>
      <anchorfile>group__constants_gae321346f90402e1b5dc7875054e49a83.html</anchorfile>
      <anchor>gae321346f90402e1b5dc7875054e49a83</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>maxlog</name>
      <anchorfile>group__constants_gaa7847ac49cf7e5db7ff5ecdd7edd9268.html</anchorfile>
      <anchor>gaa7847ac49cf7e5db7ff5ecdd7edd9268</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>maxmag</name>
      <anchorfile>group__core_gaee2e0eb2ad65678b921da8c2b4de631e.html</anchorfile>
      <anchor>gaee2e0eb2ad65678b921da8c2b4de631e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>md</name>
      <anchorfile>group__core_ga0745f202e4af71621d3f5e84e37c6abe.html</anchorfile>
      <anchor>ga0745f202e4af71621d3f5e84e37c6abe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>mhalf</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>gacf3b52a44982c70d2b2b7a11531beee3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>min</name>
      <anchorfile>group__core_gaf2ecab0082e8fa1007d5ea49c9fa1a87.html</anchorfile>
      <anchor>gaf2ecab0082e8fa1007d5ea49c9fa1a87</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>minabs</name>
      <anchorfile>group__core_gaa190c10bef44628e4701ff2fcd6728a0.html</anchorfile>
      <anchor>gaa190c10bef44628e4701ff2fcd6728a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>mindenormal</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga0a3e5881bfb4a0de7977621996c339a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>minexponent</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga4647ba96a04ee2f05047b93c70509bd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>minf</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga53eeee70008790007d0da7e69ad152e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>minmag</name>
      <anchorfile>group__core_ga3edebc887d62d202367258c76f7a1a7f.html</anchorfile>
      <anchor>ga3edebc887d62d202367258c76f7a1a7f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>minmax</name>
      <anchorfile>group__core_ga830c684d59f4722059bef14bb7f92da2.html</anchorfile>
      <anchor>ga830c684d59f4722059bef14bb7f92da2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>minus</name>
      <anchorfile>group__core_gae33d4d1bd5488f7aed156cd106f4ce74.html</anchorfile>
      <anchor>gae33d4d1bd5488f7aed156cd106f4ce74</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>modf</name>
      <anchorfile>group__core_gaf07ed2a608fc290c474c9baaa296fc76.html</anchorfile>
      <anchor>gaf07ed2a608fc290c474c9baaa296fc76</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>mone</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>gafd51d660d060685287a61ceb9a0619c5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>mul</name>
      <anchorfile>group__core_ga856a221cd309873711b978ce55df4635.html</anchorfile>
      <anchor>ga856a221cd309873711b978ce55df4635</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>mzero</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga889a98f4b2269954d9c5326e07ffdd9f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>nan</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>gab815a9e20ea8d0c215108a23413f0347</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>nbmantissabits</name>
      <anchorfile>group__constants_ga353f26b1179c82267a8066987951a553.html</anchorfile>
      <anchor>ga353f26b1179c82267a8066987951a553</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>nearest</name>
      <anchorfile>group__core_ga1c1e5e03fa7f21ea1a74311813762197.html</anchorfile>
      <anchor>ga1c1e5e03fa7f21ea1a74311813762197</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>negabsmax</name>
      <anchorfile>group__core_ga54e69f527759113beefec446c9c8f7de.html</anchorfile>
      <anchor>ga54e69f527759113beefec446c9c8f7de</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>negabsmin</name>
      <anchorfile>group__core_ga519b13d3f054b319b6ef5e59eb029a47.html</anchorfile>
      <anchor>ga519b13d3f054b319b6ef5e59eb029a47</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>negate</name>
      <anchorfile>group__core_ga0b77fce5aa260a3629bed972eee3ba39.html</anchorfile>
      <anchor>ga0b77fce5aa260a3629bed972eee3ba39</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>negatenz</name>
      <anchorfile>group__core_gacb0784fa93d2122cec99faf7a9760daa.html</anchorfile>
      <anchor>gacb0784fa93d2122cec99faf7a9760daa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>negmaxabs</name>
      <anchorfile>group__core_ga0ddb4ae3b0954209eca0c7257d166dbc.html</anchorfile>
      <anchor>ga0ddb4ae3b0954209eca0c7257d166dbc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>negminabs</name>
      <anchorfile>group__core_gace9b23e8f34fdc09478d8901078f1bb6.html</anchorfile>
      <anchor>gace9b23e8f34fdc09478d8901078f1bb6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>next</name>
      <anchorfile>group__core_ga60c7f280243a468485f42421a2c06739.html</anchorfile>
      <anchor>ga60c7f280243a468485f42421a2c06739</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>nextafter</name>
      <anchorfile>group__core_ga09f396a43b0cf65385e8a586a2b410e9.html</anchorfile>
      <anchor>ga09f396a43b0cf65385e8a586a2b410e9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>nextint</name>
      <anchorfile>group__core_gaf1c232d7bc7f81fc1a42edb3c7b7cd88.html</anchorfile>
      <anchor>gaf1c232d7bc7f81fc1a42edb3c7b7cd88</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>nthroot</name>
      <anchorfile>group__core_ga51f47a92f62d391bf10c55c304a691da.html</anchorfile>
      <anchor>ga51f47a92f62d391bf10c55c304a691da</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>one</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>gaf4a21d2a045aedd47efa31fcc8be1fcf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>oneminus</name>
      <anchorfile>group__core_gaffe46da86ea6a171bb1de5203b24334a.html</anchorfile>
      <anchor>gaffe46da86ea6a171bb1de5203b24334a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>oneosqrteps</name>
      <anchorfile>group__constants_gaf37d435e94d94585ba4b0848c520316b.html</anchorfile>
      <anchor>gaf37d435e94d94585ba4b0848c520316b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>pown</name>
      <anchorfile>group__core_ga3309e6018e6235033a2877c0d9eece8c.html</anchorfile>
      <anchor>ga3309e6018e6235033a2877c0d9eece8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>prev</name>
      <anchorfile>group__core_ga3e945bcc637ae4a744f512275949fe82.html</anchorfile>
      <anchor>ga3e945bcc637ae4a744f512275949fe82</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>prevint</name>
      <anchorfile>group__core_ga4bf8537407a460e745d9df6f37fac5f7.html</anchorfile>
      <anchor>ga4bf8537407a460e745d9df6f37fac5f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>rat</name>
      <anchorfile>group__core_gae7854c4bf7224d75816c16d3141b868c.html</anchorfile>
      <anchor>gae7854c4bf7224d75816c16d3141b868c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>rec</name>
      <anchorfile>group__core_ga38ee18ae42971becb7275f6596ada180.html</anchorfile>
      <anchor>ga38ee18ae42971becb7275f6596ada180</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>reldist</name>
      <anchorfile>group__core_ga46f13916d7af01b5f6c1f880d13e2ed4.html</anchorfile>
      <anchor>ga46f13916d7af01b5f6c1f880d13e2ed4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>rem</name>
      <anchorfile>group__core_gaba27d496c09e7ef0892b23806956a840.html</anchorfile>
      <anchor>gaba27d496c09e7ef0892b23806956a840</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>remainder</name>
      <anchorfile>group__core_ga501d3d6d436d40d647f290fce53b5bf9.html</anchorfile>
      <anchor>ga501d3d6d436d40d647f290fce53b5bf9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>reverse_horner</name>
      <anchorfile>group__functions_gaec0903d03ecaa41fc2f06bd4d9598fbe.html</anchorfile>
      <anchor>gaec0903d03ecaa41fc2f06bd4d9598fbe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>round</name>
      <anchorfile>group__core_ga94fa0cf071f9760d3b0ba4d9c3b86170.html</anchorfile>
      <anchor>ga94fa0cf071f9760d3b0ba4d9c3b86170</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>roundscale</name>
      <anchorfile>group__core_ga7e269986153d615f074a5497e163999a.html</anchorfile>
      <anchor>ga7e269986153d615f074a5497e163999a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>rsqrt</name>
      <anchorfile>group__core_ga6b68af3438bb67d5a0ac3634a01fd610.html</anchorfile>
      <anchor>ga6b68af3438bb67d5a0ac3634a01fd610</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sign</name>
      <anchorfile>group__core_ga71f110b670810f9e0e3ee1b5745a37a8.html</anchorfile>
      <anchor>ga71f110b670810f9e0e3ee1b5745a37a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sign_alternate</name>
      <anchorfile>group__core_ga564e4bc99fc8f5704fae107a5f83e847.html</anchorfile>
      <anchor>ga564e4bc99fc8f5704fae107a5f83e847</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>signnz</name>
      <anchorfile>group__core_gaa1b1663acb0eb4bbc16fd9beb3dff197.html</anchorfile>
      <anchor>gaa1b1663acb0eb4bbc16fd9beb3dff197</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sinh</name>
      <anchorfile>group__core_gab98365d8cb868ac99d97f9d0297fedfa.html</anchorfile>
      <anchor>gab98365d8cb868ac99d97f9d0297fedfa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>smallestposval</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga1089f4e0a6091f3da50a5c7655ec3643</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sqr</name>
      <anchorfile>group__core_gac72a278d06c43be14dce2cfbd8e67bdf.html</anchorfile>
      <anchor>gac72a278d06c43be14dce2cfbd8e67bdf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sqrt</name>
      <anchorfile>group__core_gab25eb1782219136d8368a2a090bcac77.html</anchorfile>
      <anchor>gab25eb1782219136d8368a2a090bcac77</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sqrt_2</name>
      <anchorfile>group__constants_ga4242d1daac24e1aa6e29ce62d230d171.html</anchorfile>
      <anchor>ga4242d1daac24e1aa6e29ce62d230d171</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sqrteps</name>
      <anchorfile>group__constants_ga193389bdf9378b4f1ab19e1ed49a52a0.html</anchorfile>
      <anchor>ga193389bdf9378b4f1ab19e1ed49a52a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sqrtvalmax</name>
      <anchorfile>group__constants_ga5b01112179d17efdb5be43518c0e0669.html</anchorfile>
      <anchor>ga5b01112179d17efdb5be43518c0e0669</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sub</name>
      <anchorfile>group__core_ga9d647eeb7803da2f5dc1d1c646e22799.html</anchorfile>
      <anchor>ga9d647eeb7803da2f5dc1d1c646e22799</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sum_of_prod</name>
      <anchorfile>group__core_ga00467d77659f76768d9798485cbbd3cf.html</anchorfile>
      <anchor>ga00467d77659f76768d9798485cbbd3cf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sum_of_squares</name>
      <anchorfile>group__core_ga2dd0aca7295af7318c56063bd90f0730.html</anchorfile>
      <anchor>ga2dd0aca7295af7318c56063bd90f0730</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>three_add</name>
      <anchorfile>group__core__accuracy_gad714fdd7a5f3a2cfcab70658cb520cd1.html</anchorfile>
      <anchor>gad714fdd7a5f3a2cfcab70658cb520cd1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>three_fma</name>
      <anchorfile>group__core__accuracy_gabda6529346e0ae007b7709fabfe7cb59.html</anchorfile>
      <anchor>gabda6529346e0ae007b7709fabfe7cb59</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>trunc</name>
      <anchorfile>group__core_ga9aa5715fd56663843e5d34d9e3904338.html</anchorfile>
      <anchor>ga9aa5715fd56663843e5d34d9e3904338</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>two_add</name>
      <anchorfile>group__core__accuracy_ga4f331a5f0e10706ede78c9ac753d6ef4.html</anchorfile>
      <anchor>ga4f331a5f0e10706ede78c9ac753d6ef4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>two_div_approx</name>
      <anchorfile>group__core__accuracy_gab1a360af3bf67971c24e0b8c94ff4c1c.html</anchorfile>
      <anchor>gab1a360af3bf67971c24e0b8c94ff4c1c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>two_fma_approx</name>
      <anchorfile>group__core__accuracy_gae79e44f7a860ba7c33be885213090df1.html</anchorfile>
      <anchor>gae79e44f7a860ba7c33be885213090df1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>two_prod</name>
      <anchorfile>group__core__accuracy_gae8d597dabc4dc057e3110c0a89afe8f3.html</anchorfile>
      <anchor>gae8d597dabc4dc057e3110c0a89afe8f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>two_split</name>
      <anchorfile>group__core__accuracy_ga9086f4afc7e04d20a2a3bf8212dc677a.html</anchorfile>
      <anchor>ga9086f4afc7e04d20a2a3bf8212dc677a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>ulp</name>
      <anchorfile>group__core_ga74d8d2b14e149dc9b687e324a7392700.html</anchorfile>
      <anchor>ga74d8d2b14e149dc9b687e324a7392700</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>ulpdist</name>
      <anchorfile>group__core_ga5bd18a9ff38290ea3898b40b5a212395.html</anchorfile>
      <anchor>ga5bd18a9ff38290ea3898b40b5a212395</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>valmax</name>
      <anchorfile>group__constants_ga107149eec536df23c4386d025b854ecf.html</anchorfile>
      <anchor>ga107149eec536df23c4386d025b854ecf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>valmin</name>
      <anchorfile>group__constants_gafce94c0fcb7990527f77886c832f2d7b.html</anchorfile>
      <anchor>gafce94c0fcb7990527f77886c832f2d7b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>variance</name>
      <anchorfile>group__core_ga0b8af824ea99e25f0aafc7e5756d97d3.html</anchorfile>
      <anchor>ga0b8af824ea99e25f0aafc7e5756d97d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>constexpr auto &amp;</type>
      <name>operator+=</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a17a30537c795078304e6f7510f0c4731</anchor>
      <arglist>(T1 &amp;self, T2 other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto &amp;</type>
      <name>operator-=</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>aef49920793b4da92e687b8d178be4835</anchor>
      <arglist>(T1 &amp;self, T2 other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto &amp;</type>
      <name>operator*=</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a58e25f46704ea034002c861386db069c</anchor>
      <arglist>(T1 &amp;self, T2 other) noexcept</arglist>
    </member>
    <member kind="function">
      <type>auto &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a1d50add5f2f5370f64b20919751ccdcf</anchor>
      <arglist>(std::basic_ostream&lt; C, Ct &gt; &amp;os, CD const &amp;z)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator+</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a18cec006320794126c85b238a68fc91c</anchor>
      <arglist>(Z const &amp;z) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator-</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a3032325260646fe3f0832b076a2b146a</anchor>
      <arglist>(Z const &amp;z) noexcept</arglist>
    </member>
    <member kind="function">
      <type>as_polyfloat_t&lt; T1, T2 &gt;</type>
      <name>operator+</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a8dc21090f71e4797c23d3d4239557026</anchor>
      <arglist>(T1 const &amp;a, T2 const &amp;b) noexcept</arglist>
    </member>
    <member kind="function">
      <type>as_polyfloat_t&lt; T1, T2 &gt;</type>
      <name>operator-</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a665bbd4d727132496baa7e4a19e00ba5</anchor>
      <arglist>(T1 const &amp;a, T2 const &amp;b) noexcept</arglist>
    </member>
    <member kind="function">
      <type>as_polyfloat_t&lt; T1, T2 &gt;</type>
      <name>operator*</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>ac8720871310050866ed9dbef62bc4908</anchor>
      <arglist>(T1 const &amp;a, T2 const &amp;b) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator==</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a561363de989d2101775d8b85655ea08e</anchor>
      <arglist>(T1 const &amp;a, T2 b)</arglist>
    </member>
    <member kind="function">
      <type>constexpr auto</type>
      <name>operator!=</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>ac345e6a953c0ec69ee85d43be131c6c6</anchor>
      <arglist>(T1 const &amp;a, T2 b)</arglist>
    </member>
    <member kind="function">
      <type>as_polyfloat_t&lt; T1, T2 &gt;</type>
      <name>operator/</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a99e34a798da1443432b03f9e5e6f9b6e</anchor>
      <arglist>(T1 const &amp;a, T2 const &amp;b) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>polyfloat</name>
      <anchorfile>structplf_1_1polyfloat_a5bc8d3714e201b591e64a8901fdeb667.html</anchorfile>
      <anchor>a5bc8d3714e201b591e64a8901fdeb667</anchor>
      <arglist>(T0) -&gt; polyfloat&lt; T0, 2u &gt;</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>polyfloat</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>acb02165730e7ed765fdde7603c186597</anchor>
      <arglist>(T0, Ts...) -&gt; polyfloat&lt; T0, 1+sizeof...(Ts)&gt;</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>concepts</name>
    <title>Concepts</title>
    <filename>group__concepts.html</filename>
    <namespace>plf</namespace>
  </compound>
  <compound kind="group">
    <name>constants</name>
    <title>Constants</title>
    <filename>group__constants.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::effective_mantissa_bits</name>
      <anchorfile>group__constants_gac4277864eeceb38de7a3e18e4f329337.html</anchorfile>
      <anchor>gac4277864eeceb38de7a3e18e4f329337</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::eps</name>
      <anchorfile>group__constants_gacd69b768b1e3278712c5dd2b3cd7b58c.html</anchorfile>
      <anchor>gacd69b768b1e3278712c5dd2b3cd7b58c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::euler</name>
      <anchorfile>group__constants_ga307c6361163f5ebe3b6a3c7ca0472da8.html</anchorfile>
      <anchor>ga307c6361163f5ebe3b6a3c7ca0472da8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::inf</name>
      <anchorfile>group__constants_ga17a6561e33fcb9f3bf0be566ca5751f7.html</anchorfile>
      <anchor>ga17a6561e33fcb9f3bf0be566ca5751f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::inveps</name>
      <anchorfile>group__constants_gae1bef0c184e2dead4007764d4e821835.html</anchorfile>
      <anchor>gae1bef0c184e2dead4007764d4e821835</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::invlog_10</name>
      <anchorfile>group__constants_gae5ba2e8a8ea4d88c2799dcdf8424f574.html</anchorfile>
      <anchor>gae5ba2e8a8ea4d88c2799dcdf8424f574</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::invlog_2</name>
      <anchorfile>group__constants_ga558ed10477a5c340a720e2ea3866327c.html</anchorfile>
      <anchor>ga558ed10477a5c340a720e2ea3866327c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::log_2</name>
      <anchorfile>group__constants_gab076b85673ceedd01180cae08b3b984e.html</anchorfile>
      <anchor>gab076b85673ceedd01180cae08b3b984e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::logeps</name>
      <anchorfile>group__constants_gad27792bcc40b8ac1693bacbd95570d68.html</anchorfile>
      <anchor>gad27792bcc40b8ac1693bacbd95570d68</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::maxflint</name>
      <anchorfile>group__constants_gae321346f90402e1b5dc7875054e49a83.html</anchorfile>
      <anchor>gae321346f90402e1b5dc7875054e49a83</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::maxlog</name>
      <anchorfile>group__constants_gaa7847ac49cf7e5db7ff5ecdd7edd9268.html</anchorfile>
      <anchor>gaa7847ac49cf7e5db7ff5ecdd7edd9268</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::nbmantissabits</name>
      <anchorfile>group__constants_ga353f26b1179c82267a8066987951a553.html</anchorfile>
      <anchor>ga353f26b1179c82267a8066987951a553</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::oneosqrteps</name>
      <anchorfile>group__constants_gaf37d435e94d94585ba4b0848c520316b.html</anchorfile>
      <anchor>gaf37d435e94d94585ba4b0848c520316b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sqrt_2</name>
      <anchorfile>group__constants_ga4242d1daac24e1aa6e29ce62d230d171.html</anchorfile>
      <anchor>ga4242d1daac24e1aa6e29ce62d230d171</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sqrteps</name>
      <anchorfile>group__constants_ga193389bdf9378b4f1ab19e1ed49a52a0.html</anchorfile>
      <anchor>ga193389bdf9378b4f1ab19e1ed49a52a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sqrtvalmax</name>
      <anchorfile>group__constants_ga5b01112179d17efdb5be43518c0e0669.html</anchorfile>
      <anchor>ga5b01112179d17efdb5be43518c0e0669</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::valmax</name>
      <anchorfile>group__constants_ga107149eec536df23c4386d025b854ecf.html</anchorfile>
      <anchor>ga107149eec536df23c4386d025b854ecf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::valmin</name>
      <anchorfile>group__constants_gafce94c0fcb7990527f77886c832f2d7b.html</anchorfile>
      <anchor>gafce94c0fcb7990527f77886c832f2d7b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>core</name>
    <title>Core</title>
    <filename>group__core.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::abs</name>
      <anchorfile>group__core_ga69b3078b6a64e0467e0595929ca947de.html</anchorfile>
      <anchor>ga69b3078b6a64e0467e0595929ca947de</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::absmax</name>
      <anchorfile>group__core_gadd0f5df2e8971e69dd54e2b9921d04a6.html</anchorfile>
      <anchor>gadd0f5df2e8971e69dd54e2b9921d04a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::absmin</name>
      <anchorfile>group__core_ga6b9323d57f26ce1cd555444d9b64c807.html</anchorfile>
      <anchor>ga6b9323d57f26ce1cd555444d9b64c807</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::add</name>
      <anchorfile>group__core_ga4d1ed930ff0fa7d990dddb01882515e6.html</anchorfile>
      <anchor>ga4d1ed930ff0fa7d990dddb01882515e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::agm</name>
      <anchorfile>group__core_gaaf79a031e1bb735e16389b0a19a2f3d7.html</anchorfile>
      <anchor>gaaf79a031e1bb735e16389b0a19a2f3d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::allbits</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>gabbd6cfcd83668ca5f081bcc515d75a59</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::average</name>
      <anchorfile>group__core_gad514388c4bd4fe58d50e53e426d62140.html</anchorfile>
      <anchor>gad514388c4bd4fe58d50e53e426d62140</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::bitincrement</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga8fa056d215485ffdb11c9e151f307df0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::cbrt</name>
      <anchorfile>group__core_gaa0cc19fbc27cb06fc0f81bb87148fd2b.html</anchorfile>
      <anchor>gaa0cc19fbc27cb06fc0f81bb87148fd2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::ceil</name>
      <anchorfile>group__core_gacf4cc27cc53a0faf471c2610eab95e8c.html</anchorfile>
      <anchor>gacf4cc27cc53a0faf471c2610eab95e8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::chi</name>
      <anchorfile>group__core_ga352e6ca52f4beeae5effd0cdf7325247.html</anchorfile>
      <anchor>ga352e6ca52f4beeae5effd0cdf7325247</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::clamp</name>
      <anchorfile>group__core_gaf3b6e14fd2890b610b24438a70b5ba87.html</anchorfile>
      <anchor>gaf3b6e14fd2890b610b24438a70b5ba87</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::convert</name>
      <anchorfile>group__core_ga3596810b24bfc8fb774e184cf3c2787e.html</anchorfile>
      <anchor>ga3596810b24bfc8fb774e184cf3c2787e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::copysign</name>
      <anchorfile>group__core_gae88e21eb3751b1d0fd7b71d288d9d1ee.html</anchorfile>
      <anchor>gae88e21eb3751b1d0fd7b71d288d9d1ee</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::cosh</name>
      <anchorfile>group__core_ga9c6115c7b57ba527694f481843d1edac.html</anchorfile>
      <anchor>ga9c6115c7b57ba527694f481843d1edac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::cosine_similarity</name>
      <anchorfile>group__core_gae9bf65899aaf52f81e706494a42c99d3.html</anchorfile>
      <anchor>gae9bf65899aaf52f81e706494a42c99d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::covariance</name>
      <anchorfile>group__core_ga849d694549afbbd8308f3509f7e2c780.html</anchorfile>
      <anchor>ga849d694549afbbd8308f3509f7e2c780</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::cumfun</name>
      <anchorfile>group__core_gad9ed275f6b6e77db5325c3893e933ef6.html</anchorfile>
      <anchor>gad9ed275f6b6e77db5325c3893e933ef6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::cumprod</name>
      <anchorfile>group__core_gaead0ce36438cf8108b2bf0997ff6e4f8.html</anchorfile>
      <anchor>gaead0ce36438cf8108b2bf0997ff6e4f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::cumsum</name>
      <anchorfile>group__core_ga431cf7d6555dc450704863dd522499b6.html</anchorfile>
      <anchor>ga431cf7d6555dc450704863dd522499b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::dec</name>
      <anchorfile>group__core_ga21dc299efb61f8ae4924e3fb0b953f7c.html</anchorfile>
      <anchor>ga21dc299efb61f8ae4924e3fb0b953f7c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::diff</name>
      <anchorfile>group__core_ga197b906315ce84f0c78181a9314c0988.html</anchorfile>
      <anchor>ga197b906315ce84f0c78181a9314c0988</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::dist</name>
      <anchorfile>group__core_ga31aaafd7f21c599693e7a2fd6533e315.html</anchorfile>
      <anchor>ga31aaafd7f21c599693e7a2fd6533e315</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::div</name>
      <anchorfile>group__core_gad96f947d70b23427a0305b9998aad337.html</anchorfile>
      <anchor>gad96f947d70b23427a0305b9998aad337</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::dot</name>
      <anchorfile>group__core_gaf5ce77de394a85c44e05c7f96215fc27.html</anchorfile>
      <anchor>gaf5ce77de394a85c44e05c7f96215fc27</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::epsilon</name>
      <anchorfile>group__core_gac68d4fa443f186a4893bda40bdadcd39.html</anchorfile>
      <anchor>gac68d4fa443f186a4893bda40bdadcd39</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::exp</name>
      <anchorfile>group__core_gab8e08b05daa3ee86e2ed652a07352d64.html</anchorfile>
      <anchor>gab8e08b05daa3ee86e2ed652a07352d64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::exp2</name>
      <anchorfile>group__core_gaec8099077dd346085e88919e08513d84.html</anchorfile>
      <anchor>gaec8099077dd346085e88919e08513d84</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::expm1</name>
      <anchorfile>group__core_ga6b355641ddbdb7ec0d1daa0bcf7be425.html</anchorfile>
      <anchor>ga6b355641ddbdb7ec0d1daa0bcf7be425</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::fam</name>
      <anchorfile>group__core_ga901d4b061ed59463f25ab684e7707f35.html</anchorfile>
      <anchor>ga901d4b061ed59463f25ab684e7707f35</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::floor</name>
      <anchorfile>group__core_gabaa3043614b3644380404814e6718a87.html</anchorfile>
      <anchor>gabaa3043614b3644380404814e6718a87</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::fma</name>
      <anchorfile>group__core_gafe2539e930df632442830952eafe983f.html</anchorfile>
      <anchor>gafe2539e930df632442830952eafe983f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::fmod</name>
      <anchorfile>group__core_ga1e5b90cb087d254f8741482c0e894594.html</anchorfile>
      <anchor>ga1e5b90cb087d254f8741482c0e894594</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::fms</name>
      <anchorfile>group__core_ga528f7b968ee1663dd96dcbf976e96491.html</anchorfile>
      <anchor>ga528f7b968ee1663dd96dcbf976e96491</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::fnma</name>
      <anchorfile>group__core_ga5b4600c48a905e3808b32a9441a6d19d.html</anchorfile>
      <anchor>ga5b4600c48a905e3808b32a9441a6d19d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::fnms</name>
      <anchorfile>group__core_ga820c60b72b131ea41f424290e4777842.html</anchorfile>
      <anchor>ga820c60b72b131ea41f424290e4777842</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::frac</name>
      <anchorfile>group__core_ga6cbff9063806f25141fbe0f5863becae.html</anchorfile>
      <anchor>ga6cbff9063806f25141fbe0f5863becae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::frexp</name>
      <anchorfile>group__core_ga89334551f0d0c2f81bf852d2a0b9f502.html</anchorfile>
      <anchor>ga89334551f0d0c2f81bf852d2a0b9f502</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::fsm</name>
      <anchorfile>group__core_gab6ffa7b2b7b589bc9bbf790c8555e7f3.html</anchorfile>
      <anchor>gab6ffa7b2b7b589bc9bbf790c8555e7f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::half</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>gafdc7f58bede6debd2ef66a4b3521cb84</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::heaviside</name>
      <anchorfile>group__core_gaacc157e51d44695e50b1e1af7643abc0.html</anchorfile>
      <anchor>gaacc157e51d44695e50b1e1af7643abc0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::hi</name>
      <anchorfile>group__core_ga85fa850c93bf943fe9e434de3552293d.html</anchorfile>
      <anchor>ga85fa850c93bf943fe9e434de3552293d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::hypot</name>
      <anchorfile>group__core_gab1d383e91204c25060d9e6f3f68fac0b.html</anchorfile>
      <anchor>gab1d383e91204c25060d9e6f3f68fac0b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::if_else</name>
      <anchorfile>group__core_gafb741bdffc03f40d05b112ff6c893e7c.html</anchorfile>
      <anchor>gafb741bdffc03f40d05b112ff6c893e7c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::inc</name>
      <anchorfile>group__core_gad3d7ea17362a2244fb6ec0ca2d5a78e5.html</anchorfile>
      <anchor>gad3d7ea17362a2244fb6ec0ca2d5a78e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_bit_equal</name>
      <anchorfile>group__core_ga15e2026fc3252509ad69742f7daf0682.html</anchorfile>
      <anchor>ga15e2026fc3252509ad69742f7daf0682</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_denormal</name>
      <anchorfile>group__core_ga3b8438957e33ee0ee5b3ab2508aa72ac.html</anchorfile>
      <anchor>ga3b8438957e33ee0ee5b3ab2508aa72ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_eqmz</name>
      <anchorfile>group__core_ga1a258750e54fc736597fa9439bea340f.html</anchorfile>
      <anchor>ga1a258750e54fc736597fa9439bea340f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_eqpz</name>
      <anchorfile>group__core_ga1d3c7d7b9441ebc3115872893b1f35a7.html</anchorfile>
      <anchor>ga1d3c7d7b9441ebc3115872893b1f35a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_equal</name>
      <anchorfile>group__core_gaa3f884f1bd114c09949fb5d4e1af9876.html</anchorfile>
      <anchor>gaa3f884f1bd114c09949fb5d4e1af9876</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_eqz</name>
      <anchorfile>group__core_ga4d8c8308d3b4bba663bb237a195b27a6.html</anchorfile>
      <anchor>ga4d8c8308d3b4bba663bb237a195b27a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_even</name>
      <anchorfile>group__core_gabfa4b5248f0e3f16859f471e7445a0ec.html</anchorfile>
      <anchor>gabfa4b5248f0e3f16859f471e7445a0ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_finite</name>
      <anchorfile>group__core_ga51a63988bfb6162220cd95bcf37af748.html</anchorfile>
      <anchor>ga51a63988bfb6162220cd95bcf37af748</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_flint</name>
      <anchorfile>group__core_ga72a296047ea9f24dc1438e3a1161e58b.html</anchorfile>
      <anchor>ga72a296047ea9f24dc1438e3a1161e58b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_greater</name>
      <anchorfile>group__core_ga1a413faf72a8ca404c5445c18660b038.html</anchorfile>
      <anchor>ga1a413faf72a8ca404c5445c18660b038</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_greater_equal</name>
      <anchorfile>group__core_ga97645462f4430d66d0da2a93a1b2f37d.html</anchorfile>
      <anchor>ga97645462f4430d66d0da2a93a1b2f37d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_gtz</name>
      <anchorfile>group__core_gabd560b7b077896323ee38940ef5a3583.html</anchorfile>
      <anchor>gabd560b7b077896323ee38940ef5a3583</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_infinite</name>
      <anchorfile>group__core_gae4511a6a87e546c2fa45b2483a26cbd2.html</anchorfile>
      <anchor>gae4511a6a87e546c2fa45b2483a26cbd2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_less</name>
      <anchorfile>group__core_gaeb3a722d8086ab0090707c53e2058c3d.html</anchorfile>
      <anchor>gaeb3a722d8086ab0090707c53e2058c3d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_less_equal</name>
      <anchorfile>group__core_ga288303686db135dde311d78d6ebcc103.html</anchorfile>
      <anchor>ga288303686db135dde311d78d6ebcc103</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_lessgreater</name>
      <anchorfile>group__core_ga93c70fd4967b9569ea28724a993369be.html</anchorfile>
      <anchor>ga93c70fd4967b9569ea28724a993369be</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_lez</name>
      <anchorfile>group__core_gad212f44157bf7a494a02cdc8e2cb01b4.html</anchorfile>
      <anchor>gad212f44157bf7a494a02cdc8e2cb01b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_ltz</name>
      <anchorfile>group__core_ga62ddb7af573f49058eba0f222072310a.html</anchorfile>
      <anchor>ga62ddb7af573f49058eba0f222072310a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_minf</name>
      <anchorfile>group__core_gab77d212b376f19f9172c3741d6b2df35.html</anchorfile>
      <anchor>gab77d212b376f19f9172c3741d6b2df35</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_nan</name>
      <anchorfile>group__core_ga1db11a0b9a18822ffe41043c38cc80c3.html</anchorfile>
      <anchor>ga1db11a0b9a18822ffe41043c38cc80c3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_negative</name>
      <anchorfile>group__core_ga5b1a93ce270f1b01560e0007b998ea73.html</anchorfile>
      <anchor>ga5b1a93ce270f1b01560e0007b998ea73</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_nemz</name>
      <anchorfile>group__core_gab196817aaa41a88c58ed791c715b0350.html</anchorfile>
      <anchor>gab196817aaa41a88c58ed791c715b0350</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_nepz</name>
      <anchorfile>group__core_ga588f3519dcd992829d6060db0b2dd0b6.html</anchorfile>
      <anchor>ga588f3519dcd992829d6060db0b2dd0b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_nez</name>
      <anchorfile>group__core_ga1e4d7cd895471d034bfab1d93130be54.html</anchorfile>
      <anchor>ga1e4d7cd895471d034bfab1d93130be54</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_ngez</name>
      <anchorfile>group__core_ga4299f6d8bf5e48900d92af1371735d2f.html</anchorfile>
      <anchor>ga4299f6d8bf5e48900d92af1371735d2f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_ngtz</name>
      <anchorfile>group__core_ga1012d9d76ecb23bf85402fea5b7719ae.html</anchorfile>
      <anchor>ga1012d9d76ecb23bf85402fea5b7719ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_nlez</name>
      <anchorfile>group__core_ga78f7c97500b38f86a7a63242368aae2c.html</anchorfile>
      <anchor>ga78f7c97500b38f86a7a63242368aae2c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_nltz</name>
      <anchorfile>group__core_gae2a0761ccbc5a9fe472f2f5c14a8fcd9.html</anchorfile>
      <anchor>gae2a0761ccbc5a9fe472f2f5c14a8fcd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_denormal</name>
      <anchorfile>group__core_ga315ab6ec01496d96b325d266be09767f.html</anchorfile>
      <anchor>ga315ab6ec01496d96b325d266be09767f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_equal</name>
      <anchorfile>group__core_gaed9f3b4229041da1ac2a2070db903277.html</anchorfile>
      <anchor>gaed9f3b4229041da1ac2a2070db903277</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_finite</name>
      <anchorfile>group__core_ga63749142d53ad0d040659d8d4cffee74.html</anchorfile>
      <anchor>ga63749142d53ad0d040659d8d4cffee74</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_flint</name>
      <anchorfile>group__core_ga42ae7e20907bd55debe6262ff5ea78f9.html</anchorfile>
      <anchor>ga42ae7e20907bd55debe6262ff5ea78f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_greater</name>
      <anchorfile>group__core_ga2717687d1b7470024cd67a978c7b42b3.html</anchorfile>
      <anchor>ga2717687d1b7470024cd67a978c7b42b3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_greater_equal</name>
      <anchorfile>group__core_gabe0e10750aea5fdf460f4c56f46d84c9.html</anchorfile>
      <anchor>gabe0e10750aea5fdf460f4c56f46d84c9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_infinite</name>
      <anchorfile>group__core_gad3cf2c8f13b83ffed9f1b2924a8a8529.html</anchorfile>
      <anchor>gad3cf2c8f13b83ffed9f1b2924a8a8529</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_less</name>
      <anchorfile>group__core_gacad2e09ee75c713a87065f75a2a18c64.html</anchorfile>
      <anchor>gacad2e09ee75c713a87065f75a2a18c64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_less_equal</name>
      <anchorfile>group__core_gac10cc53f0009c90aa0a206f346e21cee.html</anchorfile>
      <anchor>gac10cc53f0009c90aa0a206f346e21cee</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_nan</name>
      <anchorfile>group__core_ga64a07f1dd60b6e1409442078cc039a42.html</anchorfile>
      <anchor>ga64a07f1dd60b6e1409442078cc039a42</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_odd</name>
      <anchorfile>group__core_ga455e06a0df2a0068637f251becfbb944.html</anchorfile>
      <anchor>ga455e06a0df2a0068637f251becfbb944</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_ordered</name>
      <anchorfile>group__core_ga7c90ae517c18bab6325f49cce61f4edf.html</anchorfile>
      <anchor>ga7c90ae517c18bab6325f49cce61f4edf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_pinf</name>
      <anchorfile>group__core_gaff62e2a7284c69e0b8c388e70ad2e066.html</anchorfile>
      <anchor>gaff62e2a7284c69e0b8c388e70ad2e066</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_positive</name>
      <anchorfile>group__core_ga382498c379928168e37005f38a9b8eaf.html</anchorfile>
      <anchor>ga382498c379928168e37005f38a9b8eaf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_pow2</name>
      <anchorfile>group__core_gaf77de37071bc9885bab1dc8d8bb235b0.html</anchorfile>
      <anchor>gaf77de37071bc9885bab1dc8d8bb235b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_unit</name>
      <anchorfile>group__core_gae00ac1ff95cdeca72e526d70cc419e51.html</anchorfile>
      <anchor>gae00ac1ff95cdeca72e526d70cc419e51</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_unordered</name>
      <anchorfile>group__core_ga46fff13f9c73cf8cdbe1ed78f4083f65.html</anchorfile>
      <anchor>ga46fff13f9c73cf8cdbe1ed78f4083f65</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::ldexp</name>
      <anchorfile>group__core_gaaafb5f51797ebd81c0fdc1011e0275a3.html</anchorfile>
      <anchor>gaaafb5f51797ebd81c0fdc1011e0275a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::lerp</name>
      <anchorfile>group__core_ga8875d0b61cf3fbeeaa6ed18b29e5ca9f.html</anchorfile>
      <anchor>ga8875d0b61cf3fbeeaa6ed18b29e5ca9f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::lo</name>
      <anchorfile>group__core_ga986719f5a39d352e01286ab52b9a54ff.html</anchorfile>
      <anchor>ga986719f5a39d352e01286ab52b9a54ff</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::log</name>
      <anchorfile>group__core_ga39d37d0f777a93ba32640c56565e2710.html</anchorfile>
      <anchor>ga39d37d0f777a93ba32640c56565e2710</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::log10</name>
      <anchorfile>group__core_gaae901ccc06c7a5efa0242e5fcd654bd4.html</anchorfile>
      <anchor>gaae901ccc06c7a5efa0242e5fcd654bd4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::log2</name>
      <anchorfile>group__core_ga74fe53ba9509c1894684a4fe92865d07.html</anchorfile>
      <anchor>ga74fe53ba9509c1894684a4fe92865d07</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::mantissa</name>
      <anchorfile>group__core_ga592c5eb0fdeb82b41dd07a2ddc48dd6e.html</anchorfile>
      <anchor>ga592c5eb0fdeb82b41dd07a2ddc48dd6e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::max</name>
      <anchorfile>group__core_ga1d6b7e84a59f51f3fdeab89704ce3bb1.html</anchorfile>
      <anchor>ga1d6b7e84a59f51f3fdeab89704ce3bb1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::maxabs</name>
      <anchorfile>group__core_ga943ef8abb2c09066d89722a3ea69c78c.html</anchorfile>
      <anchor>ga943ef8abb2c09066d89722a3ea69c78c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::maxmag</name>
      <anchorfile>group__core_gaee2e0eb2ad65678b921da8c2b4de631e.html</anchorfile>
      <anchor>gaee2e0eb2ad65678b921da8c2b4de631e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::md</name>
      <anchorfile>group__core_ga0745f202e4af71621d3f5e84e37c6abe.html</anchorfile>
      <anchor>ga0745f202e4af71621d3f5e84e37c6abe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::mhalf</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>gacf3b52a44982c70d2b2b7a11531beee3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::min</name>
      <anchorfile>group__core_gaf2ecab0082e8fa1007d5ea49c9fa1a87.html</anchorfile>
      <anchor>gaf2ecab0082e8fa1007d5ea49c9fa1a87</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::minabs</name>
      <anchorfile>group__core_gaa190c10bef44628e4701ff2fcd6728a0.html</anchorfile>
      <anchor>gaa190c10bef44628e4701ff2fcd6728a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::mindenormal</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga0a3e5881bfb4a0de7977621996c339a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::minexponent</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga4647ba96a04ee2f05047b93c70509bd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::minf</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga53eeee70008790007d0da7e69ad152e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::minmag</name>
      <anchorfile>group__core_ga3edebc887d62d202367258c76f7a1a7f.html</anchorfile>
      <anchor>ga3edebc887d62d202367258c76f7a1a7f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::minmax</name>
      <anchorfile>group__core_ga830c684d59f4722059bef14bb7f92da2.html</anchorfile>
      <anchor>ga830c684d59f4722059bef14bb7f92da2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::minus</name>
      <anchorfile>group__core_gae33d4d1bd5488f7aed156cd106f4ce74.html</anchorfile>
      <anchor>gae33d4d1bd5488f7aed156cd106f4ce74</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::modf</name>
      <anchorfile>group__core_gaf07ed2a608fc290c474c9baaa296fc76.html</anchorfile>
      <anchor>gaf07ed2a608fc290c474c9baaa296fc76</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::mone</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>gafd51d660d060685287a61ceb9a0619c5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::mul</name>
      <anchorfile>group__core_ga856a221cd309873711b978ce55df4635.html</anchorfile>
      <anchor>ga856a221cd309873711b978ce55df4635</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::mzero</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga889a98f4b2269954d9c5326e07ffdd9f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::nan</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>gab815a9e20ea8d0c215108a23413f0347</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::nearest</name>
      <anchorfile>group__core_ga1c1e5e03fa7f21ea1a74311813762197.html</anchorfile>
      <anchor>ga1c1e5e03fa7f21ea1a74311813762197</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::negabsmax</name>
      <anchorfile>group__core_ga54e69f527759113beefec446c9c8f7de.html</anchorfile>
      <anchor>ga54e69f527759113beefec446c9c8f7de</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::negabsmin</name>
      <anchorfile>group__core_ga519b13d3f054b319b6ef5e59eb029a47.html</anchorfile>
      <anchor>ga519b13d3f054b319b6ef5e59eb029a47</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::negate</name>
      <anchorfile>group__core_ga0b77fce5aa260a3629bed972eee3ba39.html</anchorfile>
      <anchor>ga0b77fce5aa260a3629bed972eee3ba39</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::negatenz</name>
      <anchorfile>group__core_gacb0784fa93d2122cec99faf7a9760daa.html</anchorfile>
      <anchor>gacb0784fa93d2122cec99faf7a9760daa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::negmaxabs</name>
      <anchorfile>group__core_ga0ddb4ae3b0954209eca0c7257d166dbc.html</anchorfile>
      <anchor>ga0ddb4ae3b0954209eca0c7257d166dbc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::negminabs</name>
      <anchorfile>group__core_gace9b23e8f34fdc09478d8901078f1bb6.html</anchorfile>
      <anchor>gace9b23e8f34fdc09478d8901078f1bb6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::next</name>
      <anchorfile>group__core_ga60c7f280243a468485f42421a2c06739.html</anchorfile>
      <anchor>ga60c7f280243a468485f42421a2c06739</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::nextafter</name>
      <anchorfile>group__core_ga09f396a43b0cf65385e8a586a2b410e9.html</anchorfile>
      <anchor>ga09f396a43b0cf65385e8a586a2b410e9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::nextint</name>
      <anchorfile>group__core_gaf1c232d7bc7f81fc1a42edb3c7b7cd88.html</anchorfile>
      <anchor>gaf1c232d7bc7f81fc1a42edb3c7b7cd88</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::nthroot</name>
      <anchorfile>group__core_ga51f47a92f62d391bf10c55c304a691da.html</anchorfile>
      <anchor>ga51f47a92f62d391bf10c55c304a691da</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::one</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>gaf4a21d2a045aedd47efa31fcc8be1fcf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::oneminus</name>
      <anchorfile>group__core_gaffe46da86ea6a171bb1de5203b24334a.html</anchorfile>
      <anchor>gaffe46da86ea6a171bb1de5203b24334a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::pown</name>
      <anchorfile>group__core_ga3309e6018e6235033a2877c0d9eece8c.html</anchorfile>
      <anchor>ga3309e6018e6235033a2877c0d9eece8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::prev</name>
      <anchorfile>group__core_ga3e945bcc637ae4a744f512275949fe82.html</anchorfile>
      <anchor>ga3e945bcc637ae4a744f512275949fe82</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::prevint</name>
      <anchorfile>group__core_ga4bf8537407a460e745d9df6f37fac5f7.html</anchorfile>
      <anchor>ga4bf8537407a460e745d9df6f37fac5f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::rat</name>
      <anchorfile>group__core_gae7854c4bf7224d75816c16d3141b868c.html</anchorfile>
      <anchor>gae7854c4bf7224d75816c16d3141b868c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::rec</name>
      <anchorfile>group__core_ga38ee18ae42971becb7275f6596ada180.html</anchorfile>
      <anchor>ga38ee18ae42971becb7275f6596ada180</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::reldist</name>
      <anchorfile>group__core_ga46f13916d7af01b5f6c1f880d13e2ed4.html</anchorfile>
      <anchor>ga46f13916d7af01b5f6c1f880d13e2ed4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::rem</name>
      <anchorfile>group__core_gaba27d496c09e7ef0892b23806956a840.html</anchorfile>
      <anchor>gaba27d496c09e7ef0892b23806956a840</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::remainder</name>
      <anchorfile>group__core_ga501d3d6d436d40d647f290fce53b5bf9.html</anchorfile>
      <anchor>ga501d3d6d436d40d647f290fce53b5bf9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::round</name>
      <anchorfile>group__core_ga94fa0cf071f9760d3b0ba4d9c3b86170.html</anchorfile>
      <anchor>ga94fa0cf071f9760d3b0ba4d9c3b86170</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::roundscale</name>
      <anchorfile>group__core_ga7e269986153d615f074a5497e163999a.html</anchorfile>
      <anchor>ga7e269986153d615f074a5497e163999a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::rsqrt</name>
      <anchorfile>group__core_ga6b68af3438bb67d5a0ac3634a01fd610.html</anchorfile>
      <anchor>ga6b68af3438bb67d5a0ac3634a01fd610</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sign</name>
      <anchorfile>group__core_ga71f110b670810f9e0e3ee1b5745a37a8.html</anchorfile>
      <anchor>ga71f110b670810f9e0e3ee1b5745a37a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sign_alternate</name>
      <anchorfile>group__core_ga564e4bc99fc8f5704fae107a5f83e847.html</anchorfile>
      <anchor>ga564e4bc99fc8f5704fae107a5f83e847</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::signnz</name>
      <anchorfile>group__core_gaa1b1663acb0eb4bbc16fd9beb3dff197.html</anchorfile>
      <anchor>gaa1b1663acb0eb4bbc16fd9beb3dff197</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sinh</name>
      <anchorfile>group__core_gab98365d8cb868ac99d97f9d0297fedfa.html</anchorfile>
      <anchor>gab98365d8cb868ac99d97f9d0297fedfa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::smallestposval</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga1089f4e0a6091f3da50a5c7655ec3643</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sqr</name>
      <anchorfile>group__core_gac72a278d06c43be14dce2cfbd8e67bdf.html</anchorfile>
      <anchor>gac72a278d06c43be14dce2cfbd8e67bdf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sqrt</name>
      <anchorfile>group__core_gab25eb1782219136d8368a2a090bcac77.html</anchorfile>
      <anchor>gab25eb1782219136d8368a2a090bcac77</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sub</name>
      <anchorfile>group__core_ga9d647eeb7803da2f5dc1d1c646e22799.html</anchorfile>
      <anchor>ga9d647eeb7803da2f5dc1d1c646e22799</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sum_of_prod</name>
      <anchorfile>group__core_ga00467d77659f76768d9798485cbbd3cf.html</anchorfile>
      <anchor>ga00467d77659f76768d9798485cbbd3cf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sum_of_squares</name>
      <anchorfile>group__core_ga2dd0aca7295af7318c56063bd90f0730.html</anchorfile>
      <anchor>ga2dd0aca7295af7318c56063bd90f0730</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::trunc</name>
      <anchorfile>group__core_ga9aa5715fd56663843e5d34d9e3904338.html</anchorfile>
      <anchor>ga9aa5715fd56663843e5d34d9e3904338</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::ulp</name>
      <anchorfile>group__core_ga74d8d2b14e149dc9b687e324a7392700.html</anchorfile>
      <anchor>ga74d8d2b14e149dc9b687e324a7392700</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::ulpdist</name>
      <anchorfile>group__core_ga5bd18a9ff38290ea3898b40b5a212395.html</anchorfile>
      <anchor>ga5bd18a9ff38290ea3898b40b5a212395</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::variance</name>
      <anchorfile>group__core_ga0b8af824ea99e25f0aafc7e5756d97d3.html</anchorfile>
      <anchor>ga0b8af824ea99e25f0aafc7e5756d97d3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>core_accuracy</name>
    <title>Core_accuracy</title>
    <filename>group__core__accuracy.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::dekker_prod</name>
      <anchorfile>group__core__accuracy_ga1a41dc23e01e636ab69b39a3238a893f.html</anchorfile>
      <anchor>ga1a41dc23e01e636ab69b39a3238a893f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::three_add</name>
      <anchorfile>group__core__accuracy_gad714fdd7a5f3a2cfcab70658cb520cd1.html</anchorfile>
      <anchor>gad714fdd7a5f3a2cfcab70658cb520cd1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::three_fma</name>
      <anchorfile>group__core__accuracy_gabda6529346e0ae007b7709fabfe7cb59.html</anchorfile>
      <anchor>gabda6529346e0ae007b7709fabfe7cb59</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::two_add</name>
      <anchorfile>group__core__accuracy_ga4f331a5f0e10706ede78c9ac753d6ef4.html</anchorfile>
      <anchor>ga4f331a5f0e10706ede78c9ac753d6ef4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::two_div_approx</name>
      <anchorfile>group__core__accuracy_gab1a360af3bf67971c24e0b8c94ff4c1c.html</anchorfile>
      <anchor>gab1a360af3bf67971c24e0b8c94ff4c1c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::two_fma_approx</name>
      <anchorfile>group__core__accuracy_gae79e44f7a860ba7c33be885213090df1.html</anchorfile>
      <anchor>gae79e44f7a860ba7c33be885213090df1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::two_prod</name>
      <anchorfile>group__core__accuracy_gae8d597dabc4dc057e3110c0a89afe8f3.html</anchorfile>
      <anchor>gae8d597dabc4dc057e3110c0a89afe8f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::two_split</name>
      <anchorfile>group__core__accuracy_ga9086f4afc7e04d20a2a3bf8212dc677a.html</anchorfile>
      <anchor>ga9086f4afc7e04d20a2a3bf8212dc677a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>core_internal</name>
    <title>Core_internal</title>
    <filename>group__core__internal.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::exponent</name>
      <anchorfile>group__core__internal_ga60713c93ccdf574a916e2c96eede7018.html</anchorfile>
      <anchor>ga60713c93ccdf574a916e2c96eede7018</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>functions</name>
    <title>Functions</title>
    <filename>group__functions.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::horner</name>
      <anchorfile>group__functions_gae998e94f32f326d4c67342e2ceb35982.html</anchorfile>
      <anchor>gae998e94f32f326d4c67342e2ceb35982</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::reverse_horner</name>
      <anchorfile>group__functions_gaec0903d03ecaa41fc2f06bd4d9598fbe.html</anchorfile>
      <anchor>gaec0903d03ecaa41fc2f06bd4d9598fbe</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>traits</name>
    <title>Traits</title>
    <filename>group__traits.html</filename>
    <class kind="struct">plf::as_component</class>
    <member kind="typedef">
      <type>typename as_component_type&lt; T &gt;::type</type>
      <name>plf::as_component_type_t</name>
      <anchorfile>group__traits_gaa325dcaa3d30c3a89c5333b2800aac54.html</anchorfile>
      <anchor>gaa325dcaa3d30c3a89c5333b2800aac54</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename as_polyfloat_n&lt; Dim, Ts... &gt;::type</type>
      <name>plf::as_polyfloat_n_t</name>
      <anchorfile>group__traits_gaa65fa3ada94ae1d661001889062623b4.html</anchorfile>
      <anchor>gaa65fa3ada94ae1d661001889062623b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename as_polyfloat&lt; Ts... &gt;::type</type>
      <name>plf::as_polyfloat_t</name>
      <anchorfile>group__traits_gabb544245c689b7e0ea2f9f6e8feb8594.html</anchorfile>
      <anchor>gabb544245c689b7e0ea2f9f6e8feb8594</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr unsigned int</type>
      <name>plf::dimension_v</name>
      <anchorfile>group__traits_ga846021636ff96cc73a58d2f664e7ce1f.html</anchorfile>
      <anchor>ga846021636ff96cc73a58d2f664e7ce1f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>types</name>
    <title>Types</title>
    <filename>group__types.html</filename>
    <class kind="class">plf::polyfloat</class>
    <member kind="typedef">
      <type>as_polyfloat_n_t&lt; 2, T &gt;</type>
      <name>plf::double_real_t</name>
      <anchorfile>group__types_gad8203f72c65a6761f03db03f8ac55c61.html</anchorfile>
      <anchor>gad8203f72c65a6761f03db03f8ac55c61</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>as_polyfloat_n_t&lt; 3, T &gt;</type>
      <name>plf::triple_real_t</name>
      <anchorfile>group__types_ga3150408863a87ad5a78978ea1eebf102.html</anchorfile>
      <anchor>ga3150408863a87ad5a78978ea1eebf102</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="page">
    <name>licence</name>
    <title>Licence</title>
    <filename>licence.html</filename>
    <docanchor file="licence.html" title="/__w/polyfloat/polyfloat/doc/licence.md">md__2____w_2polyfloat_2polyfloat_2doc_2licence</docanchor>
  </compound>
  <compound kind="page">
    <name>md__2____w_2polyfloat_2polyfloat_2doc_2index</name>
    <title>Polyfloat</title>
    <filename>md__2____w_2polyfloat_2polyfloat_2doc_2index.html</filename>
  </compound>
</tagfile>
