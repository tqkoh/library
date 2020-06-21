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


# :heavy_check_mark: Graph Template

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/graph-template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-03 19:00:32+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/dijkstra.test.cpp.html">test/graph/dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/graph/warshall-floyd.test.cpp.html">test/graph/warshall-floyd.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
using length=lint;
struct edge{
	int src,to;
	length cost;
	edge()=default;
	edge(int src,int to,length cost): src(src),to(to),cost(cost){}
};

using Edges=vector<edge>;
using Weighted=vector<Edges>;
using UnWeighted=vector<vector<int> >;
using Matrix=vector<vector<length> >;

void e2w(Weighted& g,Edges edges,bool directed){
	for(auto& e:edges){
		g[e.src].push_back(e);
		if(!directed)g[e.to].push_back(edge(e.to,e.src,e.cost));
	}
}
void e2u(UnWeighted& g,Edges edges,bool directed){
	for(auto& e:edges){
		g[e.src].push_back(e.to);
		if(!directed)g[e.to].push_back(e.src);
	}
}
void e2m(Matrix& g,Edges edges,bool directed,length infinity){
	for(auto& e:g)e.resize(g.size(),infinity);
	for(int i=0;i<g.size();++i)g[i][i]=0;
	for(auto& e:edges){
		g[e.src][e.to]=min(g[e.src][e.to],e.cost);
		if(!directed)g[e.to][e.src]=min(g[e.to][e.src],e.cost);
	}
}


/*
* @title Graph Template
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
	edge()=default;
	edge(int src,int to,length cost): src(src),to(to),cost(cost){}
};

using Edges=vector<edge>;
using Weighted=vector<Edges>;
using UnWeighted=vector<vector<int> >;
using Matrix=vector<vector<length> >;

void e2w(Weighted& g,Edges edges,bool directed){
	for(auto& e:edges){
		g[e.src].push_back(e);
		if(!directed)g[e.to].push_back(edge(e.to,e.src,e.cost));
	}
}
void e2u(UnWeighted& g,Edges edges,bool directed){
	for(auto& e:edges){
		g[e.src].push_back(e.to);
		if(!directed)g[e.to].push_back(e.src);
	}
}
void e2m(Matrix& g,Edges edges,bool directed,length infinity){
	for(auto& e:g)e.resize(g.size(),infinity);
	for(int i=0;i<g.size();++i)g[i][i]=0;
	for(auto& e:edges){
		g[e.src][e.to]=min(g[e.src][e.to],e.cost);
		if(!directed)g[e.to][e.src]=min(g[e.to][e.src],e.cost);
	}
}


/*
* @title Graph Template
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

