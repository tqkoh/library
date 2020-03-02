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


# :heavy_check_mark: test/graph/warshall-floyd.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/graph/warshall-floyd.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-03 04:13:43+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/graph/graph-template.cpp.html">Graph Template <small>(lib/graph/graph-template.cpp)</small></a>
* :heavy_check_mark: <a href="../../../library/lib/graph/warshall-floyd.cpp.html">Warshall Floyd <small>(lib/graph/warshall-floyd.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include "../template/template.hpp"
#include "lib/graph/graph-template.cpp"
#include "lib/graph/warshall-floyd.cpp"

void e2m(Matrix &g,Edges edges,bool directed,length infinity){
	for(auto& e:g)e.resize(g.size(),infinity);
	for(int i=0;i<g.size();++i)g[i][i]=0;
	for(auto& e:edges){
		g[e.src][e.to]=min(g[e.src][e.to],e.cost);
		if(!directed)g[e.to][e.src]=min(g[e.to][e.src],e.cost);
	}
}

int main(){
	int V,E; cin>>V>>E;
	vector<lint>s(E),t(E),d(E); for(int i=0;i<E;++i) cin>>s[i]>>t[i]>>d[i];
	Edges ge(E);
	for(int i=0;i<E;++i)ge[i]=edge(s[i],t[i],d[i]);
	Matrix g(V); e2m(g,ge,1,2*linf);
	warshall_floyd(g);

	bool ok=1;
	for(int i=0;i<V;++i)if(g[i][i]<0)ok=0;
	if(!ok)return cout<<"NEGATIVE CYCLE"<<endl,0;
	for(int i=0;i<V;++i){
		for(int j=0;j<V;++j){
			if(g[i][j]>linf)cout<<"INF";
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
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 68, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 182, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 182, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 77, in _resolve
    raise BundleError(path, -1, "no such header")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: bits/stdc++.h: line -1: no such header

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

