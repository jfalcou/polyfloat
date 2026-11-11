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
    <name>plf::callable</name>
    <filename>structplf_1_1callable.html</filename>
    <templarg>template&lt; typename &gt; class Func</templarg>
    <templarg>template&lt; typename &gt; class Eve</templarg>
    <templarg>typename OptionsValues</templarg>
    <templarg>typename... Options</templarg>
  </compound>
  <compound kind="struct">
    <name>complexify</name>
    <filename>structcomplexify.html</filename>
  </compound>
  <compound kind="struct">
    <name>plf::constant_callable</name>
    <filename>structplf_1_1constant__callable.html</filename>
    <templarg>template&lt; typename &gt; class Func</templarg>
    <templarg>template&lt; typename &gt; class Eve</templarg>
    <templarg>typename OptionsValues</templarg>
    <templarg>typename... Options</templarg>
  </compound>
  <compound kind="struct">
    <name>plf::elementwise_callable</name>
    <filename>structplf_1_1elementwise__callable.html</filename>
    <templarg>template&lt; typename &gt; class Func</templarg>
    <templarg>template&lt; typename &gt; class Eve</templarg>
    <templarg>typename OptionsValues</templarg>
    <templarg>typename... Options</templarg>
  </compound>
  <compound kind="class">
    <name>plf::polyfloat</name>
    <filename>structplf_1_1polyfloat.html</filename>
    <templarg>eve::floating_scalar_value Type</templarg>
    <templarg>unsigned int N</templarg>
    <member kind="function">
      <type>POLYFLOAT_ABI auto &amp;</type>
      <name>operator++</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a4558dc4dc790dc3684bef57028fcdde3</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>POLYFLOAT_ABI auto</type>
      <name>operator++</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a4c60104ca223728c67e3c3ac88e9135e</anchor>
      <arglist>(int) noexcept</arglist>
    </member>
    <member kind="function">
      <type>POLYFLOAT_ABI auto &amp;</type>
      <name>operator--</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>a2e7da6d138a6b1e5d628fc5feed306f6</anchor>
      <arglist>() noexcept</arglist>
    </member>
    <member kind="function">
      <type>POLYFLOAT_ABI auto</type>
      <name>operator--</name>
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
      <anchor>ae0eb00c7c2f02edb1c0d92ffe849c7b1</anchor>
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
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
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
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
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
  <compound kind="struct">
    <name>plf::strict_tuple_callable</name>
    <filename>structplf_1_1strict__tuple__callable.html</filename>
    <templarg>template&lt; typename &gt; class Func</templarg>
    <templarg>template&lt; typename &gt; class Eve</templarg>
    <templarg>typename OptionsValues</templarg>
    <templarg>typename... Options</templarg>
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
    <name>plf::concepts::simd_integral</name>
    <filename>conceptplf_1_1concepts_1_1simd__integral.html</filename>
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
    <class kind="struct">plf::callable</class>
    <class kind="struct">plf::constant_callable</class>
    <class kind="struct">plf::elementwise_callable</class>
    <class kind="class">plf::polyfloat</class>
    <class kind="struct">plf::strict_tuple_callable</class>
    <member kind="typedef">
      <type>typename as_component_type&lt; T &gt;::type</type>
      <name>as_component_type_t</name>
      <anchorfile>group__traits.html</anchorfile>
      <anchor>gaa325dcaa3d30c3a89c5333b2800aac54</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename as_polyfloat_n&lt; Dim, Ts... &gt;::type</type>
      <name>as_polyfloat_n_t</name>
      <anchorfile>group__traits.html</anchorfile>
      <anchor>gaa65fa3ada94ae1d661001889062623b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename as_polyfloat&lt; Ts... &gt;::type</type>
      <name>as_polyfloat_t</name>
      <anchorfile>group__traits.html</anchorfile>
      <anchor>gabb544245c689b7e0ea2f9f6e8feb8594</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>as_polyfloat_n_t&lt; 2, T &gt;</type>
      <name>double_real_t</name>
      <anchorfile>group__types.html</anchorfile>
      <anchor>gad8203f72c65a6761f03db03f8ac55c61</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>as_polyfloat_n_t&lt; 3, T &gt;</type>
      <name>triple_real_t</name>
      <anchorfile>group__types.html</anchorfile>
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
      <anchorfile>group__plf__abs.html</anchorfile>
      <anchor>ga69b3078b6a64e0467e0595929ca947de</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>absmax</name>
      <anchorfile>group__plf__absmax.html</anchorfile>
      <anchor>gadd0f5df2e8971e69dd54e2b9921d04a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>absmin</name>
      <anchorfile>group__plf__absmin.html</anchorfile>
      <anchor>ga6b9323d57f26ce1cd555444d9b64c807</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>acos</name>
      <anchorfile>group__plf__acos.html</anchorfile>
      <anchor>ga16bd93f50121516a6f2321aec146b4c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>acosh</name>
      <anchorfile>group__plf__acosh.html</anchorfile>
      <anchor>gaed114cf184f7a06cadd10432981d3516</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>acoth</name>
      <anchorfile>group__plf__acoth.html</anchorfile>
      <anchor>ga255478078703a5e3983f9a1f391c5807</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>acsc</name>
      <anchorfile>group__plf__acsc.html</anchorfile>
      <anchor>ga1c3b2469b5b4a43fb08afec46d984e35</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>acsch</name>
      <anchorfile>group__plf__acsch.html</anchorfile>
      <anchor>ga9063b9310082cd6b6ee1e38e5eb735ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>add</name>
      <anchorfile>group__plf__add.html</anchorfile>
      <anchor>ga4d1ed930ff0fa7d990dddb01882515e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>agd</name>
      <anchorfile>group__plf__agd.html</anchorfile>
      <anchor>ga825911adaa3fc328ca8780ab04b7a44b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>agm</name>
      <anchorfile>group__plf__agm.html</anchorfile>
      <anchor>gaaf79a031e1bb735e16389b0a19a2f3d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>allbits</name>
      <anchorfile>group__plf__allbits.html</anchorfile>
      <anchor>gabbd6cfcd83668ca5f081bcc515d75a59</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>arg</name>
      <anchorfile>group__plf__arg.html</anchorfile>
      <anchor>ga071efd467f1094e602acecb0896fd63c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>asec</name>
      <anchorfile>group__plf__asec.html</anchorfile>
      <anchor>ga9d81960283c44e7fcc54624ae6985c0b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>asech</name>
      <anchorfile>group__plf__asech.html</anchorfile>
      <anchor>ga99313b04dd90c0e4b99898bd9adff2d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>asin</name>
      <anchorfile>group__plf__asin.html</anchorfile>
      <anchor>gac33460dcd2548f05618f163aa6b8f447</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>asinh</name>
      <anchorfile>group__plf__asinh.html</anchorfile>
      <anchor>gac6517fdf90349f548ef51ecab16a7da2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>atan</name>
      <anchorfile>group__plf__atan.html</anchorfile>
      <anchor>ga786c4561195e6d5b68b02db954d79f3f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>atan2</name>
      <anchorfile>group__plf__atan2.html</anchorfile>
      <anchor>ga7620db80392919b6ae699eeec18fe979</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>atanh</name>
      <anchorfile>group__plf__atanh.html</anchorfile>
      <anchor>ga1a41e219730981cadf767bbd10cec87f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>average</name>
      <anchorfile>group__plf__average.html</anchorfile>
      <anchor>gad514388c4bd4fe58d50e53e426d62140</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>bitincrement</name>
      <anchorfile>group__plf__bitincrement.html</anchorfile>
      <anchor>ga8fa056d215485ffdb11c9e151f307df0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>catalan</name>
      <anchorfile>group__plf__catalan.html</anchorfile>
      <anchor>gaee63e6e9e1962dca40c5cde1b52ab905</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>cbrt</name>
      <anchorfile>group__plf__cbrt.html</anchorfile>
      <anchor>gaa0cc19fbc27cb06fc0f81bb87148fd2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>cbrt_pi</name>
      <anchorfile>group__plf__cbrt__pi.html</anchorfile>
      <anchor>gaba67a1ce281a6722928fcdbe6d037f60</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>ceil</name>
      <anchorfile>group__plf__ceil.html</anchorfile>
      <anchor>gacf4cc27cc53a0faf471c2610eab95e8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>chi</name>
      <anchorfile>group__plf__chi.html</anchorfile>
      <anchor>ga352e6ca52f4beeae5effd0cdf7325247</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>clamp</name>
      <anchorfile>group__plf__clamp.html</anchorfile>
      <anchor>gaf3b6e14fd2890b610b24438a70b5ba87</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>convert</name>
      <anchorfile>group__plf__convert.html</anchorfile>
      <anchor>ga3596810b24bfc8fb774e184cf3c2787e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>copysign</name>
      <anchorfile>group__plf__copysign.html</anchorfile>
      <anchor>gae88e21eb3751b1d0fd7b71d288d9d1ee</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>cos</name>
      <anchorfile>group__plf__cos.html</anchorfile>
      <anchor>ga305ef58bb0ca0c9ba8819663f74e70a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>cos_1</name>
      <anchorfile>group__plf__cos__1.html</anchorfile>
      <anchor>ga9d32e0a5bf045bfbde9ac25549b2e1cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>cosh</name>
      <anchorfile>group__plf__cosh.html</anchorfile>
      <anchor>ga9c6115c7b57ba527694f481843d1edac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>cosh_1</name>
      <anchorfile>group__plf__cosh__1.html</anchorfile>
      <anchor>ga196b76f0b9a3da0eb1612216fec0adee</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>cosine_similarity</name>
      <anchorfile>group__plf__cosine__similarity.html</anchorfile>
      <anchor>gae9bf65899aaf52f81e706494a42c99d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>cot</name>
      <anchorfile>group__plf__cot.html</anchorfile>
      <anchor>gae7ab589536adafb793a86b8f4c1801e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>coth</name>
      <anchorfile>group__plf__coth.html</anchorfile>
      <anchor>gaf01f8c2e4a091896659fccc21a962290</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>covariance</name>
      <anchorfile>group__plf__covariance.html</anchorfile>
      <anchor>ga849d694549afbbd8308f3509f7e2c780</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>csc</name>
      <anchorfile>group__plf__csc.html</anchorfile>
      <anchor>ga0ec9ae5e0635c4e001edd52b8688c190</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>csch</name>
      <anchorfile>group__plf__csch.html</anchorfile>
      <anchor>ga4f7c3e54da1f4dd5c0a97722dd4f56ed</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>cumfun</name>
      <anchorfile>group__plf__cumfun.html</anchorfile>
      <anchor>gad9ed275f6b6e77db5325c3893e933ef6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>cumprod</name>
      <anchorfile>group__plf__cumprod.html</anchorfile>
      <anchor>gaead0ce36438cf8108b2bf0997ff6e4f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>cumsum</name>
      <anchorfile>group__plf__cumsum.html</anchorfile>
      <anchor>ga431cf7d6555dc450704863dd522499b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>dec</name>
      <anchorfile>group__plf__dec.html</anchorfile>
      <anchor>ga21dc299efb61f8ae4924e3fb0b953f7c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>dekker_prod</name>
      <anchorfile>group__plf__dekker__prod.html</anchorfile>
      <anchor>ga1a41dc23e01e636ab69b39a3238a893f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>diff</name>
      <anchorfile>group__plf__diff.html</anchorfile>
      <anchor>ga197b906315ce84f0c78181a9314c0988</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr unsigned int</type>
      <name>dimension_v</name>
      <anchorfile>group__traits.html</anchorfile>
      <anchor>ga846021636ff96cc73a58d2f664e7ce1f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>dist</name>
      <anchorfile>group__plf__dist.html</anchorfile>
      <anchor>ga31aaafd7f21c599693e7a2fd6533e315</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>div</name>
      <anchorfile>group__plf__div.html</anchorfile>
      <anchor>gad96f947d70b23427a0305b9998aad337</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>div_180</name>
      <anchorfile>group__plf__div__180.html</anchorfile>
      <anchor>gad588675f0e3b67228f703e4729b95996</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>dot</name>
      <anchorfile>group__plf__dot.html</anchorfile>
      <anchor>gaf5ce77de394a85c44e05c7f96215fc27</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>effective_mantissa_bits</name>
      <anchorfile>group__plf__effective__mantissa__bits.html</anchorfile>
      <anchor>gac4277864eeceb38de7a3e18e4f329337</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>egamma</name>
      <anchorfile>group__plf__egamma.html</anchorfile>
      <anchor>gab41420b093b23cbda01fe8617f29e5cb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>eps</name>
      <anchorfile>group__plf__eps.html</anchorfile>
      <anchor>gacd69b768b1e3278712c5dd2b3cd7b58c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>epsilon</name>
      <anchorfile>group__plf__epsilon.html</anchorfile>
      <anchor>gac68d4fa443f186a4893bda40bdadcd39</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>euler</name>
      <anchorfile>group__plf__euler.html</anchorfile>
      <anchor>ga307c6361163f5ebe3b6a3c7ca0472da8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>exp</name>
      <anchorfile>group__plf__exp.html</anchorfile>
      <anchor>gab8e08b05daa3ee86e2ed652a07352d64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>exp10</name>
      <anchorfile>group__plf__exp10.html</anchorfile>
      <anchor>gab2d4aa80b5aa4a96f314f3e94932f28c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>exp2</name>
      <anchorfile>group__plf__exp2.html</anchorfile>
      <anchor>gaec8099077dd346085e88919e08513d84</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>exp2n</name>
      <anchorfile>group__plf__exp2n.html</anchorfile>
      <anchor>ga9c7c797f076bcdb2062d2bd3205bb325</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>exp_pi</name>
      <anchorfile>group__plf__exp__pi.html</anchorfile>
      <anchor>ga6fa3edda699d41702f6c3daca8202d6a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>expm1</name>
      <anchorfile>group__plf__expm1.html</anchorfile>
      <anchor>ga6b355641ddbdb7ec0d1daa0bcf7be425</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>exponent</name>
      <anchorfile>group__core__internal.html</anchorfile>
      <anchor>ga60713c93ccdf574a916e2c96eede7018</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>fam</name>
      <anchorfile>group__plf__fam.html</anchorfile>
      <anchor>ga901d4b061ed59463f25ab684e7707f35</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>floor</name>
      <anchorfile>group__plf__floor.html</anchorfile>
      <anchor>gabaa3043614b3644380404814e6718a87</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>fma</name>
      <anchorfile>group__plf__fma.html</anchorfile>
      <anchor>gafe2539e930df632442830952eafe983f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>fmod</name>
      <anchorfile>group__plf__fmod.html</anchorfile>
      <anchor>ga1e5b90cb087d254f8741482c0e894594</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>fms</name>
      <anchorfile>group__plf__fms.html</anchorfile>
      <anchor>ga528f7b968ee1663dd96dcbf976e96491</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>fnma</name>
      <anchorfile>group__plf__fnma.html</anchorfile>
      <anchor>ga5b4600c48a905e3808b32a9441a6d19d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>fnms</name>
      <anchorfile>group__plf__fnms.html</anchorfile>
      <anchor>ga820c60b72b131ea41f424290e4777842</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>four_minus_pi</name>
      <anchorfile>group__plf__four__minus__pi.html</anchorfile>
      <anchor>ga54faf31f647165ae47e3a880e23d5d3f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>four_pio_3</name>
      <anchorfile>group__plf__four__pio__3.html</anchorfile>
      <anchor>gaf5af972a1c9b8ba32015011e7462f64f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>frac</name>
      <anchorfile>group__plf__frac.html</anchorfile>
      <anchor>ga6cbff9063806f25141fbe0f5863becae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>frexp</name>
      <anchorfile>group__plf__frexp.html</anchorfile>
      <anchor>ga89334551f0d0c2f81bf852d2a0b9f502</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>fsm</name>
      <anchorfile>group__plf__fsm.html</anchorfile>
      <anchor>gab6ffa7b2b7b589bc9bbf790c8555e7f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>gd</name>
      <anchorfile>group__plf__gd.html</anchorfile>
      <anchor>ga7a370ae4843d70f50869cb0d54eb2e85</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>geommean</name>
      <anchorfile>group__plf__geommean.html</anchorfile>
      <anchor>ga94e49091e938d9924175ca01e67a974e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>half</name>
      <anchorfile>group__plf__half.html</anchorfile>
      <anchor>gafdc7f58bede6debd2ef66a4b3521cb84</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>harmmean</name>
      <anchorfile>group__plf__harmmean.html</anchorfile>
      <anchor>ga1a9ee49f483a6bc0728c30b0ecdb500d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>heaviside</name>
      <anchorfile>group__plf__heaviside.html</anchorfile>
      <anchor>gaacc157e51d44695e50b1e1af7643abc0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>hi</name>
      <anchorfile>group__plf__hi.html</anchorfile>
      <anchor>ga85fa850c93bf943fe9e434de3552293d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>horner</name>
      <anchorfile>group__plf__horner.html</anchorfile>
      <anchor>gae998e94f32f326d4c67342e2ceb35982</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>hypot</name>
      <anchorfile>group__plf__hypot.html</anchorfile>
      <anchor>gab1d383e91204c25060d9e6f3f68fac0b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>if_else</name>
      <anchorfile>group__plf__if__else.html</anchorfile>
      <anchor>gafb741bdffc03f40d05b112ff6c893e7c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>inc</name>
      <anchorfile>group__plf__inc.html</anchorfile>
      <anchor>gad3d7ea17362a2244fb6ec0ca2d5a78e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>inf</name>
      <anchorfile>group__plf__inf.html</anchorfile>
      <anchor>ga17a6561e33fcb9f3bf0be566ca5751f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>inv_2pi</name>
      <anchorfile>group__plf__inv__2pi.html</anchorfile>
      <anchor>ga44c0709faa879e32e2cc9ccbd5d2d999</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>inv_e</name>
      <anchorfile>group__plf__inv__e.html</anchorfile>
      <anchor>gadfc4db657908ea0e29851034a825b058</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>inv_pi</name>
      <anchorfile>group__plf__inv__pi.html</anchorfile>
      <anchor>ga8c20889a18fc8b1d8e5b40960a0c104d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>invcbrt_pi</name>
      <anchorfile>group__plf__invcbrt__pi.html</anchorfile>
      <anchor>ga3821c8d6cf74a9a66a893f37c4f82139</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>inveps</name>
      <anchorfile>group__plf__inveps.html</anchorfile>
      <anchor>gae1bef0c184e2dead4007764d4e821835</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>invlog_10</name>
      <anchorfile>group__plf__invlog__10.html</anchorfile>
      <anchor>gae5ba2e8a8ea4d88c2799dcdf8424f574</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>invlog_2</name>
      <anchorfile>group__plf__invlog__2.html</anchorfile>
      <anchor>ga558ed10477a5c340a720e2ea3866327c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_bit_equal</name>
      <anchorfile>group__plf__is__bit__equal.html</anchorfile>
      <anchor>ga15e2026fc3252509ad69742f7daf0682</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_denormal</name>
      <anchorfile>group__plf__is__denormal.html</anchorfile>
      <anchor>ga3b8438957e33ee0ee5b3ab2508aa72ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_eqmz</name>
      <anchorfile>group__plf__is__eqmz.html</anchorfile>
      <anchor>ga1a258750e54fc736597fa9439bea340f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_eqpz</name>
      <anchorfile>group__plf__is__eqpz.html</anchorfile>
      <anchor>ga1d3c7d7b9441ebc3115872893b1f35a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_equal</name>
      <anchorfile>group__plf__is__equal.html</anchorfile>
      <anchor>gaa3f884f1bd114c09949fb5d4e1af9876</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_eqz</name>
      <anchorfile>group__plf__is__eqz.html</anchorfile>
      <anchor>ga4d8c8308d3b4bba663bb237a195b27a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_even</name>
      <anchorfile>group__plf__is__even.html</anchorfile>
      <anchor>gabfa4b5248f0e3f16859f471e7445a0ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_finite</name>
      <anchorfile>group__plf__is__finite.html</anchorfile>
      <anchor>ga51a63988bfb6162220cd95bcf37af748</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_flint</name>
      <anchorfile>group__plf__is__flint.html</anchorfile>
      <anchor>ga72a296047ea9f24dc1438e3a1161e58b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_gez</name>
      <anchorfile>group__plf__is__gez.html</anchorfile>
      <anchor>ga2a265c7a54226e24c82cd97ef610c7e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_greater</name>
      <anchorfile>group__plf__is__greater.html</anchorfile>
      <anchor>ga1a413faf72a8ca404c5445c18660b038</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_greater_equal</name>
      <anchorfile>group__plf__is__greater__equal.html</anchorfile>
      <anchor>ga97645462f4430d66d0da2a93a1b2f37d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_gtz</name>
      <anchorfile>group__plf__is__gtz.html</anchorfile>
      <anchor>gabd560b7b077896323ee38940ef5a3583</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_infinite</name>
      <anchorfile>group__plf__is__infinite.html</anchorfile>
      <anchor>gae4511a6a87e546c2fa45b2483a26cbd2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_less</name>
      <anchorfile>group__plf__is__less.html</anchorfile>
      <anchor>gaeb3a722d8086ab0090707c53e2058c3d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_less_equal</name>
      <anchorfile>group__plf__is__less__equal.html</anchorfile>
      <anchor>ga288303686db135dde311d78d6ebcc103</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_lessgreater</name>
      <anchorfile>group__plf__is__lessgreater.html</anchorfile>
      <anchor>ga93c70fd4967b9569ea28724a993369be</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_lez</name>
      <anchorfile>group__plf__is__lez.html</anchorfile>
      <anchor>gad212f44157bf7a494a02cdc8e2cb01b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_ltz</name>
      <anchorfile>group__plf__is__ltz.html</anchorfile>
      <anchor>ga62ddb7af573f49058eba0f222072310a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_minf</name>
      <anchorfile>group__plf__is__minf.html</anchorfile>
      <anchor>gab77d212b376f19f9172c3741d6b2df35</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_nan</name>
      <anchorfile>group__plf__is__nan.html</anchorfile>
      <anchor>ga1db11a0b9a18822ffe41043c38cc80c3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_negative</name>
      <anchorfile>group__plf__is__negative.html</anchorfile>
      <anchor>ga5b1a93ce270f1b01560e0007b998ea73</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_nemz</name>
      <anchorfile>group__plf__is__nemz.html</anchorfile>
      <anchor>gab196817aaa41a88c58ed791c715b0350</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_nepz</name>
      <anchorfile>group__plf__is__nepz.html</anchorfile>
      <anchor>ga588f3519dcd992829d6060db0b2dd0b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_nez</name>
      <anchorfile>group__plf__is__nez.html</anchorfile>
      <anchor>ga1e4d7cd895471d034bfab1d93130be54</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_ngez</name>
      <anchorfile>group__plf__is__ngez.html</anchorfile>
      <anchor>ga4299f6d8bf5e48900d92af1371735d2f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_ngtz</name>
      <anchorfile>group__plf__is__ngtz.html</anchorfile>
      <anchor>ga1012d9d76ecb23bf85402fea5b7719ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_nlez</name>
      <anchorfile>group__plf__is__nlez.html</anchorfile>
      <anchor>ga78f7c97500b38f86a7a63242368aae2c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_nltz</name>
      <anchorfile>group__plf__is__nltz.html</anchorfile>
      <anchor>gae2a0761ccbc5a9fe472f2f5c14a8fcd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_normalized</name>
      <anchorfile>group__plf__is__normalized.html</anchorfile>
      <anchor>ga113b95e7d3065357cea2e7278e16b167</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_denormal</name>
      <anchorfile>group__plf__is__not__denormal.html</anchorfile>
      <anchor>ga315ab6ec01496d96b325d266be09767f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_equal</name>
      <anchorfile>group__plf__is__not__equal.html</anchorfile>
      <anchor>gaed9f3b4229041da1ac2a2070db903277</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_finite</name>
      <anchorfile>group__plf__is__not__finite.html</anchorfile>
      <anchor>ga63749142d53ad0d040659d8d4cffee74</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_flint</name>
      <anchorfile>group__plf__is__not__flint.html</anchorfile>
      <anchor>ga42ae7e20907bd55debe6262ff5ea78f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_greater</name>
      <anchorfile>group__plf__is__not__greater.html</anchorfile>
      <anchor>ga2717687d1b7470024cd67a978c7b42b3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_greater_equal</name>
      <anchorfile>group__plf__is__not__greater__equal.html</anchorfile>
      <anchor>gabe0e10750aea5fdf460f4c56f46d84c9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_infinite</name>
      <anchorfile>group__plf__is__not__infinite.html</anchorfile>
      <anchor>gad3cf2c8f13b83ffed9f1b2924a8a8529</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_less</name>
      <anchorfile>group__plf__is__not__less.html</anchorfile>
      <anchor>gacad2e09ee75c713a87065f75a2a18c64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_less_equal</name>
      <anchorfile>group__plf__is__not__less__equal.html</anchorfile>
      <anchor>gac10cc53f0009c90aa0a206f346e21cee</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_not_nan</name>
      <anchorfile>group__plf__is__not__nan.html</anchorfile>
      <anchor>ga64a07f1dd60b6e1409442078cc039a42</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_odd</name>
      <anchorfile>group__plf__is__odd.html</anchorfile>
      <anchor>ga455e06a0df2a0068637f251becfbb944</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_ordered</name>
      <anchorfile>group__plf__is__ordered.html</anchorfile>
      <anchor>ga7c90ae517c18bab6325f49cce61f4edf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_pinf</name>
      <anchorfile>group__plf__is__pinf.html</anchorfile>
      <anchor>gaff62e2a7284c69e0b8c388e70ad2e066</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_positive</name>
      <anchorfile>group__plf__is__positive.html</anchorfile>
      <anchor>ga382498c379928168e37005f38a9b8eaf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_pow2</name>
      <anchorfile>group__plf__is__pow2.html</anchorfile>
      <anchor>gaf77de37071bc9885bab1dc8d8bb235b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_unit</name>
      <anchorfile>group__plf__is__unit.html</anchorfile>
      <anchor>gae00ac1ff95cdeca72e526d70cc419e51</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>is_unordered</name>
      <anchorfile>group__plf__is__unordered.html</anchorfile>
      <anchor>ga46fff13f9c73cf8cdbe1ed78f4083f65</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>kolmmean</name>
      <anchorfile>group__plf__kolmmean.html</anchorfile>
      <anchor>gacc494abd22af242970d010990f088ede</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>ldexp</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>gaaafb5f51797ebd81c0fdc1011e0275a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>ldexpb</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga7d76dbaf783e2205873c423084100a3b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>lerp</name>
      <anchorfile>group__plf__lerp.html</anchorfile>
      <anchor>ga8875d0b61cf3fbeeaa6ed18b29e5ca9f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>lo</name>
      <anchorfile>group__plf__lo.html</anchorfile>
      <anchor>ga986719f5a39d352e01286ab52b9a54ff</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>log</name>
      <anchorfile>group__plf__log.html</anchorfile>
      <anchor>ga39d37d0f777a93ba32640c56565e2710</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>log10</name>
      <anchorfile>group__plf__log10.html</anchorfile>
      <anchor>gaae901ccc06c7a5efa0242e5fcd654bd4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>log1p</name>
      <anchorfile>group__plf__log1p.html</anchorfile>
      <anchor>ga94a26247473867f18517eb7d654b9f5a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>log2</name>
      <anchorfile>group__plf__log2.html</anchorfile>
      <anchor>ga74fe53ba9509c1894684a4fe92865d07</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>log_10</name>
      <anchorfile>group__plf__log__10.html</anchorfile>
      <anchor>ga7d0a5181eb3193505a5be468ade48d62</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>log_2</name>
      <anchorfile>group__plf__log__2.html</anchorfile>
      <anchor>gab076b85673ceedd01180cae08b3b984e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>log_abs</name>
      <anchorfile>group__plf__log__abs.html</anchorfile>
      <anchor>ga74e89d74258edc3ffa690b970ce0519d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>logeps</name>
      <anchorfile>group__plf__logeps.html</anchorfile>
      <anchor>gad27792bcc40b8ac1693bacbd95570d68</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>logspace_add</name>
      <anchorfile>group__plf__logspace__add.html</anchorfile>
      <anchor>ga0a1e0bab561000aa41ed2f5142cb9c37</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>logspace_sub</name>
      <anchorfile>group__plf__logspace__sub.html</anchorfile>
      <anchor>gac6e8817a750645f722883e1b8f7d319d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>lpnorm</name>
      <anchorfile>group__plf__lpnorm.html</anchorfile>
      <anchor>ga0b35ba464177d39b675aebaae393d1e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>mantissa</name>
      <anchorfile>group__plf__mantissa.html</anchorfile>
      <anchor>ga592c5eb0fdeb82b41dd07a2ddc48dd6e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>max</name>
      <anchorfile>group__plf__max.html</anchorfile>
      <anchor>ga1d6b7e84a59f51f3fdeab89704ce3bb1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>maxabs</name>
      <anchorfile>group__plf__maxabs.html</anchorfile>
      <anchor>ga943ef8abb2c09066d89722a3ea69c78c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>maxexponent</name>
      <anchorfile>group__plf__maxexponent.html</anchorfile>
      <anchor>ga2657732c3d32e5f7ebf52928cc7e77d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>maxexponentm1</name>
      <anchorfile>group__plf__maxexponentm1.html</anchorfile>
      <anchor>ga9a853f802e2e8048694dadfbf66109b3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>maxexponentp1</name>
      <anchorfile>group__plf__maxexponentp1.html</anchorfile>
      <anchor>ga41487618f4587a15ff32960dd2f94945</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>maxflint</name>
      <anchorfile>group__plf__maxflint.html</anchorfile>
      <anchor>gae321346f90402e1b5dc7875054e49a83</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>maxlog</name>
      <anchorfile>group__plf__maxlog.html</anchorfile>
      <anchor>gaa7847ac49cf7e5db7ff5ecdd7edd9268</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>maxlog2</name>
      <anchorfile>group__plf__maxlog2.html</anchorfile>
      <anchor>ga64fcae751fc85c4ea13187127deb5ab7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>maxmag</name>
      <anchorfile>group__plf__maxmag.html</anchorfile>
      <anchor>gaee2e0eb2ad65678b921da8c2b4de631e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>md</name>
      <anchorfile>group__plf__md.html</anchorfile>
      <anchor>ga0745f202e4af71621d3f5e84e37c6abe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>mhalf</name>
      <anchorfile>group__plf__mhalf.html</anchorfile>
      <anchor>gacf3b52a44982c70d2b2b7a11531beee3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>min</name>
      <anchorfile>group__plf__min.html</anchorfile>
      <anchor>gaf2ecab0082e8fa1007d5ea49c9fa1a87</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>minabs</name>
      <anchorfile>group__plf__minabs.html</anchorfile>
      <anchor>gaa190c10bef44628e4701ff2fcd6728a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>mindenormal</name>
      <anchorfile>group__plf__mindenormal.html</anchorfile>
      <anchor>ga0a3e5881bfb4a0de7977621996c339a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>minexponent</name>
      <anchorfile>group__plf__minexponent.html</anchorfile>
      <anchor>ga4647ba96a04ee2f05047b93c70509bd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>minf</name>
      <anchorfile>group__plf__minf.html</anchorfile>
      <anchor>ga53eeee70008790007d0da7e69ad152e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>minmag</name>
      <anchorfile>group__plf__minmag.html</anchorfile>
      <anchor>ga3edebc887d62d202367258c76f7a1a7f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>minmax</name>
      <anchorfile>group__plf__minmax.html</anchorfile>
      <anchor>ga830c684d59f4722059bef14bb7f92da2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>minus</name>
      <anchorfile>group__plf__minus.html</anchorfile>
      <anchor>gae33d4d1bd5488f7aed156cd106f4ce74</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>modf</name>
      <anchorfile>group__plf__modf.html</anchorfile>
      <anchor>gaf07ed2a608fc290c474c9baaa296fc76</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>mone</name>
      <anchorfile>group__plf__mone.html</anchorfile>
      <anchor>gafd51d660d060685287a61ceb9a0619c5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>mul</name>
      <anchorfile>group__plf__mul.html</anchorfile>
      <anchor>ga856a221cd309873711b978ce55df4635</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>mul_pi</name>
      <anchorfile>group__plf__mul__pi.html</anchorfile>
      <anchor>gab8f950f821aa3dda14dc737d30564599</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>mzero</name>
      <anchorfile>group__plf__mzero.html</anchorfile>
      <anchor>ga889a98f4b2269954d9c5326e07ffdd9f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>nan</name>
      <anchorfile>group__plf__nan.html</anchorfile>
      <anchor>gab815a9e20ea8d0c215108a23413f0347</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>nbmantissabits</name>
      <anchorfile>group__plf__nbmantissabits.html</anchorfile>
      <anchor>ga353f26b1179c82267a8066987951a553</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>nearest</name>
      <anchorfile>group__plf__nearest.html</anchorfile>
      <anchor>ga1c1e5e03fa7f21ea1a74311813762197</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>negabsmax</name>
      <anchorfile>group__plf__negabsmax.html</anchorfile>
      <anchor>ga54e69f527759113beefec446c9c8f7de</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>negabsmin</name>
      <anchorfile>group__plf__negabsmin.html</anchorfile>
      <anchor>ga519b13d3f054b319b6ef5e59eb029a47</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>negate</name>
      <anchorfile>group__plf__negate.html</anchorfile>
      <anchor>ga0b77fce5aa260a3629bed972eee3ba39</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>negatenz</name>
      <anchorfile>group__plf__negatenz.html</anchorfile>
      <anchor>gacb0784fa93d2122cec99faf7a9760daa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>negmaxabs</name>
      <anchorfile>group__plf__negmaxabs.html</anchorfile>
      <anchor>ga0ddb4ae3b0954209eca0c7257d166dbc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>negminabs</name>
      <anchorfile>group__plf__negminabs.html</anchorfile>
      <anchor>gace9b23e8f34fdc09478d8901078f1bb6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>neville</name>
      <anchorfile>group__plf__neville.html</anchorfile>
      <anchor>gada98330f63111f37aa310dcb450fb2aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>next</name>
      <anchorfile>group__plf__next.html</anchorfile>
      <anchor>ga60c7f280243a468485f42421a2c06739</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>nextafter</name>
      <anchorfile>group__plf__nextafter.html</anchorfile>
      <anchor>ga09f396a43b0cf65385e8a586a2b410e9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>nextint</name>
      <anchorfile>group__plf__nextint.html</anchorfile>
      <anchor>gaf1c232d7bc7f81fc1a42edb3c7b7cd88</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>nthroot</name>
      <anchorfile>group__plf__nthroot.html</anchorfile>
      <anchor>ga51f47a92f62d391bf10c55c304a691da</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>one</name>
      <anchorfile>group__plf__one.html</anchorfile>
      <anchor>gaf4a21d2a045aedd47efa31fcc8be1fcf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>oneminus</name>
      <anchorfile>group__plf__oneminus.html</anchorfile>
      <anchor>gaffe46da86ea6a171bb1de5203b24334a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>oneo_180</name>
      <anchorfile>group__plf__oneo__180.html</anchorfile>
      <anchor>gaa48483e2def333b32d0921c7622caa11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>oneosqrteps</name>
      <anchorfile>group__plf__oneosqrteps.html</anchorfile>
      <anchor>gaf37d435e94d94585ba4b0848c520316b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>pi</name>
      <anchorfile>group__plf__pi.html</anchorfile>
      <anchor>gab9b05ae205213ff9eb38c22b9f777eb4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>pio_2</name>
      <anchorfile>group__plf__pio__2.html</anchorfile>
      <anchor>ga4f050d319a737624f6fda3edc2f10d64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>pio_3</name>
      <anchorfile>group__plf__pio__3.html</anchorfile>
      <anchor>ga6474fff2fbfd3debcb1e6c08bc6b8e70</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>pio_4</name>
      <anchorfile>group__plf__pio__4.html</anchorfile>
      <anchor>ga2833089ea102010508589ab0a7c62ae5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>pio_6</name>
      <anchorfile>group__plf__pio__6.html</anchorfile>
      <anchor>ga3a5657d9a62ca57b93cff8f720aae898</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>pow</name>
      <anchorfile>group__plf__pow.html</anchorfile>
      <anchor>ga2ac39d06d5a669c537c5aef7e888ea47</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>pow1p</name>
      <anchorfile>group__plf__pow1p.html</anchorfile>
      <anchor>gac514868a7f61ecfeedf6a22db91aa304</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>pow_abs</name>
      <anchorfile>group__plf__pow__abs.html</anchorfile>
      <anchor>gae9f28b8422733a3ec084b057c4963b8d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>powm1</name>
      <anchorfile>group__plf__powm1.html</anchorfile>
      <anchor>ga81c3266b93996cf7e50e86c058c69674</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>pown</name>
      <anchorfile>group__plf__pown.html</anchorfile>
      <anchor>ga3309e6018e6235033a2877c0d9eece8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>prev</name>
      <anchorfile>group__plf__prev.html</anchorfile>
      <anchor>ga3e945bcc637ae4a744f512275949fe82</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>prevint</name>
      <anchorfile>group__plf__prevint.html</anchorfile>
      <anchor>ga4bf8537407a460e745d9df6f37fac5f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>quadrant</name>
      <anchorfile>group__plf__quadrant.html</anchorfile>
      <anchor>ga01ac2266639f9cb05ad11ced1a4e0619</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>rad2deg</name>
      <anchorfile>group__plf__rad2deg.html</anchorfile>
      <anchor>gade6dc8cc08c7e513fa33b5c461d449a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>radindeg</name>
      <anchorfile>group__plf__radindeg.html</anchorfile>
      <anchor>ga9296f6efaa1e2f591284ffe5c46e0b11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>radinpi</name>
      <anchorfile>group__plf__radinpi.html</anchorfile>
      <anchor>ga7c6799944109d3ef28d44e8c65d46ccf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>rat</name>
      <anchorfile>group__plf__rat.html</anchorfile>
      <anchor>gae7854c4bf7224d75816c16d3141b868c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>rec</name>
      <anchorfile>group__plf__rec.html</anchorfile>
      <anchor>ga38ee18ae42971becb7275f6596ada180</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>reldist</name>
      <anchorfile>group__plf__reldist.html</anchorfile>
      <anchor>ga46f13916d7af01b5f6c1f880d13e2ed4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>rem</name>
      <anchorfile>group__plf__rem.html</anchorfile>
      <anchor>gaba27d496c09e7ef0892b23806956a840</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>remainder</name>
      <anchorfile>group__plf__remainder.html</anchorfile>
      <anchor>ga501d3d6d436d40d647f290fce53b5bf9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>reverse_horner</name>
      <anchorfile>group__plf__reverse__horner.html</anchorfile>
      <anchor>gaec0903d03ecaa41fc2f06bd4d9598fbe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>round</name>
      <anchorfile>group__plf__round.html</anchorfile>
      <anchor>ga94fa0cf071f9760d3b0ba4d9c3b86170</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>roundscale</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga7e269986153d615f074a5497e163999a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>rsqrt</name>
      <anchorfile>group__plf__rsqrt.html</anchorfile>
      <anchor>ga6b68af3438bb67d5a0ac3634a01fd610</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sec</name>
      <anchorfile>group__plf__sec.html</anchorfile>
      <anchor>ga7df98fd9e56c73c6cfc8ab445879d514</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sech</name>
      <anchorfile>group__plf__sech.html</anchorfile>
      <anchor>ga682c42c12657647392743320cfde271a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sigmoid</name>
      <anchorfile>group__plf__sigmoid.html</anchorfile>
      <anchor>gab9a23ada2593afbfcb3adc93c5be697a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sign</name>
      <anchorfile>group__plf__sign.html</anchorfile>
      <anchor>ga71f110b670810f9e0e3ee1b5745a37a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sign_alternate</name>
      <anchorfile>group__plf__sign__alternate.html</anchorfile>
      <anchor>ga564e4bc99fc8f5704fae107a5f83e847</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>signnz</name>
      <anchorfile>group__plf__signnz.html</anchorfile>
      <anchor>gaa1b1663acb0eb4bbc16fd9beb3dff197</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sin</name>
      <anchorfile>group__plf__sin.html</anchorfile>
      <anchor>gaf5e77c3acf98245222c45029d7ad486d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sinc</name>
      <anchorfile>group__plf__sinc.html</anchorfile>
      <anchor>gaf483ad7b861bf6d4966000ac0dfe1bc2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sincos</name>
      <anchorfile>group__plf__sincos.html</anchorfile>
      <anchor>gae73a40c7a5d33fd5e75dc8fda06ecbc7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sinh</name>
      <anchorfile>group__plf__sinh.html</anchorfile>
      <anchor>gab98365d8cb868ac99d97f9d0297fedfa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sinhcosh</name>
      <anchorfile>group__plf__sinhcosh.html</anchorfile>
      <anchor>ga02d2b89a953909ef1283cb5847c2054a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>smallestposval</name>
      <anchorfile>group__plf__smallestposval.html</anchorfile>
      <anchor>ga1089f4e0a6091f3da50a5c7655ec3643</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sqr</name>
      <anchorfile>group__plf__sqr.html</anchorfile>
      <anchor>gac72a278d06c43be14dce2cfbd8e67bdf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sqrt</name>
      <anchorfile>group__plf__sqrt.html</anchorfile>
      <anchor>gab25eb1782219136d8368a2a090bcac77</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sqrt_2</name>
      <anchorfile>group__plf__sqrt__2.html</anchorfile>
      <anchor>ga4242d1daac24e1aa6e29ce62d230d171</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sqrteps</name>
      <anchorfile>group__plf__sqrteps.html</anchorfile>
      <anchor>ga193389bdf9378b4f1ab19e1ed49a52a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sqrtvalmax</name>
      <anchorfile>group__plf__sqrtvalmax.html</anchorfile>
      <anchor>ga5b01112179d17efdb5be43518c0e0669</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sub</name>
      <anchorfile>group__plf__sub.html</anchorfile>
      <anchor>ga9d647eeb7803da2f5dc1d1c646e22799</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sum_of_prod</name>
      <anchorfile>group__plf__sum__of__prod.html</anchorfile>
      <anchor>ga00467d77659f76768d9798485cbbd3cf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>sum_of_squares</name>
      <anchorfile>group__plf__sum__of__squares.html</anchorfile>
      <anchor>ga2dd0aca7295af7318c56063bd90f0730</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>tan</name>
      <anchorfile>group__plf__tan.html</anchorfile>
      <anchor>ga20c0ba81f757e6afeaf8489e4a7b9099</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>tanh</name>
      <anchorfile>group__plf__tanh.html</anchorfile>
      <anchor>ga5e44e8b5b54edaf7a95210528073e01b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>three_add</name>
      <anchorfile>group__plf__three__add.html</anchorfile>
      <anchor>gad714fdd7a5f3a2cfcab70658cb520cd1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>three_fma</name>
      <anchorfile>group__plf__three__fma.html</anchorfile>
      <anchor>gabda6529346e0ae007b7709fabfe7cb59</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>three_pio_4</name>
      <anchorfile>group__plf__three__pio__4.html</anchorfile>
      <anchor>gae924ebd3b979c867f7a19b8b4d4ae57b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>trunc</name>
      <anchorfile>group__plf__trunc.html</anchorfile>
      <anchor>ga9aa5715fd56663843e5d34d9e3904338</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>two_add</name>
      <anchorfile>group__plf__two__add.html</anchorfile>
      <anchor>ga4f331a5f0e10706ede78c9ac753d6ef4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>two_div_approx</name>
      <anchorfile>group__plf__two__div__approx.html</anchorfile>
      <anchor>gab1a360af3bf67971c24e0b8c94ff4c1c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>two_fma_approx</name>
      <anchorfile>group__plf__two__fma__approx.html</anchorfile>
      <anchor>gae79e44f7a860ba7c33be885213090df1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>two_prod</name>
      <anchorfile>group__plf__two__prod.html</anchorfile>
      <anchor>gae8d597dabc4dc057e3110c0a89afe8f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>two_split</name>
      <anchorfile>group__plf__two__split.html</anchorfile>
      <anchor>ga9086f4afc7e04d20a2a3bf8212dc677a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>ulp</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga74d8d2b14e149dc9b687e324a7392700</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>ulpdist</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga5bd18a9ff38290ea3898b40b5a212395</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>valmax</name>
      <anchorfile>group__plf__valmax.html</anchorfile>
      <anchor>ga107149eec536df23c4386d025b854ecf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>valmin</name>
      <anchorfile>group__plf__valmin.html</anchorfile>
      <anchor>gafce94c0fcb7990527f77886c832f2d7b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>variance</name>
      <anchorfile>group__plf__variance.html</anchorfile>
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
      <anchorfile>structplf_1_1polyfloat.html</anchorfile>
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
    <subgroup>plf_allbits</subgroup>
    <subgroup>plf_bitincrement</subgroup>
    <subgroup>plf_catalan</subgroup>
    <subgroup>plf_cbrt_pi</subgroup>
    <subgroup>plf_cos_1</subgroup>
    <subgroup>plf_cosh_1</subgroup>
    <subgroup>plf_effective_mantissa_bits</subgroup>
    <subgroup>plf_egamma</subgroup>
    <subgroup>plf_eps</subgroup>
    <subgroup>plf_euler</subgroup>
    <subgroup>plf_exp_pi</subgroup>
    <subgroup>plf_false_</subgroup>
    <subgroup>plf_four_minus_pi</subgroup>
    <subgroup>plf_four_pio_3</subgroup>
    <subgroup>plf_half</subgroup>
    <subgroup>plf_inf</subgroup>
    <subgroup>plf_inv_2pi</subgroup>
    <subgroup>plf_inv_e</subgroup>
    <subgroup>plf_inv_pi</subgroup>
    <subgroup>plf_invcbrt_pi</subgroup>
    <subgroup>plf_inveps</subgroup>
    <subgroup>plf_invlog_10</subgroup>
    <subgroup>plf_invlog_2</subgroup>
    <subgroup>plf_log_10</subgroup>
    <subgroup>plf_log_2</subgroup>
    <subgroup>plf_logeps</subgroup>
    <subgroup>plf_maxexponent</subgroup>
    <subgroup>plf_maxexponentm1</subgroup>
    <subgroup>plf_maxexponentp1</subgroup>
    <subgroup>plf_maxflint</subgroup>
    <subgroup>plf_maxlog</subgroup>
    <subgroup>plf_maxlog2</subgroup>
    <subgroup>plf_mhalf</subgroup>
    <subgroup>plf_mindenormal</subgroup>
    <subgroup>plf_minexponent</subgroup>
    <subgroup>plf_minf</subgroup>
    <subgroup>plf_mone</subgroup>
    <subgroup>plf_mzero</subgroup>
    <subgroup>plf_nan</subgroup>
    <subgroup>plf_nbmantissabits</subgroup>
    <subgroup>plf_one</subgroup>
    <subgroup>plf_oneo_180</subgroup>
    <subgroup>plf_oneosqrteps</subgroup>
    <subgroup>plf_pi</subgroup>
    <subgroup>plf_pio_2</subgroup>
    <subgroup>plf_pio_3</subgroup>
    <subgroup>plf_pio_4</subgroup>
    <subgroup>plf_pio_6</subgroup>
    <subgroup>plf_rad2deg</subgroup>
    <subgroup>plf_smallestposval</subgroup>
    <subgroup>plf_sqrt_2</subgroup>
    <subgroup>plf_sqrteps</subgroup>
    <subgroup>plf_sqrtvalmax</subgroup>
    <subgroup>plf_three_pio_4</subgroup>
    <subgroup>plf_true_</subgroup>
    <subgroup>plf_valmax</subgroup>
    <subgroup>plf_valmin</subgroup>
    <subgroup>plf_zero</subgroup>
  </compound>
  <compound kind="group">
    <name>core</name>
    <title>Core functions</title>
    <filename>group__core.html</filename>
    <subgroup>plf_abs</subgroup>
    <subgroup>plf_absmax</subgroup>
    <subgroup>plf_absmin</subgroup>
    <subgroup>plf_add</subgroup>
    <subgroup>plf_agm</subgroup>
    <subgroup>plf_average</subgroup>
    <subgroup>plf_ceil</subgroup>
    <subgroup>plf_chi</subgroup>
    <subgroup>plf_clamp</subgroup>
    <subgroup>plf_convert</subgroup>
    <subgroup>plf_copysign</subgroup>
    <subgroup>plf_cosine_similarity</subgroup>
    <subgroup>plf_covariance</subgroup>
    <subgroup>plf_cumfun</subgroup>
    <subgroup>plf_cumprod</subgroup>
    <subgroup>plf_cumsum</subgroup>
    <subgroup>plf_dec</subgroup>
    <subgroup>plf_diff</subgroup>
    <subgroup>plf_dist</subgroup>
    <subgroup>plf_div</subgroup>
    <subgroup>plf_dot</subgroup>
    <subgroup>plf_epsilon</subgroup>
    <subgroup>plf_exp2n</subgroup>
    <subgroup>plf_fam</subgroup>
    <subgroup>plf_floor</subgroup>
    <subgroup>plf_fma</subgroup>
    <subgroup>plf_fmod</subgroup>
    <subgroup>plf_fms</subgroup>
    <subgroup>plf_fnma</subgroup>
    <subgroup>plf_fnms</subgroup>
    <subgroup>plf_frac</subgroup>
    <subgroup>plf_frexp</subgroup>
    <subgroup>plf_fsm</subgroup>
    <subgroup>plf_heaviside</subgroup>
    <subgroup>plf_hi</subgroup>
    <subgroup>plf_hypot</subgroup>
    <subgroup>plf_if_else</subgroup>
    <subgroup>plf_inc</subgroup>
    <subgroup>plf_is_bit_equal</subgroup>
    <subgroup>plf_is_denormal</subgroup>
    <subgroup>plf_is_eqmz</subgroup>
    <subgroup>plf_is_eqpz</subgroup>
    <subgroup>plf_is_equal</subgroup>
    <subgroup>plf_is_eqz</subgroup>
    <subgroup>plf_is_even</subgroup>
    <subgroup>plf_is_finite</subgroup>
    <subgroup>plf_is_flint</subgroup>
    <subgroup>plf_is_gez</subgroup>
    <subgroup>plf_is_greater</subgroup>
    <subgroup>plf_is_greater_equal</subgroup>
    <subgroup>plf_is_gtz</subgroup>
    <subgroup>plf_is_infinite</subgroup>
    <subgroup>plf_is_less</subgroup>
    <subgroup>plf_is_less_equal</subgroup>
    <subgroup>plf_is_lessgreater</subgroup>
    <subgroup>plf_is_lez</subgroup>
    <subgroup>plf_is_ltz</subgroup>
    <subgroup>plf_is_minf</subgroup>
    <subgroup>plf_is_nan</subgroup>
    <subgroup>plf_is_negative</subgroup>
    <subgroup>plf_is_nemz</subgroup>
    <subgroup>plf_is_nepz</subgroup>
    <subgroup>plf_is_nez</subgroup>
    <subgroup>plf_is_ngez</subgroup>
    <subgroup>plf_is_ngtz</subgroup>
    <subgroup>plf_is_nlez</subgroup>
    <subgroup>plf_is_nltz</subgroup>
    <subgroup>plf_is_normalized</subgroup>
    <subgroup>plf_is_not_denormal</subgroup>
    <subgroup>plf_is_not_equal</subgroup>
    <subgroup>plf_is_not_finite</subgroup>
    <subgroup>plf_is_not_flint</subgroup>
    <subgroup>plf_is_not_greater</subgroup>
    <subgroup>plf_is_not_greater_equal</subgroup>
    <subgroup>plf_is_not_infinite</subgroup>
    <subgroup>plf_is_not_less</subgroup>
    <subgroup>plf_is_not_less_equal</subgroup>
    <subgroup>plf_is_not_nan</subgroup>
    <subgroup>plf_is_odd</subgroup>
    <subgroup>plf_is_ordered</subgroup>
    <subgroup>plf_is_pinf</subgroup>
    <subgroup>plf_is_positive</subgroup>
    <subgroup>plf_is_pow2</subgroup>
    <subgroup>plf_is_unit</subgroup>
    <subgroup>plf_is_unordered</subgroup>
    <subgroup>plf_lerp</subgroup>
    <subgroup>plf_lo</subgroup>
    <subgroup>plf_mantissa</subgroup>
    <subgroup>plf_max</subgroup>
    <subgroup>plf_maxabs</subgroup>
    <subgroup>plf_maxmag</subgroup>
    <subgroup>plf_md</subgroup>
    <subgroup>plf_min</subgroup>
    <subgroup>plf_minabs</subgroup>
    <subgroup>plf_minmag</subgroup>
    <subgroup>plf_minmax</subgroup>
    <subgroup>plf_minus</subgroup>
    <subgroup>plf_modf</subgroup>
    <subgroup>plf_mul</subgroup>
    <subgroup>plf_nearest</subgroup>
    <subgroup>plf_negabsmax</subgroup>
    <subgroup>plf_negabsmin</subgroup>
    <subgroup>plf_negate</subgroup>
    <subgroup>plf_negatenz</subgroup>
    <subgroup>plf_negmaxabs</subgroup>
    <subgroup>plf_negminabs</subgroup>
    <subgroup>plf_next</subgroup>
    <subgroup>plf_nextafter</subgroup>
    <subgroup>plf_nextint</subgroup>
    <subgroup>plf_oneminus</subgroup>
    <subgroup>plf_pown</subgroup>
    <subgroup>plf_prev</subgroup>
    <subgroup>plf_prevint</subgroup>
    <subgroup>plf_quadrant</subgroup>
    <subgroup>plf_rat</subgroup>
    <subgroup>plf_rec</subgroup>
    <subgroup>plf_reldist</subgroup>
    <subgroup>plf_rem</subgroup>
    <subgroup>plf_remainder</subgroup>
    <subgroup>plf_round</subgroup>
    <subgroup>plf_rsqrt</subgroup>
    <subgroup>plf_sign</subgroup>
    <subgroup>plf_sign_alternate</subgroup>
    <subgroup>plf_signnz</subgroup>
    <subgroup>plf_sqr</subgroup>
    <subgroup>plf_sqrt</subgroup>
    <subgroup>plf_sub</subgroup>
    <subgroup>plf_sum_of_prod</subgroup>
    <subgroup>plf_sum_of_squares</subgroup>
    <subgroup>plf_trunc</subgroup>
    <subgroup>plf_variance</subgroup>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::ldexp</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>gaaafb5f51797ebd81c0fdc1011e0275a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::ldexpb</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga7d76dbaf783e2205873c423084100a3b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::roundscale</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga7e269986153d615f074a5497e163999a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::ulp</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga74d8d2b14e149dc9b687e324a7392700</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::ulpdist</name>
      <anchorfile>group__core.html</anchorfile>
      <anchor>ga5bd18a9ff38290ea3898b40b5a212395</anchor>
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
      <anchorfile>group__core__internal.html</anchorfile>
      <anchor>ga60713c93ccdf574a916e2c96eede7018</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>math</name>
    <title>Elementary functions</title>
    <filename>group__math.html</filename>
    <subgroup>plf_acos</subgroup>
    <subgroup>plf_acosh</subgroup>
    <subgroup>plf_acoth</subgroup>
    <subgroup>plf_acsc</subgroup>
    <subgroup>plf_acsch</subgroup>
    <subgroup>plf_agd</subgroup>
    <subgroup>plf_arg</subgroup>
    <subgroup>plf_asec</subgroup>
    <subgroup>plf_asech</subgroup>
    <subgroup>plf_asin</subgroup>
    <subgroup>plf_asinh</subgroup>
    <subgroup>plf_atan</subgroup>
    <subgroup>plf_atan2</subgroup>
    <subgroup>plf_atanh</subgroup>
    <subgroup>plf_cbrt</subgroup>
    <subgroup>plf_cos</subgroup>
    <subgroup>plf_cosh</subgroup>
    <subgroup>plf_cot</subgroup>
    <subgroup>plf_coth</subgroup>
    <subgroup>plf_csc</subgroup>
    <subgroup>plf_csch</subgroup>
    <subgroup>plf_div_180</subgroup>
    <subgroup>plf_exp</subgroup>
    <subgroup>plf_exp10</subgroup>
    <subgroup>plf_exp2</subgroup>
    <subgroup>plf_expm1</subgroup>
    <subgroup>plf_gd</subgroup>
    <subgroup>plf_geommean</subgroup>
    <subgroup>plf_harmmean</subgroup>
    <subgroup>plf_kolmmean</subgroup>
    <subgroup>plf_log</subgroup>
    <subgroup>plf_log10</subgroup>
    <subgroup>plf_log1p</subgroup>
    <subgroup>plf_log2</subgroup>
    <subgroup>plf_log_abs</subgroup>
    <subgroup>plf_logspace_add</subgroup>
    <subgroup>plf_logspace_sub</subgroup>
    <subgroup>plf_lpnorm</subgroup>
    <subgroup>plf_mul_pi</subgroup>
    <subgroup>plf_nthroot</subgroup>
    <subgroup>plf_pow</subgroup>
    <subgroup>plf_pow1p</subgroup>
    <subgroup>plf_pow_abs</subgroup>
    <subgroup>plf_powm1</subgroup>
    <subgroup>plf_radindeg</subgroup>
    <subgroup>plf_radinpi</subgroup>
    <subgroup>plf_sec</subgroup>
    <subgroup>plf_sech</subgroup>
    <subgroup>plf_sigmoid</subgroup>
    <subgroup>plf_sin</subgroup>
    <subgroup>plf_sinc</subgroup>
    <subgroup>plf_sincos</subgroup>
    <subgroup>plf_sinh</subgroup>
    <subgroup>plf_sinhcosh</subgroup>
    <subgroup>plf_tan</subgroup>
    <subgroup>plf_tanh</subgroup>
  </compound>
  <compound kind="group">
    <name>core_accuracy</name>
    <title>Error-free transformations</title>
    <filename>group__core__accuracy.html</filename>
    <subgroup>plf_dekker_prod</subgroup>
    <subgroup>plf_three_add</subgroup>
    <subgroup>plf_three_fma</subgroup>
    <subgroup>plf_two_add</subgroup>
    <subgroup>plf_two_div_approx</subgroup>
    <subgroup>plf_two_fma_approx</subgroup>
    <subgroup>plf_two_prod</subgroup>
    <subgroup>plf_two_split</subgroup>
  </compound>
  <compound kind="group">
    <name>functions</name>
    <title>Polynomial evaluation</title>
    <filename>group__functions.html</filename>
    <subgroup>plf_horner</subgroup>
    <subgroup>plf_neville</subgroup>
    <subgroup>plf_reverse_horner</subgroup>
  </compound>
  <compound kind="group">
    <name>traits</name>
    <title>Traits</title>
    <filename>group__traits.html</filename>
    <class kind="struct">plf::as_component</class>
    <class kind="struct">plf::callable</class>
    <class kind="struct">plf::constant_callable</class>
    <class kind="struct">plf::elementwise_callable</class>
    <class kind="struct">plf::strict_tuple_callable</class>
    <member kind="typedef">
      <type>typename as_component_type&lt; T &gt;::type</type>
      <name>plf::as_component_type_t</name>
      <anchorfile>group__traits.html</anchorfile>
      <anchor>gaa325dcaa3d30c3a89c5333b2800aac54</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename as_polyfloat_n&lt; Dim, Ts... &gt;::type</type>
      <name>plf::as_polyfloat_n_t</name>
      <anchorfile>group__traits.html</anchorfile>
      <anchor>gaa65fa3ada94ae1d661001889062623b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename as_polyfloat&lt; Ts... &gt;::type</type>
      <name>plf::as_polyfloat_t</name>
      <anchorfile>group__traits.html</anchorfile>
      <anchor>gabb544245c689b7e0ea2f9f6e8feb8594</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr unsigned int</type>
      <name>plf::dimension_v</name>
      <anchorfile>group__traits.html</anchorfile>
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
      <anchorfile>group__types.html</anchorfile>
      <anchor>gad8203f72c65a6761f03db03f8ac55c61</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>as_polyfloat_n_t&lt; 3, T &gt;</type>
      <name>plf::triple_real_t</name>
      <anchorfile>group__types.html</anchorfile>
      <anchor>ga3150408863a87ad5a78978ea1eebf102</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_abs</name>
    <title>plf::abs</title>
    <filename>group__plf__abs.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::abs</name>
      <anchorfile>group__plf__abs.html</anchorfile>
      <anchor>ga69b3078b6a64e0467e0595929ca947de</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_absmax</name>
    <title>plf::absmax</title>
    <filename>group__plf__absmax.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::absmax</name>
      <anchorfile>group__plf__absmax.html</anchorfile>
      <anchor>gadd0f5df2e8971e69dd54e2b9921d04a6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_absmin</name>
    <title>plf::absmin</title>
    <filename>group__plf__absmin.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::absmin</name>
      <anchorfile>group__plf__absmin.html</anchorfile>
      <anchor>ga6b9323d57f26ce1cd555444d9b64c807</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_acos</name>
    <title>plf::acos</title>
    <filename>group__plf__acos.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::acos</name>
      <anchorfile>group__plf__acos.html</anchorfile>
      <anchor>ga16bd93f50121516a6f2321aec146b4c1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_acosh</name>
    <title>plf::acosh</title>
    <filename>group__plf__acosh.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::acosh</name>
      <anchorfile>group__plf__acosh.html</anchorfile>
      <anchor>gaed114cf184f7a06cadd10432981d3516</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_acoth</name>
    <title>plf::acoth</title>
    <filename>group__plf__acoth.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::acoth</name>
      <anchorfile>group__plf__acoth.html</anchorfile>
      <anchor>ga255478078703a5e3983f9a1f391c5807</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_acsc</name>
    <title>plf::acsc</title>
    <filename>group__plf__acsc.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::acsc</name>
      <anchorfile>group__plf__acsc.html</anchorfile>
      <anchor>ga1c3b2469b5b4a43fb08afec46d984e35</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_acsch</name>
    <title>plf::acsch</title>
    <filename>group__plf__acsch.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::acsch</name>
      <anchorfile>group__plf__acsch.html</anchorfile>
      <anchor>ga9063b9310082cd6b6ee1e38e5eb735ae</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_add</name>
    <title>plf::add</title>
    <filename>group__plf__add.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::add</name>
      <anchorfile>group__plf__add.html</anchorfile>
      <anchor>ga4d1ed930ff0fa7d990dddb01882515e6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_agd</name>
    <title>plf::agd</title>
    <filename>group__plf__agd.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::agd</name>
      <anchorfile>group__plf__agd.html</anchorfile>
      <anchor>ga825911adaa3fc328ca8780ab04b7a44b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_agm</name>
    <title>plf::agm</title>
    <filename>group__plf__agm.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::agm</name>
      <anchorfile>group__plf__agm.html</anchorfile>
      <anchor>gaaf79a031e1bb735e16389b0a19a2f3d7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_allbits</name>
    <title>plf::allbits</title>
    <filename>group__plf__allbits.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::allbits</name>
      <anchorfile>group__plf__allbits.html</anchorfile>
      <anchor>gabbd6cfcd83668ca5f081bcc515d75a59</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_arg</name>
    <title>plf::arg</title>
    <filename>group__plf__arg.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::arg</name>
      <anchorfile>group__plf__arg.html</anchorfile>
      <anchor>ga071efd467f1094e602acecb0896fd63c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_asec</name>
    <title>plf::asec</title>
    <filename>group__plf__asec.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::asec</name>
      <anchorfile>group__plf__asec.html</anchorfile>
      <anchor>ga9d81960283c44e7fcc54624ae6985c0b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_asech</name>
    <title>plf::asech</title>
    <filename>group__plf__asech.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::asech</name>
      <anchorfile>group__plf__asech.html</anchorfile>
      <anchor>ga99313b04dd90c0e4b99898bd9adff2d7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_asin</name>
    <title>plf::asin</title>
    <filename>group__plf__asin.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::asin</name>
      <anchorfile>group__plf__asin.html</anchorfile>
      <anchor>gac33460dcd2548f05618f163aa6b8f447</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_asinh</name>
    <title>plf::asinh</title>
    <filename>group__plf__asinh.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::asinh</name>
      <anchorfile>group__plf__asinh.html</anchorfile>
      <anchor>gac6517fdf90349f548ef51ecab16a7da2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_atan</name>
    <title>plf::atan</title>
    <filename>group__plf__atan.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::atan</name>
      <anchorfile>group__plf__atan.html</anchorfile>
      <anchor>ga786c4561195e6d5b68b02db954d79f3f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_atan2</name>
    <title>plf::atan2</title>
    <filename>group__plf__atan2.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::atan2</name>
      <anchorfile>group__plf__atan2.html</anchorfile>
      <anchor>ga7620db80392919b6ae699eeec18fe979</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_atanh</name>
    <title>plf::atanh</title>
    <filename>group__plf__atanh.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::atanh</name>
      <anchorfile>group__plf__atanh.html</anchorfile>
      <anchor>ga1a41e219730981cadf767bbd10cec87f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_average</name>
    <title>plf::average</title>
    <filename>group__plf__average.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::average</name>
      <anchorfile>group__plf__average.html</anchorfile>
      <anchor>gad514388c4bd4fe58d50e53e426d62140</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_bitincrement</name>
    <title>plf::bitincrement</title>
    <filename>group__plf__bitincrement.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::bitincrement</name>
      <anchorfile>group__plf__bitincrement.html</anchorfile>
      <anchor>ga8fa056d215485ffdb11c9e151f307df0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_catalan</name>
    <title>plf::catalan</title>
    <filename>group__plf__catalan.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::catalan</name>
      <anchorfile>group__plf__catalan.html</anchorfile>
      <anchor>gaee63e6e9e1962dca40c5cde1b52ab905</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_cbrt</name>
    <title>plf::cbrt</title>
    <filename>group__plf__cbrt.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::cbrt</name>
      <anchorfile>group__plf__cbrt.html</anchorfile>
      <anchor>gaa0cc19fbc27cb06fc0f81bb87148fd2b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_cbrt_pi</name>
    <title>plf::cbrt_pi</title>
    <filename>group__plf__cbrt__pi.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::cbrt_pi</name>
      <anchorfile>group__plf__cbrt__pi.html</anchorfile>
      <anchor>gaba67a1ce281a6722928fcdbe6d037f60</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_ceil</name>
    <title>plf::ceil</title>
    <filename>group__plf__ceil.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::ceil</name>
      <anchorfile>group__plf__ceil.html</anchorfile>
      <anchor>gacf4cc27cc53a0faf471c2610eab95e8c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_chi</name>
    <title>plf::chi</title>
    <filename>group__plf__chi.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::chi</name>
      <anchorfile>group__plf__chi.html</anchorfile>
      <anchor>ga352e6ca52f4beeae5effd0cdf7325247</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_clamp</name>
    <title>plf::clamp</title>
    <filename>group__plf__clamp.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::clamp</name>
      <anchorfile>group__plf__clamp.html</anchorfile>
      <anchor>gaf3b6e14fd2890b610b24438a70b5ba87</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_convert</name>
    <title>plf::convert</title>
    <filename>group__plf__convert.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::convert</name>
      <anchorfile>group__plf__convert.html</anchorfile>
      <anchor>ga3596810b24bfc8fb774e184cf3c2787e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_copysign</name>
    <title>plf::copysign</title>
    <filename>group__plf__copysign.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::copysign</name>
      <anchorfile>group__plf__copysign.html</anchorfile>
      <anchor>gae88e21eb3751b1d0fd7b71d288d9d1ee</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_cos</name>
    <title>plf::cos</title>
    <filename>group__plf__cos.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::cos</name>
      <anchorfile>group__plf__cos.html</anchorfile>
      <anchor>ga305ef58bb0ca0c9ba8819663f74e70a3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_cos_1</name>
    <title>plf::cos_1</title>
    <filename>group__plf__cos__1.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::cos_1</name>
      <anchorfile>group__plf__cos__1.html</anchorfile>
      <anchor>ga9d32e0a5bf045bfbde9ac25549b2e1cc</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_cosh</name>
    <title>plf::cosh</title>
    <filename>group__plf__cosh.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::cosh</name>
      <anchorfile>group__plf__cosh.html</anchorfile>
      <anchor>ga9c6115c7b57ba527694f481843d1edac</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_cosh_1</name>
    <title>plf::cosh_1</title>
    <filename>group__plf__cosh__1.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::cosh_1</name>
      <anchorfile>group__plf__cosh__1.html</anchorfile>
      <anchor>ga196b76f0b9a3da0eb1612216fec0adee</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_cosine_similarity</name>
    <title>plf::cosine_similarity</title>
    <filename>group__plf__cosine__similarity.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::cosine_similarity</name>
      <anchorfile>group__plf__cosine__similarity.html</anchorfile>
      <anchor>gae9bf65899aaf52f81e706494a42c99d3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_cot</name>
    <title>plf::cot</title>
    <filename>group__plf__cot.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::cot</name>
      <anchorfile>group__plf__cot.html</anchorfile>
      <anchor>gae7ab589536adafb793a86b8f4c1801e1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_coth</name>
    <title>plf::coth</title>
    <filename>group__plf__coth.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::coth</name>
      <anchorfile>group__plf__coth.html</anchorfile>
      <anchor>gaf01f8c2e4a091896659fccc21a962290</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_covariance</name>
    <title>plf::covariance</title>
    <filename>group__plf__covariance.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::covariance</name>
      <anchorfile>group__plf__covariance.html</anchorfile>
      <anchor>ga849d694549afbbd8308f3509f7e2c780</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_csc</name>
    <title>plf::csc</title>
    <filename>group__plf__csc.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::csc</name>
      <anchorfile>group__plf__csc.html</anchorfile>
      <anchor>ga0ec9ae5e0635c4e001edd52b8688c190</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_csch</name>
    <title>plf::csch</title>
    <filename>group__plf__csch.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::csch</name>
      <anchorfile>group__plf__csch.html</anchorfile>
      <anchor>ga4f7c3e54da1f4dd5c0a97722dd4f56ed</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_cumfun</name>
    <title>plf::cumfun</title>
    <filename>group__plf__cumfun.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::cumfun</name>
      <anchorfile>group__plf__cumfun.html</anchorfile>
      <anchor>gad9ed275f6b6e77db5325c3893e933ef6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_cumprod</name>
    <title>plf::cumprod</title>
    <filename>group__plf__cumprod.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::cumprod</name>
      <anchorfile>group__plf__cumprod.html</anchorfile>
      <anchor>gaead0ce36438cf8108b2bf0997ff6e4f8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_cumsum</name>
    <title>plf::cumsum</title>
    <filename>group__plf__cumsum.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::cumsum</name>
      <anchorfile>group__plf__cumsum.html</anchorfile>
      <anchor>ga431cf7d6555dc450704863dd522499b6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_dec</name>
    <title>plf::dec</title>
    <filename>group__plf__dec.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::dec</name>
      <anchorfile>group__plf__dec.html</anchorfile>
      <anchor>ga21dc299efb61f8ae4924e3fb0b953f7c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_dekker_prod</name>
    <title>plf::dekker_prod</title>
    <filename>group__plf__dekker__prod.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::dekker_prod</name>
      <anchorfile>group__plf__dekker__prod.html</anchorfile>
      <anchor>ga1a41dc23e01e636ab69b39a3238a893f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_diff</name>
    <title>plf::diff</title>
    <filename>group__plf__diff.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::diff</name>
      <anchorfile>group__plf__diff.html</anchorfile>
      <anchor>ga197b906315ce84f0c78181a9314c0988</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_dist</name>
    <title>plf::dist</title>
    <filename>group__plf__dist.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::dist</name>
      <anchorfile>group__plf__dist.html</anchorfile>
      <anchor>ga31aaafd7f21c599693e7a2fd6533e315</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_div</name>
    <title>plf::div</title>
    <filename>group__plf__div.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::div</name>
      <anchorfile>group__plf__div.html</anchorfile>
      <anchor>gad96f947d70b23427a0305b9998aad337</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_div_180</name>
    <title>plf::div_180</title>
    <filename>group__plf__div__180.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::div_180</name>
      <anchorfile>group__plf__div__180.html</anchorfile>
      <anchor>gad588675f0e3b67228f703e4729b95996</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_dot</name>
    <title>plf::dot</title>
    <filename>group__plf__dot.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::dot</name>
      <anchorfile>group__plf__dot.html</anchorfile>
      <anchor>gaf5ce77de394a85c44e05c7f96215fc27</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_effective_mantissa_bits</name>
    <title>plf::effective_mantissa_bits</title>
    <filename>group__plf__effective__mantissa__bits.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::effective_mantissa_bits</name>
      <anchorfile>group__plf__effective__mantissa__bits.html</anchorfile>
      <anchor>gac4277864eeceb38de7a3e18e4f329337</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_egamma</name>
    <title>plf::egamma</title>
    <filename>group__plf__egamma.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::egamma</name>
      <anchorfile>group__plf__egamma.html</anchorfile>
      <anchor>gab41420b093b23cbda01fe8617f29e5cb</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_eps</name>
    <title>plf::eps</title>
    <filename>group__plf__eps.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::eps</name>
      <anchorfile>group__plf__eps.html</anchorfile>
      <anchor>gacd69b768b1e3278712c5dd2b3cd7b58c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_epsilon</name>
    <title>plf::epsilon</title>
    <filename>group__plf__epsilon.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::epsilon</name>
      <anchorfile>group__plf__epsilon.html</anchorfile>
      <anchor>gac68d4fa443f186a4893bda40bdadcd39</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_euler</name>
    <title>plf::euler</title>
    <filename>group__plf__euler.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::euler</name>
      <anchorfile>group__plf__euler.html</anchorfile>
      <anchor>ga307c6361163f5ebe3b6a3c7ca0472da8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_exp</name>
    <title>plf::exp</title>
    <filename>group__plf__exp.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::exp</name>
      <anchorfile>group__plf__exp.html</anchorfile>
      <anchor>gab8e08b05daa3ee86e2ed652a07352d64</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_exp10</name>
    <title>plf::exp10</title>
    <filename>group__plf__exp10.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::exp10</name>
      <anchorfile>group__plf__exp10.html</anchorfile>
      <anchor>gab2d4aa80b5aa4a96f314f3e94932f28c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_exp2</name>
    <title>plf::exp2</title>
    <filename>group__plf__exp2.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::exp2</name>
      <anchorfile>group__plf__exp2.html</anchorfile>
      <anchor>gaec8099077dd346085e88919e08513d84</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_exp2n</name>
    <title>plf::exp2n</title>
    <filename>group__plf__exp2n.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::exp2n</name>
      <anchorfile>group__plf__exp2n.html</anchorfile>
      <anchor>ga9c7c797f076bcdb2062d2bd3205bb325</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_exp_pi</name>
    <title>plf::exp_pi</title>
    <filename>group__plf__exp__pi.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::exp_pi</name>
      <anchorfile>group__plf__exp__pi.html</anchorfile>
      <anchor>ga6fa3edda699d41702f6c3daca8202d6a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_expm1</name>
    <title>plf::expm1</title>
    <filename>group__plf__expm1.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::expm1</name>
      <anchorfile>group__plf__expm1.html</anchorfile>
      <anchor>ga6b355641ddbdb7ec0d1daa0bcf7be425</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_false_</name>
    <title>plf::false_</title>
    <filename>group__plf__false__.html</filename>
  </compound>
  <compound kind="group">
    <name>plf_fam</name>
    <title>plf::fam</title>
    <filename>group__plf__fam.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::fam</name>
      <anchorfile>group__plf__fam.html</anchorfile>
      <anchor>ga901d4b061ed59463f25ab684e7707f35</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_floor</name>
    <title>plf::floor</title>
    <filename>group__plf__floor.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::floor</name>
      <anchorfile>group__plf__floor.html</anchorfile>
      <anchor>gabaa3043614b3644380404814e6718a87</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_fma</name>
    <title>plf::fma</title>
    <filename>group__plf__fma.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::fma</name>
      <anchorfile>group__plf__fma.html</anchorfile>
      <anchor>gafe2539e930df632442830952eafe983f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_fmod</name>
    <title>plf::fmod</title>
    <filename>group__plf__fmod.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::fmod</name>
      <anchorfile>group__plf__fmod.html</anchorfile>
      <anchor>ga1e5b90cb087d254f8741482c0e894594</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_fms</name>
    <title>plf::fms</title>
    <filename>group__plf__fms.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::fms</name>
      <anchorfile>group__plf__fms.html</anchorfile>
      <anchor>ga528f7b968ee1663dd96dcbf976e96491</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_fnma</name>
    <title>plf::fnma</title>
    <filename>group__plf__fnma.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::fnma</name>
      <anchorfile>group__plf__fnma.html</anchorfile>
      <anchor>ga5b4600c48a905e3808b32a9441a6d19d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_fnms</name>
    <title>plf::fnms</title>
    <filename>group__plf__fnms.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::fnms</name>
      <anchorfile>group__plf__fnms.html</anchorfile>
      <anchor>ga820c60b72b131ea41f424290e4777842</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_four_minus_pi</name>
    <title>plf::four_minus_pi</title>
    <filename>group__plf__four__minus__pi.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::four_minus_pi</name>
      <anchorfile>group__plf__four__minus__pi.html</anchorfile>
      <anchor>ga54faf31f647165ae47e3a880e23d5d3f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_four_pio_3</name>
    <title>plf::four_pio_3</title>
    <filename>group__plf__four__pio__3.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::four_pio_3</name>
      <anchorfile>group__plf__four__pio__3.html</anchorfile>
      <anchor>gaf5af972a1c9b8ba32015011e7462f64f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_frac</name>
    <title>plf::frac</title>
    <filename>group__plf__frac.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::frac</name>
      <anchorfile>group__plf__frac.html</anchorfile>
      <anchor>ga6cbff9063806f25141fbe0f5863becae</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_frexp</name>
    <title>plf::frexp</title>
    <filename>group__plf__frexp.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::frexp</name>
      <anchorfile>group__plf__frexp.html</anchorfile>
      <anchor>ga89334551f0d0c2f81bf852d2a0b9f502</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_fsm</name>
    <title>plf::fsm</title>
    <filename>group__plf__fsm.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::fsm</name>
      <anchorfile>group__plf__fsm.html</anchorfile>
      <anchor>gab6ffa7b2b7b589bc9bbf790c8555e7f3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_gd</name>
    <title>plf::gd</title>
    <filename>group__plf__gd.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::gd</name>
      <anchorfile>group__plf__gd.html</anchorfile>
      <anchor>ga7a370ae4843d70f50869cb0d54eb2e85</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_geommean</name>
    <title>plf::geommean</title>
    <filename>group__plf__geommean.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::geommean</name>
      <anchorfile>group__plf__geommean.html</anchorfile>
      <anchor>ga94e49091e938d9924175ca01e67a974e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_half</name>
    <title>plf::half</title>
    <filename>group__plf__half.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::half</name>
      <anchorfile>group__plf__half.html</anchorfile>
      <anchor>gafdc7f58bede6debd2ef66a4b3521cb84</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_harmmean</name>
    <title>plf::harmmean</title>
    <filename>group__plf__harmmean.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::harmmean</name>
      <anchorfile>group__plf__harmmean.html</anchorfile>
      <anchor>ga1a9ee49f483a6bc0728c30b0ecdb500d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_heaviside</name>
    <title>plf::heaviside</title>
    <filename>group__plf__heaviside.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::heaviside</name>
      <anchorfile>group__plf__heaviside.html</anchorfile>
      <anchor>gaacc157e51d44695e50b1e1af7643abc0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_hi</name>
    <title>plf::hi</title>
    <filename>group__plf__hi.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::hi</name>
      <anchorfile>group__plf__hi.html</anchorfile>
      <anchor>ga85fa850c93bf943fe9e434de3552293d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_horner</name>
    <title>plf::horner</title>
    <filename>group__plf__horner.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::horner</name>
      <anchorfile>group__plf__horner.html</anchorfile>
      <anchor>gae998e94f32f326d4c67342e2ceb35982</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_hypot</name>
    <title>plf::hypot</title>
    <filename>group__plf__hypot.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::hypot</name>
      <anchorfile>group__plf__hypot.html</anchorfile>
      <anchor>gab1d383e91204c25060d9e6f3f68fac0b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_if_else</name>
    <title>plf::if_else</title>
    <filename>group__plf__if__else.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::if_else</name>
      <anchorfile>group__plf__if__else.html</anchorfile>
      <anchor>gafb741bdffc03f40d05b112ff6c893e7c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_inc</name>
    <title>plf::inc</title>
    <filename>group__plf__inc.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::inc</name>
      <anchorfile>group__plf__inc.html</anchorfile>
      <anchor>gad3d7ea17362a2244fb6ec0ca2d5a78e5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_inf</name>
    <title>plf::inf</title>
    <filename>group__plf__inf.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::inf</name>
      <anchorfile>group__plf__inf.html</anchorfile>
      <anchor>ga17a6561e33fcb9f3bf0be566ca5751f7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_inv_2pi</name>
    <title>plf::inv_2pi</title>
    <filename>group__plf__inv__2pi.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::inv_2pi</name>
      <anchorfile>group__plf__inv__2pi.html</anchorfile>
      <anchor>ga44c0709faa879e32e2cc9ccbd5d2d999</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_inv_e</name>
    <title>plf::inv_e</title>
    <filename>group__plf__inv__e.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::inv_e</name>
      <anchorfile>group__plf__inv__e.html</anchorfile>
      <anchor>gadfc4db657908ea0e29851034a825b058</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_inv_pi</name>
    <title>plf::inv_pi</title>
    <filename>group__plf__inv__pi.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::inv_pi</name>
      <anchorfile>group__plf__inv__pi.html</anchorfile>
      <anchor>ga8c20889a18fc8b1d8e5b40960a0c104d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_invcbrt_pi</name>
    <title>plf::invcbrt_pi</title>
    <filename>group__plf__invcbrt__pi.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::invcbrt_pi</name>
      <anchorfile>group__plf__invcbrt__pi.html</anchorfile>
      <anchor>ga3821c8d6cf74a9a66a893f37c4f82139</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_inveps</name>
    <title>plf::inveps</title>
    <filename>group__plf__inveps.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::inveps</name>
      <anchorfile>group__plf__inveps.html</anchorfile>
      <anchor>gae1bef0c184e2dead4007764d4e821835</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_invlog_10</name>
    <title>plf::invlog_10</title>
    <filename>group__plf__invlog__10.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::invlog_10</name>
      <anchorfile>group__plf__invlog__10.html</anchorfile>
      <anchor>gae5ba2e8a8ea4d88c2799dcdf8424f574</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_invlog_2</name>
    <title>plf::invlog_2</title>
    <filename>group__plf__invlog__2.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::invlog_2</name>
      <anchorfile>group__plf__invlog__2.html</anchorfile>
      <anchor>ga558ed10477a5c340a720e2ea3866327c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_bit_equal</name>
    <title>plf::is_bit_equal</title>
    <filename>group__plf__is__bit__equal.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_bit_equal</name>
      <anchorfile>group__plf__is__bit__equal.html</anchorfile>
      <anchor>ga15e2026fc3252509ad69742f7daf0682</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_denormal</name>
    <title>plf::is_denormal</title>
    <filename>group__plf__is__denormal.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_denormal</name>
      <anchorfile>group__plf__is__denormal.html</anchorfile>
      <anchor>ga3b8438957e33ee0ee5b3ab2508aa72ac</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_eqmz</name>
    <title>plf::is_eqmz</title>
    <filename>group__plf__is__eqmz.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_eqmz</name>
      <anchorfile>group__plf__is__eqmz.html</anchorfile>
      <anchor>ga1a258750e54fc736597fa9439bea340f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_eqpz</name>
    <title>plf::is_eqpz</title>
    <filename>group__plf__is__eqpz.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_eqpz</name>
      <anchorfile>group__plf__is__eqpz.html</anchorfile>
      <anchor>ga1d3c7d7b9441ebc3115872893b1f35a7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_equal</name>
    <title>plf::is_equal</title>
    <filename>group__plf__is__equal.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_equal</name>
      <anchorfile>group__plf__is__equal.html</anchorfile>
      <anchor>gaa3f884f1bd114c09949fb5d4e1af9876</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_eqz</name>
    <title>plf::is_eqz</title>
    <filename>group__plf__is__eqz.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_eqz</name>
      <anchorfile>group__plf__is__eqz.html</anchorfile>
      <anchor>ga4d8c8308d3b4bba663bb237a195b27a6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_even</name>
    <title>plf::is_even</title>
    <filename>group__plf__is__even.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_even</name>
      <anchorfile>group__plf__is__even.html</anchorfile>
      <anchor>gabfa4b5248f0e3f16859f471e7445a0ec</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_finite</name>
    <title>plf::is_finite</title>
    <filename>group__plf__is__finite.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_finite</name>
      <anchorfile>group__plf__is__finite.html</anchorfile>
      <anchor>ga51a63988bfb6162220cd95bcf37af748</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_flint</name>
    <title>plf::is_flint</title>
    <filename>group__plf__is__flint.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_flint</name>
      <anchorfile>group__plf__is__flint.html</anchorfile>
      <anchor>ga72a296047ea9f24dc1438e3a1161e58b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_gez</name>
    <title>plf::is_gez</title>
    <filename>group__plf__is__gez.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_gez</name>
      <anchorfile>group__plf__is__gez.html</anchorfile>
      <anchor>ga2a265c7a54226e24c82cd97ef610c7e2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_greater</name>
    <title>plf::is_greater</title>
    <filename>group__plf__is__greater.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_greater</name>
      <anchorfile>group__plf__is__greater.html</anchorfile>
      <anchor>ga1a413faf72a8ca404c5445c18660b038</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_greater_equal</name>
    <title>plf::is_greater_equal</title>
    <filename>group__plf__is__greater__equal.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_greater_equal</name>
      <anchorfile>group__plf__is__greater__equal.html</anchorfile>
      <anchor>ga97645462f4430d66d0da2a93a1b2f37d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_gtz</name>
    <title>plf::is_gtz</title>
    <filename>group__plf__is__gtz.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_gtz</name>
      <anchorfile>group__plf__is__gtz.html</anchorfile>
      <anchor>gabd560b7b077896323ee38940ef5a3583</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_infinite</name>
    <title>plf::is_infinite</title>
    <filename>group__plf__is__infinite.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_infinite</name>
      <anchorfile>group__plf__is__infinite.html</anchorfile>
      <anchor>gae4511a6a87e546c2fa45b2483a26cbd2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_less</name>
    <title>plf::is_less</title>
    <filename>group__plf__is__less.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_less</name>
      <anchorfile>group__plf__is__less.html</anchorfile>
      <anchor>gaeb3a722d8086ab0090707c53e2058c3d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_less_equal</name>
    <title>plf::is_less_equal</title>
    <filename>group__plf__is__less__equal.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_less_equal</name>
      <anchorfile>group__plf__is__less__equal.html</anchorfile>
      <anchor>ga288303686db135dde311d78d6ebcc103</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_lessgreater</name>
    <title>plf::is_lessgreater</title>
    <filename>group__plf__is__lessgreater.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_lessgreater</name>
      <anchorfile>group__plf__is__lessgreater.html</anchorfile>
      <anchor>ga93c70fd4967b9569ea28724a993369be</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_lez</name>
    <title>plf::is_lez</title>
    <filename>group__plf__is__lez.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_lez</name>
      <anchorfile>group__plf__is__lez.html</anchorfile>
      <anchor>gad212f44157bf7a494a02cdc8e2cb01b4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_ltz</name>
    <title>plf::is_ltz</title>
    <filename>group__plf__is__ltz.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_ltz</name>
      <anchorfile>group__plf__is__ltz.html</anchorfile>
      <anchor>ga62ddb7af573f49058eba0f222072310a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_minf</name>
    <title>plf::is_minf</title>
    <filename>group__plf__is__minf.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_minf</name>
      <anchorfile>group__plf__is__minf.html</anchorfile>
      <anchor>gab77d212b376f19f9172c3741d6b2df35</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_nan</name>
    <title>plf::is_nan</title>
    <filename>group__plf__is__nan.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_nan</name>
      <anchorfile>group__plf__is__nan.html</anchorfile>
      <anchor>ga1db11a0b9a18822ffe41043c38cc80c3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_negative</name>
    <title>plf::is_negative</title>
    <filename>group__plf__is__negative.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_negative</name>
      <anchorfile>group__plf__is__negative.html</anchorfile>
      <anchor>ga5b1a93ce270f1b01560e0007b998ea73</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_nemz</name>
    <title>plf::is_nemz</title>
    <filename>group__plf__is__nemz.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_nemz</name>
      <anchorfile>group__plf__is__nemz.html</anchorfile>
      <anchor>gab196817aaa41a88c58ed791c715b0350</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_nepz</name>
    <title>plf::is_nepz</title>
    <filename>group__plf__is__nepz.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_nepz</name>
      <anchorfile>group__plf__is__nepz.html</anchorfile>
      <anchor>ga588f3519dcd992829d6060db0b2dd0b6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_nez</name>
    <title>plf::is_nez</title>
    <filename>group__plf__is__nez.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_nez</name>
      <anchorfile>group__plf__is__nez.html</anchorfile>
      <anchor>ga1e4d7cd895471d034bfab1d93130be54</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_ngez</name>
    <title>plf::is_ngez</title>
    <filename>group__plf__is__ngez.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_ngez</name>
      <anchorfile>group__plf__is__ngez.html</anchorfile>
      <anchor>ga4299f6d8bf5e48900d92af1371735d2f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_ngtz</name>
    <title>plf::is_ngtz</title>
    <filename>group__plf__is__ngtz.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_ngtz</name>
      <anchorfile>group__plf__is__ngtz.html</anchorfile>
      <anchor>ga1012d9d76ecb23bf85402fea5b7719ae</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_nlez</name>
    <title>plf::is_nlez</title>
    <filename>group__plf__is__nlez.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_nlez</name>
      <anchorfile>group__plf__is__nlez.html</anchorfile>
      <anchor>ga78f7c97500b38f86a7a63242368aae2c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_nltz</name>
    <title>plf::is_nltz</title>
    <filename>group__plf__is__nltz.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_nltz</name>
      <anchorfile>group__plf__is__nltz.html</anchorfile>
      <anchor>gae2a0761ccbc5a9fe472f2f5c14a8fcd9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_normalized</name>
    <title>plf::is_normalized</title>
    <filename>group__plf__is__normalized.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_normalized</name>
      <anchorfile>group__plf__is__normalized.html</anchorfile>
      <anchor>ga113b95e7d3065357cea2e7278e16b167</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_not_denormal</name>
    <title>plf::is_not_denormal</title>
    <filename>group__plf__is__not__denormal.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_denormal</name>
      <anchorfile>group__plf__is__not__denormal.html</anchorfile>
      <anchor>ga315ab6ec01496d96b325d266be09767f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_not_equal</name>
    <title>plf::is_not_equal</title>
    <filename>group__plf__is__not__equal.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_equal</name>
      <anchorfile>group__plf__is__not__equal.html</anchorfile>
      <anchor>gaed9f3b4229041da1ac2a2070db903277</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_not_finite</name>
    <title>plf::is_not_finite</title>
    <filename>group__plf__is__not__finite.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_finite</name>
      <anchorfile>group__plf__is__not__finite.html</anchorfile>
      <anchor>ga63749142d53ad0d040659d8d4cffee74</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_not_flint</name>
    <title>plf::is_not_flint</title>
    <filename>group__plf__is__not__flint.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_flint</name>
      <anchorfile>group__plf__is__not__flint.html</anchorfile>
      <anchor>ga42ae7e20907bd55debe6262ff5ea78f9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_not_greater</name>
    <title>plf::is_not_greater</title>
    <filename>group__plf__is__not__greater.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_greater</name>
      <anchorfile>group__plf__is__not__greater.html</anchorfile>
      <anchor>ga2717687d1b7470024cd67a978c7b42b3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_not_greater_equal</name>
    <title>plf::is_not_greater_equal</title>
    <filename>group__plf__is__not__greater__equal.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_greater_equal</name>
      <anchorfile>group__plf__is__not__greater__equal.html</anchorfile>
      <anchor>gabe0e10750aea5fdf460f4c56f46d84c9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_not_infinite</name>
    <title>plf::is_not_infinite</title>
    <filename>group__plf__is__not__infinite.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_infinite</name>
      <anchorfile>group__plf__is__not__infinite.html</anchorfile>
      <anchor>gad3cf2c8f13b83ffed9f1b2924a8a8529</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_not_less</name>
    <title>plf::is_not_less</title>
    <filename>group__plf__is__not__less.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_less</name>
      <anchorfile>group__plf__is__not__less.html</anchorfile>
      <anchor>gacad2e09ee75c713a87065f75a2a18c64</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_not_less_equal</name>
    <title>plf::is_not_less_equal</title>
    <filename>group__plf__is__not__less__equal.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_less_equal</name>
      <anchorfile>group__plf__is__not__less__equal.html</anchorfile>
      <anchor>gac10cc53f0009c90aa0a206f346e21cee</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_not_nan</name>
    <title>plf::is_not_nan</title>
    <filename>group__plf__is__not__nan.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_not_nan</name>
      <anchorfile>group__plf__is__not__nan.html</anchorfile>
      <anchor>ga64a07f1dd60b6e1409442078cc039a42</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_odd</name>
    <title>plf::is_odd</title>
    <filename>group__plf__is__odd.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_odd</name>
      <anchorfile>group__plf__is__odd.html</anchorfile>
      <anchor>ga455e06a0df2a0068637f251becfbb944</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_ordered</name>
    <title>plf::is_ordered</title>
    <filename>group__plf__is__ordered.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_ordered</name>
      <anchorfile>group__plf__is__ordered.html</anchorfile>
      <anchor>ga7c90ae517c18bab6325f49cce61f4edf</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_pinf</name>
    <title>plf::is_pinf</title>
    <filename>group__plf__is__pinf.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_pinf</name>
      <anchorfile>group__plf__is__pinf.html</anchorfile>
      <anchor>gaff62e2a7284c69e0b8c388e70ad2e066</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_positive</name>
    <title>plf::is_positive</title>
    <filename>group__plf__is__positive.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_positive</name>
      <anchorfile>group__plf__is__positive.html</anchorfile>
      <anchor>ga382498c379928168e37005f38a9b8eaf</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_pow2</name>
    <title>plf::is_pow2</title>
    <filename>group__plf__is__pow2.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_pow2</name>
      <anchorfile>group__plf__is__pow2.html</anchorfile>
      <anchor>gaf77de37071bc9885bab1dc8d8bb235b0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_unit</name>
    <title>plf::is_unit</title>
    <filename>group__plf__is__unit.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_unit</name>
      <anchorfile>group__plf__is__unit.html</anchorfile>
      <anchor>gae00ac1ff95cdeca72e526d70cc419e51</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_is_unordered</name>
    <title>plf::is_unordered</title>
    <filename>group__plf__is__unordered.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::is_unordered</name>
      <anchorfile>group__plf__is__unordered.html</anchorfile>
      <anchor>ga46fff13f9c73cf8cdbe1ed78f4083f65</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_kolmmean</name>
    <title>plf::kolmmean</title>
    <filename>group__plf__kolmmean.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::kolmmean</name>
      <anchorfile>group__plf__kolmmean.html</anchorfile>
      <anchor>gacc494abd22af242970d010990f088ede</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_lerp</name>
    <title>plf::lerp</title>
    <filename>group__plf__lerp.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::lerp</name>
      <anchorfile>group__plf__lerp.html</anchorfile>
      <anchor>ga8875d0b61cf3fbeeaa6ed18b29e5ca9f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_lo</name>
    <title>plf::lo</title>
    <filename>group__plf__lo.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::lo</name>
      <anchorfile>group__plf__lo.html</anchorfile>
      <anchor>ga986719f5a39d352e01286ab52b9a54ff</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_log</name>
    <title>plf::log</title>
    <filename>group__plf__log.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::log</name>
      <anchorfile>group__plf__log.html</anchorfile>
      <anchor>ga39d37d0f777a93ba32640c56565e2710</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_log10</name>
    <title>plf::log10</title>
    <filename>group__plf__log10.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::log10</name>
      <anchorfile>group__plf__log10.html</anchorfile>
      <anchor>gaae901ccc06c7a5efa0242e5fcd654bd4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_log1p</name>
    <title>plf::log1p</title>
    <filename>group__plf__log1p.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::log1p</name>
      <anchorfile>group__plf__log1p.html</anchorfile>
      <anchor>ga94a26247473867f18517eb7d654b9f5a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_log2</name>
    <title>plf::log2</title>
    <filename>group__plf__log2.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::log2</name>
      <anchorfile>group__plf__log2.html</anchorfile>
      <anchor>ga74fe53ba9509c1894684a4fe92865d07</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_log_10</name>
    <title>plf::log_10</title>
    <filename>group__plf__log__10.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::log_10</name>
      <anchorfile>group__plf__log__10.html</anchorfile>
      <anchor>ga7d0a5181eb3193505a5be468ade48d62</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_log_2</name>
    <title>plf::log_2</title>
    <filename>group__plf__log__2.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::log_2</name>
      <anchorfile>group__plf__log__2.html</anchorfile>
      <anchor>gab076b85673ceedd01180cae08b3b984e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_log_abs</name>
    <title>plf::log_abs</title>
    <filename>group__plf__log__abs.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::log_abs</name>
      <anchorfile>group__plf__log__abs.html</anchorfile>
      <anchor>ga74e89d74258edc3ffa690b970ce0519d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_logeps</name>
    <title>plf::logeps</title>
    <filename>group__plf__logeps.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::logeps</name>
      <anchorfile>group__plf__logeps.html</anchorfile>
      <anchor>gad27792bcc40b8ac1693bacbd95570d68</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_logspace_add</name>
    <title>plf::logspace_add</title>
    <filename>group__plf__logspace__add.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::logspace_add</name>
      <anchorfile>group__plf__logspace__add.html</anchorfile>
      <anchor>ga0a1e0bab561000aa41ed2f5142cb9c37</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_logspace_sub</name>
    <title>plf::logspace_sub</title>
    <filename>group__plf__logspace__sub.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::logspace_sub</name>
      <anchorfile>group__plf__logspace__sub.html</anchorfile>
      <anchor>gac6e8817a750645f722883e1b8f7d319d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_lpnorm</name>
    <title>plf::lpnorm</title>
    <filename>group__plf__lpnorm.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::lpnorm</name>
      <anchorfile>group__plf__lpnorm.html</anchorfile>
      <anchor>ga0b35ba464177d39b675aebaae393d1e6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_mantissa</name>
    <title>plf::mantissa</title>
    <filename>group__plf__mantissa.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::mantissa</name>
      <anchorfile>group__plf__mantissa.html</anchorfile>
      <anchor>ga592c5eb0fdeb82b41dd07a2ddc48dd6e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_max</name>
    <title>plf::max</title>
    <filename>group__plf__max.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::max</name>
      <anchorfile>group__plf__max.html</anchorfile>
      <anchor>ga1d6b7e84a59f51f3fdeab89704ce3bb1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_maxabs</name>
    <title>plf::maxabs</title>
    <filename>group__plf__maxabs.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::maxabs</name>
      <anchorfile>group__plf__maxabs.html</anchorfile>
      <anchor>ga943ef8abb2c09066d89722a3ea69c78c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_maxexponent</name>
    <title>plf::maxexponent</title>
    <filename>group__plf__maxexponent.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::maxexponent</name>
      <anchorfile>group__plf__maxexponent.html</anchorfile>
      <anchor>ga2657732c3d32e5f7ebf52928cc7e77d2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_maxexponentm1</name>
    <title>plf::maxexponentm1</title>
    <filename>group__plf__maxexponentm1.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::maxexponentm1</name>
      <anchorfile>group__plf__maxexponentm1.html</anchorfile>
      <anchor>ga9a853f802e2e8048694dadfbf66109b3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_maxexponentp1</name>
    <title>plf::maxexponentp1</title>
    <filename>group__plf__maxexponentp1.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::maxexponentp1</name>
      <anchorfile>group__plf__maxexponentp1.html</anchorfile>
      <anchor>ga41487618f4587a15ff32960dd2f94945</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_maxflint</name>
    <title>plf::maxflint</title>
    <filename>group__plf__maxflint.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::maxflint</name>
      <anchorfile>group__plf__maxflint.html</anchorfile>
      <anchor>gae321346f90402e1b5dc7875054e49a83</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_maxlog</name>
    <title>plf::maxlog</title>
    <filename>group__plf__maxlog.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::maxlog</name>
      <anchorfile>group__plf__maxlog.html</anchorfile>
      <anchor>gaa7847ac49cf7e5db7ff5ecdd7edd9268</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_maxlog2</name>
    <title>plf::maxlog2</title>
    <filename>group__plf__maxlog2.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::maxlog2</name>
      <anchorfile>group__plf__maxlog2.html</anchorfile>
      <anchor>ga64fcae751fc85c4ea13187127deb5ab7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_maxmag</name>
    <title>plf::maxmag</title>
    <filename>group__plf__maxmag.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::maxmag</name>
      <anchorfile>group__plf__maxmag.html</anchorfile>
      <anchor>gaee2e0eb2ad65678b921da8c2b4de631e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_md</name>
    <title>plf::md</title>
    <filename>group__plf__md.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::md</name>
      <anchorfile>group__plf__md.html</anchorfile>
      <anchor>ga0745f202e4af71621d3f5e84e37c6abe</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_mhalf</name>
    <title>plf::mhalf</title>
    <filename>group__plf__mhalf.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::mhalf</name>
      <anchorfile>group__plf__mhalf.html</anchorfile>
      <anchor>gacf3b52a44982c70d2b2b7a11531beee3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_min</name>
    <title>plf::min</title>
    <filename>group__plf__min.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::min</name>
      <anchorfile>group__plf__min.html</anchorfile>
      <anchor>gaf2ecab0082e8fa1007d5ea49c9fa1a87</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_minabs</name>
    <title>plf::minabs</title>
    <filename>group__plf__minabs.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::minabs</name>
      <anchorfile>group__plf__minabs.html</anchorfile>
      <anchor>gaa190c10bef44628e4701ff2fcd6728a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_mindenormal</name>
    <title>plf::mindenormal</title>
    <filename>group__plf__mindenormal.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::mindenormal</name>
      <anchorfile>group__plf__mindenormal.html</anchorfile>
      <anchor>ga0a3e5881bfb4a0de7977621996c339a9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_minexponent</name>
    <title>plf::minexponent</title>
    <filename>group__plf__minexponent.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::minexponent</name>
      <anchorfile>group__plf__minexponent.html</anchorfile>
      <anchor>ga4647ba96a04ee2f05047b93c70509bd9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_minf</name>
    <title>plf::minf</title>
    <filename>group__plf__minf.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::minf</name>
      <anchorfile>group__plf__minf.html</anchorfile>
      <anchor>ga53eeee70008790007d0da7e69ad152e5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_minmag</name>
    <title>plf::minmag</title>
    <filename>group__plf__minmag.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::minmag</name>
      <anchorfile>group__plf__minmag.html</anchorfile>
      <anchor>ga3edebc887d62d202367258c76f7a1a7f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_minmax</name>
    <title>plf::minmax</title>
    <filename>group__plf__minmax.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::minmax</name>
      <anchorfile>group__plf__minmax.html</anchorfile>
      <anchor>ga830c684d59f4722059bef14bb7f92da2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_minus</name>
    <title>plf::minus</title>
    <filename>group__plf__minus.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::minus</name>
      <anchorfile>group__plf__minus.html</anchorfile>
      <anchor>gae33d4d1bd5488f7aed156cd106f4ce74</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_modf</name>
    <title>plf::modf</title>
    <filename>group__plf__modf.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::modf</name>
      <anchorfile>group__plf__modf.html</anchorfile>
      <anchor>gaf07ed2a608fc290c474c9baaa296fc76</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_mone</name>
    <title>plf::mone</title>
    <filename>group__plf__mone.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::mone</name>
      <anchorfile>group__plf__mone.html</anchorfile>
      <anchor>gafd51d660d060685287a61ceb9a0619c5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_mul</name>
    <title>plf::mul</title>
    <filename>group__plf__mul.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::mul</name>
      <anchorfile>group__plf__mul.html</anchorfile>
      <anchor>ga856a221cd309873711b978ce55df4635</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_mul_pi</name>
    <title>plf::mul_pi</title>
    <filename>group__plf__mul__pi.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::mul_pi</name>
      <anchorfile>group__plf__mul__pi.html</anchorfile>
      <anchor>gab8f950f821aa3dda14dc737d30564599</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_mzero</name>
    <title>plf::mzero</title>
    <filename>group__plf__mzero.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::mzero</name>
      <anchorfile>group__plf__mzero.html</anchorfile>
      <anchor>ga889a98f4b2269954d9c5326e07ffdd9f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_nan</name>
    <title>plf::nan</title>
    <filename>group__plf__nan.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::nan</name>
      <anchorfile>group__plf__nan.html</anchorfile>
      <anchor>gab815a9e20ea8d0c215108a23413f0347</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_nbmantissabits</name>
    <title>plf::nbmantissabits</title>
    <filename>group__plf__nbmantissabits.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::nbmantissabits</name>
      <anchorfile>group__plf__nbmantissabits.html</anchorfile>
      <anchor>ga353f26b1179c82267a8066987951a553</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_nearest</name>
    <title>plf::nearest</title>
    <filename>group__plf__nearest.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::nearest</name>
      <anchorfile>group__plf__nearest.html</anchorfile>
      <anchor>ga1c1e5e03fa7f21ea1a74311813762197</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_negabsmax</name>
    <title>plf::negabsmax</title>
    <filename>group__plf__negabsmax.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::negabsmax</name>
      <anchorfile>group__plf__negabsmax.html</anchorfile>
      <anchor>ga54e69f527759113beefec446c9c8f7de</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_negabsmin</name>
    <title>plf::negabsmin</title>
    <filename>group__plf__negabsmin.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::negabsmin</name>
      <anchorfile>group__plf__negabsmin.html</anchorfile>
      <anchor>ga519b13d3f054b319b6ef5e59eb029a47</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_negate</name>
    <title>plf::negate</title>
    <filename>group__plf__negate.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::negate</name>
      <anchorfile>group__plf__negate.html</anchorfile>
      <anchor>ga0b77fce5aa260a3629bed972eee3ba39</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_negatenz</name>
    <title>plf::negatenz</title>
    <filename>group__plf__negatenz.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::negatenz</name>
      <anchorfile>group__plf__negatenz.html</anchorfile>
      <anchor>gacb0784fa93d2122cec99faf7a9760daa</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_negmaxabs</name>
    <title>plf::negmaxabs</title>
    <filename>group__plf__negmaxabs.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::negmaxabs</name>
      <anchorfile>group__plf__negmaxabs.html</anchorfile>
      <anchor>ga0ddb4ae3b0954209eca0c7257d166dbc</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_negminabs</name>
    <title>plf::negminabs</title>
    <filename>group__plf__negminabs.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::negminabs</name>
      <anchorfile>group__plf__negminabs.html</anchorfile>
      <anchor>gace9b23e8f34fdc09478d8901078f1bb6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_neville</name>
    <title>plf::neville</title>
    <filename>group__plf__neville.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::neville</name>
      <anchorfile>group__plf__neville.html</anchorfile>
      <anchor>gada98330f63111f37aa310dcb450fb2aa</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_next</name>
    <title>plf::next</title>
    <filename>group__plf__next.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::next</name>
      <anchorfile>group__plf__next.html</anchorfile>
      <anchor>ga60c7f280243a468485f42421a2c06739</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_nextafter</name>
    <title>plf::nextafter</title>
    <filename>group__plf__nextafter.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::nextafter</name>
      <anchorfile>group__plf__nextafter.html</anchorfile>
      <anchor>ga09f396a43b0cf65385e8a586a2b410e9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_nextint</name>
    <title>plf::nextint</title>
    <filename>group__plf__nextint.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::nextint</name>
      <anchorfile>group__plf__nextint.html</anchorfile>
      <anchor>gaf1c232d7bc7f81fc1a42edb3c7b7cd88</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_nthroot</name>
    <title>plf::nthroot</title>
    <filename>group__plf__nthroot.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::nthroot</name>
      <anchorfile>group__plf__nthroot.html</anchorfile>
      <anchor>ga51f47a92f62d391bf10c55c304a691da</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_one</name>
    <title>plf::one</title>
    <filename>group__plf__one.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::one</name>
      <anchorfile>group__plf__one.html</anchorfile>
      <anchor>gaf4a21d2a045aedd47efa31fcc8be1fcf</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_oneminus</name>
    <title>plf::oneminus</title>
    <filename>group__plf__oneminus.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::oneminus</name>
      <anchorfile>group__plf__oneminus.html</anchorfile>
      <anchor>gaffe46da86ea6a171bb1de5203b24334a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_oneo_180</name>
    <title>plf::oneo_180</title>
    <filename>group__plf__oneo__180.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::oneo_180</name>
      <anchorfile>group__plf__oneo__180.html</anchorfile>
      <anchor>gaa48483e2def333b32d0921c7622caa11</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_oneosqrteps</name>
    <title>plf::oneosqrteps</title>
    <filename>group__plf__oneosqrteps.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::oneosqrteps</name>
      <anchorfile>group__plf__oneosqrteps.html</anchorfile>
      <anchor>gaf37d435e94d94585ba4b0848c520316b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_pi</name>
    <title>plf::pi</title>
    <filename>group__plf__pi.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::pi</name>
      <anchorfile>group__plf__pi.html</anchorfile>
      <anchor>gab9b05ae205213ff9eb38c22b9f777eb4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_pio_2</name>
    <title>plf::pio_2</title>
    <filename>group__plf__pio__2.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::pio_2</name>
      <anchorfile>group__plf__pio__2.html</anchorfile>
      <anchor>ga4f050d319a737624f6fda3edc2f10d64</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_pio_3</name>
    <title>plf::pio_3</title>
    <filename>group__plf__pio__3.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::pio_3</name>
      <anchorfile>group__plf__pio__3.html</anchorfile>
      <anchor>ga6474fff2fbfd3debcb1e6c08bc6b8e70</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_pio_4</name>
    <title>plf::pio_4</title>
    <filename>group__plf__pio__4.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::pio_4</name>
      <anchorfile>group__plf__pio__4.html</anchorfile>
      <anchor>ga2833089ea102010508589ab0a7c62ae5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_pio_6</name>
    <title>plf::pio_6</title>
    <filename>group__plf__pio__6.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::pio_6</name>
      <anchorfile>group__plf__pio__6.html</anchorfile>
      <anchor>ga3a5657d9a62ca57b93cff8f720aae898</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_pow</name>
    <title>plf::pow</title>
    <filename>group__plf__pow.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::pow</name>
      <anchorfile>group__plf__pow.html</anchorfile>
      <anchor>ga2ac39d06d5a669c537c5aef7e888ea47</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_pow1p</name>
    <title>plf::pow1p</title>
    <filename>group__plf__pow1p.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::pow1p</name>
      <anchorfile>group__plf__pow1p.html</anchorfile>
      <anchor>gac514868a7f61ecfeedf6a22db91aa304</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_pow_abs</name>
    <title>plf::pow_abs</title>
    <filename>group__plf__pow__abs.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::pow_abs</name>
      <anchorfile>group__plf__pow__abs.html</anchorfile>
      <anchor>gae9f28b8422733a3ec084b057c4963b8d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_powm1</name>
    <title>plf::powm1</title>
    <filename>group__plf__powm1.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::powm1</name>
      <anchorfile>group__plf__powm1.html</anchorfile>
      <anchor>ga81c3266b93996cf7e50e86c058c69674</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_pown</name>
    <title>plf::pown</title>
    <filename>group__plf__pown.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::pown</name>
      <anchorfile>group__plf__pown.html</anchorfile>
      <anchor>ga3309e6018e6235033a2877c0d9eece8c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_prev</name>
    <title>plf::prev</title>
    <filename>group__plf__prev.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::prev</name>
      <anchorfile>group__plf__prev.html</anchorfile>
      <anchor>ga3e945bcc637ae4a744f512275949fe82</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_prevint</name>
    <title>plf::prevint</title>
    <filename>group__plf__prevint.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::prevint</name>
      <anchorfile>group__plf__prevint.html</anchorfile>
      <anchor>ga4bf8537407a460e745d9df6f37fac5f7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_quadrant</name>
    <title>plf::quadrant</title>
    <filename>group__plf__quadrant.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::quadrant</name>
      <anchorfile>group__plf__quadrant.html</anchorfile>
      <anchor>ga01ac2266639f9cb05ad11ced1a4e0619</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_rad2deg</name>
    <title>plf::rad2deg</title>
    <filename>group__plf__rad2deg.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::rad2deg</name>
      <anchorfile>group__plf__rad2deg.html</anchorfile>
      <anchor>gade6dc8cc08c7e513fa33b5c461d449a6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_radindeg</name>
    <title>plf::radindeg</title>
    <filename>group__plf__radindeg.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::radindeg</name>
      <anchorfile>group__plf__radindeg.html</anchorfile>
      <anchor>ga9296f6efaa1e2f591284ffe5c46e0b11</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_radinpi</name>
    <title>plf::radinpi</title>
    <filename>group__plf__radinpi.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::radinpi</name>
      <anchorfile>group__plf__radinpi.html</anchorfile>
      <anchor>ga7c6799944109d3ef28d44e8c65d46ccf</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_rat</name>
    <title>plf::rat</title>
    <filename>group__plf__rat.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::rat</name>
      <anchorfile>group__plf__rat.html</anchorfile>
      <anchor>gae7854c4bf7224d75816c16d3141b868c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_rec</name>
    <title>plf::rec</title>
    <filename>group__plf__rec.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::rec</name>
      <anchorfile>group__plf__rec.html</anchorfile>
      <anchor>ga38ee18ae42971becb7275f6596ada180</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_reldist</name>
    <title>plf::reldist</title>
    <filename>group__plf__reldist.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::reldist</name>
      <anchorfile>group__plf__reldist.html</anchorfile>
      <anchor>ga46f13916d7af01b5f6c1f880d13e2ed4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_rem</name>
    <title>plf::rem</title>
    <filename>group__plf__rem.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::rem</name>
      <anchorfile>group__plf__rem.html</anchorfile>
      <anchor>gaba27d496c09e7ef0892b23806956a840</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_remainder</name>
    <title>plf::remainder</title>
    <filename>group__plf__remainder.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::remainder</name>
      <anchorfile>group__plf__remainder.html</anchorfile>
      <anchor>ga501d3d6d436d40d647f290fce53b5bf9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_reverse_horner</name>
    <title>plf::reverse_horner</title>
    <filename>group__plf__reverse__horner.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::reverse_horner</name>
      <anchorfile>group__plf__reverse__horner.html</anchorfile>
      <anchor>gaec0903d03ecaa41fc2f06bd4d9598fbe</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_round</name>
    <title>plf::round</title>
    <filename>group__plf__round.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::round</name>
      <anchorfile>group__plf__round.html</anchorfile>
      <anchor>ga94fa0cf071f9760d3b0ba4d9c3b86170</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_rsqrt</name>
    <title>plf::rsqrt</title>
    <filename>group__plf__rsqrt.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::rsqrt</name>
      <anchorfile>group__plf__rsqrt.html</anchorfile>
      <anchor>ga6b68af3438bb67d5a0ac3634a01fd610</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_sec</name>
    <title>plf::sec</title>
    <filename>group__plf__sec.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sec</name>
      <anchorfile>group__plf__sec.html</anchorfile>
      <anchor>ga7df98fd9e56c73c6cfc8ab445879d514</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_sech</name>
    <title>plf::sech</title>
    <filename>group__plf__sech.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sech</name>
      <anchorfile>group__plf__sech.html</anchorfile>
      <anchor>ga682c42c12657647392743320cfde271a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_sigmoid</name>
    <title>plf::sigmoid</title>
    <filename>group__plf__sigmoid.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sigmoid</name>
      <anchorfile>group__plf__sigmoid.html</anchorfile>
      <anchor>gab9a23ada2593afbfcb3adc93c5be697a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_sign</name>
    <title>plf::sign</title>
    <filename>group__plf__sign.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sign</name>
      <anchorfile>group__plf__sign.html</anchorfile>
      <anchor>ga71f110b670810f9e0e3ee1b5745a37a8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_sign_alternate</name>
    <title>plf::sign_alternate</title>
    <filename>group__plf__sign__alternate.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sign_alternate</name>
      <anchorfile>group__plf__sign__alternate.html</anchorfile>
      <anchor>ga564e4bc99fc8f5704fae107a5f83e847</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_signnz</name>
    <title>plf::signnz</title>
    <filename>group__plf__signnz.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::signnz</name>
      <anchorfile>group__plf__signnz.html</anchorfile>
      <anchor>gaa1b1663acb0eb4bbc16fd9beb3dff197</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_sin</name>
    <title>plf::sin</title>
    <filename>group__plf__sin.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sin</name>
      <anchorfile>group__plf__sin.html</anchorfile>
      <anchor>gaf5e77c3acf98245222c45029d7ad486d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_sinc</name>
    <title>plf::sinc</title>
    <filename>group__plf__sinc.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sinc</name>
      <anchorfile>group__plf__sinc.html</anchorfile>
      <anchor>gaf483ad7b861bf6d4966000ac0dfe1bc2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_sincos</name>
    <title>plf::sincos</title>
    <filename>group__plf__sincos.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sincos</name>
      <anchorfile>group__plf__sincos.html</anchorfile>
      <anchor>gae73a40c7a5d33fd5e75dc8fda06ecbc7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_sinh</name>
    <title>plf::sinh</title>
    <filename>group__plf__sinh.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sinh</name>
      <anchorfile>group__plf__sinh.html</anchorfile>
      <anchor>gab98365d8cb868ac99d97f9d0297fedfa</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_sinhcosh</name>
    <title>plf::sinhcosh</title>
    <filename>group__plf__sinhcosh.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sinhcosh</name>
      <anchorfile>group__plf__sinhcosh.html</anchorfile>
      <anchor>ga02d2b89a953909ef1283cb5847c2054a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_smallestposval</name>
    <title>plf::smallestposval</title>
    <filename>group__plf__smallestposval.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::smallestposval</name>
      <anchorfile>group__plf__smallestposval.html</anchorfile>
      <anchor>ga1089f4e0a6091f3da50a5c7655ec3643</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_sqr</name>
    <title>plf::sqr</title>
    <filename>group__plf__sqr.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sqr</name>
      <anchorfile>group__plf__sqr.html</anchorfile>
      <anchor>gac72a278d06c43be14dce2cfbd8e67bdf</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_sqrt</name>
    <title>plf::sqrt</title>
    <filename>group__plf__sqrt.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sqrt</name>
      <anchorfile>group__plf__sqrt.html</anchorfile>
      <anchor>gab25eb1782219136d8368a2a090bcac77</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_sqrt_2</name>
    <title>plf::sqrt_2</title>
    <filename>group__plf__sqrt__2.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sqrt_2</name>
      <anchorfile>group__plf__sqrt__2.html</anchorfile>
      <anchor>ga4242d1daac24e1aa6e29ce62d230d171</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_sqrteps</name>
    <title>plf::sqrteps</title>
    <filename>group__plf__sqrteps.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sqrteps</name>
      <anchorfile>group__plf__sqrteps.html</anchorfile>
      <anchor>ga193389bdf9378b4f1ab19e1ed49a52a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_sqrtvalmax</name>
    <title>plf::sqrtvalmax</title>
    <filename>group__plf__sqrtvalmax.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sqrtvalmax</name>
      <anchorfile>group__plf__sqrtvalmax.html</anchorfile>
      <anchor>ga5b01112179d17efdb5be43518c0e0669</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_sub</name>
    <title>plf::sub</title>
    <filename>group__plf__sub.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sub</name>
      <anchorfile>group__plf__sub.html</anchorfile>
      <anchor>ga9d647eeb7803da2f5dc1d1c646e22799</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_sum_of_prod</name>
    <title>plf::sum_of_prod</title>
    <filename>group__plf__sum__of__prod.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sum_of_prod</name>
      <anchorfile>group__plf__sum__of__prod.html</anchorfile>
      <anchor>ga00467d77659f76768d9798485cbbd3cf</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_sum_of_squares</name>
    <title>plf::sum_of_squares</title>
    <filename>group__plf__sum__of__squares.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::sum_of_squares</name>
      <anchorfile>group__plf__sum__of__squares.html</anchorfile>
      <anchor>ga2dd0aca7295af7318c56063bd90f0730</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_tan</name>
    <title>plf::tan</title>
    <filename>group__plf__tan.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::tan</name>
      <anchorfile>group__plf__tan.html</anchorfile>
      <anchor>ga20c0ba81f757e6afeaf8489e4a7b9099</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_tanh</name>
    <title>plf::tanh</title>
    <filename>group__plf__tanh.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::tanh</name>
      <anchorfile>group__plf__tanh.html</anchorfile>
      <anchor>ga5e44e8b5b54edaf7a95210528073e01b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_three_add</name>
    <title>plf::three_add</title>
    <filename>group__plf__three__add.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::three_add</name>
      <anchorfile>group__plf__three__add.html</anchorfile>
      <anchor>gad714fdd7a5f3a2cfcab70658cb520cd1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_three_fma</name>
    <title>plf::three_fma</title>
    <filename>group__plf__three__fma.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::three_fma</name>
      <anchorfile>group__plf__three__fma.html</anchorfile>
      <anchor>gabda6529346e0ae007b7709fabfe7cb59</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_three_pio_4</name>
    <title>plf::three_pio_4</title>
    <filename>group__plf__three__pio__4.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::three_pio_4</name>
      <anchorfile>group__plf__three__pio__4.html</anchorfile>
      <anchor>gae924ebd3b979c867f7a19b8b4d4ae57b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_true_</name>
    <title>plf::true_</title>
    <filename>group__plf__true__.html</filename>
  </compound>
  <compound kind="group">
    <name>plf_trunc</name>
    <title>plf::trunc</title>
    <filename>group__plf__trunc.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::trunc</name>
      <anchorfile>group__plf__trunc.html</anchorfile>
      <anchor>ga9aa5715fd56663843e5d34d9e3904338</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_two_add</name>
    <title>plf::two_add</title>
    <filename>group__plf__two__add.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::two_add</name>
      <anchorfile>group__plf__two__add.html</anchorfile>
      <anchor>ga4f331a5f0e10706ede78c9ac753d6ef4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_two_div_approx</name>
    <title>plf::two_div_approx</title>
    <filename>group__plf__two__div__approx.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::two_div_approx</name>
      <anchorfile>group__plf__two__div__approx.html</anchorfile>
      <anchor>gab1a360af3bf67971c24e0b8c94ff4c1c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_two_fma_approx</name>
    <title>plf::two_fma_approx</title>
    <filename>group__plf__two__fma__approx.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::two_fma_approx</name>
      <anchorfile>group__plf__two__fma__approx.html</anchorfile>
      <anchor>gae79e44f7a860ba7c33be885213090df1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_two_prod</name>
    <title>plf::two_prod</title>
    <filename>group__plf__two__prod.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::two_prod</name>
      <anchorfile>group__plf__two__prod.html</anchorfile>
      <anchor>gae8d597dabc4dc057e3110c0a89afe8f3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_two_split</name>
    <title>plf::two_split</title>
    <filename>group__plf__two__split.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::two_split</name>
      <anchorfile>group__plf__two__split.html</anchorfile>
      <anchor>ga9086f4afc7e04d20a2a3bf8212dc677a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_valmax</name>
    <title>plf::valmax</title>
    <filename>group__plf__valmax.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::valmax</name>
      <anchorfile>group__plf__valmax.html</anchorfile>
      <anchor>ga107149eec536df23c4386d025b854ecf</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_valmin</name>
    <title>plf::valmin</title>
    <filename>group__plf__valmin.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::valmin</name>
      <anchorfile>group__plf__valmin.html</anchorfile>
      <anchor>gafce94c0fcb7990527f77886c832f2d7b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_variance</name>
    <title>plf::variance</title>
    <filename>group__plf__variance.html</filename>
    <member kind="variable">
      <type>constexpr auto</type>
      <name>plf::variance</name>
      <anchorfile>group__plf__variance.html</anchorfile>
      <anchor>ga0b8af824ea99e25f0aafc7e5756d97d3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>plf_zero</name>
    <title>plf::zero</title>
    <filename>group__plf__zero.html</filename>
  </compound>
  <compound kind="page">
    <name>changelog</name>
    <title>Changelog</title>
    <filename>changelog.html</filename>
    <docanchor file="changelog.html" title="/__w/polyfloat/polyfloat/doc/changelog.md">md__2____w_2polyfloat_2polyfloat_2doc_2changelog</docanchor>
  </compound>
  <compound kind="page">
    <name>licence</name>
    <title>Licence</title>
    <filename>licence.html</filename>
    <docanchor file="licence.html" title="/__w/polyfloat/polyfloat/doc/licence.md">md__2____w_2polyfloat_2polyfloat_2doc_2licence</docanchor>
  </compound>
  <compound kind="page">
    <name>setup</name>
    <title>Installation</title>
    <filename>setup.html</filename>
    <docanchor file="setup.html" title="/__w/polyfloat/polyfloat/doc/setup.md">md__2____w_2polyfloat_2polyfloat_2doc_2setup</docanchor>
  </compound>
  <compound kind="page">
    <name>tutorial-basics</name>
    <title>Polyfloat numbers</title>
    <filename>tutorial-basics.html</filename>
  </compound>
  <compound kind="page">
    <name>tutorial-simd</name>
    <title>SIMD support</title>
    <filename>tutorial-simd.html</filename>
  </compound>
  <compound kind="page">
    <name>biblio</name>
    <title>Bibliography</title>
    <filename>biblio.html</filename>
    <docanchor file="biblio.html" title="/__w/polyfloat/polyfloat/doc/biblio.md">md__2____w_2polyfloat_2polyfloat_2doc_2biblio</docanchor>
  </compound>
  <compound kind="page">
    <name>building</name>
    <title>Building for Testing</title>
    <filename>building.html</filename>
    <docanchor file="building.html" title="/__w/polyfloat/polyfloat/doc/building.md">md__2____w_2polyfloat_2polyfloat_2doc_2building</docanchor>
  </compound>
  <compound kind="page">
    <name>implementation_precisions</name>
    <title>Precision</title>
    <filename>implementation_precisions.html</filename>
    <docanchor file="implementation_precisions.html" title="/__w/polyfloat/polyfloat/doc/implementation_precisions.md">md__2____w_2polyfloat_2polyfloat_2doc_2implementation__precisions</docanchor>
  </compound>
  <compound kind="page">
    <name>index</name>
    <title>SIMD-Aware Extended Precision Floating-Point</title>
    <filename>index.html</filename>
  </compound>
</tagfile>
