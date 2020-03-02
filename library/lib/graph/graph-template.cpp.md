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


# :heavy_check_mark: Graph Template <small>(lib/graph/graph-template.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/graph-template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-03 03:58:47+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/warshall-floyd.test.cpp.html">test/graph/warshall-floyd.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
using length=lint;
struct edge{
	int src,to;
	length cost;

	edge(int src,int to,length cost): src(src),to(to),cost(cost){}
};

using Edges=vector<edge>;
using Weighted=vector<Edges>;
using UnWeighted=vector<vector<int> >;
using Matrix=vector<vector<length> >;

/*
* @brief Graph Template
*/
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/graph/graph-template.cpp"
using length=lint;
struct edge{
	int src,to;
	length cost;

	edge(int src,int to,length cost): src(src),to(to),cost(cost){}
};

using Edges=vector<edge>;
using Weighted=vector<Edges>;
using UnWeighted=vector<vector<int> >;
using Matrix=vector<vector<length> >;

/*
* @brief Graph Template
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

