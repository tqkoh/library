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


# :heavy_check_mark: Warshall Floyd <small>(lib/graph/warshall-floyd.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/warshall-floyd.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-03 03:58:47+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/warshall-floyd.test.cpp.html">test/graph/warshall-floyd.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
void warshall_floyd(Matrix &g){
	rep(k,g.size())rep(g.size())rep(j,g.size())chmin(g[i][j],g[i][k]+g[k][j]);
	for(int k=0;k<g.size();++k){
		for(int i=0;i<g.size();++i){
			for(int j=0;j<g.size();++j){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
}
/*
* @brief Warshall Floyd
*/
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/graph/warshall-floyd.cpp"
void warshall_floyd(Matrix &g){
	rep(k,g.size())rep(g.size())rep(j,g.size())chmin(g[i][j],g[i][k]+g[k][j]);
	for(int k=0;k<g.size();++k){
		for(int i=0;i<g.size();++i){
			for(int j=0;j<g.size();++j){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
}
/*
* @brief Warshall Floyd
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

