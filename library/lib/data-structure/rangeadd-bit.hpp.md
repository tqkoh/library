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


# :warning: Rangeadd Binary Indexed Tree

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#cbed23bc82f8d451042dd45b42d995ac">lib/data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/data-structure/rangeadd-bit.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 05:05:34+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
template<typename T>
class BIT{
public:
	vector<T> b,a;
	BIT(int sz){ sz+=2;a.assign(sz,0);b.assign(sz,0); }
	void updateAB(int k,T na,T nb){
		for(;k<a.size();k+=k&-k){
			a[k]+=na;
			b[k]+=nb;
		}
	}
	T query(int k){
		T A=0;
		T B=0;
		int start=k;
		for(;k>0;k-=k&-k){
			A += a[k];
			B += b[k];
		}
		return A*--start+B;
	}
	void add(int l,int r,T x){
		updateAB(l,x,-x*(l-1));
		updateAB(r,-x,x*(r-1));
	}
	T sum(int l,int r){
		return query(r)-query(l);
	}
};

/*
* @title Rangeadd Binary Indexed Tree
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/data-structure/rangeadd-bit.hpp"
template<typename T>
class BIT{
public:
	vector<T> b,a;
	BIT(int sz){ sz+=2;a.assign(sz,0);b.assign(sz,0); }
	void updateAB(int k,T na,T nb){
		for(;k<a.size();k+=k&-k){
			a[k]+=na;
			b[k]+=nb;
		}
	}
	T query(int k){
		T A=0;
		T B=0;
		int start=k;
		for(;k>0;k-=k&-k){
			A += a[k];
			B += b[k];
		}
		return A*--start+B;
	}
	void add(int l,int r,T x){
		updateAB(l,x,-x*(l-1));
		updateAB(r,-x,x*(r-1));
	}
	T sum(int l,int r){
		return query(r)-query(l);
	}
};

/*
* @title Rangeadd Binary Indexed Tree
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

