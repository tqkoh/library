---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/template/template.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3bd26683cf387f4976fcd993c9e66cb5">test/template</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/template/template.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-22 16:37:39+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/data-structure/union-find.test.cpp.html">test/data-structure/union-find.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/dijkstra.test.cpp.html">test/graph/dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/warshall-floyd.test.cpp.html">test/graph/warshall-floyd.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/util/divisors.test.cpp.html">test/util/divisors.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "bits/stdc++.h"
using namespace std;

using lint=int64_t;
const lint linf=1ll<<61;
const lint mod=1000000007;

struct Start{
	Start(){
		cin.tie(nullptr);
		ios::sync_with_stdio(0);
		cout<<fixed<<setprecision(10);
	}
} __start;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 307, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 187, in _resolve
    raise BundleErrorAt(path, -1, "no such header")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h: line -1: no such header

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

