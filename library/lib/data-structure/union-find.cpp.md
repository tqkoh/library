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


# :heavy_check_mark: Union Find <small>(lib/data-structure/union-find.cpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#cbed23bc82f8d451042dd45b42d995ac">lib/data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/data-structure/union-find.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-03 03:35:38+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/data-structure/union-find.test.cpp.html">test/data-structure/union-find.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
class UnionFind{
public:
	vector<int>par,rank;
	UnionFind(int n){
		par.resize(n);rank.resize(n,0);
		for(int i=0;i<n;++i)par[i]=i;
	}
	int root(int x){
		return x==par[x]?x:par[x]=root(par[x]);
	}
	bool same(int x,int y){
		return root(x)==root(y);
	}
	void unite(int x,int y){
		x=root(x);
		y=root(y);
		if(x==y)return;
		if(rank[x]<rank[y])par[x]=y;
		else{
			par[y]=x;
			if(rank[x]==rank[y])++rank[x];
		}
	}
};

/**
* @brief Union Find
*/
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/data-structure/union-find.cpp"
class UnionFind{
public:
	vector<int>par,rank;
	UnionFind(int n){
		par.resize(n);rank.resize(n,0);
		for(int i=0;i<n;++i)par[i]=i;
	}
	int root(int x){
		return x==par[x]?x:par[x]=root(par[x]);
	}
	bool same(int x,int y){
		return root(x)==root(y);
	}
	void unite(int x,int y){
		x=root(x);
		y=root(y);
		if(x==y)return;
		if(rank[x]<rank[y])par[x]=y;
		else{
			par[y]=x;
			if(rank[x]==rank[y])++rank[x];
		}
	}
};

/**
* @brief Union Find
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

