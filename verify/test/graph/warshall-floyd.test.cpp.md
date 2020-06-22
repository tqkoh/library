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


# :x: test/graph/warshall-floyd.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baa37bfd168b079b758c0db816f7295f">test/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/warshall-floyd.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-22 13:08:10+09:00




## Depends on

* :x: <a href="../../../library/lib/graph/graph-template.cpp.html">Graph Template</a>
* :x: <a href="../../../library/lib/graph/warshall-floyd.cpp.html">Warshall Floyd</a>
* :x: <a href="../../../library/test/template/template.cpp.html">test/template/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include "../../test/template/template.cpp"
#include "../../lib/graph/graph-template.cpp"
#include "../../lib/graph/warshall-floyd.cpp"

int main(){
	int V,E; cin>>V>>E;
	vector<lint>s(E),t(E),d(E); for(int i=0;i<E;++i) cin>>s[i]>>t[i]>>d[i];
	Edges ge(E);
	for(int i=0;i<E;++i)ge[i]=edge(s[i],t[i],d[i]);
	Matrix g(V); e2m(g,ge,1,linf); //Edges to Matrix

	warshall_floyd(g,linf);
	bool ok=1;
	for(int i=0;i<V;++i)if(g[i][i]<0)ok=0;
	if(!ok)return cout<<"NEGATIVE CYCLE"<<endl,0;
	for(int i=0;i<V;++i){
		for(int j=0;j<V;++j){
			if(g[i][j]==linf)cout<<"INF";
			else cout<<g[i][j];
			if(j!=V-1)cout<<" ";
		}
		cout<<endl;
	}
}
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
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 307, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 187, in _resolve
    raise BundleErrorAt(path, -1, "no such header")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h: line -1: no such header

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

